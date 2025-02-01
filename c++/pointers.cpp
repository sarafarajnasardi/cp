#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
void display(int* arr){
    for(int i=0;i<5;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}
int main(){
    // int a=10;
    // char b='m';
    // char* c=&b;
    // int* ptr=&a;//it stores an adress;
    // cout<<ptr<<endl;
    // cout<<*ptr<<endl;
    // cout<<sizeof(ptr)<<endl;
    
    // cout<<sizeof(c)<<endl;//size of pointer is always same
    
    // int arr[4]={1,28,36,49};
    // cout<<arr<<endl;
    // cout<<&arr<<endl;
    // cout<<&arr[0]<<endl;
    // cout<<*arr+1<<endl;
    // cout<<*(arr+2)<<endl;
    // int i=0;
    // cout<<arr[i]<<endl;
    // cout<<i[arr]<<endl;//it will run

    int arr1[]={1,231,11,14,51};
    cout<<arr1<<endl;
    cout<<&arr1<<endl;
    cout<<*(arr1)<<endl;
    *(arr1)=5;
    cout<<arr1<<endl;
    cout<<*(arr1)<<endl;
    display(arr1);




}