#include "constants.h"
#include <iostream>
using namespace std;


// pull in constants and calculate circle values
int main (){
    double r = 1.0;
    cout << "For a circle of radius " << r << ":" << endl;
    cout << "Diameter = " << 2*pi*r << endl;
    cout << "Area = " << pi*r*r << endl;
    return 0;
}