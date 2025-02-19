# CalculatorLab

## 🔖 Background Information
Generally, when we write mathematical expressions we use what is called “infix notation”. This means that the operators appear in-between the numbers. Check out the following examples of infix notation:

2+5
3+6∗5
4∗(2+3)
(7+9)/8
The problem with infix expressions is that they are difficult for computers to parse and evaluate. It can be tedious to write the code that makes sure that operations are done in a particular order. Parentheses are especially annoying…

Thus, we often use Reverse Polish Notation (a.k.a. postfix notation) when working with computers. In this notation, operators follow the arguments. The examples from above translate to the following postfix expression:

25+
65∗3+
23+4∗
79+8/
Postfix notation can be easily evaluated using a stack data structure. See this link for a nice overview of how it works (Gary Explains, 2024).

Thus, mathematical software will often take infix expressions, convert them to postfix expressions, and then evaluate them. The Shunting Yard Algorithm is often used to convert from infix expressions to postfix expressions (Gary Explains, 2024b).

## 🎯 Problem Statement
Write me a calculator! I want you to implement a console calculator that takes an infix mathematical expression and evaluates it. The strategy we will use is:

Use the Shunting Yard Algorithm to convert the infix expression to a postfix expression.
Evaluate the postfix expression using a stack

## ✅ Acceptance Criteria
Implement a Calculator class which has an evaluate method that takes an infix mathematical expression as a string and returns a double as its output.
Under the hood, the evaluate method will first call some sort of “infix to postfix” method that performs the Shunting Yard Algorithm.
Then, it will call an “evaluate postfix” method that performs the calculations of the postfix expression.

## 📋 Dev Notes
A full implementation of an infix expression calculator which takes into account edge cases and invalid inputs can be thousands of lines long. The goal here is to get a working prototype. Thus, there are a number of items that you do NOT need to worry about:

You do NOT need to implement all of the possible mathematical operators. You only need to include addition, subtraction, multiplication, division, and grouping by parentheses.
You do NOT need to validate if the mathematical expression is valid (e.g. check if the parentheses match). You can assume that the expressions are always valid.
You do NOT need to implement your own stacks / queues from scratch. Feel free to use the stacks and queues from the C++ and Java libraries.
You do NOT need to handle different types of whitespace. Do whatever is easiest for you - for example, you assume that there are no spaces between each character in the string and code accordingly.
You ARE allowed to make assumptions / simplifications when implementing this calculator to get a prototype working. You can tell me what those are when you answer the Thought-Provoking Questions.

## 🖥️ Example Output
I might expect to see the Calculator class used like this:

C++


#include <iostream>
 
int main() {
 Calculator calculator;
 
  // Prints out the number 7
  std::cout << calculator.evaluate("2 + 5");
 
  // Prints out the number 33
  std::cout << calculator.evaluate("3 + 6 * 5");
 
  // Prints out the number 20
  std::cout << calculator.evaluate("4 * (2 + 3)");
 
  // Prints out the number 2
  std::cout << calculator.evaluate("(7 + 9) / 8");
}

## 📝 Thought Provoking Questions
What assumptions / simplifications did you make to get a prototype of the calculator working?
How would you implement exponential expressions in your calculator? Note: you do not have to actually implement them, just tell me what you think you would have to do.
One way to think about certain computer science problems is that you are taking some data and passing it through a series of transformations. For example, you might take some initial input from a user, then mark it as “raw”, then clean up whitespace, then check it for errors, etc. How does this program fit that model of a series of data transformations?

## 💼 Add-Ons For the Portfolio
N/A

## 🔗 Useful Links

Java Project Template

## 📘 Works Cited
Gary Explains. (2024a). What Is Reverse Polish Notation (AKA Postfix Notation)? Why Is It Important?
Gary Explains. (2024b). The Shunting Yard Algorithm Demystified: Transform Expressions Like a Pro!
