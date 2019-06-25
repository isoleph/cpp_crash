#include <iostream>
using namespace std;


// introduction to while operators
bool proceed () {
    int i = 0;
    while (i<4) {
        cout << "Do you wish to proceed?" << endl;
        char answer; cin >> answer;

        switch (answer) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                cout << "Sorry, I don't understand." << endl;
                i++;
        }
    }
    cout << "I'll take that as a no." << endl;
    return false;
}

int main () {
    proceed ();
    return 0;
}