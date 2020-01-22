#include <iostream>

using namespace std;

/*
    Unijeti broj elemenata niza.  Unijeti niz. Ispisati niz po rastućem i po opadajućem redoslijedu.

*/

int main(){

int n;
cout<<"Enter array size: ";
cin>>n;

int arr[n];

cout<<"Enter elements: ";
for(int i=0;i<n;i++){
    cin>>arr[i];
}

int temp;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(arr[j]>arr[i]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
}
cout<<"\nSorted decreasing:\n";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}


cout<<"\nSorted ascending :\n";
for(int i=n-1;i>=0;i--){
    cout<<arr[i]<<" ";
}

return 0;
}
