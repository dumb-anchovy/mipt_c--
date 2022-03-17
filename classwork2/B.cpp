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
            k+=1;
        }
        
    }
    cout << (k-1);
    return 0;
}