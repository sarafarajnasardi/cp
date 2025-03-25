#include <iostream>
using namespace std;

class Iterator {
public:
    int value;
    Iterator(int v) : value(v) {}
    void show() { cout << "Value: " << value << endl; }
};

class Container {
public:
    Iterator getIterator(int val) { return Iterator(val); }
};

int main() {
    Container obj;
    Iterator it = obj.getIterator(10);
    it.show();
    return 0;
}
