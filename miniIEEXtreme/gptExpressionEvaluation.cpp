#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '%' || c == '@');
}

int applyOperator(int operand1, int operand2, char op) {
    switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '%':
            return operand1 < operand2 ? operand1 : operand2;;
        case '@':
            return operand1 > operand2 ? operand1 : operand2;
        default:
            return 0;  // Invalid operator
    }
}

int evaluateExpression(const string& expression) {
    stack<int> operandStack;
    stack<char> operatorStack;

    for (char c : expression) {
        if (c == ' ') {
            continue;
        } else if (isdigit(c)) {
            int num = c - '0';
            cout << "num: " << num << "c : "<< c<< endl;
            
            operandStack.push(num);
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                char op = operatorStack.top();
                operatorStack.pop();

                if (operandStack.size() < 2) {
                    return 0;  // Invalid expression
                }

                int operand2 = operandStack.top();
                operandStack.pop();
                int operand1 = operandStack.top();
                operandStack.pop();

                int result = applyOperator(operand1, operand2, op);
                operandStack.push(result);
            }

            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop();
            } else {
                return 0;  // Invalid expression
            }
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && operatorStack.top() != '(' &&
                   ((c == '+' || c == '-') || (c == '*' || c == '%' || c == '@') && operatorStack.top() != '+' &&
                    operatorStack.top() != '-')) {
                char op = operatorStack.top();
                operatorStack.pop();

                if (operandStack.size() < 2) {
                    return 0;  // Invalid expression
                }

                int operand2 = operandStack.top();
                operandStack.pop();
                int operand1 = operandStack.top();
                operandStack.pop();

                int result = applyOperator(operand1, operand2, op);
                // print the result of the operation


                cout << operand1 << " " << op << " " << operand2 << " = " << result << endl;
                operandStack.push(result);
            }

            operatorStack.push(c);
        } else {
            return 0;  // Invalid character
        }
    }

    while (!operatorStack.empty()) {
        if (operandStack.size() < 2) {
            return 0;  // Invalid expression
        }

        char op = operatorStack.top();
        operatorStack.pop();

        int operand2 = operandStack.top();
        operandStack.pop();
        int operand1 = operandStack.top();
        operandStack.pop();

        int result = applyOperator(operand1, operand2, op);
        cout<< "110"<< endl;
        cout << operand1 << " " << op << " " << operand2 << " = " << result << endl;
        operandStack.push(result);
    }

    if (operandStack.size() == 1) {
        return operandStack.top();
    } else {
        return 0;  // Invalid expression
    }
}

int main() {
    // Testing the algorithm with sample expressions
    string expressions[] = {"2+3*4", "(2+3)*4", "5*6-8", "10%2@4", "10%-2@4", "10%-2@4%", "10@-2%4", "0*5", "9/0" ,"2@4%1","4-3-1","(2-2-2)@","()"};
    int numExpressions = sizeof(expressions) / sizeof(expressions[0]);

    for (int i = 0; i < numExpressions; i++) {
        cout << expressions[i] << " -> " <<  evaluateExpression(expressions[i]) << endl;
    }
    // get number of expressions
    // int numExpressions;
    // cin >> numExpressions;

    // // get expressions
    // string expressions[numExpressions];
    // for (int i = 0; i < numExpressions; i++) {
    //     cin >> expressions[i];
    // }

    // // evaluate expressions
    // for (int i = 0; i < numExpressions; i++) {
    //     cout << evaluateExpression(expressions[i]) << endl;
    // }


    


    return 0;
}
