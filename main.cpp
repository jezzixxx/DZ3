//
// Created by Kamilla IU8-13
//

#include "header.hpp"

int main() {
    std::stack<Element> nums, oper;
    Element init;
    bool zero = true;
    std::string mode;
    std::cout << "Text 'p' to use const Pi\nText 'exp(1)' to use const e\n";
    std::cout << "Enter the expression:";
    char ch = '0';
    while (ch != '\n') {
        ch = std::cin.peek();
        if ((ch >= '0' && ch <= '9') || ch == '-' && zero) {
            init.type = '0';
            std::cin >> init.value;
            nums.push(init);
            zero = false;
        } else if (ch == 'p') {
            init.type = '0';
            init.value = Pi;
            nums.push(init);
            std::cin.ignore();
        } else if (ch == 's') {
            std::cin.ignore();
            ch = std::cin.peek();
            if (ch == 'i') {
                std::cin.ignore();
                ch = std::cin.peek();
                if (ch == 'n') {
                    init.type = 's';
                    init.value = 0;
                    oper.push(init);
                    std::cin.ignore();
                } else {
                    std::cerr << "unidentified symbol";
                    return 0;
                }
            } else {
                std::cerr << "unidentified symbol";
                return 0;
            }
        } else if (ch == 'c') {
            std::cin.ignore();
            ch = std::cin.peek();
            if (ch == 'o') {
                std::cin.ignore();
                ch = std::cin.peek();
                if (ch == 's') {
                    init.type = 'c';
                    init.value = 0;
                    oper.push(init);
                    std::cin.ignore();
                } else {
                    std::cerr << "unidentified symbol";
                    return 0;
                }
            } else if (ch == 't') {
                std::cin.ignore();
                ch = std::cin.peek();
                if (ch == 'g') {
                    init.type = 'g';
                    init.value = 0;
                    oper.push(init);
                    std::cin.ignore();
                } else {
                    std::cerr << "unidentified symbol";
                    return 0;
                }
            } else {
                std::cerr << "unidentified symbol";
                return 0;
            }
        } else if (ch == 't') {
            std::cin.ignore();
            ch = std::cin.peek();
            if (ch == 'g') {
                init.type = 't';
                init.value = 0;
                oper.push(init);
                std::cin.ignore();
            } else {
                std::cerr << "unidentified symbol";
                return 0;
            }
        } else if (ch == 'e') {
            std::cin.ignore();
            ch = std::cin.peek();
            if (ch == 'x') {
                std::cin.ignore();
                ch = std::cin.peek();
                if (ch == 'p') {
                    init.type = 'e';
                    init.value = 0;
                    oper.push(init);
                    std::cin.ignore();
                } else {
                    std::cerr << "unidentified symbol";
                    return 0;
                }
            } else {
                std::cerr << "unidentified symbol";
                return 0;
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            if (oper.empty() || priority(ch) > priority(oper.top().type)) {
                init.type = ch;
                init.value = 0;
                oper.push(init);
                std::cin.ignore();
            } else if (priority(ch) <= priority(oper.top().type)) {
                count(nums, oper, init);
            }
        } else if (ch == '(') {
            init.type = ch;
            init.value = 0;
            oper.push(init);
            std::cin.ignore();
        } else if (ch == ')') {
            while (oper.top().type != '(') {
                count(nums, oper, init);
            }
            oper.pop();
            std::cin.ignore();
        } else if (ch == ' ' || ch == '\n') {
            std::cin.ignore();
        } else {
            std::cerr << "unidentified symbol";
            return 0;
        }
    }
    while (!oper.empty()) {
        if (!count(nums, oper, init)) {
            return 1;
        }
    }
    std::cout << "=" << nums.top().value;
    return 0;
}
