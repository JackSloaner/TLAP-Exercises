# TLAP-Exercises
## Description
This repository contains all the practice questions I've completed while reading the book "Think Like a Programmer: An Introduction to Creative Problem Solving" by V. Anton Spraul. At the end of each of his chapters, all of which focus on one of what the author believes are core concepts in modern programming, he includes a set of practice quesions to help the reader apply the methods he presents in the chapter. This helps the reader internalize the concepts at hand by having them flesh out each individual idea themselves. By solving these questions, I was able to apply and deepen my knowledge of various programming abstractions, including but not limited to:
- Object Oriented programming 
- Recursion
- Pointers and dynamic memory
- Complex data types/data structures (linked lists, different variations of binary trees, hash tables, lists, etc.)
- Algorithms
- Libraries
- Design patterns (builders, iterators, strategy/policy, etc.).

Completing these exercises has been incredibly helpful in my learning journey, not only in terms of learning new programming concepts but also in the fundamental way in which I approach problems in general.

## Table of Contents
## Chapter 2: Puzzles
### 2.1: upside_down_triangle
- Print an upside down triangle in the shell using hashes and spaces
### 2.2: diamond
- Print a diamond in the shell using hashes and spaces
### 2.3: weird_x
- Print a weird X in the shell using hashes and spaces, mimicing the shape from the book
- Use timer library to make the X appear to grow in the shell, printing a slightly larger X each time 0.1 seconds passes.
### 2.4: box
- Print length * length box of hashes in the shell, with an X of hashes crossing through the middle of the box
- Use timer library to make the box appear to grow in the shell, printing a slightly larger box each time 0.1 seconds passes.
- Adapt algorithm to deal with even and odd values of length slightly differently
### 2.5: to_binary
- Convert any integer (up to `__INT_MAX__`) number to binary (base 2). The rightmost unit is `2^0`, then going left, the digits follow as: `2^1`, `2^2`, `2^3`, etc.
### 2.6: to_any
- Convert any integer number to its closest representation of the number in base `b`, where the smallest denomination (rightmost unit) is `b^0` and the largest is `b^(max - 1)` (leftmost unit)
- `max` is calculated in relation to the base and the maximum integer value (`__INT_MAX__`).

## Chapter 3: Arrays
### 3.1: student_quartiles
- Find the quartiles of a set of student grades.
- Include `fstream` library to read in `.csv` file
### 3.2: median
- Find the highest median out of 3 agents' sales data over 12 months
- User inputs data
- Use `qsort()` to sort monthly sales from fiscal year
- return middle number in sequence or the mean of 2 middle numbers
### 3.3: mode
- Counts the number of times each number appears in a sequence of numbers, and returns the mode(s) (the number(s) that appear the most frequently) in the form of a `vector`.
- Use `vector` histogram to keep track of the numbers that appear in the sequence and the amount of times they've appeared

## Chapter 4: Pointers
### 4.1: dynamically_allocated_strings
- Stores strings as a struct containing a pointer to the string (array of characters), and its length.
- Includes functions for
- Reading in a string from a file
- Deleting a string
- Printing a string
- Getting a substring
- Replacing a substring with another string.
- Deleting lists after use to free up memory
### 4.2: linked_list_numbers
- Numbers are represented with linked lists, each node representing a digit of the number, ascending in order of magnitude
- `sumLists()`Adds two linked list numbers together, and returns the sum in the form of linked list
- Includes functions for:
- Getting user input
- Converting int number to linked list
- Deleting lists after use to free up memory
### 4.3: linked_list_strings
- Stores strings as linked lists of characters. 
- Includes functions for:
- Appending character to string
- Concatenating string to another string
- Removing characters from a string given a position and a number of characters to delete.
- Deleting lists after use to free up memory
### 4.4: mode_linked_list
- Finds the mode(s) in a linked list of numbers
- Use linked list histogram to keep track of the numbers that appear in the sequence and the amount of times they've appeared

## Chapter 5: Classes
### 5.1: automobile_class
- First C++ class, mock automobile information class
### 5.2: student_collection
- Class for a collection of students
- Includes public methods for:
- Adding a student
- Getting the average grade
- Getting a student by `id`
- Getting a collection of students within a grade range
- Also includes overloaded assignment operator, destructor, and copy constructor.
### 5.3: string_class
- Class for strings as linked list of of characters. 
- Includes public methods for:
- Appending an extra character
- Concatenating another string of the same class
- Deleting a certain character out of a string,
- Deleting the last character in the string
- Finding character at a given index
- Getting substrings. 
- Also includes destructor, copy constructor, overloaded assignment operator and overloaded `[]` operator.

## Chapter 6: Recursion
### 6.0: binary_tree_template
- My template for basic binary tree
- Includes methods for: 
- Making a new tree given amount of levels 
- Printing the tree 
- Inserting a number
- Also includes overloaded assignment operator, destructor, and copy constructor.
### 6.1: largest_array_value
- Finds largest number in an array recursively
### 6.2: pos_num_sum
- Recursively add all of the positive numbers in a linked list, return sum
### 6.3: binary_string
#### binary_string (array)
- Store string of `boolean` values in an array, return true if there are an even number of true values, false otherwise
- Done recursively and iteratively
#### binary_string (linked list)
- Store string of `boolean` values in a linked list, return true if there are an even number of true values, false otherwise
- Done recursively
### 6.4: appearance_counter
#### appearance_counter (array)
- Counts the amount of times a target number appears in an array
- Done recursively and iteratively
#### appearance_counter (linked list)
- Counts the amount of times a target number appears in a linked list
- Done recursively.
### 6.5: heap_binary_tree
- Binary Tree Heap program
- Includes functions for:
- Checking if a tree is a heap
- Making a heap
- Printing binary tree
- Making a random binary tree
- Deleting tree after use to free up memory
### 6.6: binary_search_tree
- Class for binary search tree.
- Includes methods for:
- Making a basic binary search tree given number of levels
- verifying if tree is in fact binary search using recursion (`isBinarySearch()`)
- Making random tree given a number levels to test `isBS()` (`makeRandTree()`)
- Inserting any given number into tree at the proper place to maintain binary search \*\***main display of recursion**\*\*
- Printing numbers in tree in a sequence (primitivePrint())
- Printing tree visually (printTree())
- Also includes copy constructor, random tree constructor, and destructor
### 6.7: binary_tree_statistics
Class for binary tree
- Includes methods for:
- Inserting number into next available spot in tree
- Finding the mean of all numbers in the tree
- Finding the median of all numbers in the tree
- Finding the mode(s) of all numbers in the tree
- Print modes
- Print numbers in tree in sequence
- Printing the tree visually
- Overloaded assignment operator
- Constructor and destructor


\*\***Highlighted helper function**\*\*:
- `mergeSort`: Sorts an array of integers using merge sort, returns a pointer to the sorted array

## Chapter 7: Code Reuse
### 7.1: list_students
- Variant of the studentColletion class that uses imported list class instead of a linked list to store the studentRecord objects
### 7.2: hash_table
- My Hash table template class
- Includes methods to:
- Add key-value pairs
- Get values by key
- Hash function
- Constructor and destructor
- Includes hashNode class as linked list to deal with collisions
### 7.3: first_student
Use policy/strategy design pattern to allow the user to specify the sorting policy for the firstStudent() method.
### 7.4: dynamic_features
Add on to the studentCollection class from chapter 5. 
- Student records are now stored in objects with linked lists containing their attributes (grade, name date of birth, etc.), seperated into types. 
- Includes a builder class that can be used to create student records with custom attributes.
- The studentCollection (`stuCo`) class can read in a csv file and create student records from it. Also includes deep copy constructor and overloaded assignment operator.
- Contains modified methods from the original stuCo class that work with the new builder and studentrecord classes, such as: averageRecord, recordRange, as well as the overloaded assignment operator and deep copy constructor.
