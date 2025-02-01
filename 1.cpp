#include <bits/stdc++.h>
using namespace std;



int main() {

    int t;
    cin >> t;

    while (t--) {

    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int c=0;
    for (int i = 0; i < n; i++)
    {
       if(a[i-1]=='x'&&a[i]=='.'&&a[i+1]=='x'&&b[i]=='.'&&b[i-1]=='.'&&b[i+1]=='.'){
        c++;
       }
       if(b[i-1]=='x'&&b[i]=='.'&&b[i+1]=='x'&&a[i]=='.'&&a[i-1]=='.'&&a[i+1]=='.'){
        c++;
       }
    }
    
   cout<<c<<endl;




    }

    return 0;
}
