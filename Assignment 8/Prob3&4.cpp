#include <bits/stdc++.h>
using namespace std;


void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        cout << "Insertion Sort - Step " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        cout << "Selection Sort - Step " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        // Print the current step
        cout << "Bubble Sort - Step " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    indef();
    int A[] = {10, 8, 2, 7, 3, 4, 9, 1, 6, 5};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    int insertionArr[n];
    int selectionArr[n];
    int bubbleArr[n];

    copy(A, A + n, insertionArr);
    copy(A, A + n, selectionArr);
    copy(A, A + n, bubbleArr);
    double start,end,timeTaken;
    start = clock();
    insertionSort(insertionArr, n);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "insertionSort Sort: " << timeTaken*1000 << " miliseconds" << endl << endl;
    
    start = clock();
    bubbleSort(bubbleArr, n);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Bubble Sort: " << timeTaken*1000 << " miliseconds" << endl << endl;

    start = clock();
    selectionSort(selectionArr, n);
    end = clock();
    timeTaken = double(end - start) / CLOCKS_PER_SEC;
    cout << "selectionSort Sort: " << timeTaken*1000 << " miliseconds" << endl << endl;

    

    return 0;
}
