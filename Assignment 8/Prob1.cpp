#include <bits/stdc++.h>
using namespace std;

void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        cout << "Checking element at index " << i << ": " << arr[i] << endl;
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1; 
}

int main() {
    indef();
    int A[] = {10, 8, 2, 7, 3, 4, 9, 1, 6, 5};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 4;

    int index = linearSearch(A, n, x);

    if (index != -1) {
        cout << "Target value found at index " << index << endl;
    } else {
        cout << "Target value not found" << endl;
    }

    return 0;
}
