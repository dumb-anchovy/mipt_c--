#include <iostream>
#include <cmath>
using namespace std;

double kahan_sum(double const psi[], double const pdf[], double const dv, unsigned size){
    double sum = 0.0;
    double c = 0.0;
    for(int i = 0; i < size; i++){
        double y = psi[i] * pdf[i] * dv - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
} 

int main()
{
    double const f_pi = 3.14159265359;
    double const f_e = 2.718281828459;
    double T = 300;
    unsigned int n = 100000;
    double left = -100;
    double right = 100;
    double v = left;
    double dv = (right - left) / n;
    double *psi = 0;
    double *pdf = 0;
    psi = new double[n];
    pdf = new double[n];
    for (int i = 0; i < n; i++)
    {
        v = v + dv;
        psi[i] = abs(v);
        pdf[i] = pow(f_e, (- v * v / T)) / sqrt(f_pi * T);
    }
    cout<< "expectation:" << sqrt(T/f_pi)<<endl;
    cout << "result:" << kahan_sum(psi, pdf, dv, n) << endl;
    delete [] psi;
    delete [] pdf;
    return 0;
}
