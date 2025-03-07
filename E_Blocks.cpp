#include <bits/stdc++.h>

using namespace std;
class Human{
    private:
      string color_of_hair;
      Human(){
        cout<<"hello1"<<endl;
      }
    public:
     int height;
     int weight;
     int age;
     
     int get_height()  { return height;}
     int get_weight()  { return weight;}
     int get_age()  { return age;}
     
     void set_height(int h) { height = h;}
     void set_weight(int w) { weight = w;}
     void set_age(int a) { age = a;}

     void result(){
        int res= height + weight + age;
        cout<<"Result: "<<res<<endl;
     }
     virtual void sleep(){
        cout<<"hello"<<endl;
     }
};

class Male: private Human{
    public:
    string color;
     void sleep() override{
        cout<<"The male is sleeping."<<endl;
    }
};
int main(){
   
    Human m;
    m.sleep();
}