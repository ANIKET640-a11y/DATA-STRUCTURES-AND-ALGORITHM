#include<iostream>
using namespace std;

int search(int arr[], int st, int end, int tar){
    int mid = st + (end -st)/2;
    if(st>end){
        return -1;
    }

    if(arr[mid] == tar){
        return mid;

    }

    if(arr[st] <= arr[mid]){
        if(tar >= arr[st] && tar <= arr[mid]){
            return search(arr, st, mid-1, tar);
        }
        else{
            return search(arr, mid+1, end, tar);
        }
    }
    else{
        if(tar >= arr[mid] && tar <= arr[end]){
            return search(arr, mid+1, end, tar);
        }
        else{
            return search(arr, st, mid-1, tar);
        }
    }



}

int main(){
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int tar = 0;
    int ans = search(arr, 0, n-1, tar);
    cout<<ans;
    return 0;
}