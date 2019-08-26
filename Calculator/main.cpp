//
//  main.cpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/20/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include <iostream>
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Interpreter.hpp"

int main(int argc, const char * argv[]) {
    std::string data = "4 * (12 - 2) / 12";
    
    std::vector<Token> tokens = Lexer(data).tokenize();
    Node* node = Parser(tokens).parse();
    double result = Interpreter().evaluate(node);
    std::cout << result << std::endl;
}
