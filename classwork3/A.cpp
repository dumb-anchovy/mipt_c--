#include <iostream>
#include <cmath>
using namespace std;

const int N = 8;

void gnome(int a[N]){
    int i = 1;
    int j = 2;
    while (i < N){
        if (a[i - 1] < a[i]){
            i = j;
            j = j + 1;
        } 
        else{
            int k = a[i];
            a[i] = a[i - 1];
            a[i - 1] = k;
            i = i - 1;
            if (i == 0){
                i = j;
                j = j + 1;
            }
        }

    }
        
}

void print(int a[N]) {
    for (int i = 0; i < N; i++) {
        cout << a[i] << "\t";
    }
}

int main()
{
    int a[N] = {0};
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    gnome(a);
    print(a);
    return 0;
}
