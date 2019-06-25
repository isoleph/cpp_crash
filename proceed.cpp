#include <iostream>
using namespace std;


// introduction to if statements
bool proceed () {
    cout << "Do you wish to proceed?" << endl;
    char answer; cin >> answer;

    if (answer == 'y') {
        cout << "We shall proceed." << endl;
        return true;
    }
    cout << "Very well, we shall not proceed." << endl;
    return false;
}

int main () {
    proceed();
    return 0;
}