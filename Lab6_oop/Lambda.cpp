#include "Lambda.h"
#include <iostream>
#include <cmath>

using namespace std;

int dyhotomia(function<double(double)> func, double a, double b, double eps, double &x)
{
    if (func(a) * func(b) > 0)
    {
        cout << "Немає розв'язку на проміжку" << endl;
        return 1;
    }

    double c;
    while ((b - a) > eps)
    {
        c = (a + b) / 2;
        if (func(c) == 0)
        {
            x = c;
            return 0;
        }
        else if (func(a) * func(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    x = (a + b) / 2;
    return 0;
}

int newton(function<double(double)> func, function<double(double)> dfunc, double x0, double eps, double &x)
{
    x = x0;
    while (fabs(func(x)) > eps)
    {
        if (dfunc(x) == 0)
        {
            cout << "Помилка: похідна стала нулем" << endl;
            return 1;
        }
        x = x - func(x) / dfunc(x);
    }
    return 0;
}