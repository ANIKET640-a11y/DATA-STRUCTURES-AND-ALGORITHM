#include<iostream>
using namespace std;

int countways(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    return countways(n-1) + countways(n-2);
}

int main(){
    int n;
    cout<<"Enter the size of the floor: ";
    cin>>n;

    cout<<"The number of ways to tile the floor is: "<<countways(n)<<endl;

    return 0;
}