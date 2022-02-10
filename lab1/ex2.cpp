#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    double d;
    d = b * b - 4 * a * c;
    if (a == 0)
    {
        double x = -c * 1.0 / b;
        cout << x;
    }
    else if (a == 0 and b == 0)
    {
        if (c != 0)
            cout << "\n";
    }
    else if (d > 0)
    {
        double x1 = (-b - sqrt(d)) / 2 / a;
        double x2 = (-b + sqrt(d)) / 2 / a;
        cout << x1 << " " << x2;
        
    }
    else if (d == 0)
    {
        double x = -b * 1.0 / 2 / a;
        cout << x;
    }
    else
    {
        cout << "\n";
    }

    return 0;
}