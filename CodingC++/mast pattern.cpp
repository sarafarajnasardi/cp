#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i=1;
    
    while(i<=n){
    int j=1;
    /*char space=1;
    while(space<=i-1){
    cout << " ";
    space=space+1;}*/
     
    
    
    while(j<=i){
    char let='A'+n-i+j-1;
    cout << let<<" ";
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