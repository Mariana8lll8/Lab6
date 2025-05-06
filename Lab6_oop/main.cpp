#include "Lambda.h"
#include <iostream>

using namespace std;

int main()
{
    const double eps = 1e-9;
    double a, b, x0, root;

    auto func = [](double x) { return 3 * x - 4 * log(x) - 5; };
    auto dfunc = [](double x) { return 3 - 4 / x; };

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