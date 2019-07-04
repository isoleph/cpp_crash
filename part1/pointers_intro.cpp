#include <iostream>
using namespace std;


// introduction to how pointers work
int main () {
    int p = 3;             // assign p = 3
    cout << &p << endl;    // returns address of p
    cout << *(&p) << endl; // returns contents of address at p
    
    int* q = &p;           // assign pointer q with address of p
    cout << q << endl;     // print pointer q
    cout << *q << endl;    // print contents of pointer q

    return 0;
}