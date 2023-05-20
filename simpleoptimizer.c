#include "simpleoptimizer.h"
#include <cmath>
#include <cstring>
#include <random>

double *computeGradient(FunctionPtr exampleFunction, double *variables,
                        int variablessize, double *parameters,
                        int parameterssize) {
  const double h = 1e-5; // Step size for numerical differentiation
  double *gradient = new double[variablessize];
  double *variablesPlusH = new double[variablessize];

  for (int i = 0; i < variablessize; ++i) {
    // Slightly increase the variable

    for (int j = 0; j < variablessize; j++)
      variablesPlusH[j] = variables[j];
    variablesPlusH[i] += h;

    // Calculate function values
    double fPlusH = exampleFunction(variablesPlusH, parameters);
    double f = exampleFunction(variables, parameters);

    // Calculate numerical derivative
    gradient[i] = (fPlusH - f) / h;
  }
  delete[] variablesPlusH; // Free memory

  return gradient;
}

double gradientDescent(FunctionPtr exampleFunction, double *initialVariables,
                       double *parameters, int variablessize,
                       int parameterssize, double learningRate,
                       int numIterations) {
  double min = 1E9;
  double currentValue;
  double *bestvariables = new double[variablessize];
  std::memcpy(bestvariables, initialVariables, variablessize * sizeof(double));

  for (int iter = 0; iter < numIterations; iter++) {
    // Calculate the gradient
    double *gradient =
        computeGradient(exampleFunction, initialVariables, variablessize,
                        parameters, parameterssize);

    // Update the variables
    for (int i = 0; i < variablessize; ++i) {
      initialVariables[i] -= learningRate * gradient[i];
    }

    currentValue = exampleFunction(initialVariables, parameters);

    if (currentValue < min) {
      min = currentValue;
      std::memcpy(bestvariables, initialVariables,
                  variablessize * sizeof(double));
    }

    delete[] gradient; // Free memory
  }

  std::memcpy(initialVariables, bestvariables, variablessize * sizeof(double));
  delete[] bestvariables; // Free memory

  return min;
}

double simulatedAnnealing(FunctionPtr exampleFunction, double *variables,
                          double *parameters, int numVariables,
                          int numParameters, double initialcurrentValueerature,
                          double coolingRate, int numIterations) {

  // Initialize random number generator
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(-1.0, 1.0);

  // Initialize current solution
  double currentSolution = exampleFunction(variables, parameters);

  // Initialize best solution
  double bestSolution = currentSolution;
  double *bestVariables = new double[numVariables];
  std::copy(variables, variables + numVariables, bestVariables);

  // Perform simulated annealing
  double currentValueerature = initialcurrentValueerature;
  for (int iteration = 0; iteration < numIterations; iteration++) {
    // Generate a new neighboring solution
    double *newVariables = new double[numVariables];
    for (int i = 0; i < numVariables; i++) {
      newVariables[i] = variables[i] + dist(gen);
    }

    // Calculate the new solution's value
    double newSolution = exampleFunction(newVariables, parameters);

    // Calculate the acceptance probability
    double acceptanceProbability =
        std::exp((currentSolution - newSolution) / currentValueerature);

    // Accept or reject the new solution
    if (newSolution < currentSolution ||
        std::bernoulli_distribution(acceptanceProbability)(gen)) {
      std::copy(newVariables, newVariables + numVariables, variables);
      currentSolution = newSolution;

      // Check if the new solution is the best so far
      if (newSolution < bestSolution) {
        bestSolution = newSolution;
        std::copy(newVariables, newVariables + numVariables, bestVariables);
      }
    }

    // Decrease the currentValueerature
    currentValueerature *= coolingRate;

    delete[] newVariables;
  }

  std::copy(bestVariables, bestVariables + numVariables, variables);
  delete[] bestVariables;

  return bestSolution;
}
