#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
/*arraysss


int printarray(int b[],int size){
  for(int i=0;i<size;i++){
    cout<<b[i]<<" ";
  }
  cout<<endl;
}
int inc(int a[],int size){
  for(int i=0;i<size;i++){
  a[i]=a[i]+10; 
  
  }
printarray(a,size);
}


bool findarray(int x[],int size,int key){
  for(int i=0;i<size;i++){
    
      if(x[i]==key){
     return true;
         }
    
  }

return false;


}

int find(int arr[],int size){
  int count=1;
  for(int i=0;i<size;i++){
    
      if(arr[i]==0||arr[i]==1){
     count++;
         }
    
  }

return count;



}


int max(int arr[],int size){
  int maxnum=INT_MIN;
  
  for (int i = 0; i < size; i++)
  {
    
    if(arr[i]>maxnum){
        maxnum=arr[i];
    }


  }
  
return maxnum;




}


int min(int arr[],int size){
  int minnum=INT_MAX;
  
  for (int i = 0; i < size; i++)
  {
    
    if(arr[i]<minnum){
        minnum=arr[i];
    }


  }
  
return minnum;




}

int ext(int arr[],int size){
  
  
  for (int i = 0; i < size*0.5; i++)
  {
    cout<<arr[i]<<","<<arr[size-i]<<",";
  }
  




}
int main(){
//array declaration it creates 40 bytes in storage...
/*int m[10];
cout<<m<<endl;
//array initialisation....
int arr[]={4,7,8,9,0};
int x[10]={4,7,8,9,0};//

//int arr[4]={4,7,8,9,0};//nhi chlega...
char h[7]={'a','b','c'};

//index and access...
for(int i=0;i<5;i++){
cout<<arr[i]<<endl;

}*/
/*int arr[10];

//taking inputs 
cout<<"enter the input values of array"<<endl;
for(int i=0;i<10;i++){
  cin>>arr[i];

}

cout<<"printing output values of array"<<endl;
for(int i=0;i<10;i++){
cout<<arr[i]<<endl;

}

*/
/*int arr[10];
cout<<"enter the inputs"<<endl;
for(int i=0;i<10;i++){
  cin>>arr[i];

}

cout<<"printing the double outputs"<<endl;
for(int i=0;i<10;i++){
double c= 2*arr[i];
cout<<c<<endl;


}
*/
/*int n=9;
int i=0;
while(i<=n){

i=i+2;
if(i==n){
  cout<<"even";
  break;
}
}
if(i!=n){
  cout<<"odd";
}*/




/*8int arr[]={5,6};
int size=sizeof(arr);
cout<<size<<endl;
printarray(arr,size);
inc(arr,size);
*/


//linear search in array
/*int arr[]={1,3,5,6,7};
int size=5;
cout<<"enter the key to find "<<endl;
int key;
cin>>key;
bool ans=findarray( arr,size,key);
if(ans)//if findarray is true i
{
    cout<<"yes it is presemnt"<<endl;
    
  }
else{
  cout<<"not found"<<endl;
}*/
//measuring 0n and 1s in a array 
/*int arr[]={0,1,2,1,0,1};
int size=5;
int x=find(arr,size);
cout<<x;
*/
//finding maximum number
/*int arr[]={3,1,9,1,7,1};
int size=5;
int x=max(arr,size);
cout<<x;
*/
//finding minimum number 
/*int arr[]={3,1,9,1,7,1};
int size=5;
int x=min(arr,size);
cout<<x;

*/
//printing extreme positions
/*int arr[]={3,1,9,1,7,1};
int size=5;
ext(arr,size);

*/

//printing extreme positions

/*int arr[]={3,1,9,1,7,1};
int size=6;

int start=0;
int end=size-1;
int start=0;
int end=size-1;

*/

/*int arr[]={3,1,9,1,7,1};
int size=6;
int start=0;
int end=size-1;

while(start<=end){
  swap(arr[start],arr[end]);
  start++;
  end--;
}

for (int i = 0; i < size; i++)
{
  cout<<arr[i];
}

*/

/*int arr[]={0,2,3,1,3,54,5,2};
int size=8;
int count=0;

for (int i = 0; i < size; i++)
{

  if (arr[i]==0||arr[i]==1)
  {
    count++;
  }


  
}
*/




 /*int arr[]={0,2,3,1,3,54,5,2};
int size=8;
int maxnum=INT_MIN;
int n;

for (int i = 0; i < size; i++)
{

  if (arr[i]>maxnum)
  {
    maxnum=arr[i];
     n=i;
  }


  
}
cout<<maxnum<<" "<<n;
*/

 /*8int arr[]={0,2,3,1,3,54,5,2};

int size=8;
int start=0;
int end=size-1;

while(start<=end){//important condition
    
    swap(arr[start],arr[end]);
    start++;
    end--;
    
}

for(int i=0;i<size;i++){
    
    cout<<arr[i];
    
}




}
end of arrays

*/


//VECTORS
void transpose(int arr[][3],int cols,int rows,int trans[][3]){

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j<cols; i++)
    {
     trans[j][i]=arr[i][j];
    }
    
  }

}

void printarray(int arr[][3],int cols,int rows,int trans[][3]){
          
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j<cols; i++)
    {
     cout<<trans[i][j];
    }
    
  }



}

/*
int main(){

  
  //create vector
 /*vector<int>arr;//6 is size
cout<<arr.size()<<endl;//jitne elements total bhar skte hai
cout<<arr.capacity()<<endl;//jitne elements abhi aur bhar skte
//putting input in an array

arr.push_back(1);
arr.push_back(6);
//int size=arr.size();

for(int i=0;i<size;i++){

  cout<<arr[i]<<endl;

}*/

//to remove

//arr.pop_back();

/*
//taking inputs
cout<<"enter the numbers for an array";
int n;
cin>>n;
vector<int>x(n,5);//n times 5nwill be printed on screen
int size=x.size();
for (int i = 0; i < size; i++)
{
  cout<<x[i]<<",";
}


bool m=x.empty();//it shows vector x is empty or not
cout<<"the array is empty is"<<m;
*/

//taking inputs in an array
/*int n;
cout<<"enter the size of an array"<<endl;
cin>>n;

vector<int>arr(n);
for (int i = 0; i < arr.size(); i++)
{
  cin>>arr[i];
}
for (int i = 0; i < arr.size(); i++)
{
  cout<<arr[i];
}

*/
/*
//PROBLEM SOLVING
//FIND UNIQUE ELEMENT WHICH IS NOT REPEATING TWICE
int n;
cout<<"enter the size of an array"<<endl;
cin>>n;

vector<int>arr(n);
for (int i = 0; i < arr.size(); i++)
{
  cin>>arr[i];
}
//ye logic samhjh le bruh...
int x=0;
for (int i = 0; i<arr.size(); i++)
{
   x=x^ arr[i];// xor of same elments is always 0 and xor of zero and number is always tha t number


}


cout<<"the unique number is "<<x;

*/

/*
//UNION OF TWO ARRAYS


int a;
cout<<"enter the size of an array"<<endl;
cin>>a;

vector<int>arr(a);
for (int i = 0; i < arr.size(); i++)
{
  cin>>arr[i];
}


int b;
cout<<"enter the size of an array"<<endl;
cin>>b;

vector<int>brr(b);
for (int i = 0; i < brr.size(); i++)
{
  cin>>brr[i];
}

vector<int>mer;
for(int i=0;i<arr.size();i++){
  mer.push_back(arr[i]);
  
}
int j=0;
for(int i=0;i<arr.size();i++){
  for(int j=0;j<brr.size();j++){
      if(arr[i]==brr[j]){
        brr[j]=INT_MIN ;//iska logic ye hai ki yeh jo brr ka element hai dobara kisi same element ke saath match na ho....
        
       }
  
}
  
}

for(int i=0;i<brr.size();i++){
  if (brr[j]!=INT_MIN)
  
  {
       mer.push_back(brr[i]);
  }
  

  
}

for (int i = 0; i < mer.size(); i++)
{
  cout<<mer[i];
}
*/

//INTERSECTION OF TWO ARRAYS
/*

int a;
cout<<"enter the size of an array"<<endl;
cin>>a;

vector<int>arr(a);
for (int i = 0; i < arr.size(); i++)
{
  cin>>arr[i];
}


int b;
cout<<"enter the size of an array"<<endl;
cin>>b;

vector<int>brr(b);
for (int i = 0; i < brr.size(); i++)
{
  cin>>brr[i];
}

vector<int>mer;
for(int i=0;i<arr.size();i++){
  for(int j=0;j<brr.size();j++){
      if(arr[i]==brr[j]){
        brr[j]=-1 ;//iska logic ye hai ki yeh jo brr ka element hai dobara kisi same element ke saath match na ho....
        mer.push_back(arr[i]);
       }
  
}
  
}


for (int i = 0; i < mer.size(); i++)
{
  cout<<mer[i]<<" ";
}





*/

/*
//pair of two elememts whose sum is 9;

vector<int>arr{1,3,5,7,2,4,6};

for (int i = 0; i < arr.size()*0.5; i++)
{
  for (int j= i+1;j< arr.size(); j++)//j=i+1 isiliye kiya kyuki uske piche wala number repeat na ho
  {
    if(arr[i]+arr[j]==9){


      cout<<"the pair is "<<arr[i]<<" "<<arr[j]<<endl;

    }

  }
  
}



*/




/*TRIPLET
vector<int>arr{1,3,5,7,2,4,6};

for (int i = 0; i < arr.size(); i++)
{
  for (int j= i+1;j< arr.size(); j++)//j=i+1 isiliye put kara kyuki triplet repeat nhi honge
  {
    for(int k=j+1;k<arr.size();k++)
    {
    if(arr[i]+arr[j]+arr[k]==9){

cout<<"the triplet       is "<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;

    }

  }
  
}
}

*/
/*
//swaping of o's and 1's

vector<int>arr{0,1,1,1,0,0,1,0,0,0,1};
int zero=0;
  int one=0;
for (int i = 0; i < arr.size(); i++)
{
  
  if(arr[i]==0){
    zero++;
  }
 if(arr[i]==1){
    one++;
  }
}
vector<int>brr;
for (int i = 0; i <zero; i++)
{
  brr.push_back(0);
}
for (int i = 0; i <one; i++)
{
  brr.push_back(1);
}
for (int i = 0; i <brr.size(); i++)
{
  cout<<brr[i];
}

*/

/*
//2nd method
//THODA CONFUSED HU MAI
vector<int>arr{0,1,1,1,0,0,1,0,0,0,1};
int strt=0;
  int end=arr.size()-1;
  int i=0;
while( strt<=end)
{
  
  if(arr[i]==0){
    swap(arr[i],arr[strt]);
   i++;//humne i++yha use kiya kyuki second wale if me hume i+1 chahiye//ye lecture se samjh lo jaldi samjh ayega last part of array lecture e2
    strt++;
  }
  if(arr[i]==1){
  swap(arr[i],arr[end]);
    
    end--;
  }

  
}
//for (int i = 0; i <arr.size(); i++)
{
  cout<<arr[i];
}
//iski jagah yeh use kar skte hai
for (auto i:arr)
{
  cout<<i;
}


*/

/*
//write a program to delete an element from given location in an array
int n;
cout<<"enter the size"<<endl;
cin>>n;
vector<int>arr(n);
cout<<"enter the elements"<<endl;
for(int i=0;i<arr.size();i++){
 cin>>arr[i];

}
cout<<"enter the position from which you have to remove an element"<<endl;
int a;
cin>>a;

swap(arr[a],arr[n-1]);
for(int i=0;i<arr.size()-1;i++){
 cout<<arr[i];

}
*/


//2D ARRAYS
/*int arr[3][3]={{1,2,3},{4,2,3},{1,2,4}};
for (int i = 0; i < 3; i++)
{
  for (int j = 0; j< 3; j++)
  {
    cout<<arr[i][j];
  }
  cout<<endl;

}



cout<<arr[1][0];*/
/*
//taking input in an 2D array
int rows;
cout<<"enter the rows of the array"<<endl;
cin>>rows;
int cols;
cout<<"enter the coloumns of the array"<<endl;
cin>>cols;
int arr[rows][cols];//its important to define an 2D array
for (int i= 0; i< rows; i++)
{
  
  for (int j = 0; j<cols; j++)
  {
    cin>>arr[i][j];
  }
  
}
for (int i = 0; i < rows; i++)
{
  
  for (int j= 0; j<cols; j++)
  {
    cout<<arr[i][j];
  }
  cout<<endl;
  
}


*/

/*

//print row sum

int rows;
cout<<"enter the rows of the array"<<endl;
cin>>rows;
int cols;
cout<<"enter the coloumns of the array"<<endl;
cin>>cols;
int arr[rows][cols];//its important to define an 2D array

for (int i= 0; i< rows; i++)
{
  
  for (int j = 0; j<cols; j++)
  {
    cin>>arr[i][j];
  }
  
}
int sum=0;
for (int i = 0; i < rows; i++)
{
  
  for (int j= 0; j < cols; j++)
{
  sum=sum+arr[i][j];

}
cout<<"the sum is"<<sum;
sum=0;
cout<<endl;


}


*/

/*
//linear searching

int rows;
cout<<"enter the rows of the array"<<endl;
cin>>rows;
int cols;
cout<<"enter the coloumns of the array"<<endl;
cin>>cols;
int arr[rows][cols];//its important to define an 2D array

for (int i= 0; i< rows; i++)
{
  
  for (int j = 0; j<cols; j++)
  {
    cin>>arr[i][j];
  }
  
}

int m;
cout<<"enter which number you want to check which is present or not in array"<<endl;
cin>>m;
int num;
for (int i= 0; i< rows; i++)
{
  
  for (int j = 0; j<cols; j++)
  {
    if(arr[i][j]==m){
      num=1;
    }
    else{
      num=0;
    }

  }
  
}

if(num==1){
      cout<<"that number is present in the array"<<endl;
    }
  
else if(num==0){
  cout<<"that number is not present in the array"<<endl;
}

*/
/*
//max and minn num in an 2d array

int arr[3][3]={{1,2,3},{2,3,4},{3,6,8}};
int maxnum=INT_MIN;
int minnum=INT_MAX;
for (int i = 0; i < 3; i++)
{
  for (int j= 0; j < 3; j++)
  {
    if(arr[i][j]>maxnum){
        maxnum=arr[i][j];
    }
    if(arr[i][j]<minnum){
        minnum=arr[i][j];
    }
  
  }
  cout<<endl;
  
}


cout<<"maximu num is "<<maxnum<<endl;
cout<<"min num is "<<minnum<<endl;





}*/

/*
void transpose(int arr[][3],int cols,int rows,int trans[][3]){

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j<cols; i++)
    {
     trans[j][i]=arr[i][j];
    }
    
  }

}

void printarray(int cols,int rows,int trans[][3]){
          
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j<cols; i++)
    {
     cout<<trans[i][j];
    }
    
  }



}
int main(){

/*loguic samjh aya par code run nhi ho rha
//transpose the matrix mtlb rows ko coloumns kardo


int rows=3;
int cols=3;
int arr[rows][cols];
cout<<"enter the elements"<<endl;
for (int i = 0; i < rows; i++)
{
  for (int j = 0; j<cols; j++)
  {
    cin>>arr[i][j];
  }
  
}

int trans[rows][cols];
transpose(arr,rows,cols,trans);//2nd dimension me bound dena padega
printarray(rows,cols,trans);

}
*/
//VECTOR IN 2D ARRAYS
/*
int main(){

int rows=5;
int cols=5;

vector<vector<int> >arr(rows,vector<int>(cols,-8));

for (int i = 0; i < arr.size(); i++)
{
  for (int j = 0; j < arr[i].size(); j++)
  {
    cout<<arr[i][j]<<" ";
  }
  cout<<endl;
  
}

*/





















