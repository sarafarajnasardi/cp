#include <iostream>
using namespace std;

class A1 {
public:
    int val1;
    A1(int v) : val1(v) {}
};

class A2 : public A1 {
public:
    int val2;
    A2(int v1, int v2) : A1(v1), val2(v2) {}
};

class A3 : public A2 {
public:
    int val3;
    A3(int v1, int v2, int v3) : A2(v1, v2), val3(v3) {}
    void show() { cout << "Values: " << val1 << ", " << val2 << ", " << val3 << endl; }
};

int main() {
    A3 obj(1, 2, 3);
    obj.show();
    return 0;
}
