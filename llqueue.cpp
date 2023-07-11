#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class Queue{
    public:
    Node *head, *tail;
    Queue(){
        head=NULL;
        tail=NULL;
    }
    bool isEmpty();
    void add(int);
    int poll();
    void display();
};

bool Queue::isEmpty(){
    return head==NULL;
}

void Queue::add(int data){
    Node *newNode=new Node(data);
    if(head==NULL){
        head=tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}

int Queue::poll(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return 0;
    }
    else{
        int removed=head->data;;
        Node *temp=head;
        head=head->next;
        delete temp;
        return removed;
    }
}

void Queue::display(){
    if(isEmpty()){
        cout<<"Queue empty"<<endl;
    }
    else{
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void printQueueReverse(Node *ptr){
    if(ptr!=NULL){
        printQueueReverse(ptr->next);
        cout<<ptr->data<<" ";
    }
}

void printReverse(Queue q){
    if(q.isEmpty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    printQueueReverse(q.head);
    cout<<endl;
}

int main(){
    Queue s=Queue();
    int n, queryType, data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>queryType;
        switch (queryType)
        {
        case 1:
            cin>>data;
            s.add(data);
            break;
        case 2:
            if(!s.isEmpty()){
                cout<<"Polled Element:"<<s.poll()<<endl;
            }
            else{
                s.poll();
            }
            break;
        case 3:
            s.display();
            break;
        case 4:
            printReverse(s);
            break;
        }
    }
    return 0;
}