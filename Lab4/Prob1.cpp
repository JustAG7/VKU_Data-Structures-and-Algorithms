#include <bits/stdc++.h>
using namespace std;

void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int generateRandomNumber() {
    return rand() % 1000 + 1;
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}


void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void merge(int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int leftArr[leftSize], rightArr[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


int linearSearch(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int main() {
    indef();
    srand(time(0));
    int arr[100];

    for (int i = 0; i < 100; i++) {
        arr[i] = generateRandomNumber();
    }

    cout << "Original Array: ";
    printArray(arr, 100);

    bubbleSort(arr, 100);
    selectionSort(arr, 100);
    insertionSort(arr, 100);
    quickSort(arr, 0, 99);
    mergeSort(arr, 0, 99);

    cout << "Sorted Arrays:\n";
    cout << "Bubble Sort: ";
    printArray(arr, 100);
    cout << "Selection Sort: ";
    printArray(arr, 100);
    cout << "Insertion Sort: ";
    printArray(arr, 100);
    cout << "Quick Sort: ";
    printArray(arr, 100);
    cout << "Merge Sort: ";
    printArray(arr, 100);

    ofstream outputFile("SortingTime.txt");
    if (outputFile.is_open()) {
        clock_t start, end;
        double timeTaken;

        start = clock();
        bubbleSort(arr, 100);
        end = clock();
        timeTaken = double(end - start) / CLOCKS_PER_SEC;
        outputFile << "Bubble Sort: " << timeTaken*1000 << " miliseconds" << endl;

        start = clock();
        selectionSort(arr, 100);
        end = clock();
        timeTaken = double(end - start) / CLOCKS_PER_SEC;
        outputFile << "Selection Sort: " << timeTaken*1000 << " miliseconds" << endl;

        start = clock();
        insertionSort(arr, 100);
        end = clock();
        timeTaken = double(end - start) / CLOCKS_PER_SEC;
        outputFile << "Insertion Sort: " << timeTaken*1000<< " miliseconds" << endl;

        start = clock();
        quickSort(arr, 0, 99);
        end = clock();
        timeTaken = double(end - start) / CLOCKS_PER_SEC;
        outputFile << "Quick Sort: " << timeTaken*1000 << " miliseconds" << endl;

        start = clock();
        mergeSort(arr, 0, 99);
        end = clock();
        timeTaken = double(end - start) / CLOCKS_PER_SEC;
        outputFile << "Merge Sort: " << timeTaken*1000 << " miliseconds" << endl;

        outputFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }

    int x = 12;

    int linearSearchIndex = linearSearch(arr, 100, x);
    if (linearSearchIndex != -1) {
        cout << "Element " << x << " found at index " << linearSearchIndex << " (using linear search)." << endl;
    } else {
        cout << "Element " << x << " not found in the array (using linear search)." << endl;
    }

    sort(arr, arr + 100); 
    int binarySearchIndex = binarySearch(arr, 0, 99, x);
    if (binarySearchIndex != -1) {
        cout << "Element " << x << " found at index " << binarySearchIndex << " (using binary search)." << endl;
    } else {
        cout << "Element " << x << " not found in the array (using binary search)." << endl;
    }

    return 0;
}
