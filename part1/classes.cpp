#include <iostream>
using namespace std;


// this script does the same things as structure.cpp
// except with the class object
class cvector {
    public:
        cvector(int s): 
            elem{new double[s]}, sz{s} {} // create cvector
        double& operator[](int i) {       // element subscripting
            return elem[i]; 
        }
        int size() {
            return sz;
        }
    private:
        double* elem; // pointer to the elements
        int sz;       // save number of elements
};

double vrs(int s) {
    cvector v(s); double sum;

    for (int i=0; i!=v.size(); i++) {
        cin>>v[i];
    }
    for (int i=0; i!=v.size(); i++) {
        sum += v[i];
    }
    return sum;
}

int main () {
    int entries = 3; double sum;
    cout << "Please input " << entries << " entries line by line to get their sum." << endl;
    sum = vrs(entries);
    cout << "Sum: " << sum << endl;
    return 0;
}