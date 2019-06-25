#include <iostream>
#include <array>
using namespace std;


// print all contents of a string array
int main () {

    string v[2] = {"yes","no"};
    for (int i = 0; i < std::size(v) ; i++) {
        cout << v[i] << endl;
    }
    return 0;
}
