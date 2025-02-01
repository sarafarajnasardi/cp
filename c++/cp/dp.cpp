#include <bits/stdc++.h>
#include<iostream>
#include<limits.h>
#include<vector>
using  namespace std;
int fibmemo(int n,vector<int>dp){
    if (n<=1)
    {
       return n;
    }
    if (dp[n]!=-1)
    {
       return dp[n];
    }
    
    return dp[n]=fibmemo(n-1,dp)+fibmemo(n-2,dp);
    
}
int steps(int n){
    if(n==0||n==1){
        return 1;
        }
    
    return steps(n-1)+steps(n-2);
}
int frogs(vector<int>&arr,int n){
    if (n==0)
    {
       return 0;
    }
    
    int backone=frogs(arr,n-1)+abs(arr[n-1]-arr[n]);
    int backtwo=INT_MAX;
    if (n>1)
    {
         backtwo=frogs(arr,n-2)+abs(arr[n-2]-arr[n]);
    }
    
   
    return min(backone,backtwo);
    
}

int kfrogs(vector<int>&arr,int n){
    if (n==0)
    {
       return 0;
    }
    
    int i=1;
    int minsteps=INT_MAX;
    while (k--)
    {
        
       if (n>i-1)
        {
            int jump=frogs(arr,n-i)+abs(arr[n-i]-arr[n]);
            minsteps=min(minsteps,jump);
        }
        
    }
    
    
   
    return minsteps;
    
}

int main(){
    //fibonacci
    //0 1 1 2 3 5 8 13 21 ...
    //f(n)=f(n-1)+f(n-2)
    //by memorization method:tend to store the value of sub problems in some map/table
    // int n;
    // cin>>n;
   
//    vector<int>dp(n+1,-1);
//    cout<<fibmemo(n,dp); 

   //tabulation format:bottom to up means base case to required number
//    int prev2=0;
//    int prev=1;
//    for (int i = 2; i <=n; i++)
//    {
//     int curi=prev+prev2;
//     prev2=prev;
//     prev=curi;
//    }
//    cout<<prev;
   
   
       //count number of distinct ways to reach nth step from 0th step;
    //how to understand dp problems:1>count the number of ways
                                   //2>maximum ways or minimum ways   
     //try to represen a problem in the term of index
     //do all possible stuffs on that index
     //sum up all stuffs->count all ways
     //min of all stuffs->minimum ways
//     int n;
//     cin>>n;
//     cout<<steps(n);
//        int prev2=1;
//    int prev=1;
//    for (int i = 2; i <=n; i++)
//    {
//     int curi=prev+prev2;
//     prev2=prev;
//     prev=curi;
//    }
//    cout<<prev;

    //frog jump
    //frog jumps from 1 index to another find minimum energy to reach n-1 inex from 0 frog is allowed to jump +1 or +2
    
    // int n;
    // cin>>n;
    // vector<int>arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>arr[i];
    // }
    //first recurssion
   //frogs(arr,n);
    //we can done it by memo also as shown in fiboanccii
    //tabular method;
    
    // int x=0;
    // int y=0;
    // for (int i = 1; i <n; i++)
    // {
    //    int backone=x+abs(arr[i]-arr[i-1]);
    //    int backtwo=INT_MAX;
    //    if (i>1)
    //    {
    //       backtwo=y+abs(arr[i]-arr[i-2]);
    //    }
    //    int l=min(backone,backtwo);
    //    y=x;
    //    x=l;
      
    // }
    // cout<<x<<endl;

    //frog jumps with k index ahead...
     int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<kfrogs(arr,n);
    //tabulation
    
    int x=0
    for (int i = 0; i <n; i++)
    {
   
    int i=1;
    
    while (i<=k)
    {
       if (n>i-1)
        {
            int jumps=x+abs(arr[n-i]-arr[n]);
            x=min(x,jump);
        }
        i++;
    }
    }
    cout<<x<<endl;

    
}