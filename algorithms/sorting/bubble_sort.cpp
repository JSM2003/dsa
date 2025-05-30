#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void BubbleSort(int* arr, int n){
    int temp;

    for(int i = 0; i < n-1; ++i){
        for(int j = 0; j < n-i-1; ++j){

            if(arr[j+1] < arr[j]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }        
        }
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
    BubbleSort(arr, n);
    auto after = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(after - before);

    cout << "Sorted array: "<<ends;
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " " << ends;
    }


    cout << "\nArray sorted after " << duration.count() << " nanoseconds" << endl;
    return 0;
}