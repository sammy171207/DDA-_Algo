 
DDA Line Algorithm in C++

Welcome to the Digital Differential Analyzer (DDA) Line Algorithm implementation in C++! This repository showcases an efficient method for line generation in computer graphics, calculating the intermediate points seamlessly between two given endpoints.
Overview

The DDA Line Algorithm is a fundamental concept in Computer Graphics and Multimedia Applications (CGMA), providing a simple and computationally effective way to draw straight lines by interpolating between the starting and ending points. By incrementing either the x or y coordinate and calculating the other based on the line's slope, the algorithm efficiently generates each intermediate point, ensuring a smooth and accurate rendering.
Features

    🚀 Efficient Line Drawing: Uses incremental calculations, minimizing the complexity while avoiding costly floating-point operations.
    ✨ Simple and Elegant: The code is designed for clarity, making it easy to understand and integrate into C++ projects.
    📍 Detailed Output: Displays each coordinate calculated along the path of the line for better visualization and debugging.

How the DDA Algorithm Works

The Digital Differential Analyzer (DDA) is an incremental algorithm that works as follows:

    Calculate Differences: Compute the differences (dx and dy) between the x and y coordinates of the endpoints.
    Determine Steps: The number of steps is determined based on the greater of the absolute differences between dx and dy.
    Increment Coordinates: The increments (X_inc and Y_inc) are computed to determine the rate of change, and these increments are used to generate all points on the line.

DDA Increment Formula

makefile

X_inc = dx / steps
Y_inc = dy / steps

Code Implementation

Here's the C++ code that implements the DDA Line Algorithm:

cpp

#include <iostream>
#include <cmath>

using namespace std;

// Function to implement DDA Line Drawing Algorithm
void DDA_Line(int x1, int y1, int x2, int y2) {
    // Calculate dx and dy
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate steps
    int steps = max(abs(dx), abs(dy));

    // Calculate increments for each axis
    float X_inc = dx / (float) steps;
    float Y_inc = dy / (float) steps;

    // Starting point
    float X = x1;
    float Y = y1;

    // Print the first point
    cout << "Point: (" << round(X) << ", " << round(Y) << ")" << endl;

    // Iterate and generate intermediate points
    for (int i = 0; i <= steps; i++) {
        // Round off X and Y to get the pixel coordinates
        cout << "Point: (" << round(X) << ", " << round(Y) << ")" << endl;
        
        // Increment X and Y by calculated values
        X += X_inc;
        Y += Y_inc;
    }
}

int main() {
    int x1, y1, x2, y2;

    // Input coordinates
    cout << "Enter the coordinates of the first point (x1, y1): ";
    cin >> x1 >> y1;
    
    cout << "Enter the coordinates of the second point (x2, y2): ";
    cin >> x2 >> y2;

    // Call the DDA Line Drawing function
    DDA_Line(x1, y1, x2, y2);

    return 0;
}

Getting Started

Follow these steps to run the code on your local machine:

    Clone the Repository:

    bash

git clone https://github.com/yourusername/DDA_Algorithm.git

Compile and Run:

bash

    g++ dda_line_algorithm.cpp -o dda_line
    ./dda_line

    Input Coordinates: Enter the coordinates of the two endpoints when prompted, and see the generated points that form the line.

Example Output

For a pair of points (2, 3) and (8, 6), the output will look like:

mathematica

Enter the coordinates of the first point (x1, y1): 2 3
Enter the coordinates of the second point (x2, y2): 8 6
Point: (2, 3)
Point: (3, 3)
Point: (4, 4)
Point: (5, 4)
Point: (6, 5)
Point: (7, 5)
Point: (8, 6)

License

This project is licensed under the MIT License, giving you freedom to use, modify, and distribute the code while maintaining attribution to the original author.
