#include <iostream>
#include <cmath>
using namespace std;
int pr(int x){
        int p = 1;
        for  ( int k = (x / 2 + 1); k > 1; k -=1 ){
            if (x % k == 0){
                p = 0;
                break;
                
            }
        }
        return p;
    }

int main(){
    int x;
    cin >> x;
    if (pr(x) == 1){
        cout << "YES";
    } else{
        cout << "NO";
    }  
    return 0;
}