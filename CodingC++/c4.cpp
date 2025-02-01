#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i=2;
    int prime;
   
    while(i<n){
    prime=n%i;
    i=i+1;
    if(prime=0){cout<<"the number is not  prime"<<endl;}
    
    
    if(prime!=0){cout<<"the number is  prime"<<endl;}
    break;
    
    }
    
    return 0;
}