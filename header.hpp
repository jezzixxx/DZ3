//
// Created by Kamilla IU8-13
//

#ifndef UNTITLED1_HEADER_HPP
#define UNTITLED1_HEADER_HPP

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <vector>

struct Element {
    char type;
    double value;
};

bool count(std::stack<Element> &nums, std::stack<Element> &oper, Element &init) {
    double y = nums.top().value;
    double x;
    nums.pop();
    double result;
    switch (oper.top().type) {
        case '+':
            x = nums.top().value;
            nums.pop();
            result = x + y;
            break;
        case '-':
            x = nums.top().value;
            nums.pop();
            result = x - y;
            break;
        case '*':
            x = nums.top().value;
            nums.pop();
            result = x * y;
            break;
        case '/':
            x = nums.top().value;
            nums.pop();
            if (y != 0) {
                result = x / y;
            } else {
                std::cerr << "attempt to devide by 0";
                return false;
            }
            break;
        case '^':
            x = nums.top().value;
            nums.pop();
            result = pow(x, y);
            break;
        case 's':
            result = round(sin(y)*10000000)/10000000;
            break;
        case 'c':
            result = round(cos(y)*10000000)/10000000;
            break;
        case 'g':
            if (round(sin(y)*10000000)/10000000 != 0) {
                result = round(cos(y)*10000000)/10000000 / (round(sin(y)*10000000)/10000000);
            } else {
                std::cerr << "ctg is not exist";
                return false;
            }
            break;
        case 't':
            if (round(cos(y)*10000000)/10000000 != 0) {
                result = round(sin(y)*10000000)/10000000 / (round(cos(y)*10000000)/10000000);
            } else {
                std::cerr << "tg is not exist";
                return false;
            }
            break;
        case 'e':
            result = exp(y);
            break;
        default:
            std::cerr << "unidentified operation";
            return false;
    }
    init.type = '0';
    init.value = result;
    nums.push(init);
    oper.pop();
    return true;
}

unsigned priority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') {
        return 3;
    } else if (ch == 's' || ch == 'c' || ch == 't' || ch == 'g' || ch == 'e') {
        return 4;
    } else return 0;
}

const double Pi = acos(-1);

#endif //UNTITLED1_HEADER_HPP
