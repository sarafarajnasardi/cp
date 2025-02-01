/*bitwisw opertors
       AND(&),OR(|),NOT(~),XOR(IF DONO SAME HAI TOH 0 AUR DONO ALAG HAI TOH 1)

#include<iostream>
using namespace std;
int main(){
/*
    bool a=true;//a=1
    bool b=false;//b=1

    cout<<(a&b)<<endl;
    cout<<(a|b)<<endl;
    cout<<(a^b)<<endl;
    cout<<(~b)<<endl;
 cout<<(5|17)<<endl;
*/
/*
int a=4;
a=a>>1;//right shift by 1 bit
cout<<a<<endl;
a=a<<1;//left shift it doubles the original value
cout<<a<<endl;
*/
/*
int a=5;
cout<<a<<endl;
cout<<++a<<endl;//pehle increment hoga phir use hoga
cout<<a++<<endl;//pehle use karlo then increment karo...
cout<<(++a)*(++a);

*/
/*for (int i = 0; i < 5; i++)
{
    cout<<"hello"<<endl;
    continue;//iske nich ka print nhi karega
    cout<<"rolex"<<endl;
   // break;//loop ko break karega aur uske bahar ka print karega
    cout<<"dilli"<<endl;
    
}
cout<<"leo";

*/


//ek variable ko ek baar hi define kar skte hai in one bracket
/*int a=7;

if(7>5){
    int a=11;
    cout<<a<<endl;
}

cout<<a;
*/
/*cout<<"enter the operator"<<endl;
char c;
cin>>c;
cout<<"enter the first"<<endl;
int a;
cin>>a;
cout<<"enter the second number"<<endl;
int b;
cin>>b;

switch (c)
{
case '+':
     cout<<"the sum is"<<a+b<<endl;
     break;
case '-':
     cout<<"the subtraction is"<<a-b<<endl;
     break;
case '*':
     cout<<"the multiplication is"<<a*b<<endl;
     break;
case '/':
     cout<<"the division is"<<a/b<<endl;
     break;





}
*/





/*
#include <bits/stdc++.h>
using namespace std;
int a=0,b;


int main() {
	// your code goes here
    
	int c,d;
	cin>>c;
	int arr[d];
     
     for(int e=0;e<c;e++){
	    cin>>d;
	    for(int i=0;i<d;i++){
	    cin>>arr[i];
	    
	    }
         
	    for(int i=0;i<d;i++){
	    
	        if(arr[i]>a){
	            a=arr[i];
	            b=i;
	        	}
	    }
	
	   for(int i=0;i<d;i++){
	    cout<<d-b-1;
	   }
      
	    
	 
	}
	
	

}*/

#include <iostream>
#include <vector>

using namespace std;

int countCandiesReceived(int N, const vector<int>& A) {
   // vector<int> candiesReceived(N, 0);
   int max=0;
   int space;
   int count=0;

    for (int i = 0; i < N ; ++i) {
        
            if ( A[i]>max) {
               // candiesReceived[j]++;
               max=A[i];
               space=i;
            }
        
    }

    /*int result = 0;
    for (int candies : candiesReceived) {
        result += candies;
    }*/
    int l=N-space-1;

    return l;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        int result = countCandiesReceived(N, A);
        cout << result << endl;
    }

    return 0;
}

