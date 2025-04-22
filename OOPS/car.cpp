#include <bits/stdc++.h>

using namespace std;
class Car{
  public:
     string brand,model,year;
      
     Car(string a,string b,string c){
        this->brand=a;
        this->model=b;
        this->year=c;
     }
     void display(){
        cout<<this->brand<<" "<<this->model<<" "<<this->year<<endl;
     }
};


// int main(){
//     Car a[5];
//     for(int i=0;i<5;i++){
//         string a,b,c;
//         cin>>a>>b>>c;
//         a[i]=Car(a,b,c);
//     }
    
//     for(int i=0;i<5;i++){
//        a[i].display();
//     }
// }

class Rectangle{
    public:
    int l;int b;
    Rectangle(int length,int breadth){
        l=length;
        b=breadth;
    }
    Rectangle(int length,double breadth){
        l=length;
        b=breadth;
    }
    int area(){
        return l*b;
    }
};
int main(){
    Rectangle a(4,6.8);
    cout<<a.area()<<endl;
}