#include<iostream>
using namespace std;

#define MAXSIZE 100



int arr[MAXSIZE];
int listSize
=0;

bool isEmpty(){
    return listSize==0;
}

void insert(int data, int p){
    if(listSize>=MAXSIZE){
        cout<<"list is full"<<endl;
        return;
    }
    if(p<1 || p>listSize+1){
        cout<<"Invalid position"<<endl;
        return;
    }
    for(int i=listSize;i>=p;i--){
        arr[i]=arr[i-1];
    }
    arr[p-1]=data;
    listSize++;
}

void search(int data){
    for(int i=0;i<listSize;i++){
        if(arr[i]==data){
            cout<<"data is present at "<<i+1<<endl;
            return;
        }
    }
    cout<<"data not present";
}

void remove(int data){
    int p=-1;
    for(int i=0;i<listSize;i++){
        if(arr[i]==data){
            p=i;
            break;
        }
    }
    if(p==-1){
        cout<<"Element not found";
    }
    else{
        for(int i=p;i<listSize;i++){
            arr[i]=arr[i+1];
        }
        listSize--;
    }
}

void display(){
    if(isEmpty()){
        cout<<"array is empty"<<endl;
        return;
    }
    for(int i=0;i<listSize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printReverse(){
    if(isEmpty()){
        cout<<"array is empty"<<endl;
        return;
    }
    for(int i=listSize-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, queryType, data, p;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>queryType;
        switch(queryType){
            case 1:
                cin>>data>>p;
                insert(data,p);
                break;
            case 2:
                cin>>data;
                remove(data);
                break;
            case 3:
                cin>>data;
                search(data);
                break;
            case 4:
                display();
                break;
            case 5:
                printReverse();
                break;
        }
    }
}