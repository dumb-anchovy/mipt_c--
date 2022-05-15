#include <iostream>
#include <cmath>
using namespace std;

void Split(float const x, float &x_h, float &x_l) {
    auto c = static_cast<float>((1ul << 11) + 1ul);
    x_h = (c * x) + (x - (c * x));
    x_l = x - x_h;
}

float TwoMult(float const a, float const b){
    float a_high, a_low, b_high, b_low;
    Split(b, b_high, b_low);
    Split(a, a_high, a_low);
    float s = a * b, t;
    t = a_high * b_high;
    t += a_high * b_low;
    t += a_low * b_high;
    t += a_low * b_low;
    return t;
}

float rec_sum(float const psi[], float const pdf[], float const dv, unsigned size){
    if (size==1){
        return psi[0]*pdf[0]*dv;
    }
    return rec_sum(psi, pdf, dv, size/2) + rec_sum(psi+size/2, pdf+size/2, dv, size-size/2);
}

float fma_rec_sum(float const psi[], float const pdf[], float const dv, unsigned size){
    if (size==1){
        return TwoMult(TwoMult(psi[0],pdf[0]),dv);
    }
    return rec_sum(psi, pdf, dv, size/2) + rec_sum(psi+size/2, pdf+size/2, dv, size-size/2);
} 

int main()
{
    float const f_pi = 3.14159265359f;
    float const f_e = 2.718281828459f;
    float T = 300;
    unsigned int n = 1000000;
    float left = -1000;
    float right = 1000;
    float v = left;
    float dv = (right - left) / n;
    float *psi = 0;
    float *pdf = 0;
    psi = new float[n];
    pdf = new float[n];
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
