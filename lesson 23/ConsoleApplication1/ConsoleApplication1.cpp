#include <iostream>


struct Dog;
struct Owner
{
    Owner() {

    }

    ~Owner(){

    }
    
    Dog* dog;

};

struct Dog
{
    Dog() {
    
    }
    
    ~Dog() {
    }

    void voice() {
        std::cout << "bark " << std::endl;
    }
    Owner* owner;
};

int main() {
    
    Owner* owner = new Owner;
    Dog* dog = new Dog;

    owner->dog = dog;
    dog->owner = owner;

    return 0;
}
