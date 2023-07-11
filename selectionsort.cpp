#include<iostream>
using namespace std;

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int arr[], int n){
    int i, j, ind;
    for(i=0;i<n-1;i++){
        ind=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[ind]){
                ind=j;
            }
        }
        if(ind!=i){
            swap(arr[ind],arr[i]);
        }
        print(arr,n);
        cout<<endl;
    }
}

int main(){
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<endl;
    print(arr,n);
    selectionSort(arr,n);
}