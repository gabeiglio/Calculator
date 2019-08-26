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

double evaluate(Node* node) {
    
    if (BinaryOpNode* result = static_cast<BinaryOpNode*>(node)) {
        switch (result->op) {
            case TokenType::plus: return evaluate(result->lhs) + evaluate(result->rhs);
            case TokenType::hyphen: return evaluate(result->lhs) - evaluate(result->rhs);
            case TokenType::slash: return evaluate(result->lhs) / evaluate(result->rhs);
            case TokenType::star: return evaluate(result->lhs) * evaluate(result->rhs);
            default: break;
        }
    }
    
    if (NumberNode* result = static_cast<NumberNode*>(node)) {
        return result->digit;
    }
    if (UnaryNode* result = static_cast<UnaryNode*>(node)) {
        if (result->symbol == TokenType::hyphen) return -(evaluate(result->expr));
        else return evaluate(result->expr);
    }
    
    throw "Unexpected operation";
}

int main(int argc, const char * argv[]) {
    std::string data = "13 - 12";
    
    std::vector<Token> tokens = Lexer(data).tokenize();
    Node* node = Parser(tokens).parse();
    std::cout << evaluate(node) << std::endl;
}
