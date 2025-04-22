#include <iostream>
using namespace std;
class Animal {
    public:
        virtual void speak() {
            cout << "Animal sound\n";
        }
    };
    
class Dog : public Animal {
    public:
        void speak() {
            cout << "Woof!\n";
        }
    };
    
    int main() {
        Dog d;
        d.speak();
    }
    