#include <iostream>
#include <cmath>
using namespace std;

double rec_sum(double const psi[], double const pdf[], double const dv, unsigned size){
    if (size==1){
        return psi[0]*pdf[0]*dv;
    }
    return rec_sum(psi, pdf, dv, size/2) + rec_sum(psi+size/2, pdf+size/2, dv, size-size/2);
} 

int main()
{
    double const f_pi = 3.14159265359;
    double const f_e = 2.718281828459;
    double T = 300;
    unsigned int n = 10000000;
    double left = -1000;
    double right = 1000;
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
    cout << "result:" << rec_sum(psi, pdf, dv, n) << endl;
    delete [] psi;
    delete [] pdf;
    return 0;
}
