#include<bits/stdc++.h>
#define a(v) (v).begin(),(v).end()
#define heap_sort sort
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]<arr[largest]){
        largest=left;
    }
    if(right<n&&arr[right]<arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heap(int arr[],int n){
    for(int i=0;i<n/2-1;i++){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,n,i);
    }
}
void count(int arr[],int it,int n){
    int count[10]={0};
    int output[n];
    for(int i=0;i<n;i++){
        count[(arr[i]/it)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/it)%10]-1]=arr[i];
        count[(arr[i]/it)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
int radix(int arr[],int n){
    int maxi=*max_element(arr,arr+n);
    int it=1;
    while(maxi/it>0){
        count(arr,it,n);
        it*=10;
    }
}
int main(){
    int arr[]={13,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
   // heap_sort(a(arr));
    radix(arr,n);
    for(auto x:arr)cout<<x<<" ";
}