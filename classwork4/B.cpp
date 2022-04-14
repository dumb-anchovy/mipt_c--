#include <iostream>

using namespace std;

int main()
{
    cout << "enter the size of the array";
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    //forward
    for (int i = 0; i < n; i++){
        cout << *(a+i) << " ";
    }
    cout << endl;
    //backward
    for (int i = n; i > 0; i--){
        cout << *(a+i-1) << " ";
    }

    delete [] a;
}
