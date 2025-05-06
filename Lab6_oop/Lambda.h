#pragma once
#include <iostream>
#include <cmath>

using namespace std;

int dyhotomia(function<double(double)> func, double a, double b, double eps, double &x);

int newton(function<double(double)> func, function<double(double)> dfunc, double x0, double eps, double &x);