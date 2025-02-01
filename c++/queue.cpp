#include <bits/stdc++.h>
using namespace std;
class Queue
{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    Queue(int size){
        this->size=size;
        arr= new int[size];
        front=0;
        rear=0;
    }
    void push(int data){
        if(rear==size){
            cout<<"queue is full"<<endl;
        }else{
            arr[rear]=data;
            rear++;
        }
    }
    void pop(){
        if(rear==front){
            cout<<"queue is empty"<<endl;
        }else{
            
            front++;
        }
    }

    bool isempty(){
        if(rear==front){
            return true;
        }

       return false;
    }

    int getfront(){
        if(rear==front){
            return -1;
        }

        return arr[front];
    }

    
    int getsize(){
        return (rear-front);
    }

};

int main(){
    //stl
    // queue<int>q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);

    // cout<<q.size()<<endl;
    // q.pop();
    // cout<<q.size()<<endl;
    // if(q.empty()){
    //     cout<<"YES"<<endl;
    // }else{
    //     cout<<"NO"<<endl;
    // }

    // cout<<q.front()<<endl;

    //implementation
    
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.getsize()<<endl;
    q.pop();
    cout<<q.getsize()<<endl;
    if(q.isempty()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    cout<<q.getfront()<<endl;


}