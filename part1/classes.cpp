#include <iostream>
using namespace std;


// this script does the same things as structure.cpp
// except with the class object
class cvector {
    public:
        cvector(int s):                   // create cvector
            elem{new double[s]}, sz{s} {} // allocate elem; store s as sz
        double& operator[](int i) {       // enable indexing
            return elem[i]; 
        }
        int size() {                      // return size
            return sz;
        }
    private:
        double* elem; // pointer to the elements
        int sz;       // save number of elements
};

double vrs(int s) {
    cvector v(s); double sum;             // create cvector, sum variable

    for (int i=0; i!=v.size(); i++) {     // ask for elements
        cin>>v[i];
    }
    for (int i=0; i!=v.size(); i++) {     // sum all elements
        sum += v[i];
    }
    return sum;
}

int main () {
    int entries = 3; double sum;          // entries = 3 = sz =  s
    cout << "Please input " << entries << " entries line by line to get their sum." << endl;
    sum = vrs(entries);
    cout << "Sum: " << sum << endl;
    return 0;
}
