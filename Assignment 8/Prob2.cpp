#include <iostream>
using namespace std;

void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        cout << "Checking element at index " << mid << ": " << arr[mid] << endl;

        if (arr[mid] == target) {
            return mid;  
        } else if (arr[mid] > target) {
            high = mid - 1;  
        } else {
            low = mid + 1;  
        }
    }

    return -1;  
}

int main() {
    indef();
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(A) / sizeof(A[0]);
    int x = 4;

    int index = binarySearch(A, n, x);

    if (index != -1) {
        cout << "Target value found at index " << index << endl;
    } else {
        cout << "Target value not found" << endl;
    }

    return 0;
}
