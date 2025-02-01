#include <bits/stdc++.h>
using namespace std;

int main() {

int x,y;
cin>>x>>y;

if(x>=0&&y>=0){
    int cor=0;
    if(x>=y){
      cor=(max(x,y)-1)*4+1;
    }else{
       cor=(max(x,y)-1)*4+2;
    }
    cout<<cor<<endl;
    return 0;
}else if(x<=0&&y>=0){
  int cor=0;
    if(abs(x)>=abs(y)){
      cor=(max(abs(x),abs(y))-1)*4+2;
    }else{
       cor=(max(abs(x),abs(y))-1)*4+3;
    }
    cout<<cor<<endl;
    return 0;

}else if(x<=0&&y<=0){
  int cor=0;
    if(abs(x)>=abs(y)){
      cor=(max(abs(x),abs(y))-1)*4+3;
    }else{
       cor=(max(abs(x),abs(y))-1)*4+4;
    }
    cout<<cor<<endl;
    return 0;

}else if(x>=0&&y<=0){
   int cor=0;
    if(abs(x)>=abs(y)){
      cor=(max(abs(x),abs(y))-1)*4+4;
    }else{
       cor=(max(abs(x),abs(y))-1)*4+5;
    }
    cout<<cor<<endl;
    return 0;
}



}
