#include<iostream>
#include<limits.h>
using namespace std;


/*int main(){

int a,b;

cin>>a>>b;
cout<<"sum is = "<<a+b<<endl;

return 0;

}*/

/*int main(){
    int m;
    cout<<"enter the number"<<endl;
    int count;
    cin>>count;
    int a=3;
    
while( a < count)
{
    

int i=2;
       while(i<a){
           int m=a%i;
           i++;
       }
            
       if(m==0){
        cout<<"x"<<endl;
        break;
       }
        
       else{
            cout<<a<<endl;
            }
    a++;
        
}}*/

int main() {
   
/*
int arr[]={5,7,7,8,10,11};
int target=8;
int size=6;

        
        int s1=0;
        int e1=size-1;
        int last;int mid1=s1+(e1-s1)/2;
         while(s1<=e1){
            
            if(arr[mid1]==target){
             last=mid1;
              s1=mid1+1;
            }
            else if(arr[mid1]>target){
                e1=mid1-1;
            }
            else{
                s1=mid1+1;
            }
            mid1=s1+(e1-s1)/2;
        }
        cout<<first<<last;
}



int lsearch(vector<int>& arr, int target, int size) {
        int strt = 0;
        int end = size - 1;

        while (strt <= end) {
           int mid=strt+(end-strt)/2;
           if(strt==end){
               return strt;
           }
             if (mid + 1 <= end && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            else if (strt <= mid - 1 && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            } else if (arr[mid] > arr[0] && arr[mid] > arr[size - 1]) {
                strt = mid + 1;
            }
             else {
                end = mid - 1;
            }  
        }
        return -1;
    }
    int rsearch(vector<int>& arr, int target, int size) {
        int strt = 0;
        int end = size - 1;

        while (strt <= end) {
           int mid=strt+(end-strt)/2;
           if(strt==end){
               return strt;
           }
             if (mid + 1 <= end && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            else if (strt <= mid - 1 && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            } else if (arr[mid] >= arr[0] && arr[mid] >= arr[size - 1]) {
                strt = mid + 1;
            }
            } else {
                end = mid - 1;
            }  
        }
        return -1;
    }
    int psearch(vector<int>& arr, int target, int size) {
        int strt = 0;
        int end = size - 1;

        while (strt <= end) {
           int mid=strt+(end-strt)/2;
           if(strt==end){
               return strt;
           }
             if (mid + 1 <= end && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            else if (strt <= mid - 1 && arr[mid] < arr[mid - 1]) {
                return mid - 1;
            } else if (arr[mid] > arr[0] && arr[mid] > arr[size - 1]) {
                strt = mid + 1;
            }else if (arr[mid]== arr[0] && arr[mid] == arr[size - 1]) {
                if(lsearch(arr,target,size)!=-1){
                    return lsearch(arr,target,size);
                }
                else if(psearch(arr,target,size)!=-1){
                    return psearch(arr,target,size);
                }
            } else {
                end = mid - 1;
            }  
        }
        return -1;
    }
    int bsearch(vector<int>& arr, int strt, int end, int target) {
        
        while (strt <= end) {
            int mid=strt+(end-strt)/2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] > target) {
                end = mid - 1;
            } else {
                strt = mid + 1;
            }
           
        }
        return -1;
        */
//     int big,secondl;
//    int arr[7]={19,23,16,46,2,54,3};
//    for(int i=0;i<=6;i++){
//       big=arr[i];
//       for(int j=0;j<=6;j++){
//       if(arr[j]>big){
//          big=arr[j];
//       }
//       }
//    }
//    for(int i=0;i<=6;i++){
//       secondl=arr[i];
//         for(int j=0;j<=6;j++){
//      if(secondl<arr[j]<big){
//         secondl=arr[j];
//      }
//         }
//   }
//    cout<<secondl;

 
//    int arr[7]={19,23,16,46,2,54,3};
//    int big=INT_MIN;
//    for(int i=0;i<7;i++){
//       if (arr[i]>big)
//       {
//         big=arr[i];
//       }
      
//    }
//    cout<<big;
//    int secondl=INT_MIN;
//    for(int i=0;i<7;i++){
      
//      if(secondl<arr[i] && arr[i]<big){
//         secondl=arr[i];
//         }
//      }
//    cout<<secondl;
// 
double m=35;
double y=4;
double x=m/y;
cout<<x;



    }