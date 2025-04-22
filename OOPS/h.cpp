#include <bits/stdc++.h>
using namespace std;

// class Vecto{
//     public:
//     static int i=0;
//     int arr[10];
//     Vecto(int a){
//         arr[i++]=a;
//     }
//     int len(){
//         return i;
//     }
//     Vecto operator+(const Vecto& b){}
// };

class Vector{
    public:
        int x, y;

    Vector(){
        x = 0; y = 0;
    }

    Vector(int x, int y){
        this->x = x; this->y;
    }

    Vector operator+(const Vector& obj){
        return Vector(this->x + obj.x, this->y + obj.y);
    }

    bool operator==(const Vector& obj){
        return obj.x == this->x && obj.y == this->y;
    }
};
