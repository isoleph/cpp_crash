#include <iostream>
using namespace std;

double square(double x){
    return x*x;
}
// function takes in a double and prints out square
int main () {

    double x = 5.0;
    cout << "The square of " << x << " is "  << square(x) << endl;
    return 0;
}