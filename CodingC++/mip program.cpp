#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i=1;
    
    int toprint=9;
    while(i<=n){
    int j=1;
    /*char space=1;
    while(space<=i-1){
    cout << " ";
    space=space+1;}*/
     
    
    
    while(j<=n){
    cout << toprint ;
    toprint=toprint-1;
    j=j+1;
    
    }
    
   /* while(j<=i){
    cout << "*" ;
    j=j+1;
    }*/
    
    cout << endl;
    i=i+1;
    
    }
    
    return 0;
}