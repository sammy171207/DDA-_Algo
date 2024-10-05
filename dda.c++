#include <iostream>
#include <cmath>  // For abs() and round() functions
#include <graphics.h>  // For graphics functions
#include <conio.h>  // For getch()

using namespace std;

// DDA line drawing function
void dda(int x0, int y0, int x1, int y1, int color, string style = "solid") {
    int dx = x1 - x0;  // Change in x
    int dy = y1 - y0;  // Change in y
    int steps = max(abs(dx), abs(dy));  // Calculate the number of steps needed

    float xIncrement = static_cast<float>(dx) / steps;  // Increment in x
    float yIncrement = static_cast<float>(dy) / steps;  // Increment in y

    float x = x0;
    float y = y0;

    // Draw the line using calculated increments
    for (int i = 0; i <= steps; i++) {
        if (style == "dashed" && (i % 10 < 5)) {
            putpixel(round(x), round(y), color);  // Plot dashed line with the specified color
        } else if (style == "solid") {
            putpixel(round(x), round(y), color);  // Plot solid line with the specified color
        }

        x += xIncrement;  // Update x
        y += yIncrement;  // Update y
    }
}

// Function to show the color palette
void showColorPalette() {
    cout << "Color Palette (0-15):" << endl;
    for (int i = 0; i < 16; i++) {
        cout << "Color " << i << ": ";
        setcolor(i);
        rectangle(20 + i * 40, 10, 60 + i * 40, 50);
        floodfill(30 + i * 40, 20, i);
    }
    getch();
}

// Function to initialize graphics mode and handle errors
bool initializeGraphics() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    if (graphresult() != grOk) {
        cout << "Error: Graphics initialization failed!" << endl;
        return false;
    }
    return true;
}

// Function to get color input with validation
int getColorInput() {
    int color;
    do {
        cout << "Enter the color code (0-15) for the line: ";
        cin >> color;
        if (color < 0 || color > 15) {
            cout << "Invalid color code! Please enter a value between 0 and 15." << endl;
        }
    } while (color < 0 || color > 15);

    return color;
}

int main() {
    // Initialize graphics mode
    if (!initializeGraphics()) {
        return 1;
    }

    // Display color palette to the user
    showColorPalette();

    // Get user input for line coordinates
    int x0, y0, x1, y1;
    cout << "Enter the starting coordinates (x0, y0): ";
    cin >> x0 >> y0;
    cout << "Enter the ending coordinates (x1, y1): ";
    cin >> x1 >> y1;

    // Get color input
    int color = getColorInput();

    // Get user input for line style
    string style;
    cout << "Enter the line style (solid/dashed): ";
    cin >> style;

    // Draw the line using DDA with chosen style
    dda(x0, y0, x1, y1, color, style);

    // Wait for a key press and close graphics
    cout << "Press any key to exit..." << endl;
    getch();
    closegraph();

    return 0;
}
