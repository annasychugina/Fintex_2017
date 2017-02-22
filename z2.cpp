#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;


int getPriority(char operand) {
    if (operand == '*' || operand == '/') {
        return 4;
    }
    if (operand == '+' || operand == '-') {
        return 3;
    }
    if (operand == '(') {
        return 2;
    }
    if (operand == ')') {
        return 1;
    }
    return -1;
}


int calculate(string outStr);


class Stack {
public:
    Stack();
    
    ~Stack();
    
    void Push(int a);
    int Pop();
    int Top();
    bool IsEmpty() const { return top == -1; }
    
private:
    int *buffer;
    int bufferSize;
    int top;
    
    void grow();
};

int main() {
    char symbol = '0';
    string outStr;
    bool isPreviousSymbolNumber = false;
    Stack stackForCalculate;
    while (scanf("%c", &symbol) == 1) {
        if (symbol == '\n' || symbol == '\0') {
            break;
        }
        if (isdigit(symbol) != 0) {
            isPreviousSymbolNumber = true;
            outStr.push_back(symbol);
        } else {
            
            if (isPreviousSymbolNumber) {
                outStr.push_back(' ');
                isPreviousSymbolNumber = false;
            }
            if (symbol == '(' || symbol == ')') {
                if (symbol == '(') {
                    stackForCalculate.Push(symbol);
                } else {
                    while (stackForCalculate.Pop() != '(') {
                        outStr.push_back(char(stackForCalculate.Top()));
                    }
                    stackForCalculate.Top();
                }
            } else {
                if (stackForCalculate.IsEmpty()) {
                    stackForCalculate.Push(symbol);
                } else {
                    
                    while (!stackForCalculate.IsEmpty()) {
                        if (getPriority(char(stackForCalculate.Pop())) >= getPriority(symbol)) {
                            outStr.push_back(char(stackForCalculate.Top()));
                        } else {
                            break;
                        }
                    }
                    stackForCalculate.Push(symbol);
                }
            }
        }
    }
    while (!stackForCalculate.IsEmpty()) {
        outStr.push_back(char(stackForCalculate.Top()));
    }
    cout << calculate(outStr);
    
    return 0;
}


Stack::Stack() : bufferSize(2), top(-1) {
    buffer = new int[bufferSize];
}


Stack::~Stack() {
    delete[] buffer;
}


void Stack::Push(int a) {
    if (top + 2 > bufferSize) {
        grow();
    }
    
    buffer[++top] = a;
}


int Stack::Pop() {
    assert(top != -1);
    return buffer[top];
}


int Stack::Top() {
    assert(top != -1);
    return buffer[top--];
}


void Stack::grow() {
    int newBufferSize = bufferSize * 2;
    int *tempBuffer = new int[newBufferSize];
    for (int i = 0; i < bufferSize; ++i) {
        tempBuffer[i] = buffer[i];
    }
    delete[] buffer;
    buffer = tempBuffer;
    bufferSize = newBufferSize;
}


int calculate(string outStr) {
    Stack stack;
    bool isNumberFirst = true;
    int tempInt = 0;
    int first = 0;
    int second = 0;
    for (int i = 0; i < outStr.length(); ++i) {
        if (isdigit(outStr[i])) {
            if (isNumberFirst) {
                stack.Push(outStr[i] % 48);
                isNumberFirst = false;
            } else {
                tempInt = stack.Top();
                stack.Push(tempInt * 10 + outStr[i] % 48);
            }
        }
        if (outStr[i] == ' ') {
            isNumberFirst = true;
        }
        if (outStr[i] == '+') {
            
            first = stack.Top();
            second = stack.Top();
            stack.Push(first + second);
        }
        if (outStr[i] == '-') {
            first = stack.Top();
            second = stack.Top();
            stack.Push(second - first);
        }
        if (outStr[i] == '/') {
            first = stack.Top();
            second = stack.Top();
            stack.Push(second / first);
        }
        if (outStr[i] == '*') {
            first = stack.Top();
            second = stack.Top();
            stack.Push(first * second);
        }
    }
    return stack.Top();
}
