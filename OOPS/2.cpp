#include<iostream>
using namespace std;

class A {
public:
    int m = 10;
};

class B :virtual public A {
public:
    int m = 20;
};

class C :virtual public A {
public:
    int m = 30;
};

class D :virtual public A {
public:
    int m = 40;
};

class E : public B, public C, public D {
public:
    int m = 50;
    void print() {
        cout << "E::m = " << m << endl;
        cout << "B::m = " << B::m << endl;
        cout << "C::m = " << C::m << endl;
        cout << "D::m = " << D::m << endl;
        cout << "A from B = "<< A::m << endl;
    }
};

int main() {
    E obj;
    obj.print();
    return 0;
}
