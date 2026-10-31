#include <iostream>
using namespace std;

struct Node1{
    Node1* next;
    int data;
};

struct Node2{
    Node2* next;
    Node2* last;
    int data;
};

class Queue{
private:
    Node1* Front;
    Node1* Rear;
public:
    Queue(){
        Front=Rear=nullptr;
    }
    bool isEmpty(){
        return Front==nullptr;
    }
    void Enqueue(int data){
        Node1* temp=new Node1;
        temp->data=data;
        temp->next=nullptr;
        if(!isEmpty()){
            Rear->next=temp;
        }else{
            Front=temp;
        }
        Rear=temp;
    }
    void Dequeue(){
        if(!isEmpty()){
            if(Front->next!=nullptr){
                Node1* temp=Front;
                Front=Front->next;
                delete temp;
            }else{
                delete Front;
                Front=Rear=nullptr;
            }
        }else{
            cout<<"Underflow"<<endl;
        }
    }
    void Peek(){
        if(!isEmpty()){
            cout<<Front->data<<endl;
        }else{
            cout<<"Underflow"<<endl;
        }
    }
    void Display(){
        if(!isEmpty()){
            Node1* temp=Front;
            while(temp!=nullptr){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }else{
            cout<<"Underflow"<<endl;
        }
    }
};

class Stack{
private:
    Node1* Top;
    Node1* Back;
public:
    Stack(){
        Top=Back=nullptr;
    }
    bool isEmpty(){
        return Top==nullptr;
    }
    void Push(int data){
        Node1* temp=new Node1;
        temp->data=data;
        if(!isEmpty()){
            temp->next=Back;
        }else{
            temp->next=nullptr;
            Top=temp;
        }
        Back=temp;
    }
    void Pop(){
        if(!isEmpty()){
            if(Back->next!=nullptr){
                Node1* temp=Back;
                Back=Back->next;
                delete temp;
            }else{
                delete Top;
                Top=Back=nullptr;
            }
        }else{
            cout<<"Underflow"<<endl;
        }
    }
    void Front(){
        if(!isEmpty()){
            cout<<Top->data<<endl;
        }else{
            cout<<"Underflow"<<endl;
        }
    }
    void Rear(){
        if(!isEmpty()){
            cout<<Back->data<<endl;
        }else{
            cout<<"Underflow"<<endl;
        }
    }
};

class SinglyLinkedList{
private:
    Node1* Front;
    Node1* Rear;
public:
    SinglyLinkedList(){
        Front=Rear=nullptr;
    }
    bool isEmpty(){
        return Front==nullptr;
    }
    void InsertAtBeggining(int data){
        Node1* temp=new Node1;
        temp->data=data;
        temp->next=Front;
        if(isEmpty()){
            Rear=temp;
        }
        Front=temp;
    }
    void InsertAtEnd(int data){
        Node1* temp=new Node1;
        temp->data=data;
        temp->next=nullptr;
        if(isEmpty()){
            Front=temp;
            Rear=temp;
            return;
        }
        Rear->next=temp;
        Rear=temp;
    }
    void InsertAtPosition(int data,int position){
//InsertAtPosition
    }
    void DeleteAtBeginning(){
        if(!isEmpty()){
            Node1* temp=Front;
            if(Front==Rear){
                Rear=nullptr;
            }
            Front=Front->next;
            delete temp;
        }else{
            cout<<"Underflow"<<endl;
        }
    }
    void DeleteAtEnd(){
        if(!isEmpty()){
            Node1* temp1=Rear;
            if(Front==Rear){
                Front=Rear=nullptr;
            }else{
                Node1* temp2=Front;
                while(temp2->next!=Rear){
                    temp2=temp2->next;
                }
                Rear=temp2;
                Rear->next=nullptr;
            }
            delete temp1;
        }else{
            cout<<"Underflow"<<endl;
        }
    }
    void DeleteAtPosition(int position){
//DeleteAtPosition
    }
    void Traverse(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return;
        }
        Node1* temp=Front;
        while(temp!=nullptr){
            cout<<temp->data<<"-->";
            temp=temp->next;
        }
        cout<<endl;
    }
};

class DoubleLinkedList{
private:
    Node2* Front;
    Node2* Rear;
public:
    DoubleLinkedList(){
        Front=Rear=nullptr;
    }
    bool isEmpty(){
        return Front==nullptr;
    }
    void InsertAtBeggining(int data){
        Node2* temp=new Node2;
        temp->data=data;
        temp->next=Front;
        temp->last=nullptr;
        if(isEmpty()){
            Rear=temp;
        }
        Front=temp;
    }
    void InsertAtEnd(int data){
        Node2* temp=new Node2;
        temp->data=data;
        temp->next=nullptr;
        temp->last=Rear;
        if(isEmpty()){
            Front=temp;
        }
        Rear=temp;
    }
    void InsertAtPosition(int data,int position){
        if(position<0){
            cout<<"No negative position is allow"<<endl;
            return;
        }
        Node2* temp1=new Node2;
        temp1->data=data;
        if(isEmpty()){
            temp1->next=nullptr;
            temp1->last=nullptr;
            Front=Rear=temp1;
            return;
        }
        if(position==0){
            temp1->next=Front;
            temp1->last=nullptr;
            Front=temp1;
            return;
        }
        Node2* temp2=Front;
        while(position>1){
            if(temp2==Rear){
                temp2->next=temp1;
                temp1->next=nullptr;
                temp1->last=temp2;
                Rear=temp1;
                return;
            }
            temp2=temp2->next;
            position--;
        }
        temp1->next=temp2->next;
        temp1->last=temp2;
        temp2->next->last=temp1;
        temp2->next=temp1;
    }
//DeleteAtBeggining
//DeleteAtEnd
//DeleteAtPosition
    void FordwardTraverse(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return;
        }
        Node2* temp=Front;
        while(temp!=Rear){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    void BackwardTraverse(){
        if(isEmpty()){
            cout<<"Underflow"<<endl;
            return;
        }
        Node2* temp=Rear;
        while(temp!=Front){
            cout<<temp->data<<"-->";
            temp=temp->last;
        }
        cout<<endl;
    }
};

class CircularLinkedList{
private:
    Node1* Front;
    Node1* Rear;
public:
    CircularLinkedList(){
        Front=Rear=nullptr;
    }
    bool isEmpty(){
        return Front==nullptr;
    }
//InsertAtBeggining
//InsertAtEnd
//InsertAtPosition
//DeleteAtBeggining
//DeleteAtEnd
//DeleteAtPosition
//CircularTraverse
};

//Interface

int main(){
    return 0;
}
