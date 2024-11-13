#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WIDTH  20
#define HEIGHT 5

// Frame buffer to store the ASCII image
char framebuffer[HEIGHT][WIDTH];

// Structure to represent a rectangle
typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t width;
    uint8_t height;
    char ch;
} Rectangle;

// Function to initialize the frame buffer with spaces
void initialize_framebuffer() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            framebuffer[i][j] = ' ';
        }
    }
}

// Function to render a rectangle into the frame buffer
void render_rectangle(Rectangle *rect) {
    for (int i = 0; i < rect->height; i++) {
        int y = rect->y + i;
        if (y >= HEIGHT) continue;
        for (int j = 0; j < rect->width; j++) {
            int x = rect->x + j;
            if (x >= WIDTH) continue;
            framebuffer[y][x] = rect->ch;
        }
    }
}

// Function to print the frame buffer to stdout
void print_framebuffer() {
    for (int i = 0; i < HEIGHT; i++) {
        fwrite(framebuffer[i], sizeof(char), WIDTH, stdout);
        putchar('\n');
    }
}

// Function to convert the frame buffer into a string
void framebuffer_to_string(char *buffer, size_t size) {
    char *p = buffer;
    for (int i = 0; i < HEIGHT; i++) {
        if ((size_t)(p - buffer + WIDTH + 1) >= size) {
            break;
        }
        memcpy(p, framebuffer[i], WIDTH);
        p += WIDTH;
        *p++ = '\n';
    }
    *p = '\0';
}

// Function to compare the frame buffer with the expected output
int framebuffer_matches(const char *expected_output) {
    char buffer[(WIDTH + 1) * HEIGHT + 1];
    framebuffer_to_string(buffer, sizeof(buffer));
    return strcmp(buffer, expected_output) == 0;
}

int main() {
    initialize_framebuffer();

    // Read the number of rectangles from stdin
    uint32_t num_rectangles;
    if (fread(&num_rectangles, sizeof(uint32_t), 1, stdin) != 1) {
        fprintf(stderr, "Failed to read number of rectangles\n");
        exit(1);
    }

    // Read each rectangle and render it
    for (uint32_t i = 0; i < num_rectangles; i++) {
        Rectangle rect;
        if (fread(&rect, sizeof(Rectangle), 1, stdin) != 1) {
            fprintf(stderr, "Failed to read rectangle %u\n", i);
            exit(1);
        }
        render_rectangle(&rect);
    }

    // Print the resulting ASCII image
    print_framebuffer();

    // Expected output to compare with the frame buffer
    const char expected_output[] =
        "********************\n"
        "*                  *\n"
        "*  HELLO, WORLD!   *\n"
        "*                  *\n"
        "********************\n";

    // If the frame buffer matches the expected output, read and print the flag
    if (framebuffer_matches(expected_output)) {
        FILE *f = fopen("/flag", "r");
        if (f == NULL) {
            fprintf(stderr, "Failed to open /flag\n");
            exit(1);
        }
        char flag[128];
        if (fgets(flag, sizeof(flag), f) != NULL) {
            printf("%s\n", flag);
        } else {
            fprintf(stderr, "Failed to read flag\n");
        }
        fclose(f);
    }

    return 0;
}
