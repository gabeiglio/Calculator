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
    std::unique_ptr<Node> expr;
    UnaryNode(TokenType symbol, std::unique_ptr<Node>& expr): symbol(symbol), expr(std::move(expr)) {}
};

struct BinaryOpNode: public Node {
    std::unique_ptr<Node> lhs;
    TokenType op;
    std::unique_ptr<Node> rhs;
    BinaryOpNode(std::unique_ptr<Node>& lhs, TokenType op, std::unique_ptr<Node>& rhs): lhs(std::move(lhs)), op(op), rhs(std::move(rhs)) {}
};
