# C++ Crash Course 

<div align="center">

<img src=img/cpp.png width = 150> 
  
  [![Status](https://img.shields.io/badge/status-active-success.svg)]()
  [![GitHub Issues](https://img.shields.io/github/issues/isoleph/cpp_crash.svg)](https://github.com/isoleph/cpp_crash/issues)
  [![GitHub Pull Requests](https://img.shields.io/github/issues-pr/isoleph/cpp_crash.svg)](https://github.com/isoleph/cpp_crash/pulls)
  [![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)
  [![Tweet](https://img.shields.io/twitter/url/https/shields.io.svg?style=social)](https://twitter.com/risvoi)

</div>

This is a record of all of the C++ files and programs that I have written after closely following Bjarne Stroustrup's [*The C++ Programming Language, 4ed*](http://www.stroustrup.com/4th.html).

Have fun!

## 📝 Table of Contents

[Part One](#part1)
- [Hello World](#hello)
- [Basic Functions](#functions)
- [Constants from another File](#constants)
- [Input Variables and Loops](#iandl)
- [Arrays](#arrays)

# Part One <a name = 'part1'></a>
## 👋 Hello World! <a name = 'hello'></a>
[//]: # (refer to hello.c)
*The code for this part may be seen in* `hello.cpp`

This macro prints "Hello World" to the screen. It's a [very standard way](https://en.wikipedia.org/wiki/%22Hello,_World!%22_program) of testing out a new language. 
```cpp
#include <iostream>
using namespace std;
```
This preamble tells the program to include the `iostream` library that allows input and output to the terminal. 

Then you might see that `using namespace std;` indicates that we are using the standard library namespace for functions that we might otherwise have to explicitly written out as `std::cout` or `std::endl`. These print out to the screen and end the current line, respectively.

Bear in mind as well that the `<<` functions push the string literal "Hello World" out to the screen. Likewise the `<< endl` part attaches the endline instance to the end of the "Hello World" string. (You'll see the `<<` work in the opposite way when we look at `cin`)

Then you can see that we declare an `int main ()` function that executes the program. But notice that we have to declare what the output of the function is in the lines:

```cpp
int main () {
  cout << "Hello World!" << endl;
  return 0;
}
```

Notice as well that the contents of the function are held within brackets. Moreover, the sentence that we want to output to the screen is held in quotes to identify it as a [string literal](https://en.wikipedia.org/wiki/String_literal).

Finally when the program is done, we ask it to return the integer `0` to demonstrate that it has completed successfully. 

## ➗ Basic Functions  <a name = 'functions'></a>
[//]: # (refer to square.cpp)
*The code for this part may be found in* `square.cpp`

We can write a very basic function that outputs the square of a number. Consider the function where:
```cpp
double square(double x) {
  return x*x;
}
```
First, we declare the function above to give a `double` (float) output. Then inside of the parantheses, we specify what kind of input the function takes, here it is another double as the variable `x`.

Within the brackets, we specify for the function to return the value of x multiplied against itself to square it. 

## 🔤 Constants from another File <a name = 'constants'></a>
[//]: # (refer to constants.h and circle.cpp)
*The code for this part may be found in* `constants.h` and `circle.cpp`.

Here, we have two files. Notice that one of these files is an .h file instead of a traditional .cpp file. The reason for this is because the .h file will serve as a `header` file that we are going to reference later. 

If you look at `constants.h`, you'll notice the lines: 

```cpp
#if !defined(angels_constants)
#define angels_constants 1

const double pi = 3.14159;
const double tau = 2*pi;

#endif
```

The `#if !defined` line checks to see if file has already been accessed and defiend the constants. If it turns out that it has not, then it will define the constants as written in the .h file. When this is finished, `#endif` tells the compiler to stop there.

The reason for us defining these constants here is so that we can refer to them in `circle.cpp`. Notice that in this .cpp file, that we are including our constants with the statement:

```cpp
#include "constants.h"
```

Be careful to put user-defined .h files in quotation marks. If you put them in brackets as we did for `#include <iostream>` for instance, then the compiler won't necessarilly know to search within your current directory for the header file.

Then, for our function in the .cpp file, we can access those included constants and use them to print out the values of a circle with the code below:

```cpp
int main (){
    double r = 1.0;
    cout << "For a circle of radius " << r << ":" << endl;
    cout << "Diameter = " << 2*pi*r << endl;
    cout << "Area = " << pi*r*r << endl;
    return 0;
}
```

## 🔁 Input Variables and Loops <a name = 'iandl'></a>
[//]: # (refer to proceed)
*The code for this part may be seen in all* `proceed.cpp` *files*.

In the first proceed file, you may see the program prints out "Do you wish to proceed?" to the screen using `cout` and `endl`. This function is done with `bool proceed ()` which should also return a boolean value, i.e. `true` or `false`.

Then the script creates an empty variable `char answer`. The reason for this is so that when it requests user input with `cin >> answer`, that when the `>>` push the response to that variable, it will store it and use it for the rest of the program.

```cpp
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
```

Then the program uses the `if (condition)` statement to check what was input into the answer variable. If it matches 'y' and hence if the if statement `if (answer == 'y')` becomes `if true`, then it will print out a specific statement and return a `true` boolean value. Then if this condition is not met, it will print something else out and return a `false` boolean value. 

Likewise, `proceed2.cpp` does this by using `case` instead of if statements. You may see:

```cpp
    switch(answer) {
        case 'y':
            cout << "Let us continue." << endl;
            return true;
        case 'n':
            cout << "Be gone from my sight." << endl;
            return false;
```

In this case, the `switch(answer)` function will check the provided answer against different possible cases of its value and go from there. 

Finally, in `proceed_while.cpp` this is done in a while loop that will repeatedly check if its conditions are not met. Notice that this is doen with a `while loop` where a condition will be constantly checked, and then we will define an increment that will make the while statement false eventually.
```cpp
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
```
You may notice above that we made the while loop check against an int variable i. And every time the loop runs, i grows larger by one until eventually the while statement is no longer true.

Likewise, if you want to make a loop run forever, you would start it with `while true`. 
## 📜 Arrays <a name = 'arrays'></a>
[//]: # (refer to array, increment, string_array)
*The code for this part may be found in* `array.cpp`, `increment.cpp`, and `string_array.cpp`.

