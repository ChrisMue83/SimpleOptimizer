# SimpleOptimizer

This program provides a simple implementation of the gradient descent and simulated annealing methods for optimization problems. It allows you to define the function to be minimized and the number of variables involved.

## Table of Contents
- [Introduction](#introduction)
- [Usage](#usage)
- [Functions](#functions)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Simple Optimizer is designed to find the minimum value of a given function by iteratively adjusting the variables using either the gradient descent or simulated annealing algorithm. It calculates the numerical derivative using a step size for numerical differentiation and updates the variables accordingly.

## Usage

To use the Simple Optimizer, follow these steps:

1. Include the header file `simpleoptimizer.h` in your program.
2. Implement the function that you want to minimize. This function should take an array of variables and an array of parameters as input and return a double value.
3. Call the appropriate optimization function (`gradientDescent` or `simulatedAnnealing`) with the necessary parameters.

## Functions

The Simple Optimizer provides the following functions:

- `computeGradient`: Calculates the gradient of the function using numerical differentiation.
- `gradientDescent`: Performs gradient descent optimization to find the minimum value of the function.
- `simulatedAnnealing`: Performs simulated annealing optimization to find the minimum value of the function.

## Example

Here's an example of how to use the Simple Optimizer:

```cpp
#include "simpleoptimizer.h"

// Define the function to be minimized
double exampleFunction(double *variables, double *parameters) {
  // Implement your function here
  // Return the value to be minimized
}

int main() {
  // Define the necessary variables and parameters
  double initialVariables[] = {0.0, 0.0, 0.0};
  double parameters[] = {1.0, 2.0, 3.0};
  double learningRate = 0.01;
  int numIterations = 1000;

  // Perform gradient descent optimization
  double min = gradientDescent(exampleFunction, initialVariables, parameters,
                               3, 3, learningRate, numIterations);

  // Print the minimum value found
  std::cout << "Minimum value: " << min << std::endl;

  return 0;
}

