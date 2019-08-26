//
//  Parser.cpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/21/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include "Parser.hpp"
#include <iostream>

Node* Parser::parse() {
    return parseExpressionExpr();
}

Node* Parser::parseExpressionExpr() {
    Node* lhs = parseFactorExpr();
    
    if (tokens[index].type == TokenType::plus || tokens[index].type == TokenType::hyphen) {
        TokenType type = tokens[index].type;
        index++;
        return new BinaryOpNode {lhs, type, parseExpressionExpr()};
    }
    
    return lhs;
}

Node* Parser::parseFactorExpr() {
    Node* lhs = parseUnaryExpr();
    
    if (tokens[index].type == TokenType::star || tokens[index].type == TokenType::slash) {
        TokenType type = tokens[index].type;
        index++;
        return new BinaryOpNode {lhs, type, parseFactorExpr()};
    }
    
    return lhs;
}

Node* Parser::parseUnaryExpr() {
    if (tokens[index].type == TokenType::hyphen) {
        TokenType type = tokens[index].type;
            index++;
            Node* expr = parseLiteralExpr();
            return new UnaryNode(type, expr);
    }
    return parseLiteralExpr();
}

Node* Parser::parseLiteralExpr() {
    
    if (tokens[index].type == TokenType::integerLiteral || tokens[index].type == TokenType::doubleLiteral) {
        double digit = stod(tokens[index].lexeme);
        index++;
        return new NumberNode(digit);
    }
    
    if (tokens[index].type == TokenType::openParen) {
        index++;
        Node* expr = parse();
        if (tokens[index].type != TokenType::closeParen) throw "Expected )";
        index++;
        return expr;
    }
    
    throw "Unexpected character";
}
