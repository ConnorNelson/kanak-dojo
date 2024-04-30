from flask import Flask, render_template_string

app = Flask(__name__)

@app.route('/')
def hello():
    html = """
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Hello World</title>
        <style>
            body {
                background-color: #f0f0f0;
                font-family: Arial, sans-serif;
            }
            .container {
                display: flex;
                justify-content: center;
                align-items: center;
                height: 100vh;
            }
            .content {
                background-color: #ffffff;
                padding: 20px;
                box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
            }
            h1 {
                color: #333333;
            }
        </style>
    </head>
    <body>
        <div class="container">
            <div class="content">
                <h1>Hello, World!</h1>
            </div>
        </div>
    </body>
    </html>
    """
    return render_template_string(html)

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=80)
