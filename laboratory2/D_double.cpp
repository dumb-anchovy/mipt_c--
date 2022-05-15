#include <iostream>
#include <cmath>
using namespace std;

void Split(double const x, double &x_h, double &x_l) {
    auto c = static_cast<double>((1ul << 11) + 1ul);
    x_h = (c * x) + (x - (c * x));
    x_l = x - x_h;
}

double TwoMult(double const a, double const b){
    double a_high, a_low, b_high, b_low;
    Split(b, b_high, b_low);
    Split(a, a_high, a_low);
    double s = a * b, t;
    t = a_high * b_high;
    t += a_high * b_low;
    t += a_low * b_high;
    t += a_low * b_low;
    return t;
}

double rec_sum(double const psi[], double const pdf[], double const dv, unsigned size){
    if (size==1){
        return psi[0]*pdf[0]*dv;
    }
    return rec_sum(psi, pdf, dv, size/2) + rec_sum(psi+size/2, pdf+size/2, dv, size-size/2);
}

double fma_rec_sum(double const psi[], double const pdf[], double const dv, unsigned size){
    if (size==1){
        return TwoMult(TwoMult(psi[0],pdf[0]),dv);
    }
    return rec_sum(psi, pdf, dv, size/2) + rec_sum(psi+size/2, pdf+size/2, dv, size-size/2);
} 

int main()
{
    double const f_pi = 3.14159265359;
    double const f_e = 2.718281828459;
    double T = 300;
    unsigned int n = 1000000;
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
    cout << "recursive addition result:" << rec_sum(psi, pdf, dv, n) << endl;
    cout << "recursive addition using fma result :" << fma_rec_sum(psi, pdf, dv, n) << endl;
    delete [] psi;
    delete [] pdf;
    return 0;
}
