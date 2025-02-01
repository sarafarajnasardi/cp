#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
char arr[r][c];
    
    int ct1=0,ct2=0;
    int ans1,ans2,final,pass1,pass2;
    for(int i=0;i<r;i++){
        string s;
        cin>>s;
    for(int j=0;j<c;j++){
        arr[i][j]=s[j];
    }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]!='S'){
                ct1++;
            }

        }
        pass1++;
    }
for(int j=0;j<c;j++){
        for(int i=0;i<r;i++){
            if(arr[i][j]!='S'){
                ct2++;
            }

        }
        pass2++;
    }
    if(ct1%c==0){
        ans1=ct1;
    }
    if(ct2%r==0){
        ans2=ct2-(pass1*pass2);
    }
final=ans1+ans2;
cout<<final;

    return 0;
}