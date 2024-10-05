#include <iostream>
#include <cmath> // For abs() and round() functions
#include <graphics.h> // For graphics functions

using namespace std;

// DDA line drawing function
void dda(int x0, int y0, int x1, int y1, int color)
{
    int dx = x1 - x0; // Change in x
    int dy = y1 - y0; // Change in y
    int steps = max(abs(dx), abs(dy)); // Max of dx and dy determines steps

    float xIncrement = static_cast<float>(dx) / steps; // Increment in x
    float yIncrement = static_cast<float>(dy) / steps; // Increment in y

    float x = x0;
    float y = y0;

    // Draw the line pixel by pixel
    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), color); // Plot the pixel at (x, y) with the given color
        x += xIncrement; // Update x for the next step
        y += yIncrement; // Update y for the next step
    }
}

// Function to initialize graphics mode and handle errors
bool initializeGraphics()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    if (graphresult() != grOk)
    {
        cout << "Error: Graphics initialization failed!" << endl;
        return false;
    }
    return true;
}

// Function to get color input with validation
int getColorInput()
{
    int color;
    do
    {
        cout << "Enter the color code (0-15) for the line: ";
        cin >> color;
        if (color < 0 || color > 15)
        {
            cout << "Invalid color code! Please enter a value between 0 and 15." << endl;
        }
    } while (color < 0 || color > 15);

    return color;
}

int main()
{
    // Initialize graphics mode
    if (!initializeGraphics())
    {
        return 1;
    }

    // Get user input for line coordinates
    int x0, y0, x1, y1;
    cout << "Enter the starting coordinates (x0, y0): ";
    cin >> x0 >> y0;
    cout << "Enter the ending coordinates (x1, y1): ";
    cin >> x1 >> y1;

    // Get color input
    int color = getColorInput();

    // Draw the line using DDA algorithm
    dda(x0, y0, x1, y1, color);

    // Wait for key press before closing the graphics window
    cout << "Press any key to exit..." << endl;
    getch();
    closegraph();

    return 0;
}
