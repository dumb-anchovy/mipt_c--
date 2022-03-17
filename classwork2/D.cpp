#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int k = 0 ;
    int x = 1;
    while (x!=0){
        cin >> x;
        if (x%2 == 0){
            if (x > k){
                k = x;
            }
        }
    }
    if (k!=0){
        cout << (k);
    }
    return 0;
}