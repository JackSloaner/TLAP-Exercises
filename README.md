# TLAP-Exercises
## Description
This repository contains all the practice questions I've completed while reading the book "Think Like a Programmer: An Introduction to Creative Problem Solving" by V. Anton Spraul. At the end of each of his chapters, all of which focus on one of what the author believes are core concepts in modern programming, he includes a set of practice quesions to help the reader apply the methods he presents in the chapter. This helps the reader internalize the concepts at hand by having them flesh out each individual idea themselves. By solving these questions, I was able to apply and deepen my knowledge of various programming abstractions, including but not limited to:
- Object Oriented programming 
- Recursion
- Pointers and dynamic memory
- Complex data types/data structures (linked lists, different variations of binary trees, hash tables, lists, etc.)
- Algorithms
- Libraries
- Design patterns (builders, iterators, strategy/policy, etc.)

Completing these exercises has been incredibly helpful in my learning journey, not only in terms of learning new programming concepts but also in the fundamental way in which I approach problems in general.
### Side Note
You may notice that I committed all of the C++ programs in one commit. This is because I completed all of these exercises a few months before deciding to make a github repository to document them.


## How to use
1. Clone this repository onto your local machine
2. To run the programs as they are already set up in `int main()`, simply navigate to the chosen program's file, in which you will find a pre-compiled executable file, enter `./{filename}` into the command line to run the program
3. (optional) If you want to make changes to the code in `int main()` to test out the different functions in a given program, you will first have to install a C++ compiler to compile and execute your new code. Here are the steps for the different operating systems:
- Windows: Install the latest supported release [here](https://sourceforge.net/projects/mingw/).
- Mac: Enter the following line into your command line to download Xcode command line tools: `xcode-select --install`.
- Linux: Follow outlined steps in this [article](https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/).
4. (optional) Once you have dowloaded the compiler, navigate to the program you would like to edit. Once you have made your changes, enter `g++ {filename.cpp}` into the command line to compile code. To run your new code, enter `./a.out` into the command line.

## Highlighted Programs
These are the programs I believe best display my ability to apply the techniques taught in this book. The programs are in ascending order of difficulty.
1. [6.4: appearance_counter](#64-appearance_counter)
2. [2.6: to_any](#26-to_any)
3. [4.4: mode_linked_list](#44-mode_linked_list)
4. [5.3: string_class](#53-string_class)
5. [7.2: hash_table](#72-hash_table)
6. [7.3: first_student](#73-first_student)
7. [6.6: binary_search_tree](#66-binary_search_tree)
8. [7.4: dynamic_features](#74-dynamic_features)
9. [6.7: binary_tree_statistics](#67-binary_tree_statistics)

## Table of Contents
**[Chapter 2: Puzzles](#chapter-2-puzzles)**
- [2.1: upside_down_triangle](#21-upside_down_triangle)
- [2.2: diamond](#22-diamond)
- [2.3: weird-x](#23-weird_x)
- [2.4: box](#24-box)
- [2.5: to_binary](#25-to_binary)
- [2.6: to_any](#26-to_any)

<!--New Chapter-->

**[Chapter 3: Arrays](#chapter-3-arrays)**
- [3.1: student_quartiles](#31-student_quartiles)
- [3.2: median](#32-median)
- [3.3: mode](#33-mode)

<!--New Chapter-->

**[Chapter 4: Pointers](#chapter-4-pointers)**
- [4.1: dynamically_allocated_strings](#41-dynamically_allocated_strings)
- [4.2: linked_list_numbers](#42-linked_list_numbers)
- [4.3: linked_list_strings](#43-linked_list_strings)
- [4.4: mode_linked_list](#44-mode_linked_list)

<!--New Chapter-->

**[Chapter 5: Classes](#chapter-5-classes)**
- [5.1: automobile_class](#51-automobile_class)
- [5.2: student_collection](#52-student_collection)
- [5.3: string_class](#53-string_class)

<!--New Chapter-->

**[Chapter 6: Recursion](#chapter-6-recursion)**
- [6.0: binary_tree_template](#60-binary_tree_template)
- [6.1: largest_array_value](#61-largest_array_value)
- [6.2: pos_num_sum](#62-pos_num_sum)
- [6.3: binary_string](#63-binary_string)
- [6.4: appearance_counter](#64-appearance_counter)
- [6.5: heap_binary_tree](#65-heap_binary_tree)
- [6.6: binary_search_tree](#66-binary_search_tree)
- [6.7: binary_tree_statistics](#67-binary_tree_statistics)

<!--New Chapter-->

**[Chapter 7: Code Reuse](#chapter-7-code-reuse)**
- [7.1: list_students](#71-list_students)
- [7.2: hash_table](#72-hash_table)
- [7.3: first_student](#73-first_student)
- [7.4: dynamic_features](#74-dynamic_features)


## Chapter 2: Puzzles
### 2.1: upside_down_triangle
**Question in the book:** **Using only single-character output statements that output a hash mark, a space, or an end of line, write a program that produces the following shape: {Depiction of an upside down triangle}.** <br>‎<br>
**Program description:** <br>
- Print an upside down triangle in the shell using hashes and spaces
- Print the shape in variable size (i.e. `triangle(5)` is one hash taller and two hashes wider than `triangle(4)` since it is a dually symmetrical shape. The rest of the shape is adjusted accordingly.)
### 2.2: diamond
**Question in the book:** **Using only single-character output statements that output a hash mark, a space, or an end of line, write a program that produces the following shape: {Deptiction of a diamond shape}.** <br>‎<br>
**Program description:** <br>
- Print a diamond in the shell using hashes and spaces 
- Print the shape in variable size (i.e. `diamond(5)` is two hashes taller and two hashes wider than `diamond(4)` since it is a dually symmetrical shape. The rest of the shape is adjusted accordingly.)
### 2.3: weird_x
**Question in the book:** **Using only single-character output statements that output a hash mark, a space, or an end of line, write a program that produces the following shape: {Depiction of an elongated "X"}.** <br>‎<br>
**Program description:** <br>
- Print an elongated X in the shell using hashes and spaces, mimicing the shape from the book
- Print the shape in variable size (i.e. `x(5)` is two hashes taller and two hashes wider than `x(4)` since it is a dually symmetrical shape. The rest of the shape is adjusted accordingly.)
- Use timer library to make the X appear to grow in the shell, printing a slightly larger X each time 0.1 seconds passes
### 2.4: box
**Question in the book:** **Design your own: Think up your own symetrical pattern of hash marks, and see whether you can write a program to produce it that follows the shape's rule.**<br>‎<br>
**Program description:** <br>
- Print `length` * `length` box of hashes in the shell, with an X of hashes crossing through the middle of the box
- Print the shape in variable size (i.e. `box(5)` is one hash taller and one hash wider than `box(4)`. The rest of the shape is adjusted accordingly.)
- Use timer library to make the box appear to grow in the shell, printing a slightly larger box each time 0.1 seconds passes.
- Adapt algorithm to deal with even and odd values of length slightly differently
### 2.5: to_binary
**Question in the book:** **If you've learned about binary numbers and how to convert from decimal to binary and the reverse, try writing programs to do those conversions with unlimited length numbers (but you can assume the numbers are small enough to be stored into a standard C++ `int`).**<br>‎<br>
**Program description:** <br>
- Convert any integer (up to `__INT_MAX__`) number to binary (base 2). The rightmost unit is `2^0`, then going left, the digits follow as: `2^1`, `2^2`, `2^3`, etc.
### 2.6: to_any 
**Question in the book:** **Want an extra challenge? Generalize the code for the previous exercise to make a program that converts from any number base-16 or less to any other number base.**<br>‎<br>
**Program description:** <br>
- Convert any number in any base to its representation of the number in any other base `b`, where the smallest denomination (rightmost unit) represents `number` * `b^0` and the largest is `number` * `b^(max - 1)` (leftmost unit)
- `max` is calculated in relation to the base and the maximum integer value (`__INT_MAX__`)

## Chapter 3: Arrays
### 3.1: student_quartiles
**Question in the book:** **Write a program that processes an array of student objects and determines the grade quartiles--that is, the grade one would need to score as well as or better than 25% of the students, 50% of the students, and 75% of the students.**<br>‎<br>
**Program description:** <br>
- Find the quartiles of a set of student grades
- Include `fstream` library to read in `.csv` file
### 3.2: median
**Question in the book:** **Rewrite the code that finds the agent with the best monthly sales average so that it finds the agent with the highest median sales. As stated earlier, the median of a set of values is the "one in the middle," ...[explanation of the median].**<br>‎<br>
**Program description:** <br>
- Find the highest median out of 3 agents' sales data over 12 months
- User inputs data
- Use `qsort()` to sort monthly sales from fiscal year
- Return middle number in sequence or the mean of 2 middle numbers
### 3.3: mode
**Question in the book:** **Write a program that is given an array of integers and determines the mode, which is the number that appears most frequently in the array.** <br>‎<br>
**Program description:** <br>
- Count the number of times each number appears in a sequence of numbers, and returns the mode(s) (the number(s) that appear the most frequently) in the form of a `vector`
- Use `vector` histogram to keep track of the numbers that appear in the sequence and the amount of times they've appeared

## Chapter 4: Pointers
### 4.1: dynamically_allocated_strings
**Questions in the book:** (For context, the original string program was just made from coding along with the examples in the chapter, modifications were made while doing the practice questions). <br>**q1: For our dynamically allocated strings, create a function `substring` that takes three parameters: An `arrayString`, a starting position integer, and an integer length of characters. The function returns a pointer to a new dynamically allocated string array. This string array contains the characters in the original string, starting at the specified position, for the specified length. The original string is unaffected by the operation.** <br> **q2: For our dynamically allocated strings, create a function `replaceString` that takes three paramaters, each of type `arrayString`: source, target, and replaceText. For example, if source points to an array containing `abcdabee`, target points to `ab`, and `replaceText` points to `xyz`, then when the function ends, source should point to an array containing `xyzdxyzee`.**<br>‎<br>
**Program description:** <br>
- Store strings as a struct containing a pointer to the string (array of characters), and its length
- Highlighted functions:
  - `readFile`: Read in a string from a file
  - `deleteStr`: Delete a string
  - `printString`: Print a string
  - `subString`: Get a substring
  - `replaceText`: Replace a substring with another string
  - `deleteList`: Delete position lists after use to free up memory
### 4.2: linked_list_numbers
**Questions in the book:**<br> **q1: Imagine a linked list where instead of the node storing a character, the node stores a digit: an int in the range 0-9. We could represent positive numbers of any size using such a linked list; the number 149, for example would be a linked list in which the first node stores a 1, the second a 4, and the third a 9. Write a function `intToList` that takes an integer value and produces a linked list of this sort.**<br>
**q2: For the digit list of the previous exercise, write a function that takes two such lists and produces a new list representing their sum.**<br>‎<br>
**Program description:** <br>
- Represent numbers with linked lists, each node representing a digit of the number, ascending in order of magnitude
- Highlighted functions:
  - `sumLists()`: Add two linked list numbers together, returning the sum in the form of linked list
  - `userPrompt`: Get user input
  - `intToList`: Convert int number to linked list
  - `deleteList`: Delete lists after use to free up memory
### 4.3: linked_list_strings
**Question in the book:** **Let's create an implementation for strings that uses a linked list of characters instead of dynamically allocated arrays. So we'll have a linked list where the data payload is a single `char`; this will allow strings to grow without having to re-create the entire string. We'll start by implementing the `append` and `characterAt` functions.** <br>‎<br>
**Program description:** <br>
- Store strings as linked lists of characters
- Highlighted functions:
  - `append`: Append character to string
  - `concat`: Concatenate string to another string
  - `removeChars`: Remove characters from a string given a position and a number of characters to delete
  - `deleteList`: Delete lists after use to free up memory
### 4.4: mode_linked_list
**Question in the book: Take a problem that you already know how to solve using an array but that is limited by the size of the array. Rewrite the code to remove that limitation using pointers.** <br>‎<br>
**Program description:** <br>
- Use linked list to solve limitation caused by arrays when using histogram, eliminating need to use `vector` class
- Find the mode(s) in a linked list of numbers
- Use linked list histogram to keep track of the numbers that appear in the sequence and the amount of times they've appeared
- Highlighted functions:
  - `findMode`: Use reference to linked list of modes, updates to point to the mode(s) of the array
  - `updateHistogram`: Update linked list histogram by either adding new number or incrementing the existing number's count

## Chapter 5: Classes
### 5.1: automobile_class
**Questions in the book: <br>
q1: Let's try implementing a class using the basic framework. Consider a class to store the data for an automobile. We'll have three pieces of data: a manufacturer name and a model name, both strings, and a model year, an integer. Create a class with `get`/`set` methods for each data member.<br>
q2: For our automobile class from the previous exercise, add a support method that returns a complete description of the automobile object as a formatted string, such as, `1957 Chevrolet Impala`. Add a support method that returns the age of the automobile in years.**<br>‎<br>
**Program description:** <br>
- First C++ class, mock automobile information class
- Public methods:
  - `getManufacturer`, `getModel`, `getYear`: "Get"/"Set" methods for data members
  - `getAge`: Get age of the car in years, calculated on method call
  - `getCar`: Get full description of the car
  - `automobile`: Class constructor
### 5.2: student_collection
**Questions in the book: <br>q1: Take the student record functions from Chapter 4 (`addRecord` and `averageRecord`) and use them to create a class representing a collection of student records, as before, making sure to implement all necessary constructors, a destructor, and an overloaded assignment operator.<br>
q2: For the student record class of the previous exercise, add a method `recordRange` that takes a low grade and a high grade as parameters and returns a new collection consisting of the records in that range (the original collection is unaffected). For example, `myCollection.recordRange(75, 80)` would return a collection of all records with grades in the range 75-80 inclusive.**<br>‎<br>
**Program description:** <br>
- Class for a collection of students
- Public methods:
  - `addRecord`: Add a student
  - `averageRecord`: Get the average grade
  - `getStudentWithID`: Get a student by `id`
  - `recordRange`: Get a collection of students within a grade range
  - Overloaded assignment operator, destructor, constructor, and copy constructor
### 5.3: string_class
**Questions in the book:<br>q1: Take the variable length string functions from Chapter 4 (`append`, `concatenate`, `characterAt`) and use them to create a class for variable-length strings, making sure to implement all necessary constructors, a destructor, and an overloaded assignment operator.<br>
q2: For the variable-length string class of the previous exercise, replace the `characterAt` method with an overloaded `[]` operator. For example, if `myString` is an object of our class, then `myString[1]` should return the same result as `myString.characterAt(1)`.**<br>‎<br>
**Program description:** <br>
- Class for strings as linked list of of characters
- Public methods:
  - `appendChar`: Append an extra character
  - `concatenate`: Concatenate another string of the same class
  - `deleteChar`: Delete a certain character out of a string
  - `deleteLastChar`: Delete the last character in the string
  - `characterAt`: Find character at a given index
  - `subStr`: Get substring given a position and a number of characters. 
  - Destructor, copy constructor, overloaded assignment operator and overloaded `[]` operator
- Highlighted private methods:
  - `deepCopy`: Create a deep copy of `stringC` object

## Chapter 6: Recursion
### 6.0: binary_tree_template
**Not a question in the book. I made the decision to make a template for a binary tree class.** <br>‎<br>
**Program description:** <br>
- Template for basic binary tree
- Public methods: 
  - `makeNewTree`: Make a new tree of random numbers given amount of levels 
  - `printTree`: Print the tree 
  - `insertNum`: Insert a number
  - Overloaded assignment operator, destructor, and copy constructor
### 6.1: largest_array_value
**Not a practice question; just coding along with one of the examples from the chapter.** <br>‎<br>
**Program description:** <br>
- Find largest number in an array recursively
### 6.2: pos_num_sum
**Questions in the book: Write a function to compute the sum of just the positive numbers in an array of integers. First, solve the problem using iteration. Then, using the technique shown in the chapter, convert your iterative function to a recursive function.**<br>‎<br>
**Program description:** <br>
- Recursively add all of the positive numbers in a linked list, return sum.
### 6.3: binary_string
**Questions in the book: <br>
q1: Consider an array representing a binary string, where every element's data value is `0` or `1`. Write a `bool` function to determine whether the binary string has odd parity (an odd number of 1 bits), or even parity (an even number of 1 bits). Solve the problem first using iteration, then recursion. <br>
q2: Solve exercise \[`q1`] again, using a linked list instead of an array.**<br>‎<br>
**Program description:** <br>
#### binary_string (array)
- Store string of `boolean` values in an array, return true if there are an even number of true values, false otherwise
- Done recursively and iteratively
#### binary_string (linked list)
- Store string of `boolean` values in a linked list, return true if there are an even number of true values, false otherwise
- Done recursively
### 6.4: appearance_counter
**Questions in the book: <br>
q1: Write a function that is passed an array of integers and a `target` number and returns the number of occurrences of the `target` in the array. Solve the problem first using iteration, then recursion. <br>
q2: Solve exercise \[`q1`] again, using a linked list instead of an array.** <br>‎<br>
**Program description:** <br>
#### appearance_counter (array)
- Count the amount of times a target number appears in an array
- Done recursively and iteratively
#### appearance_counter (linked list)
- Count the amount of times a target number appears in a linked list
- Done recursively
### 6.5: heap_binary_tree
**Question in the book: Some words in programming have more than one common meaning. In `Chapter 4`, we learned about the `heap`, from which we get memory allocated with `new`. The term `heap` also describes a binary tree in which each node value is higher than any in the left or right subtree. Write a recursive function to determine whether a binary tree is a `heap`.** <br>‎<br>
**Program description:** <br>
- Binary Tree Heap program
- Highlighted functions:
  - `isHeap`: Check if a tree is a heap
  - `makeHeap`: Make a heap
  - `deleteTree`: Delete tree after use to free up memory
### 6.6: binary_search_tree
**Question in the book: a `binary search tree` is a binary tree in which each node value is greater than any value in that node's left subtree but less than any value in the node's right subtree. Write a recursive function to determine whether a binary tree is a `binary search tree`.** <br>‎<br>
**Program description:** <br>
- Class for binary search tree
- Public methods:
  - `makeBS`: Make a basic binary search tree given number of levels
  - `isBS`: Verify if tree is in fact binary search using recursion
  - `makeRandTree`: Make random tree given a number levels to test `isBS()` (`makeRandTree()`)
  - `insertNum`: Insert any given number into tree at the proper place to maintain binary search \*\***main display of recursion**\*\*
  - `primitivePrint`: Print numbers of the tree in a sequence
  - `printTree`: Print tree visually
  - Base Constructor, Random tree Constructor with given levels, Binary Search Tree constructor with given levels, Destructor
- Higlighted private methods:
  - `insertNum` (private): Helper method for public `inserNum` method. Insert new number and return the updated amount of levels in the tree
  - `newLevel`: Helper method for public `printTree` function. Create list representing the next level of a tree given the `ptrList` of a current level
### 6.7: binary_tree_statistics
**Question in the book: Consider basic statistical questions you can ask for a set of numerical values, such as average, median, mode, and so forth. Attempt to write recursive functions to compute those statistics for a binary tree of integers. Some are easier to write than others. Why?** <br>‎<br>
**Program description:** <br>
- Class for binary tree
- Public methods:
  - `insertNum`: Insert number into next available spot in tree
  - `avgAllNums`: Find the mean of all numbers in the tree
  - `medianAllNums`: Find the median of all numbers in the tree
  - `modeAllNums`: Find the mode(s) of all numbers in the tree. Return pointer to an int array
  - `printModes`: Print modes. Takes pointer to int array as argument
  - `primitivePrint`: Print numbers in tree in sequence
  - `printTree`: Print the tree visually
  - Overloaded assignment operator, Base Constructor, Binary Tree constructor with given levels, Destructor


- **Highlighted Private Method**:
  - `mergeSort`: Sort an array of integers using merge sort, returns a pointer to the sorted array \*\***main display of recursion**\*\*

## Chapter 7: Code Reuse
### 7.1: list_students
**Question in the book: Rewrite our studentCollection functions from Chapter 4 (`addRecord` and `averageRecord`) so that instead of directly implementing a linked list, you use a class from the C++ library.**
- Variant of the studentColletion class that uses imported list class instead of a linked list to store the studentRecord objects
### 7.2: hash_table
**Question in the book: For the problem \[other question], implement a solution by implementing an abstract data type that allows an arbitrary number of items to be stored and individual records to be retrieved based on a key value. A generic term for a structure that can efficiently store and retrieve items based on a key value is a symbol table, and common implementations of the symbol table idea are `hash tables` and `binary search trees`.** <br>‎<br>
**Program description:** <br>
- Hash table template class
- Public methods:
  - `addPair`: Add key-value pairs
  - `get`: Get values by key
  - Constructor and destructor
- Highlighted private methods:
  - `hashFunc`: Hash function
- Include hashNode class as linked list to deal with collisions
### 7.3: first_student
**Questions in the book: <br>
q1 (in chapter): At a particular achool, each class has a designated "first student" who is responsible for maintaining order in the classroom if the teacher has to leave the room. Originally, this title was bestowed upon the student with the highest grade, but now some teachers think the first student should be the student with the greatest seniority, which means the lowest student ID number, as they are assigned sequentially. Another faction of teachers thinks the first student tradition is silly and intends to protest by simply choosing the student whose name appears first in th alphabetical class roll. Our task is to modify the student collection class, adding a method to retrieve the first student from the collection, while accomodating the selection criteria of the various teacher groups. <br>
q2: A complaint offered against the policy/strategy pattern is that it requires exposing some internals of the class, such as types. Modify the "first student" program from earlier in this chapter so that the policy functions are all stored within the class and are chosen by passing a code value (of a new, enumerated type for example), instead of passing the policy function itself.** <br>‎<br>
**Program description:** <br>
- Add on to the `stuCo` class from chapter 5
- Use policy/strategy design pattern to allow the user to specify the sorting policy for the `firstStudent` method
- Public methods: 
  - *All methods from [5.2: student_collection](#52-student_collection)*
  - `setCurrentPolicy`: Set the sorting policy for finding the first student
  - `firstStudent`: Find and return `studentRecord` object of "First student", using the current policy
- Highlighted private methods:
  - `fsHighGrade`, `fsLowStuNum`, `fsAlphabetical`: The first student retrieval methods for the different "teacher policies"
### 7.4: dynamic_features
**Question in the book: Suppose you are working on a project in which a particular `studentRecord` may need to be augmented with one of the following pieces of data: term paper title, year or enrolment, or a bool indicating whether the student is auditing the class. You won't want to include all of these data fields in the base `studentRecord` class, knowing that in most cases they won't be used. Your first thought is to create three subclasses, each having one of the data fields, with names such as `studentRecordTitle`, `studentRecordYear`, and `studentRecordAudit`. Then you are informed that some students will contain two of these additional data fields or perhaps all three. Creating subclasses for each possible variation is impractical. Find a design pattern that addresses this conundrum, and implement a solution.** <br>‎<br>
**Program description:** <br>
- Add on to the studentCollection class from chapter 5
- Store student records in objects (rather than structs) with linked lists containing their attributes (grade, name date of birth, etc.), seperated into types
- Use builder design pattern to create student records with custom attributes
- Public methods for `stuCo` Class:
  - *All methods from [5.2: student_collection](#52-student_collection), modified to fit new attribute structure*
  - Deep copy constructor, `readFile` constructor for creating `studentRecord` objects from `.csv` files, Destructor, and Overloaded assignment operator
- Public methods for `Builder` Class:
  - `addDefaults`: Add default attributes for `studentRecord` (Name, Grade, Student ID)
  - `addName`, `addGrade`, `addID`, `addDOB`, `addIsAudit`, `addPaperTitle`: "Set" methods for all the different possible attributes of `studentRecord`
  - `reset`: Create new `studentRecord` object
  - `deleteRec`: Delete current `studentRecord` object
  - Constructor, Default Attribute Constructor, Destructor
- Public methods for `studentRecord` Class: 
  - `getIntVal`, `getStringVal`, `getBoolVal`: "Get" methods for the different `studentRecord` attribute types.
  - Constructor, Destructor
