//
//  Interpreter.cpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/26/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include <cmath>
#include "Interpreter.hpp"

double Interpreter::evaluate(Node* node) {
    if (BinaryOpNode* result = dynamic_cast<BinaryOpNode*>(node)) {
        switch (result->op) {
            case TokenType::plus: return evaluate(result->lhs.get()) + evaluate(result->rhs.get());
            case TokenType::hyphen: return evaluate(result->lhs.get()) - evaluate(result->rhs.get());
            case TokenType::slash: return evaluate(result->lhs.get()) / evaluate(result->rhs.get());
            case TokenType::star: return evaluate(result->lhs.get()) * evaluate(result->rhs.get());
            case TokenType::mod: return (int)evaluate(result->lhs.get()) % (int)evaluate(result->rhs.get());
            case TokenType::exponent: return pow(evaluate(result->lhs.get()), evaluate(result->rhs.get()));
            default: break;
        }
    }
    
    if (NumberNode* result = dynamic_cast<NumberNode*>(node)) {
        return result->digit;
    }
    
    if (UnaryNode* result = dynamic_cast<UnaryNode*>(node)) {
        if (result->symbol == TokenType::hyphen) return -(evaluate(result->expr.get()));
        else return evaluate(result->expr.get());
    }
    
    throw "Unexpected operation";
}
