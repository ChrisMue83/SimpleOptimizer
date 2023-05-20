#include "simpleoptimizer.h"
#include <cmath>
#include <iostream>

// Example implementation of the exampleFunction
double myExampleFunction(double *variables, double *parameters) {
  // Implement your own function here using the variables and parameters
  double result = 0;
  for (int i = 0; i < 5; i++)
    result += pow(variables[i] - parameters[i], 2);
  return result;
}

int main() {
  // Example invocation
  double initialVariables[5] = {1., 1., 1., 1.,
                                1.};               // Initial variable values
  double parameters[5] = {1.0, 2.0, 3., 4.0, 5.0}; // Fixed parameters
  double learningRate = 0.05;                       // Learning rate
  int numIterations = 150;                           // Number of iterations
  double bestfit;
  bestfit = simulatedAnnealing(myExampleFunction, initialVariables,
                                      parameters, 5, 5, 200, 0.95, 100);
  // simulatedAnnealing(myExampleFunction, initialVariables, parameters,
  // numberofvariables, numberofparameters, initialTemperature, coolingRate,
  // numIterations)

  bestfit = gradientDescent(myExampleFunction, initialVariables, parameters, 5,
                            5, learningRate, numIterations);
  // gradientDescent(myExampleFunction, initialVariables, parameters,
  // numberofvariables, numberofparameters, learningRate, numIterations);

  for (int i = 0; i < 5; i++)
    std::cout << initialVariables[i] << "  ";
  std::cout << bestfit << std::endl;

  return 0;
}
