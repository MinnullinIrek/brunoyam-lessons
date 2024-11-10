//https://github.com/google/googletest.git

#include <iostream>

#include "utils/vec.hpp"
using namespace std;

int main()
{
    cout << "Hello World!" << Vec<float>(2,5).toString() <<endl;
    return 0;
}
