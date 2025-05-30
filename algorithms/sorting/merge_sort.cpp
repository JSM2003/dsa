#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

void Combine(int* arr,int beg, int mid, int end, int* sorted_array){
    int lp = beg;
    int rp = mid+1;

    int ap = beg;

    while((lp <= mid) && (rp <= end)){
        if(arr[rp] < arr[lp]){
            sorted_array[ap] = arr[rp];
            rp++;
        }

        else{
            sorted_array[ap] = arr[lp];
            lp++;
        }

        ap++;
    }

    while((lp <= mid)){
        sorted_array[ap] = arr[lp];
        lp++;
        ap++;
    }

    while((rp <= end)){
        sorted_array[ap] = arr[rp];
        rp++;
        ap++;
    }
    //cout << "Intermediate sorted array: " << ends;
    for(int i = beg; i <= end; ++i){
        arr[i] = sorted_array[i];
        //cout << sorted_array[i] << " " << ends;
    }
    //cout << "\n\n" << endl;
}

void MergeSort(int* arr,int beg, int end, int* sorted_array){
    //cout << "beg: " << beg << " end: " << end << ends;
    if(beg >= end)
        return;
    
    int mid = (beg + end) / 2;

    //cout << " mid: " << mid <<endl;

    MergeSort(arr, beg, mid, sorted_array);
    MergeSort(arr,mid+1,end, sorted_array);

    Combine(arr,beg, mid, end, sorted_array);

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
    int sorted_array[n];

    auto before = high_resolution_clock::now();
    MergeSort(arr,0, n-1, sorted_array);
    auto after = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(after - before);

    cout << "Sorted array: "<<ends;
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " " << ends;
    }


    cout << "\nArray sorted after " << duration.count() << " nanoseconds" << endl;
    return 0;
}