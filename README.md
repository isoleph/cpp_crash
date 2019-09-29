# C++ Crash Course 

<div align="center">

<img src=img/cpp.png width = 150> 
  
  [![Status](https://img.shields.io/badge/status-active-success.svg)]()
  [![GitHub Issues](https://img.shields.io/github/issues/isoleph/cpp_crash)](https://github.com/isoleph/cpp_crash/issues)
  [![GitHub Pull Requests](https://img.shields.io/github/issues-pr/isoleph/cpp_crash.svg)](https://github.com/isoleph/cpp_crash/pulls)
  [![License](https://img.shields.io/badge/license-MIT-blue.svg)](/LICENSE)
  [![Tweet](https://img.shields.io/twitter/url/https/shields.io.svg?style=social)](https://twitter.com/risvoi)

</div>

Welcome to the C++ Crash Course! This Crash Course is closely modeled after Bjarne Stroustrup's [*The C++ Programming Language, 4ed*](http://www.stroustrup.com/4th.html). We go over some basic concepts in the C++ programming language, and I'm currently working on some practice projects to put your skills to the test when you feel ready.

Take note that this crash-course does assume some prior programming knowledge, specifically with Python; although I do try to make the writing as inclusive as possible.

Let's get started!

## 📝 Table of Contents

[Part Zero: Getting Started](#part0)
- [A Few Words](#few_words)
- [Installing](#installing)

[Part One: An Introduction](#part1)
- [Hello World](#hello)
- [Basic Functions](#functions)
- [Constants from another File](#constants)
- [Input Variables and Loops](#iandl)
- [Pointers](#pointers)
- [Arrays](#arrays)
- [Structures et al.](#structures)
    - [Data Structures](#structures)
    - [Classes](#class)
    - [Enumerations](#enums)
- [Namespaces](#names)
- [Error Handling](#error)
    - [Static Assertions](#static)

# 0️⃣ Part Zero <a name='part0'></a>

[Part Zero: Getting Started](#part0)
- [A Few Words](#few_words)
- [Installing](#installing)

Welcome to my C++ Guide! I hope that it serves you well whether as a reference guide, a learning material, or both! Before we start, just a few short words in the case that you may not know.

## A Few Words <a name='few_words'></a>

C++, unlike Python, is a [compiled](https://en.wikipedia.org/wiki/Compiled_language) rather than [interpreted](https://en.wikipedia.org/wiki/Interpreted_language) programming language. This means that unlike Python which goes line by line reading and interpreting your code, C++ will compile all of it into machine language. Here's a nice graphic from Upwork that explains the difference between an interpreter and a compiler.

![Upwork](https://content-static.upwork.com/blog/uploads/sites/3/2015/06/10132943/Compiled-vs-Interpreted-Languages-Comparison.png)

In short, saying that C++ is a *compiled language* is is a fancy way of saying that whatever you write in C++ will get translated into machine code that a computer can read. If you've ever heard of the [assembly](https://en.wikipedia.org/wiki/Assembly_language) programming language, assembly is a low-level machine code programming language that C++ can compile into. So instead of having to cumbersomely write in assembly, you can write C++ for both efficiency and ease. Compilers usually have the added benefit of going through your code and making it more efficient. This is one of the advantages of knowing C++!

Interpreted languages like Python, however, will try to execute commands line by line, create subroutines, modify themselves and *then* translate to machine code. You can read more about interpreted vs. compiled languages [here](https://medium.com/@DHGorman/a-crash-course-in-interpreted-vs-compiled-languages-5531978930b6)!

## What does that mean for us though?

If you're familiar with running python through IDLE or through terminal, then you'll know that executing your program is easy by either typing something like `python3 program.py` or by starting the interpreter and importing your program. 

In C++, however, you don't have immediate access to an in-line interpreter (although [ROOT](https://root.cern.ch/) does a great job with their [Cling Interpreter](https://github.com/root-project/cling)). Because C++ isn't interpreted, this means that to execute a program in C++, you'll have to write your program and then *compile* it. This is done with a command to call your compiler, like this in bash:

```bash
g++ -std=c++17 program.cpp -o program
chmod +x program.cpp
./program
```

Let's go line by line. The first line activates a C++ compiler `g++` to translate your code. There are many other compilers available like clang or oracle. But I use the gnu compiler `g++` because it's very popular and flexible.

In the next line, typing in `-std=c++17` tells your compiler which C++ standard/version you used when you wrote your code. 

`program.cpp` is the name of your program. The `-o` flag instructs the compiler on what to output, and then the output is an executable file called `program`. 

Finally to execute the file we make sure that it is executable by typing what you see in line 2 with `chmod +x program.cpp`. This gives the program the executable flag so the computer knows it's a file that can be run.

Finally, we run our file using `./program`!

The end product of this process is creating a [binary executable file](https://en.wikipedia.org/wiki/Binary_file) that your computer knows how to run.

This might seem like a much more convoluted process than just typing `python3 program.py`, but you are completely free to write a custom command that does all of this for you. If you'd like, [check out my dotfiles](http://www.github.com/isoleph/dotfiles) to see what I did!

Now let's find out how to get started on your computer.

## Installing <a name='installing'></a>

If you have a Linux or Windows computer I highly recommend checking out TheChernoProject's setting up tutorials on YouTube. 

I do have a short writeup for what to do for Mac below though since I work in a Mac environment.  

Here are links for [Linux](https://www.youtube.com/watch?v=LKLuvoY6U0I), [Windows](https://www.youtube.com/watch?v=1OsGXuNA5cc), and [Mac](https://www.youtube.com/watch?v=1E_kBSka_ec).

# macOS
Before you do anything, I'm sorry but you __must__ download XCode from the App Store. The terminal and developer features on macOS are super stripped down and don't include essential features that you'll need. 

When you're done installing Xcode, be sure to install the command line tools. This can be done by going to the top screen toolbar and clicking Preferences > Components. In this menu, you'll want to make sure the Command Line Tools box is checked and installed. 

When this process is done, you can double check to see that g++ is properly installed by going to terminal and typing:

```bash
g++ --version
```

Then you should get the version of g++ that you're using back! Remember, when you're done writing your code, be sure to compile it like described above! Good luck!


# 1️⃣ Part One <a name = 'part1'></a>
[Part One: An Introduction](#part1)
- [Hello World](#hello)
- [Basic Functions](#functions)
- [Constants from another File](#constants)
- [Input Variables and Loops](#iandl)
- [Pointers](#pointers)
- [Arrays](#arrays)
- [Structures et al.](#structures)
    - [Data Structures](#structures)
    - [Classes](#class)
    - [Enumerations](#enums)
- [Namespaces](#names)
- [Error Handling](#error)
    - [Static Assertions](#static)
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

Then you might see that `using namespace std;` indicates that we are using the standard library [namespace](#names). If we didn't do this, then later in our code we would have to write out `std::cout` or `std::endl` explicitly. The functions `std::cout` and `std::endl` print out a [string](https://en.wikipedia.org/wiki/String_literal) to the screen and end a line, respectively. 

Bear in mind that the `<<` function pushes the string "Hello World" out to the screen. Likewise the `<< endl` part attaches the endline instance to the end of the "Hello World" string. You can also write `<< '\n'` instead of `<< endl;` but I just do it this way because it looks nicer.  

(You'll see the `<<` work in the opposite way as `>>` when we look at `cin` later)

In our code, you can see that we declare an `int main ()` function at the beginning of our program. This is because in C++, we have to declare what the output of out function must be. So when our program succesfully runs, we have it return 0 to show that it succeeded! Moreover, every program should have a `main()` function so the compiler knows what it should execute when the program runs.

Here's the entirety of our program below:
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

Let's write a very basic function that outputs the square of some number we give that function. Let's take a look at the code where:
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

Then in the case that you want to make a loop run forever, you would start it with `while true`. 
## 📜 Arrays <a name = 'arrays'></a>
[//]: # (refer to array, increment, string_array)
*The code for this part may be found in* `arrays.cpp`, `increment.cpp`, and `string_array.cpp`.

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

# ➡️ Pointers <a name = 'pointers'></a>
Pointers are objects that do as they're named, *they point to another object or the address of another object*

A good way to think of pointers is under two types: `&` and `*`. Here, the ampersand means *the address to* and the star represents *the contents of*. The way I remember it is "andress" which is a horrific portmeantau of the word "address" and "and." 

You must always take care that pointers fulfill their destinies and point to something. When you initiate a pointer, if it doesn't necessarilly refer to anything, be sure to assign it to a null pointer. This is one value that is shared by all pointer types untill otherwise specified.

Also note that the `nullptr` object is a pointer. You can't try to assign it to any other kind of object. 

Let's start by trying to understand the utility of  a pointer. Let's look at the following script:

```cpp
#include <iostream>
using namespace std;

int main () {
    int p = 3; // assign p = 3
    cout << &p << endl; // returns address of p
    cout << *(&p) << endl; // returns contents of address at p
    int* q = &p; // assign pointer q with address of p
    cout << q << endl; // print pointer q
    cout << *q << endl; // print contents of pointer q
    return 0;
}
```

Hopefully this makes sense! Try playing around with the code in `pointer_intro.cpp` until it makes sense. 

*In older code, some null pointers may have the value of 0 or of NULL which is potentially confusing because we don't necessarilly know that the object we are working with then is a pointer.*


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

Just as you can define data structures with C++, you can also define a `class` object. Think of classes as structures, with privacy. This means that classes allow you to create methods within them that can be either public or private for a user to access. A `public` method is accessible to a user whereas a `private` method is only accessible to your code. Let's take a look at the code below. A more in-depth look is  beneath the code block.

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

# 🔢 Enumerations <a name = 'enums'></a>
*The code for this part may be found in* `enums.cpp`

Just as you can make classes in C++, there are also less complicated data structures that are called *enumerations*. Consider the example below. Here we are going to declare two enumeration classes: `color` and `traffic_light`. Each class will store different colors.

```cpp
enum class color {red, blue, green};

enum class traffic_light { green, yellow, red};

// assign these values to col and light
color col = color::red;
traffic_light light = traffic_light::red;
```
See? Using enumerations, you can create a simple data type that stores values that might be necessary. 

In our case, using the declaration `enum class color` instead of `enum color` is a good way of enforcing that we don't mix up our data types. This way, the program won't let us confuse a `color` object and a `traffic_light` object for each other.

Consequently, you'll notice that typing the following commands fail (even though they're both red):

```cpp
color x = traffic_light::red // not a color
traffic_light y = color::red // not a traffic light
```
You'll also notice that if we try to do some funny business like assigning an integer value to these enumerations, then that won't work.

```cpp
int i = color::red; // unacceptable!
color c = 2; // no!
```
Moreover, by default the `enum class` will only offer three operations: assignments, initializations, and comparisons; i.e. a = b, a == b, and/or a > b. 

We can, however, define more operators as we might see fit like below:

```cpp
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
```
The defined operator above allows us to create an increment operator `++i` to change the light into the next color as seen above!

*Note: if you change* `++start` *for* `start++` *, you'll see that the program no longer works. This is because ++start is a 'prefix operator' and start++ is a 'postfix operator.' If we want to use both, then we have to [define both explicitly](http://web.archive.org/web/20141021180738/http://www.parashift.com/c++-faq-lite/increment-pre-post-overloading.html#faq-13.14).*

If you follow `enums.cpp` correctly, you'll notice that I wrote it so that you're updated as the new instances of the `traffic_light` are assigned!

# 🤙  Namespaces <a name ='names'></a>

Just like classes or enumarations, namespaces also exist to prevent you from confusing some functions or declarations from others. Let's try to create a complex numbers namespace below in a custom namespace. 

*The code below does not work; it has a lot of pieces missing and is meant to demonstrate the nature of namespaces. For all intents and purposes, consider this [pseudo-code](http://www.wikipedia.org/wiki/pseudocode).*

```cpp
// create a custom namespace for complex numbers
namespace custom {
    
    // define a custom complex class
    class complex {
        // stuff here and definitons
    };
    complex sqrt(complex);
    // more namepsace stuff here
    int main ();
}

// define the main function for our custom namespace
int custom::main () {
    complex z {1,2}; 
    auto z2 = sqrt(z);
    // print real and imaginary part of complex number below
    std::cout << '{' << z2.real() << ',' << z2.imag() << '}' << std::endl;
    // more definitions as may be needed
    return 0;
};

int main () {
    return custom::main ();
}
```

Notice that by creating the namespace, we can clarify where our functions are coming from. You can see an example of this in the [Hello World!](#hello) lesson. Recall that when you start off a C++ program with `using namespace std;` this means that you won't explicitly have to invoke the `std` namespace by writing things like `std::cout`. 

You'll also notice above that we invoked our own `custom` namespace with declarations like `custom::main`. This is a very handy feature to prevent you from mixing up where functions come from. 

*Note: when you define a function to exist within a namespace, be sure to declare a semicolon after your last bracket. I don't know why, but C++ wants it.*

# ⚠️  Error Handling <a name='error'></a>

Error Handling and Exceptions become necessities once projects get big enough to always run into errors. Because of this, you need a way to catch errors that might happen and have some recourse for those cases. 

In order to do this, C++ has the `try` and `catch` features. Let's go back to our [custom vector class](#class) for a moment.

Imagine a scenario where a user tries to access an element out of our cvector's range. We need a way to alert the user that they tried to do this and that it doesn't work. This is error handling. 

To implement error handling, we could add the following piece to our custom vector class to catch an out of range error.
```cpp
double& cvector::operator[](int i) {

    // if i < 0 or size()
    if (i < 0 || size() <= i) throw out_of_range {"cvector::operator[]"};
    return elem[i];
}
```
The MVP of this game is `throw`. This function will transfer the control of the function to the *out_of_range* exception handler from the C++ Standard Library. This happens in the case that one of these errors is triggered in our `if` statement. Let's look at the following block of pseudo-code of what will happen when our function `f` encounters an error:

```cpp
void f(cvector& v) {
    // code
    try {
        // function will attempt everything in this block
    }
    catch (out_of_range) {
        // function alerts you something went wrong
        // function will do the following in response to the error
    }
    // more code
}
```

Okay, now let's get a bit crazy. Consider a user that types the following command in using your custom class:

```cpp
cvector v(-42);
```
Your cvector class has no clue about what the heck is happening with this command. In this case, you'll have to make your try-catch statements as explicit as possible to handle these worst-case scenarios. In this case we could instead write:

```cpp
cvector::vector(int s) { 
    if (s < 0) throw length_error{};
    elem = new double[s];
    sz = s;
```

This will now return the standard-library's `length_error` exception to the error and report a non-positive number of elements. 

Or, in the case that the `new` operator finds that there's not enough memory available, it will throw the `std::bad_alloc` exception. Using this feature and `length_error` allows you to access C++'s standard library features for recourse in the case of an error. 

Good practice for error handling is being aware of your *preconditions* Preconditions are things that you assume to be true for your function work. For instance, in our vector function above, we assumed that it would be true that a vector would be initiated with a positive integer number; we also assume that people won't try to access an element beyond the vector's size. 

Once we are aware of those *preconditons*, we can implement good error handling for the cases that violate one of them.

Okay, let's look at this problem again, but this time, let's keep our preconditions in mind. So let's try this block of code:

```cpp
void test () {
    try {
        cvector(-27);
    }
    catch (std::length_error) {
        // what to do in case of negative size error
    }
    catch (std::bad_alloc) {
        // what to do in case of memory exhaustion
    }
}
```

This reports to our user that they tried something that won't work with our custom class! This is good error handling. 

# Static Assertions <a name='static'></a>

At times, an error won't be identified until the program actually starts running. However, using *static assertions*, you can make these errors identifiable when the program compiles in the first place. Consider the code below that checks if these *assertions* are satisfied.

```cpp
void f(double speed) {
    const double c = 299'792'458
    static_assert(speed<c, "Faster than light not allowed");
}
```
You can see that the `static_assert` function will check that these conditions are met before running the program at all and give you the error message if it finds something wrong!

*Coming soon: Part 2: hands-on projects to put the above to practice!*

---
*__Note__: This repository is in active development. Any comments or additions are completely welcome! Feel free to report an [issue](https://github.com/isoleph/cpp_crash/issues) or submit a [pull request](https://github.com/isoleph/cpp_crash/pulls).*

