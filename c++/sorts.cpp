#include <bits/stdc++.h>
using namespace std;

struct Tree{
    int data;
    Tree* left;
    Tree* right;
    Tree(int data){
        this->data=data;
        left=right=NULL;
    }
};

struct CLL{
    int data;
    CLL* next;
    CLL(int data){
        this->data=data;
        next=NULL;
    }
};
int main(){
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    //selection sort
    // for(int i=0;i<n;i++){
    //     int k=i;
    //     int maxi=arr[i];
    //     for(int j=i+1;j<n;j++){
    //         if(arr[j]<maxi){
    //             maxi=arr[j];
    //             k=j;
    //         }
    //     }
    //     swap(arr[i],arr[k]);
    // }

    //bubble sort
    // for(int i=n-1;i>=0;i--){
    //     for(int j=0;j<i-1;j++){
    //         if(arr[j]>arr[j+1]){
    //             swap(arr[j],arr[j+1]);
    //         }
    //     }
    // }

    //insertion sort
    // for(int i=0;i<n;i++){
    //     int temp=arr[i];
    //     int j=i-1;
    //     while(j>=0 && arr[j]>temp){
    //         arr[j+1]=arr[j];
    //         j--;
    //     }
    //     arr[j+1]=temp;
    // }
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }


    // Tree* tree = new Tree(1);
    // tree->left = new Tree(2);
    // tree->right = new Tree(3);
    // tree->left->left = new Tree(4);
    // inOrder(tree);
    CLL* head=new CLL(1);
    CLL* tail=head;
    tail->next=head;
    for(int i=2;i<=5;i++){
        CLL* newNode=new CLL(i);
        tail->next=newNode;
        tail=newNode;
    }
    
}
