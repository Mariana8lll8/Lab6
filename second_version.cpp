#include "Lambda.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double eps = 1e-9;
    double a, b, x0, root;

    auto func = [](double x) { return 3 * x - 4 * log(x) - 5; };
    auto dfunc = [](double x) { return 3 - 4 / x; };
    auto dyhotomia = [](function<double(double)> func, double a, double b, double eps, double &x)
    {
        if (func(a) * func(b) > 0) { cout << "Немає розв'язку на проміжку" << endl; return 1; }

        double c;
        while ((b - a) > eps)
        {
            c = (a + b) / 2;
            if (func(c) == 0) { x = c; return 0; }
            else if (func(a) * func(c) < 0) { b = c; }
            else { a = c; }
        }

        x = (a + b) / 2;
    };
    auto newton = [](function<double(double)> func, function<double(double)> dfunc, double x0, double eps, double &x)
    {
        x = x0;
        while (fabs(func(x)) > eps)
        {
            if (dfunc(x) == 0) { cout << "Помилка: похідна стала нулем" << endl; return 1; }
            x = x - func(x) / dfunc(x);
        }
    };

    cout << "Введіть a, b для методу дихотомії: ";
    cin >> a >> b;
    if (dyhotomia(func, a, b, eps, root) == 0)
        cout << "Корінь (дихотомія): " << root << endl;

    cout << "Введіть x0 для методу Ньютона: ";
    cin >> x0;
    if (newton(func, dfunc, x0, eps, root) == 0)
        cout << "Корінь (метод Ньютона): " << root << endl;

    return 0;
}