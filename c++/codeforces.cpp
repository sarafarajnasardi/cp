#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int t;
  cin>>t;
  while (t--)
  {
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i];
    }
   int m=-1;
    for (int i = n-1; i >=0; i--)
    {
      if (arr[i]!=arr[n-1])
      {
        m=i;
        break;
      }  
    }
  int x=-1;
    for (int i = 0; i <n; i++)
    {
      if (arr[i]!=arr[0])
      {
        x=i;
      }  
    }
  for (int i = 1; i <n-1; i++)
    {
      if (arr[i-1]==arr[i+1])
      {
        arr[i]=arr[i-1];
      }
      
    }
    bool check=true;
    for (int i = 0; i < n; i++)
    {
      if (arr[i]!=arr[0])
      {
        check=false;
        break;
      }
      
    }
    
  if (!check)
  {
   cout<<0<<endl;
  }else if (m==-1)
  {
    cout<<-1<<endl;
  }else{
    cout<<min(n-1-m,x)<<endl;
  }
 
 
 
  }
}