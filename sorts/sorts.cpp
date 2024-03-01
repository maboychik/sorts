#include <iostream>
#include <vector>

template<class Arr>
void fillArray(Arr arr[], int n) {
    std::cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

template <class Arr>
void showArray(Arr arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}

template<class Arr>
int partition(Arr arr[], int l, int r) {
    int pivot = arr[r];
    int i = (l - 1);

    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i+1], arr[r]);
    return (i+1);
}

template<class Arr>
int partition_r(Arr arr[], int l, int r)
{
    std::srand(std::time(NULL));
    int random = l +  rand() % (r - l);

    std::swap(arr[random], arr[r]);

    return partition(arr, l, r);
}

template<class Arr>
void QuickSort(Arr arr[], int l, int r) {
    if (l < r) {
        int i = partition_r(arr, l, r);
        QuickSort(arr, l, i - 1);
        QuickSort(arr, i + 1, r);
    }
}

template <class Arr>
void BubbleSort(Arr arr[], int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = i + 1; j < r; j++) {
            if (arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

template <class Arr>
void SelectionSort(Arr a[], int l, int r) {
    for (int i = l; i < r; i++) {
        int lowest = i;
        for (int j = i + 1; j < r; j++) {
            if (a[j] < a[lowest]) {
                lowest = j;
            }
        }
        std::swap(a[i], a[lowest]);
    }
}

int main() {
    std::cout << "Enter n: ";
    int n;
    std::cin >> n;
    int* tag = new int[n];

    
    fillArray(tag, n);
    QuickSort(tag, 0, n-1);
    //SelectionSort(tag, 0, n);
    //BubbleSort(tag, 0, n);
    showArray(tag, n);
}


