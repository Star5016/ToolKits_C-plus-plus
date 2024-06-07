// This File Has Not Been Complished
// Use DirectSort As Default Mode
#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void DirectSort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        int temp = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > temp) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
        cout << "第" << i << "次排序结果：";
        display(arr, n);
        i++;
    }
}

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool flag = true;
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                flag = false;
            }
        }
        cout << "第" << i + 1 << "次排序结果：";
        display(arr, n);
        if (flag) {
            break;
        }
    }
}

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        cout << "第" << i + 1 << "次排序结果：";
        display(arr, n);
    }
}

void test() {
    int arr[] = {1, 9, 6, 8, 2, 7, 4, 3, 5, 0};
    DirectSort(arr, 10);
    /*
    BubbleSort(arr,10);
    SelectionSort(arr,10);
    */
    cout << "最终排序结果：";
    display(arr, 10);
}


int main() {
    test();
    return 0;
}