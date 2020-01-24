#include <iostream>

using namespace std;

/*
    Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

    For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

*/


bool check(int arr[], int k,int n){
int sum=0;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
            sum=arr[i]+arr[j];
            if(sum==k){
                return true;

            }else
            sum=0;
        }
    }

return false;
}

int main(){

int n,k;
cout<<"Enter array size: ";
cin>>n;
cout<<"Enter k:";
cin>>k;

int arr[n];

cout<<"Enter numbers: ";
for(int i=0;i<n;i++){
    cin>>arr[i];
}


if(check(arr,k,n)){
    cout<<"True.";
}else
cout<<"False.";

return 0;
}
