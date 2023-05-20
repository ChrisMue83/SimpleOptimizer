#ifndef SIMPLEOPTIMIZER_H
#define SIMPLEOPTIMIZER_H

typedef double (*FunctionPtr)(double *, double *);

double *computeGradient(FunctionPtr exampleFunction, double *variables,
                        int variablessize, double *parameters,
                        int parameterssize);

double gradientDescent(FunctionPtr exampleFunction, double *initialVariables,
                       double *parameters, int variablessize,
                       int parameterssize, double learningRate,
                       int numIterations);

double simulatedAnnealing(FunctionPtr exampleFunction, double *variables,
                          double *parameters, int numVariables,
                          int numParameters, double initialTemperature,
                          double coolingRate, int numIterations);

#endif // SIMPLEOPTIMIZER_H
