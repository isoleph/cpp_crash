#include <iostream>
using namespace std;


// copy contents of an array into another
int main () {
    int u[10] = {0,1,2,3,4,5,6,7,8,9};
    int v[10];

    for (int i = 0; i < 10; i++) {
        v[i] = u[i];
    }

    /* print the outputs of both arrays */
    for (int i = 0; i < 10; i++) {
        cout << u[i]<< " ";
    }

    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << v[i] << " ";
    }
    return 0;
}

