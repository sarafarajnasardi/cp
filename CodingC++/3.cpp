#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i=1;
    int fact=1;
    while(i<=n){
    fact=fact*i;
    i=i+1;
    }
    cout << "The factorial of " << n <<  " is:"  << fact<<endl;
    
    return 0;
}