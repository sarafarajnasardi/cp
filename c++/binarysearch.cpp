#include<iostream>
#include<algorithm>//to use binary function
#include<vector>
using namespace std;
/*int binarysearch(int arr[],int size,int target){
    int strt=0;
    int end=size-1;
    int mid=(strt+end)/2;
    while (strt<=end)
    {
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else {
            strt=mid+1;
        }
        mid=(strt+end)/2;
       
    }
    return -1;
    
}


int main(){
    cout<<"hello"<<endl;

int arr[]={2,4,5,7,8,9,13};
int size=7;
int target=5;

int x=binarysearch(arr,size,target);
if(x==-1){
    cout<<"TARGET NOT FOUND"<<endl;
}

else{
    cout<<"TARGET FOUND AT "<<x<<endl;
}
 
}*/




//binary search is optimised searching algorithm is faster than linear search and have to include library of algorithm
int missingelement(vector<int>v,int size){
    int strt=0;
    int end=size-1;
    int mid=strt+(end-strt)/2;
    while (strt<=end)
    {
       if(v[mid]==mid+1){
        strt=mid+1;
       }
       else if(v[mid]!=mid+1){
        return mid+1;
       }
       mid=strt+(end-strt)/2;
        
    }
    return -1;
    
}

float squareroot(vector<int>v,int size){
    int strt=0;
    int end=size-1;
    int mid=strt+(end-strt)/2;
    float ans;
    while (strt<=end)
    {
       if(v[mid]*v[mid]==size){
        return v[mid];
       }
       else if(v[mid]*v[mid]>size){
        end=mid-1;
       }
       else{
        ans=v[mid];//ans stored
        strt=mid+1;
       }
       mid=strt+(end-strt)/2;
        
    }
     float l;

    for (int i = 0; i < 10; i++)
    {
        ans=ans+0.1;
        if (ans*ans>size)
        {
            l=ans-0.1;
            break;
        }
        
    }
    float m;
    for (int i = 0; i < 10; i++)
    {
        l=l+0.01;
        if (l*l>size)
        {
            m=l-0.01;
            break;
            
        }
        
    }
    return m;




}

/*int pivot(vector<int>v,int size){
    int strt=0;
    int end=size-1;
    int mid=strt+(end-strt)/2;
    while (strt<=end)
    {
       if(v[mid]*v[mid]==size){
        return v[mid];
       }
       else if(v[mid]*v[mid]>size){
        end=mid-1;
       }
       else{
        ans=v[mid];//ans stored
        strt=mid+1;
       }
       mid=strt+(end-strt)/2;
        
    }
    
    

}*/

int binarysearch2d(vector<vector<int> >v,int target){
    int strt=0;
    int end=9-1;
    int mid=strt+(end-strt)/2;
    
    while (strt<=end)
    {
     int row=mid/3;//row of mid element=mid/col
    int col=mid%3;//col of mid element=mid%row
    int x;
       if(v[row][col]==target){
        x=row*10+col;
        return x;
       }
       else if(v[row][col]>target){
        end=mid-1;
       }
       else{
        
        strt=mid+1;
       }
       mid=strt+(end-strt)/2;
        
    }
    return -1;
    
    

}

int binarysearch(int arr[],int size,int target){
    int strt=0;
    int end=size-1;
    int mid=(strt+end)/2;
    while (strt<=end)
    {
       if(arr[mid]==target){
             return mid;
             
        }
        if(arr[mid+1]==target){
             return mid+1;
             
        }
        if(arr[mid-1]==target){
             return mid-1;
             
        }
         else if(arr[mid]>target){
            end=mid-2;
        }
        
        else {
            strt=mid+2;
        }
        mid=(strt+end)/2;
    }
    return -1;
    
}

void division(vector<int>v,int size,int devi){
    int strt=0;
    int end=size-1;
    int mid=strt+(end-strt)/2;
    int ans;
    while(strt<=end){
        if ((mid+1)*devi==size)
        {
           ans=mid+1;
          
           
        }
        else if ((mid+1)*devi>size)
        {
          end=mid-1;
        }
        else
        {
          ans=mid+1;
          strt=mid+1; 
        }
         mid=strt+(end-strt)/2;
        
        
    }

    cout<<"the quoteint is "<<ans<<endl;
    cout<<"the remainder is "<<size-ans*devi;
    

}

int oddelement(int arr[],int size){
    int strt=0;
    int end=size-1;
    int mid=strt+(end-strt)/2;
    int ans;
    while(strt<end){
        if (strt==end)
        {
            return strt; 
        }
        


        if (mid%2==0)
        {
            if(arr[mid]==arr[mid+1]){
            strt=mid+2;
            }
            else
            {
                
                end=mid;
            }
            
            
        }
        else
        {
            if(arr[mid]==arr[mid-1]){
            strt=mid+1;
        }
        else{
            end=mid-1;
        }
            
        }
        mid=strt+(end-strt)/2;

    }
}

int binarysearchinsorted(int arr[],int target,int size){
    int s=0;
    int e=size-1;
    
    int count;
    while(s<=e){
        int mid=s+(e-s)/2;
        if (mid+1<=e && arr[mid]>arr[mid+1])
        {
           count=mid;
        }
        else if (s<=mid-1 && arr[mid-1]>arr[mid])
        {
           count=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    
int strt=0;
int end=count;
    
        while (strt<=end)
        {
        int mid=strt+(end-strt)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            end=mid-1;
        }
        else {
            strt=mid+1;
        }
        
       
        }
   
   int strt1=count+1;
   int end1=size-1;

        while (strt1<=end1)
        {
        int mid=strt1+(end1-strt1)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            end1=mid-1;
        }
        else {
            strt1=mid+1;
        }
        
       
        }
    return -1;


}



int main(){
    /*
    vector<int>v{1,3,5,6,7};
    int arr[]={2,3,6,7,8};
    int size=5;
    //for vector
    if(binary_search(v.begin(),v.end(),5)){//predefined binary function
        cout<<"element found"<<endl;
    }

    else{
        cout<<"element not found"<<endl;
    }
  //for array
  if(binary_search(arr,arr+size,5)){//predefined binary function
        cout<<"element found"<<endl;
    }

    else{
        cout<<"element not found"<<endl;
    }*/
/*
//find the first occurence of an element target is 4
    int arr[]={1,2,3,3,4,4,4,6,7,9};
    int target=4;
    int size=10;
    int strt=0;
    int end=size-1;
    int mid=(strt+end)/2;
    int x;
    while (strt<=end)
    {
        if(arr[mid]==target){
             x=mid;
             end=mid-1;

        }
         else if(arr[mid]>target){
            end=mid-1;
        }
        
        else {
            strt=mid+1;
        }
        mid=(strt+end)/2;
       
    }
    if (x!=-1)
    {
        cout<<"THE FIRST OCCURENCE OF TARGET FOUND AT "<<x<<endl;
    }
    else
    {
        cout<<"TARGET NOT FOUND  "<<endl;
    }





//find the last occurence of an element target is 4

int arr[]={1,2,3,3,4,4,4,6,7,9};
    int target=4;
    int size=10;
    int strt=0;
    int end=size-1;
    int mid=(strt+end)/2;
    int x;
    while (strt<=end)
    {
        if(arr[mid]==target){
             x=mid;
             strt=mid+1;

        }
         else if(arr[mid]>target){
            end=mid-1;
        }
        
        else {
            strt=mid+1;
        }
        mid=(strt+end)/2;
       
    }
    if (x!=-1)
    {
        cout<<"THE last OCCURENCE OF TARGET FOUND AT "<<x<<endl;
    }
    else
    {
        cout<<"TARGET NOT FOUND  "<<endl;
    }

//PREDEFINED FUNCTION FOR LOWER BOUBND AND UPPER BOUND
    auto ans=lower_bound(arr,arr+size,target);
    cout<<"THE first OCCURENCE OF TARGET FOUND AT "<<ans-arr<<endl;
    auto ans1=upper_bound(arr,arr+size,target);
    cout<<"THE LAST OCCURENCE OF TARGET FOUND AT "<<ans1-arr<<endl;
    
*/
//find missing elements in an array by binary search 1 2 3 4 5 6 8 9 10
/*
vector<int>v{1,2,3,4,5,6,8,9,10};
int size=v.size();

int x=missingelement(v,size);
if(x==-1){
    cout<<"ALL ELEMENTS ARE PRESENT"<<endl;
}
else{
    cout<<"MISSING ELEMENT IS "<<x<<endl;
}*/

/*
//peak element in an mountain array
//find piviot
vector<int>v{1,2,3,4,4,5,8,9,10};
int size=v.size();

int x=pivot(v,size);
*/
/*
//search in a rotate and sorted array
vector<vector<int> >v(3,vector<int>(3,0));
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
       cin>>v[i][j];
    }
    
}
int target=4;
int x=binarysearch2d(v,target);
if (x==-1)
{
    cout<<"TARGET NOT FOUND"<<endl;
}
else
{
    cout<<"TARGET FOUND AT"<<x<<endl;

}*/




/*
//squareroot using binary search
int a;
cout<<"enter the square"<<endl;
cin>>a;
vector<int>v(a);
for (int i = 0; i < a; i++)
{
    v[i]=i+1;

}

float x=squareroot(v,a);
cout<<"the squarerrot is "<<x;

*/
/*
//search in nearly sorted array in log time as according to sorted array it maximum can shift i+1 or i-1 from i
int arr[]={10,3,40,20,50,80,70};
    int target=40;
    int size=7;
    
    

int x=binarysearch(arr,size,target);
if(x==-1){
    cout<<"TARGET NOT FOUND"<<endl;
}

else{
    cout<<"TARGET FOUND AT "<<x<<endl;
}*/


//division of 2 numbers using binary search
/*
int a;
cout<<"enter the number"<<endl;
cin>>a;
int b;
cout<<"enter the number by which we have to divide"<<endl;
cin>>b;
vector<int>v(a);
for (int i = 0; i < a; i++)
{
    v[i]=i+1;

}

division(v,a,b);

*/
//find odd occuring element using binary search
/*
int arr[]={1,1,2,2,3,3,4,4,3,6,6,4,4};
int size=13;
cout<<"THE ODD ELEMENT IS "<<arr[oddelement(arr,size)];*/

//all element occur even number of time
//all repeating occurence of number appear in a pair
//pairs and not adjacent

/*
cout<<"hello"<<endl;

int arr[]={4,5,6,7,0,1,2};
int target=0;
int size=7;
int x=binarysearchinsorted(arr,target,size);
cout<<"hello"<<endl;
if (x==-1)
{
    cout<<"element not found";
}
else{
    cout<<"element found at "<<x;
}
*/
/*
//k diff pair in an array
vector<int>arr{6,7,3,6,4,6,3,5,6,9};
int size = arr.size();
int target=4;
        sort(arr.begin(), arr.end());
       
        
        int count = 0;
        int i = 0;
        int j = i + 1;
        while (i <= j && j < size) {

            int k = arr[j] - arr[i];
            if (i > 0 && arr[i] == arr[i - 1]) {
                i++;
                
            } else if (k == target) {
                count++;
                i++;
                if (j == size - 1) {

                    j = i + 1;
                } else {
                    j++;
                }
            } else if (k < target) {
                if (j == size - 1) {
                    i++;
                    j = i + 1;
                } else {
                    j++;
                }

            } else if (k > target) {
                i++;

                if (j == size - 1) {

                    j = i + 1;
                }
            }
            if (i == j) {
                j++;
            }
        }
        cout<< count;

        int x=INT_MIN
        */
    vector<int>arr{6,7,3,6,4,6,3,5,6,9};
    int size = arr.size();
    int target=3;
    sort(arr.begin(), arr.end());
    int count = 0;
    int strt=0;
    int end=size-1;
    int mid=strt+(end-strt)/2;
    int x=0;
    while (strt<=end && x<size)
    {
        int k=arr[mid]-arr[x];
        int k1=arr[strt]-arr[x];
        if(strt==end){
            if(k1==target){
                count++;
                x++;
            }
            else{
                x++;
            }
        }
        if(arr[x]==arr[x-1]){
            x++;
        }
        if(k==target){
            count++;
            x++;
            strt=x;    
        }else if(k>target){
            end=mid-1;
        }else {
            strt=mid+1;
        }
        mid=strt+(end-strt)/2;
       
    }
    cout<<count;
        
    }





