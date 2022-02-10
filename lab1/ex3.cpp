#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n = 0;
    cin >> n;
    int m = 1;
    for (int i = 1; i <= n; i++){
        m *= i;
    }
    cout << m;
    return 0;
}