#include <iostream>
#include <cmath> // For abs() function
#include <graphics.h> // For graphics functions

using namespace std;

// DDA line drawing function
void dda(int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0; // Change in x
    int dy = y1 - y0; // Change in y
    int steps;        // Number of steps required to draw the line

    // Calculate the number of steps needed
    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xIncrement = static_cast<float>(dx) / steps; // Increment in x
    float yIncrement = static_cast<float>(dy) / steps; // Increment in y

    float x = x0;
    float y = y0;

    // Draw the line using calculated increments
    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), color); // Plot the pixel with the specified color
        x += xIncrement;                     // Update x
        y += yIncrement;                     // Update y
    }
}

int main()
{
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    if (graphresult() != grOk) {
        cout << "Graphics initialization failed!" << endl;
        return 1;
    }

    // Get user input for line coordinates
    int x0, y0, x1, y1;
    cout << "Enter the starting coordinates (x0, y0): ";
    cin >> x0 >> y0;
    cout << "Enter the ending coordinates (x1, y1): ";
    cin >> x1 >> y1;

    // Get user input for line color
    int color;
    cout << "Enter the color code (0-15) for the line: ";
    cin >> color;

    // Draw the line using DDA
    dda(x0, y0, x1, y1, color);

    // Wait for a key press
    getch();
    closegraph();

    return 0;
}
