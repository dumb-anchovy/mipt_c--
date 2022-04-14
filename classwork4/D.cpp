#include <iostream>

using namespace std;

int partition (int *A, int low, int high) {
    int middle = (low + high)/2;
    int pivot = *(A + middle);
    int i = low;
    int j = high;
    while (true) {
        while (*(A + i) < pivot){
            i++;
        }
        while (*(A + j) > pivot){
            j--;
        }
        if (i >= j){
            return j;
        }
        int s = *(A + i);
        *(A + i) = *(A + j);
        *(A + j) = s;
        i++;
        j--;
    }
}

void quicksort(int *A, int low, int high){
    if ((low >= 0)&&(high >= 0)&&(low < high)){
        int p = partition(A, low, high);
        quicksort(A, low, p);
        quicksort(A, (p + 1), high);
    }
}

int main(){
    cout << "enter the size of the array";
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    quicksort(a, 0, n-1);
    for (int i = 0; i < n; i++){
        cout << *(a+i) << " ";
    }

    delete [] a;
    return 0;
}
