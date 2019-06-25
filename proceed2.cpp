#include <iostream>
using namespace std;


// introduction to switch operator
bool proceed2 () {
    cout << "Do you wish to continue?" << endl;
    char answer; cin >> answer;

    switch(answer) {
        case 'y':
            cout << "Let us continue." << endl;
            return true;
        case 'n':
            cout << "Be gone from my sight." << endl;
            return false;
        default:
            cout << "I'll take that as a no." << endl;
            return false;
    }
}

int main () {
    proceed2 ();
    return 0;
}