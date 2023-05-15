# TLAP-Exercises
## Description
This repository contains all the practice questions I've completed while reading the book "Think Like a Programmer: An Introduction to Creative Problem Solving" by V. Anton Spraul. At the end of each of his chapters, all of which focus on one of what the author believes are core concepts in modern programming, he includes a set of practice quesions to help the reader apply the methods he presents in the chapter. This helps the reader internalize the concepts at hand by having them flesh out each individual idea themselves. By solving these questions, I was able to apply and deepen my knowledge of various programming abstractions, including but not limited to:
- Object Oriented programming 
- Recursion
- Pointers and dynamic memory allocation
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
