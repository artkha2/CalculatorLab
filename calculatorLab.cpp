#include <string>  // for strings
#include <iostream>  // for console input/output
#include <stack>  // for stacks
#include <sstream>  // for string stream

using namespace std;

class Calculator {
    // Check if string is an operator
    bool is_operator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
        // Assume no other operators are used
    }

    // Evaluate a postfix exresssion
    double eval_postfix(stringstream& expr) {
        stack<double> out_stack;
        string token;

        while (expr >> token) {
            // Assume tokens are space-separated. Garbage in = garbage out
            if (is_operator(token)) {
                // Assume there are at least 2 operands in the stack when an operator is encountered
                double num2 = out_stack.top(); out_stack.pop();
                double num1 = out_stack.top(); out_stack.pop();

                if (token == "+") {
                    out_stack.push(num1 + num2);
                }
                else if (token == "-") {
                    out_stack.push(num1 - num2);
                }
                else if (token == "*") {
                    out_stack.push(num1 * num2);
                }
                else if (token == "/") {
                    // Assume num2 != 0
                    out_stack.push(num1 / num2);
                }
            }
            else {
                // Assume token is a valid positive number if it's not an operator
                out_stack.push(stod(token));  // Convert token to double
            }
        }
        return out_stack.top();  // Assume out_stack has only 1 element left
    }

    // Get numeric representation of operator's precedence. Higher precedence = higher number
    int get_precedence(const string& oper){
        if(oper == "+" || oper== "-")
            return 1;
        else if(oper == "*" || oper == "/")
            return 2;
        
        return 0; // Assume it's parentheses, ignore their precedence. They are dealt with in a different way
    }

    // Convert infix expressions to postfix using the shunting yard algorithm
    stringstream to_postfix(stringstream& expr){
        stack<string> out_stack;
        stack<string> oper_stack;
        string token;

        while (expr >> token) {
            // Assume space-separated tokens
            if(token == "("){
                oper_stack.push(token);
            }
            else if(token == ")"){
                while(!oper_stack.empty() && oper_stack.top() != "("){
                    // Move all operators until "(" from operator stack to output
                    out_stack.push(oper_stack.top());
                    oper_stack.pop();
                }
                oper_stack.pop();  // remove "("
                // Assume balanced parentheses
            }
            else if (is_operator(token)) {  // arithmetic operator
                while(!oper_stack.empty() && get_precedence(oper_stack.top()) >= get_precedence(token)){
                    // Move all elements with greater or equal precedence from operator stack to output
                    out_stack.push(oper_stack.top());
                    oper_stack.pop();
                }
                oper_stack.push(token);
            }
            else {
                // Assume token is a valid positive number
                out_stack.push(token);
            }
        }

        // Move the remaining elements from operator stack to output
        while(!oper_stack.empty()){
            out_stack.push(oper_stack.top());
            oper_stack.pop();
        }

        stack<string> rev_stack;  // will hold reversed output stack to convert output to a string

        // Reverse order of output so that it can be stored left-to-right in a string
        while(!out_stack.empty()) {
            rev_stack.push(out_stack.top());
            out_stack.pop();
        }

        stringstream out_ss;
        // Insert elements into stringstream in correct order
        while(!rev_stack.empty()) {
            out_ss << rev_stack.top() << " ";
            rev_stack.pop();
        }

        return out_ss;
    }

public:
    // Evaluate an infix expression using the 2 functions above
    double evaluate(const string& input) {
        stringstream infix_expr(input);
        stringstream postfix_expr = to_postfix(infix_expr);
        return eval_postfix(postfix_expr);
    }
};


int main(){
    const string test_cases[] = {
        "2 + 5",                     // 7
        "3 + 6 * 5",                 // 33
        "4 * ( 2 + 3 )",             // 20
        "( 7 + 9 ) / 8",             // 2
        "3 + 4 * 2 / ( 1 - 5 )",     // 1
        "3 / 2 + 4 * 2.35 / ( 1.18 - 5 * 90.1 )",  // 1.48
        "10 + 5 - 3 * 4 / 2",        // 9
        "( 9.5 + 3 ) * 4",           // 50
        "7 - ( 6 + 2 ) * 3",         // -17
        "10 / 2 / 5",                // 1
        "100 / ( 2 * 5 )",           // 10
        "0 / 3"                      // 0
    };

    Calculator calculator;

    for(string input : test_cases)
        cout << calculator.evaluate(input) << endl;
}