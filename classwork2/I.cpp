#include <iostream>
#include <cmath>
using namespace std;
int pr(int x){
        int p = 1;
        for  ( int k = (x / 2 + 1); k > 1; k -=1 ){
            if ((x % k == 0)&&(x!=2)){
                p = 0;
                break;
                
            }
        }
        return p;
    }

int main(){
    int x;
    cin >> x;
    for  ( int k = 2; k < x+1; k +=1 ){
        if ((x % k == 0)&&(pr(k)==1)){
                cout << k << " ";
            }
        }
    }