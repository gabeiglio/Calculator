//
//  Node.hpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/21/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//
#pragma once
#ifndef Node_hpp
#define Node_hpp

#include "Token.hpp"

#endif /* Node_hpp */

struct Node {
    virtual ~Node() {};
};

struct NumberNode: public Node {
    double digit;
    NumberNode(double digit): digit(digit) {}
};

struct UnaryNode: public Node {
    TokenType symbol;
    Node* expr;
    UnaryNode(TokenType symbol, Node* expr): symbol(symbol), expr(expr) {}
};

struct BinaryOpNode: public Node {
    Node* lhs;
    TokenType op;
    Node* rhs;
    BinaryOpNode(Node* lhs, TokenType op, Node* rhs): lhs(lhs), op(op), rhs(rhs) {}
};
