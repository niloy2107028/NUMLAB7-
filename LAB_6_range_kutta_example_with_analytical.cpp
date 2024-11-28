#include <bits/stdc++.h>
using namespace std;

double func(double x, double y)
{
    return 3 * x - y;
}

pair<vector<double>, vector<double>> runge_kutta(double &x0, double &y0, double &x, double &h)
{
    double xn = x0, yn = y0;
    double k1, k2, k3, k4;
    vector<double> x_values, y_values;
    y_values.push_back(yn);
    while (xn < x)
    {
        x_values.push_back(xn);
        k1 = h * func(xn, yn);
        k2 = h * func(xn + h / 2, yn + k1 / 2);
        k3 = h * func(xn + h / 2, yn + k2 / 2);
        k4 = h * func(xn + h, yn + k3);
        yn = yn + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        xn = xn + h;
        y_values.push_back(yn);
    }
    return make_pair(x_values, y_values);
}

vector<double> analytic(double &x0, double &y0, double &x, double &h)
{
    double xn = x0, yn = y0;
    vector<double> y_values;
    while (xn < x)
    {
        yn = 3 * xn - 3 + 4 * exp(-xn);
        y_values.push_back(yn);
        xn += h;
    }
    return y_values;
}

int main()
{

    double x0 = 0;
    double y0 = 1;
    double x = 10;
    double step = 0.1;

    auto y_analytical = analytic(x0, y0, x, step);

    auto res = runge_kutta(x0, y0, x, step);
    auto x_values = res.first;
    auto y_numerical = res.second;

    for (int i = 0; i < y_analytical.size(); i++)
    {
        cout << abs(y_analytical[i] - y_numerical[i]) << endl;
    }

    // for (int i = 0; i < x_values.size(); i++)
    // {
    //     cout << x_values[i] << endl;
    // }

    // for (int i = 0; i < y_analytical.size(); i++)
    // {
    //     cout << y_analytical[i] << endl;
    // }

    // for (int i = 0; i < y_numerical.size(); i++)
    // {
    //     cout << y_numerical[i] << endl;
    // }

    return 0;
}