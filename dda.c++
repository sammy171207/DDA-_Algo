#include <iostream>

#include <cmath> // For abs() function

void dda(int x0, int y0, int x1, int y1)
{
    int dx = x1 - x0; // Change in x
    int dy = y1 - y0; // Change in y
    int steps;        // Number of steps required to draw the line

    // Calculate the number of steps needed
    if (abs(dx) > abs(dy))
    {
        steps = abs(dx); // If the line is more horizontal
    }
    else
    {
        steps = abs(dy); // If the line is more vertical
    }

    float xIncrement = static_cast<float>(dx) / steps; // Increment in x
    float yIncrement = static_cast<float>(dy) / steps; // Increment in y

    float x = x0;
    float y = y0;

    // Draw the line using calculated increments
    for (int i = 0; i <= steps; i++)
    {
        putpixel(round(x), round(y), WHITE); // Plot the pixel
        x += xIncrement;                     // Update x
        y += yIncrement;                     // Update y
    }
}

int main()
{
    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define start and end points of the line
    int x0 = 100, y0 = 100;
    int x1 = 400, y1 = 300;

    // Call the DDA function
    dda(x0, y0, x1, y1);

    // Wait for a key press
    getch();
    closegraph();
    return 0;
}
