 #include <bits/stdc++.h>
 using namespace std;
 int main(){
   int a;
   cin>>a;
   
   while (a--)
   {
    
    int n,m,x;
    cin>>n>>m>>x;
    vector<int>arr(m);
    vector<char>brr(m);
    for (int i = 0; i < m; i++)
    {
     cin>>arr[i]>>brr[i];
    }
    vector<int>crr;
    crr.push_back(x);
    for (int i = 0; i < m; i++)
    {
      if (brr[i]='0')
      {
        int p=arr[i];
        if (p+x>10)
        {
          int k=10-x;
          int j=p-j;
          x=j;
        }else{
          x=x+p;
        }
        crr.pop_back();
        crr.push_back(x);
        
      }else if (brr[i]='1')
      {
       int p=arr[i];
        if ((x-p)<1)
        {
          int k=x-1;
          int j=p-j;
          x=11-j;
        }else{
          x=x-p;
        }
        crr.pop_back();
        crr.push_back(x);
      }else if (brr[i]='?')
      {
        if (p+x>10)
        {
          int k=10-x;
          int j=p-j;
          x=j;
        }else{
          x=x+p;
        }
        if ((x-p)<1)
        {
          int k=x-1;
          int j=p-j;
          x=11-j;
        }else{
          x=x-p;
        }

      }
      
      
      
    }
    
    

    
    
    
    
   
    
    
    
 
  
   
   }
   
 
} 