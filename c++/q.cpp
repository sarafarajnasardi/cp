#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
struct q{
    int *arr;
    int size;
    int top;
    q(){
        size=10;
        arr=new int [size];
        top=-1;
    }
    void push(int data){
        if(top==size-1){
            cout<<"Queue is full"<<endl;
        }else{
            arr[++top]=data;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Queue is empty"<<endl;
        } else{
            cout<<arr[top--]<<" ";
        }
    }
    bool isempty(){
        return top==-1;
    }
    int getSize(){
        return top+1;
    }
    int peek(){
        return arr[top];
    }
    void display(){
        
    }
};
struct Queue {
    Node* front = nullptr;
    Node* rear = nullptr;

    void enqueue(int data) {
        Node* temp = new Node(data);
        if (rear == nullptr) {
            rear = temp;
            front = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) { // If the queue becomes empty, reset rear as well
            rear = nullptr;
        }
        delete temp;
    }

    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int peekFront() {  // Renamed to avoid conflict
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

struct Stack{
    Node* top;
    Stack(){
        top=nullptr;
    }
    void push(int data1){
        if(top==nullptr){
            Node* temp=new Node(data1);
            top=temp;
        }else{
            Node* temp=new Node(data1);
            temp->next=top;
            top=temp;
        }
    }
    void pop(){
        if(top==nullptr){
            cout<<"stack is empty"<<endl;
        }else{
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }
    int peek(){
        if(top==nullptr){
            return -1;
        }else{
            return top->data;
        }
    }
};
int main(){
//    Queue* q=new Queue();
//    q->enqueue(1);
//    q->enqueue(2);
//    q->dequeue();
//    q->enqueue(3);

//    q->display();
//    delete q;
//    return 0;

    Stack stack;
    stack.push(1);
    stack.push(2);
    cout<<stack.peek()<<endl; // 2
    stack.pop();
    cout<<stack.peek()<<endl; // 1
    return 0;
}
