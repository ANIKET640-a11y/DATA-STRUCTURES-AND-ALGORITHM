#include<iostream>
using namespace std;


int partition(int arr[], int st, int end){
    int i = st - 1;
    int pivot = arr[end];
    for(int j = st; j < end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }       
}
i++;
swap(arr[i], arr[end]);
return i;
}

void quick(int arr[], int st, int end){
    if(st>=end){
        return;
    }

    int pividx = partition(arr, st, end);
    quick(arr, st, pividx-1);
    quick(arr, pividx+1, end);
    
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
