#include <bits/stdc++.h>
using namespace std;
// class Stack
// {
//     public:
//     int *arr;
//     int top;
//     int size;

//     Stack(int size){
//         this->size=size;
//         arr=new int [size];
//         top=-1;
//     }

//     void push(int element){
//         if(size-top > 1){
//             top++;
//             arr[top]=element;
//         }else{
//             cout<<"Stack overflow"<<endl;
//         }
//     }

//     void pop(){
//         if(top >= 0){
//             top--;
//         }else{
//             cout<<"Stack underflow"<<endl;
//         }
//     }
//     int peek(){
//          if(top >= 0&& top<size){
//            return arr[top];
//         }else{
//             cout<<"Stack is empty"<<endl;
//         }
//     }
//     int getSize(){
//         return top+1;
//     }
//     bool isEmpty(){
//         if(top==-1){
//             return true;
//         }else
//         {
//             return false;
//         }
        
//     }

// };

class Stack
{
    public:
    int *arr;
    int top1;
    int size;
    int top2;

    Stack(int size){
        this->size=size;
        arr=new int [size];
        top1=-1;
        top2=size;
    }

    void push1(int element){
        if(top2-top1 > 1){
            top1++;
            arr[top1]=element;
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void push2(int element){
        if(top2-top1 >  1){
            top2--;
            arr[top2]=element;
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop1(){
        if(top1 >= 0){
            top1--;
        }else{
            cout<<"Stack underflow"<<endl;
        }
    }
    void pop2(){
        if(top2 < size){
            top2++;
        }else{
            cout<<"Stack underflow"<<endl;
        }
    }
    int peek1(){
         if(top1 >= 0&& top1<top2){
           return arr[top1];
        }else{
            cout<<"Stack is empty"<<endl;
        }
    }
    int peek2(){
         if(top2 < size && top1<top2){
           return arr[top2];
        }else{
            cout<<"Stack is empty"<<endl;
        }
    }
    int getSize1(){
        return top1+size-top2+1;
    }
    bool isEmpty1(){
        if(top1==-1){
            return true;
        }else
        {
            return false;
        }
        
    }
    bool isEmpty2(){
        if(top2==size){
            return true;
        }else
        {
            return false;
        }
        
    }

};

void insertattail(stack<int>& st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int ans=st.top();
    st.pop();
    insertattail(st,x);
    st.push(ans);
}
void reverse(stack<int>& st){
       if(st.empty()){
        return;
       }
            int x=st.top();
            st.pop();

            reverse(st);

            insertattail(st,x);
}

void insert(stack<int>& st,int x){
    if(st.empty()){
        st.push(x);
        return;
    }
    int ans=st.top();
    if(ans>=x){
        st.push(x);
        return;
    }
    st.pop();
    insert(st,x);
    st.push(ans);
}
void sort(stack<int>& st){
    if(st.empty()){
        return;
    }
    int x=st.top();
    st.pop();
    sort(st);

    insert(st,x);
}
int main() {   
    // stack<int>s;
    // s.push(2);
    // s.push(3);
    // s.pop();
    // cout<<"top element "<<s.top()<<endl;
    // s.pop();
    //cout<<s.size()<<endl;
    // if(s.empty()){
    //     cout<<"Stack is empty"<<endl;
    // }else{
    //     cout<<"Stack is not empty"<<endl;
    // }

    //Implementation of stack
    // Stack st(5);
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    
    // cout<<st.getSize()<<endl;
    // cout<<st.peek()<<endl;
    // st.pop();
    // cout<<st.peek()<<endl;
    // st.pop();
    // cout<<st.peek()<<endl;
    // st.pop();
    // cout<<st.peek()<<endl;
    // st.pop();
    // cout<<st.peek()<<endl;
    // cout<<st.getSize()<<endl;

    //Implementation of two stack in single array

    
    // Stack st(5);
    // st.push1(10);
    // st.push1(20);
    // st.push1(30);
    // st.push1(40);
    // st.push2(50);
    
    // cout<<st.getSize1()<<endl;
    // cout<<st.peek1()<<endl;
    // st.pop1();
    // cout<<st.peek1()<<endl;
    // st.pop1();
    // cout<<st.peek2()<<endl;
    // st.pop1();
    // cout<<st.peek1()<<endl;
    // cout<<st.peek1()<<endl;
    // cout<<st.getSize1()<<endl;

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(10000);
    st.push(40);
    st.push(50);
    sort(st);
    while (!st.empty())
    {
       cout<<st.top()<<endl;
       st.pop();
    }
    




}