#include <iostream>
#include <cmath>
using namespace std;

//бинарный поиск
bool bs(int a[], unsigned i, unsigned j, int x){
    int m = 0;
    while (j - i >1){
        int m = ( j + i) /2;
        if (a[m] < x ){
            i = m;
        }
        else{
            j=m;
        }
    }
    if ( x == a[j]){
        return true;
    }
    else{
        return false;
    }
}


int main()
{
    const int n = 8; //размер массива
    int b[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int x=0;
    cout << "enter the number";
    cin >> x;
    if (bs(b, 0, n, x)==1){
        cout << "True";
    }
    else{
        cout << "False";
    }

}
