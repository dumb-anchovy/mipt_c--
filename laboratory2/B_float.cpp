#include <iostream>
#include <cmath>
using namespace std;

float close_values(float const psi[], float const pdf[], float const dv, int size){
    int step = 1;
    float x[size];
    for(int i = 0; i < size; i++){
        x[i] = psi[i] * pdf[i] * dv;
    }
    while(step < size){
        for(int i = 0; i + step < size; i += 2*step){
            x[i] = x[i] + x[i + step];
        }
        step *= 2;
    }
    return x[0];
}

int main()
{
    float const f_pi = 3.14159265359f;
    float const f_e = 2.718281828459f;
    float T = 300;
    unsigned int n = 100000;
    float left = -100;
    float right = 100;
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
    cout << "result:" << close_values(psi, pdf, dv, n) << endl;
    delete [] psi;
    delete [] pdf;
    return 0;
}
