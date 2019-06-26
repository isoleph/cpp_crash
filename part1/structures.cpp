#include <iostream>
using namespace std;

// create the cvector structure
struct cvector {

    // lets declare variables the rest of this structure will use
    int sz;                         // number of elements in cvector
    double* elem;                   // pointer to those elements in cvector
};


// create a function for the cvector structure to run on initiation
void cvector_init(cvector& v, int s) {
    v.elem = new double[s]; // allocate an array of s doubles from heap
    v.sz = s;               // save the size of the allocated array
}

// function to read s integers from stdin and return their sum
double rs(int s) {
    double sum; cvector v;           // create empty double sum and empty cvector v
    cvector_init(v,s);               // allocate s elements to the cvector v

    for (int i=0; i!=s; i++) {
        cin >> v.elem[i];           // for each input, push value into our cvector
    }

    for (int i=0; i!=s; i++) {
        sum += v.elem[i];           // sum all elements in our cvector
    }
    return sum;
}

// main function to execute to terminal
int main () {
    int entries = 3; double sum;
    cout << "Please input " << entries << " entries line by line to get their sum." << endl;
    sum = rs(entries);
    cout << "Sum: " << sum << endl;
    return 0;
}