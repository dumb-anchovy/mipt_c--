#include <iostream>
#include <cmath>
using namespace std;
int year(int x)
{
   if ((x % 4 == 0) && (x % 100 != 0)){
       return 1;
   } else{
       x = 0;
   }
   return x;
}
int main()
{
    int x;
    cin >> x;
    if (year(x) == 1){
        cout << "YES";
    } else{
        cout << "NO";
    }  
    return 0;
}