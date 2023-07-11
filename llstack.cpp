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

class Stack{
    public:
    Node *head;
    Stack(){
        head=NULL;
    }
    bool isEmpty();
    void push(int);
    int pop();
    int peek();
};

bool Stack::isEmpty(){
    return head==NULL;
}

void Stack::push(int data){
    Node *newNode=new Node(data);
    newNode->next=head;
    head=newNode;
}

int Stack::pop(){
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

int Stack::peek(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return 0;
    }
    else{
        return head->data;
    }
}

void display(Stack s){
    if(s.isEmpty()){
        cout<<"Stack empty"<<endl;
    }
    else{
        Node *temp=s.head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

int main(){
    Stack s=Stack();
    int n, queryType, data;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>queryType;
        switch (queryType)
        {
        case 1:
            cin>>data;
            s.push(data);
            break;
        case 2:
            if(!s.isEmpty()){
                cout<<"Popped Element:"<<s.pop()<<endl;
            }
            else{
                s.pop();
            }
            break;
        case 3:
            if(!s.isEmpty()){
                cout<<"Top Element:"<<s.peek()<<endl;
            }
            else{
                s.peek();
            }
            break;
        case 4:
            display(s);
            break;
        }
    }
    return 0;
}