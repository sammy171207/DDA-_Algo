# Digital Differential Analyzer (DDA) Algorithm in C++

## Overview
The Digital Differential Analyzer (DDA) algorithm is a line generation algorithm used in computer graphics to draw a straight line between two points in a 2D space. This repository contains a C++ implementation of the DDA algorithm, demonstrating how to plot a line based on given start and end coordinates.


# Explanation
Include Libraries

    #include <graphics.h>: Required for graphics functions. Ensure you have a graphics library installed (like WinBGIm for Windows).
    #include <cmath>: For mathematical functions.
    
# DDA Function

    Takes the starting point (x0, y0) and the ending point (x1, y1).
    Calculates the differences in x and y (dx and dy).
    Determines the number of steps required to plot the line, based on which dimension (x or y) is larger.
    Computes increments for x and y based on the total number of steps.
    Uses a loop to plot each point along the line.

# Main Function

    Initializes the graphics system.
    Calls the DDA function to draw the line between two specified points.
    Waits for a key press before closing the graphics window.

# Note

    Ensure you have the necessary graphics library set up in your environment. If you're using Windows, you can use the WinBGIm library to get graphics.h working.
    To compile the program, use an appropriate compiler that supports graphics (like Code::Blocks or Dev-C++).
## Code Implementation

```cpp
#include <iostream>
#include <graphics.h> // Make sure to have graphics.h installed
#include <cmath> // For abs() function

void dda(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0; // Change in x
    int dy = y1 - y0; // Change in y
    int steps; // Number of steps required to draw the line

    // Calculate the number of steps needed
    if (abs(dx) > abs(dy)) {
        steps = abs(dx); // If the line is more horizontal
    } else {
        steps = abs(dy); // If the line is more vertical
    }

    float xIncrement = static_cast<float>(dx) / steps; // Increment in x
    float yIncrement = static_cast<float>(dy) / steps; // Increment in y

    float x = x0;
    float y = y0;

    // Draw the line using calculated increments
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE); // Plot the pixel
        x += xIncrement; // Update x
        y += yIncrement; // Update y
    }
}

int main() {
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
 




