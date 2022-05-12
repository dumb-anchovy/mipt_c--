#include <iostream>
#include <cmath>
using namespace std;

float kahan_sum(float const psi[], float const pdf[], float const dv, unsigned size){
    float sum = 0.0;
    float c = 0.0;
    for(int i = 0; i < size; i++){
        float y = psi[i] * pdf[i] * dv - c;
        float t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
} 

int main()
{
    float const f_pi = 3.14159265359f;
    float const f_e = 2.718281828459f;
    float T = 300;
    unsigned int n = 10000000;
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
    cout << "result:" << kahan_sum(psi, pdf, dv, n) << endl;
    delete [] psi;
    delete [] pdf;
    return 0;
}
