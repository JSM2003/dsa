#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void InsertionSort(int* arr, int n){
    int min_idx;
    int temp;

    for(int i = 0; i < n-1; ++i){
        min_idx = i;
        for(int j = i; j < n; ++j){

            if(arr[j] < arr[min_idx])
                min_idx = j;
            
        }

        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main(){

    int n;
    cout << "Enter number of elements in the array: " << ends;
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: " << ends;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    auto before = high_resolution_clock::now();
    InsertionSort(arr, n);
    auto after = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(after - before);

    cout << "Sorted array: "<<ends;
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " " << ends;
    }


    cout << "\nArray sorted after " << duration.count() << " nanoseconds" << endl;
    return 0;
}