#include <iostream>
using namespace std;

// print all contents using pointers
int main () {
    int v[10] = {0,1,2,3,4,5,6,7,8,9};
    for (int& x:v) {
        cout << x << endl;
        x++;
    }
    return 0;
}

