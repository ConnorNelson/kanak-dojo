#!/opt/pwn.college/python

import ctypes
import os
import pathlib
import pty
import random
import select
import subprocess
import termios

from jinja2 import Environment, FileSystemLoader


import readline

try:
    seed = open("/flag", "rb").read()
except:
    seed = 0
random = random.Random(seed)

info_path = pathlib.Path(__file__).parent.parent / ".info"
env = Environment(loader=FileSystemLoader(info_path))

libc = ctypes.CDLL("libc.so.6")
pidfd_open = lambda pid, flags: libc.syscall(434, pid, flags)

def drop_privileges():
    os.seteuid(os.getuid())
    os.setegid(os.getgid())

def run(command, **kwargs):
    kwargs["preexec_fn"] = drop_privileges
    return subprocess.run(command, **kwargs)

def render(template, **kwargs):
    text = env.get_template(template).render(**kwargs)
    run(["/usr/bin/glow"], input=text.encode(), check=True)

def shell_prompt():
    user = "hacker"
    hostname = os.uname().nodename
    cwd = os.getcwd()
    symbol = "$" if user != "root" else "#"
    prompt = f"{user}@{hostname}:{cwd}{symbol} "
    command = input(prompt)
    return command

def shell_run():
    command = shell_prompt()
    process_result = run(command, shell=True)
    return command, process_result.returncode

def forced_shell_run(forced_command, command_name=None):
    while True:
        command, result = shell_run()
        command_name = f"{command_name} command" if command_name else "command"
        if command != forced_command:
            print(f"Please run the {command_name} as specified, try again!")
            continue
        return command, result

def interactive(command, interactive_prompts):
    master, slave = pty.openpty()
    attrs = termios.tcgetattr(slave)
    attrs[3] = attrs[3] & ~termios.ECHO
    termios.tcsetattr(slave, termios.TCSANOW, attrs)
    process = subprocess.Popen(command,
                               stdin=slave,
                               stdout=slave,
                               stderr=slave,
                               shell=True)
    process_stdin = open(master, "wb", buffering=0)
    process_fd = pidfd_open(process.pid, 0)
    full_output = ""
    while True:
        timeout = 5
        ready, _, _ = select.select([process_fd, master], [], [], timeout)
        if process_fd in ready:
            break
        if ready:
            output = os.read(master, 0x1000).decode()
            if output:
                print(output, end="", flush=True)
                full_output += output
                if any(full_output.endswith(prompt) for prompt in interactive_prompts):
                    yield process_stdin
            else:
                break
        else:
            raise TimeoutError()
