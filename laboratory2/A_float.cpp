#include <iostream>
#include <cmath>
using namespace std;

float rec_sum(float const psi[], float const pdf[], float const dv, unsigned size){
    if (size==1){
        return psi[0]*pdf[0]*dv;
    }
    return rec_sum(psi, pdf, dv, size/2) + rec_sum(psi+size/2, pdf+size/2, dv, size-size/2);
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
    cout << "result:" << rec_sum(psi, pdf, dv, n) << endl;
    delete [] psi;
    delete [] pdf;
    return 0;
}
