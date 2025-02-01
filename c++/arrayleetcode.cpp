#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
#include<vector>
using namespace std;



/*
//Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

/*
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]


cout<<"enter the size of an array"<<endl;
int a;
cin>>a;

vector<int>arr(a);
for (int i = 0; i < arr.size(); i++)
{
    cin>>arr[i];
}

int start=0;
int end=arr.size()-1;
int i=0;
    while(i<=end){//thsi condition is important
    if (arr[i]==0)
    {
        swap(arr[i],arr[start]);
        start++;
        i++;
    }
    else if (arr[i]==2)
    {
        swap(arr[i],arr[end]);
        end--;
    }
    else 
    {
        i++;
    }
    

    }

for (int i = 0; i < arr.size(); i++)
{
    cout<<arr[i];
}
*/

/*
//move all -ve numbers to the one side
cout<<"enter the size of an array"<<endl;
int a;
cin>>a;
vector<int>arr(a);
cout<<"enter the values in array"<<endl;
for (int i = 0; i < arr.size(); i++)
{
       cin>>arr[i];
}

int strt=0;

int i=0;
while(i<arr.size()){

    if (arr[i]<0)
    {
        swap(arr[i],arr[strt]);
        i++;
        strt++;
    }
    else{
        i++;
    }


}


cout<<"printing the output array"<<endl;
for (int i = 0; i < arr.size(); i++)
{
       cout<<arr[i];
}
*/
/*
//find duplicate number


cout<<"enter the size of an array"<<endl;
int a;
cin>>a;
vector<int>arr(a);
cout<<"enter the values in array"<<endl;
for (int i = 0; i < arr.size(); i++)
{
       cin>>arr[i];
}
int num;
for (int strt = 0; strt< arr.size(); strt++)
{
    for (int end = arr.size()-1; end >strt; end--)
    {
       if (arr[strt]==arr[end])
       {
        num=arr[strt];
        cout<<num<<",";

       }
       
    }
    
}
*/

/*
//find missing element in an array from 1 to 5
cout<<"enter the size of an array"<<endl;
int a;
cin>>a;
vector<int>arr(a);
cout<<"enter the values in array"<<endl;
for (int i = 0; i < arr.size(); i++)
{
       cin>>arr[i];
}
int num;
for (int strt = 0; strt< arr.size(); strt++)
{
   
       for (int i = 1; i <5; i++)
       {
        if(i!=arr[strt]){
           num=i;
        }
       }
       
     
}


cout<<num;
*/

//FIRST REPEATING ELEMENT


/*
cout<<"enter the size of an array"<<endl;
int a;
cin>>a;
vector<int>arr(a);
cout<<"enter the values in array"<<endl;
for (int i = 0; i < arr.size(); i++)
{
       cin>>arr[i];
}
int num=0;
for (int strt = 0; strt< arr.size(); strt++)
{
   
       for (int end= strt+1; end<arr.size(); end++)
       {
        
        if (arr[strt]==arr[end])
        {
         num=arr[strt];
         
        }
  
       }
  
}
cout<<num;

*/
/*
//common elements in three sorted array
int arr[]={1,2,3,4,5};

int brr[]={3,4,5,6,7};
int crr[]={4,5,6,7,8};
int arrsize=5;int brrsize=5;int crrsize=5;

for (int i = 0; i < arrsize; i++)
{
  for (int j= 0; j < brrsize; j++)
  {
    for (int k = 0; k < crrsize; k++)
    {
        if (arr[i]==brr[j]&brr[j]==crr[k])
        {
            cout<<arr[i]<<",";
        }
        
    }
    
  }
  
}
*/

/*//WAVE PRINT A MATRIX
cout<<"enter the rows"<<endl;
int rows;
cin>>rows;

cout<<"enter the cols"<<endl;
int cols;
cin>>cols;

int arr[rows][cols];


for (int i = 0; i < rows; i++)
{
  for (int j = 0; j < cols; j++)
  {
    cin>>arr[i][j];
  }
  
}

for (int j = 0;  j< cols; j++)
{
    
    if(j%2==0){
        for (int i = 0; i < rows; i++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    else if(j%2!=0){
        for (int i = rows-1; i >=0; i--)
        {
            cout<<arr[i][j];
        }
         cout<<endl;
       
    }
}*/

/*
//SPIRAL PRINT A MATRIX

cout<<"enter the rows"<<endl;
int rows;
cin>>rows;

cout<<"enter the cols"<<endl;
int cols;
cin>>cols;

int arr[rows][cols];


for (int i = 0; i < rows; i++)
{
  for (int j = 0; j < cols; j++)
  {
    cin>>arr[i][j];
  }
  
}

for (int i = 0;  i< rows; i++)
{
    
   if(i==0){
    for (int j = 0; j < cols-1; j++)
    {
        cout<<arr[i][j];
    }
    
   }
 
   for (int j = 0; j < cols; j++)
    {   
        if (j==cols-1)
    {
        cout<<arr[i][j];
    }

    }

    if(i==rows-1){
    for (int j = cols-2; j >0; j--)
    {
        cout<<arr[i][j];
    }
    }

    for (int j = 0; j < cols; j++)
    {   
        if (j==0)
    {
        cout<<arr[rows-i-1][j];
    }

    }



}
*/


const char* crr[4]={"DATE","HOSPITALISED","RECOVERED","DECEASED"};
int arr[7][4]={{21,227,246,8},{22,266,319,7},{23,197,367,10},{24,185,315,9},{25,148,190,5},{26,157,218,7},{27,96,212,9}};

cout<<"ONE WEEK COVID 19 STATISTICS IN DELHI"<<endl;
for (int i = 0; i <4; i++)
{
    cout<<crr[i]<<" ";
}
cout<<endl;

for (int i = 0; i < 7; i++)
{
   for (int j = 0; j < 4; j++)
   {
    cout<<arr[i][j]<<"       ";
   }
   cout<<endl;
   
}
int sum=0;
for (int i = 1; i < 4; i++)
{
   for (int j = 0; j < 7; j++)
   {
    sum=sum+arr[i][j];
   }
   if (i==1)
   {
     cout<<"total hospilaised "<<sum<<" ";
    cout<<"avg hospilaised "<<sum/7<<" ";
   }
   cout<<endl;

    if (i==2)
   {
     cout<<"total recovered "<<sum<<" ";
    cout<<"avg recoverd "<<sum/7<<" ";
   }
   cout<<endl;
    if (i==3)
   {
     cout<<"total deceased "<<sum<<" ";
    cout<<"avg deceased "<<sum/7<<" ";
   }
   
   
}


/*

//extra candies
int a;
cout<<"enter the candies which is given to students:"<<endl;
cin>>a;
int arr[a];
for (int i = 0; i < a; i++)
{
    cin>>arr[i];
}
int b;
cout<<"enter the extra candies you have:"<<endl;
cin>>b;
bool x=false;
for (int i = 0; i < a; i++)
{

    for(int j=0;j<a;j++){
    if(j!=i)   { 
    if (b+arr[i]<arr[j])
    {
      x=false;
      break;
    }
    else{

        x=true;
    }
    }



    }

    if (x==true)
    {
        cout<<"true,";
    }
    else if(x==false){

        cout<<"false,";
    }
}

*/
/*
int a;
cout<<"enter the candies which is given to students:"<<endl;
cin>>a;
int nums1[a];
for (int i = 0; i < a; i++)
{
    cin>>nums1[i];
}
int b;
cout<<"enter the candies which is given to students:"<<endl;
cin>>b;
int nums2[b];
for (int i = 0; i < b; i++)
{
    cin>>nums2[i];
}

 int size=a+b;
        int merged[size];
        for(int i=0;i<a;i++){
            merged[i]=nums1[i];

        }

        for(int i=a;i<size;i++){
            merged[i]=nums2[i-a];
        }
        for (int i = 0; i < size; i++)
        {
            cout<<merged[i];
        }
        cout<<endl;
        int n = sizeof(merged) / sizeof(merged[0]);
 
        sort(merged, merged + n);
        for (int i = 0; i < size; i++)
        {
            cout<<merged[i];
        }
        
        cout<<endl;
            if(size%2==0){
               float x= (merged[size/2]+merged[(size-2)/2])/2;
                cout<<x;
               
             }
             else if(size%2!=0){
                double k= (merged[(size-1)/2]);
                cout<<k;
             }
*/
/*int  count=1;
       
        for(int i=3;i<n;i++){
            for( int j=2;j<i;){
                if(i%j==0){
                    count++;
                   break;
                }
                j++;
            }
        }
        int l=n-count-1;
        if(n==1||n==0||n==2){
            return 0;
        }
       
        else{
            return l;
        }
        */








int main() {
    int a;
    float m,p,q,s;
    cin>>a;
    int arr[5];
    for(int j=0;j<a;j++){
      for(int i=0;i<5;i++){
        cin>>arr[i];
      }
      if(arr[1]<arr[2]){
     m= static_cast<float>(arr[0])/arr[1];
     int n=arr[2]*arr[4];
     p= static_cast<float>(arr[0])/arr[2];
     s= static_cast<float>(arr[0])/n;
     int r=arr[0]%long(n);
     q= static_cast<float>(r)/arr[3];
     if(n>arr[0]){
         if(p>long(p)){
         cout<<long(p)+1;}
         else{
         cout<<long(p);}
     }
     else if(long(s)+long(q)>long(m)){
         if(m>long(m)){
         cout<<long(m)+1;}
         else{
         cout<<long(m);}
     }
     else{
        if(q>long(q)){
         cout<<long(s)+long(q)+1;}
         else{
         cout<<long(s)+long(q);}
     }
    
    }
    else{
        if(m>long(m)){
         cout<<long(m)+1;}
         else{
         cout<<long(m);}
        
    }
    
        
    }
    

}













