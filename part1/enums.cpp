#include <iostream>
using namespace std;

// create enum class with data objects
enum class traffic_light { red, yellow, green };

// define an increment operator ++t
traffic_light operator++(traffic_light& t) {
    switch (t) {
        case traffic_light::green:
            cout << "Green -> Yellow" << endl;
            return traffic_light::yellow;
        case traffic_light::yellow:
            cout << "Yellow -> Red" << endl;
            return traffic_light::red;
        case traffic_light::red:
            cout << "Red -> Green" << endl;
            return traffic_light::green;
    }
}

int main() {
    // initiate on red
    traffic_light start = traffic_light::red;

    // assign new instances of traffic colors
    traffic_light n1 = ++start;
    traffic_light n2 = ++n1;
    traffic_light n3 = ++n2;
    return 0;
}