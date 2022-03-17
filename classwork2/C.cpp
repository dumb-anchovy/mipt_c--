#include <iostream>
#include <cmath>
using namespace std;
int pr(int x){
        int p = 0;
        while (x >= 1){
            if (x % 2 == 0){
                p = p + 1;
                x = x / 2;                
            }
            else{
                if  (x == 1){
                    break;
                }
                p = -1;
                break;
            }
        }
        return p;
    }
int main()
{
    int x;
    cin >> x;
    if (pow(2,(pr(x))) == x){
        cout << "YES";
    } else{
        cout << "NO";
    }  
    return 0;
    
}