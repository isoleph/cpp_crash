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

This crash-course does assume some prior programming knowledge, specifically with Python; although I do try to make the writing as inclusive as possible.

Have fun!

## 📝 Table of Contents

[Part One](#part1)
- [Hello World](#hello)
- [Basic Functions](#functions)
- [Constants from another File](#constants)
- [Input Variables and Loops](#iandl)
- [Arrays](#arrays)
- [Data Structures](#structures)
- [Classes](#class)

# Part One <a name = 'part1'></a>
## 👋 Hello World! <a name = 'hello'></a>
[//]: # (refer to hello.c)
*The code for this part may be seen in* `hello.cpp`

This macro prints "Hello World" to the screen. It's a [very standard way](https://en.wikipedia.org/wiki/%22Hello,_World!%22_program) of testing out a new language. I personally use it all the time when working with a new language or interface!

Let's look at the first two lines of `hello.cpp` below.
```cpp
#include <iostream>
using namespace std;
```
This "preamble" tells the program to include the `iostream` library that allows input and output to the terminal. 

Then you might see that `using namespace std;` indicates that we are using the standard library namespace. If we didn't do this, then later in our code we would have to write out `std::cout` or `std::endl` explicitly. These functions print out a [string](https://en.wikipedia.org/wiki/String_literal) to the screen or end a line, respectively. 

Bear in mind that the `<<` function pushes the string "Hello World" out to the screen. Likewise the `<< endl` part attaches the endline instance to the end of the "Hello World" string. You can also write `<< '\n'` instead of `<< endl;` but I just do it this way because it looks nicer.  

(You'll see the `<<` work in the opposite way as `>>` when we look at `cin` later)

In our code, you can see that we declare an `int main ()` function that executes our program. This is because in C++, we have to declare what the output of out function must be. So when our program succesfully runs, we have it return 0 to show that it succeeded!

```cpp
int main () {
  cout << "Hello World!" << endl;
  return 0;
}
```

Notice as well that the contents of the function are held within brackets `{}`. Also take care that your message to the screen is in full quotation marks to identify it as a  [string literal](https://en.wikipedia.org/wiki/String_literal).

If everything is working correctly, then after compiling, this will print "Hello World!" to the screen!

## ➗ Basic Functions  <a name = 'functions'></a>
[//]: # (refer to square.cpp)
*The code for this part may be found in* `square.cpp`

Let's write a very basic function that outputs the square of soem number we give that function. Let's take a look at the code where:
```cpp
double square(double x) {
  return x*x;
}
```
First, we declare the `double square(double x)`. This means that we are making some function called *square* that will take some double value `x` and return a double value too.

Now, in the  brackets, we have our function return the value of x multiplied against itself (its square).

If you write a main function and ask it to evaluate `square(5.0)`, you should get 25 back!

## 🔤 Constants from another File <a name = 'constants'></a>
[//]: # (refer to constants.h and circle.cpp)
*The code for this part may be found in* `constants.h` and `circle.cpp`.

Now, let's find out how to define constants in another file and import them to one we're working with.

 Notice that one of our files is a .h file instead of a traditional .cpp file. The reason for this is because the .h file will serve as a `header` file that we are going to reference later. 

If you look at `constants.h`, you'll notice the lines: 

```cpp
#if !defined(angels_constants)
#define angels_constants 1

const double pi = 3.14159;
const double tau = 2*pi;

#endif
```

The `#if !defined` line checks to see if file has already been accessed and has defined the constants in it. If it turns out that it has not, then it will define the constants as written. When this is finished, `#endif` tells the compiler to stop there.

The reason for us defining these constants here is so that we can refer to them later in `circle.cpp`. Notice that in this .cpp file, that we are including our constants with the statement:

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
If everything is working correctly, then you should get it to print out that for radius = 1,  the Diameter = 6.28318 and the Area is 3.14159.

## 🔁 Input Variables and Loops <a name = 'iandl'></a>
[//]: # (refer to proceed)
*The code for this part may be seen in all* `proceed.cpp` *files*.

Let's find out how to make a program that takes user input. A little later, we'll look at how to make a while loop.

In the first proceed file, you may see the program prints out "Do you wish to proceed?" to the screen using `cout` and `endl`. This function is done with `bool proceed ()` which should return a boolean value, i.e. `true` or `false`.

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
You may notice above that we made the while loop check against an int variable i. And every time the loop runs, i grows larger by one until eventually the while statement is no longer true. You can see this at the end of the loop in the line `i++`.

Likewise, if you want to make a loop run forever, you would start it with `while true`. 
## 📜 Arrays <a name = 'arrays'></a>
[//]: # (refer to array, increment, string_array)
*The code for this part may be found in* `arrasy.cpp`, `increment.cpp`, and `string_array.cpp`.

Let's take a look at how to make arrays, or lists, in C++. 

For this part, let's copy the contents of one list into an 'empty' one. Let's look at `arrays.cpp`. Notice that at the top, we are declaring two lists:

```cpp
int u[10] = {0,1,2,3,4,5,6,7,8,9};
int v[10];
```

Here, the `int u[10]` specifies that we are creating an array with 10 entries. It is important to note that in C++, arrays are immutable in size. You can replace different entries inside of them, but you can't change their length. 

Then, you might notice that there's a for-loop that iterates over the first array `u` and copies all of its elements into the array `v`. This is done through indexing as [you might remember](https://www.digitalocean.com/community/tutorials/understanding-lists-in-python-3). You'll see that each index being iterated over in the 'empty' list will be assigned the value it is in the other list.

```cpp
    for (int i = 0; i < 10; i++) {
        v[i] = u[i];
    }
```

Notice that the conditions inside of the for-loop are done as follows `for(start; end; increment)`. Much like the while-loop, the for-loop will create a starting condition `int i = 0`, then it will repeatedly check against a condition `i < 10`, and then it will increment its starting contition so that it will eventually stop. In this case `i++` increments the start value of `i = 0` by one. Eventually, the condition being checked against `i < 10` will become false and end the loop.

Beneath this part of the code are two other for-loops that have the purpose of printing the contents of both of those lists to the terminal. Notice that in C++, unlike python, that there are no immediate functions to print out the contents of an array. This is why these other functions are written. In the end, you will see that both arrays have the same contents as we would expect from our program. 

Now, let's take a look at `increment.cpp`. The purpose of this function is to print out the contents of the array. However, notice this time that there is something interesting happening in the for-loop.

```cpp
int v[10] = {0,1,2,3,4,5,6,7,8,9};
for (int& x:v) {
        cout << x << ", ";
        x++;
    }
```
In this case, the for-loop is looking at each entry in the integer list `v` and temporarily taking its value into the integer `x`. Because of this, when we `cout << x`, we get that instance of `x`  printed out to the screen. This is done with the `(int& x:v)` part in our code. This strategy will not work with strings or other objects because `x++` won't necessarilly make an integer that the for-loop needs. 

Finally, let's see how we can work with an array of strings instead of an array of integers. Let's take a look at `string_array.cpp`.

```cpp
int main () {

    string v[2] = {"yes","no"};
    for (int i = 0; i < std::size(v) ; i++) {
        cout << v[i] << endl;
    }
    return 0;
}
```
Notice now that we declare an array of two strings when we say `string v[2]`. The for-loop should look familiar, except this time instead of explicitly telling the for-loop how long this array is, we're using the standard library function `std::size()` to find out the length of that list for us. 

Just as you would expect, we can index through the list using `v[i]` to output that respective entry of our array. You'll notice that this is done very similarly to how we worked with integers earlier!

If this runs properly, we'll have each string contained in the array printed out to the terminal.

## 📊 Data Structures <a name = 'structures'></a>
*The code for this part can be seen in* `structures.cpp`

Now let's put what we know to use and try to recreate parts of the `<vector>` library that we might include in a program in the future. This will give us an insight of how to create a library or a personal data structure later on.

Let's take at the code in `structures.cpp`:

You'll notice that we started off by creating our `cvector` data structure by declaring:
```cpp
struct cvector {
    int sz;
    double* elem;
};
```
**Take care that after you declare a structure that the final bracket has to be followed by a semicolon.**

 Notice that in this structure that we have declared the two objects that it should keep track of: `int sz` and `double* elem`. We want for our data structure to contain information on the size of the vector in the integer `sz` and the elements of that vector in `double* elem`. 

In the case of `double* elem`, the utility of using the pointer `*` is that we want for this variable `elem` to refer to other objects created by our code. The pointer makes sure that when we try to access `elem` that we will be accessing the object that it points to. In our case, it will access a double in the `v.elem` array. We'll see more of this at work later.

Now, let's take a look at the next block of code below:
```cpp
void cvector_init(cvector& v, int s) {
    v.elem = new double[s];
    v.sz = s;
}
```
For this block of code, we are making a function for the cvector class to use upon initialization. In our case this function will return nothing because we said `void cvector_init`, but it will do the special job of storing the above values into our cvector data structure. You can see this in the line `v.sz = s`. 

You might also notice that the line for `elem` is a little more complicated. The reason for this is because when assigning the `v.elem` part for our instance of our cvector `v`, this line of code will create memory for a new double in the `v.elem` array. 

This is important because C++ needs to assign memory for this spot from the computer's dynamic memory, or *heap*. Unlike python, you have to explicitly assign memory as it may be needed. 

Now let's take a look at the function `rs` in the code.
```cpp
double rs(int s) {
    double sum; cvector v;
    cvector_init(v,s);

    for (int i=0; i!=s; i++) {
        cin >> v.elem[i];
    }
    for (int i=0; i!=s; i++) {
        sum += v.elem[i];
    }
    return sum;
}
```
This part of our code will create empty instances of the double `sum` and of the cvector `v`. Then, it will use the given integer s and run both s and the cvector through `cvector_init`. Upon doing this, it will ask for numbers from the standard input with `cin` and push those values into the `v.elem` (remember, that this array is of size s) for each value requested. 

Finally, after this is done, it will take all of the values stored in the `v.elem` array and sum over them to give you the double `sum`.

The last part of our code should be pretty intuitive! Our `main ()` function asks the user for a number of inputs per line with `rs(entries)`. Here, `entries` is a number that I arbitrarily made 3 so that `v.elem` only needs 3 elements. 

If you run the code as is and type 3 numbers as requested, you should get the sum of those numbers back.

# 🎒 Classes <a name = 'class'></a>

Just as you can define data structures with C++, you can also define a `class` object. These objects allow you to create methods within them that are both public and private for a user to access. A `public` method is accessible to a user whereas a `private` method is only accessible through a user-interface. Let's take a look at the code below. A more in-depth look is  beneath the code block.

```cpp
class cvector {
    public:
        cvector(int s): 
            elem{ new double[s] }, 
            sz{s} {}
        double& operator[](int i) {
            return elem[i];
        }
        int size() {
            return sz;
        }
    private:
        double* elem;
        int sz;
};
```

Notice right off the bat that there are two main sections of the `cvector` class we made. You can see that there are the `public` and `private` sections of the class. 

Consequently, a user won't be able to neccesarrily access or manipulate the `elem` or `sz` object, but the `public` part is allowed to access them freely. 

Let's take a look at the public part first. 

```cpp
public:
    cvector(int s):
        elem { new double [s] },
        sz{s} {}
```
You might notice that the `public` section will use an integer `s`, and it will use it to allocate new memory from the heap for an array of doubles of length `s`. 

It will also create an object `sz` to store the vector's size `s`. Notice that the brackets near the line `sz{s} {}` don't have anything inside of them. That's because this method's only job is to store the vector's size. 

Now, let's look at the next part:
```cpp
double& operator[](int i) {
    return elem[i]
}
int size() {
    return sz;
 }
```

Now this part will define an operator for the vector class. Here, we are definining an operator `[]` that will take some integer `i` and use it to return the element `i` stored in the `elem` array. You might notice that we want it to return the double stored at the address of the double at elem[i]. Later we'll see that this address is called to bring up it's double element. 

 Now, let's look at the final part where:
 
 ```cpp
private:
    double* elem;
    int sz;
 ```

 Notice that this part will call the values stored at the addresses of the `elem` array. Then `int sz` will store the size of the array. 

 We can put this new class to the test by seeing how it handles the test of summing all of the elements within it. We can do this with almost the exact same code that we saw in `structures.cpp`. Look below:

```cpp
int main () {
    int entries = 3; double sum;
    cout << "Please input " << entries << " entries line by line to get their sum." << endl;
    sum = vrs(entries);
    cout << "Sum: " << sum << endl;
    return 0;
}
```

Notice that much like in the last part, I arbitrarily assigned an integer called `entries` and set it to 3. Then freed space for the sum of lthe vector elements. 

Then you can see that we are using a similar rs(entries) function to accomplish getting the vector sum. The code for `vrs` is below.

```cpp
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
```

You can see that indexing works very similarly to an array in our new class and that we can sum over them as we did before!




---
*__Note__: This repository is in active development. Any comments or additions are completely welcome! Feel free to report an [issue](https://github.com/isoleph/cpp_crash/issues) or submit a [pull request](https://github.com/isoleph/cpp_crash/pulls).*

