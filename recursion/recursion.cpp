#include <iostream>
#include <string>

using std::string;
using std::cout;

// Write two functions that finds the factorial of any number. One should use recursive, the other should just use a for loop
int findFactorialRecursive(int number) {
    int answer = 1; 

    if (number > 0) {
        answer = number * findFactorialRecursive(number-1);   
    }
    return answer;
}

int findFactorialIterative(int number) {
    int answer = number;

    for (int i = number-1; i > 0; i--) {
        answer *= i;
    }

    return answer;
}

// Given a number N return the index value of the Fibonacci sequence, where the sequence is:

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 ...
// the pattern of the sequence is that each value is the sum of the 2 previous values, that means that for N=5 → 2+3

//For example: fibonacciRecursive(6) should return 8

int fibonacciRecursive(int n) {
    if (n < 2) {
        return n;
    } else {
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    }
}

int fibonacciIterative(int n){
    int answer = 0;

    for (int i = 1; i < n-1; i++) {
        answer += i-1 + i-2;
    }

    return answer;
}

//Implement a function that reverses a string using iteration...and then recursion!
string reverseString(string str) {
    
}


//should return: 'yretsam oyoy'

int main() {
    cout << findFactorialRecursive(5) << "\n";
    cout << findFactorialIterative(5) << "\n";
    cout << fibonacciRecursive(9) << "\n";
    cout << fibonacciIterative(6) << "\n";
    cout << reverseString("yoyo mastery") << "\n";
}