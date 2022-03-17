#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int s = 0; 
    int k = 0;
    int x = 1;
    while (x!=0){
        cin >> x;
        if (x > k){
            k = x;
            s = 1;
        } else if (x == k){
            s += 1;
        }
        
    }
    cout << (s);
    return 0;
}