//
//  Parser.cpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/21/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include "Parser.hpp"
#include <iostream>

std::unique_ptr<Node>  Parser::parse() {
    return parseExpressionExpr();
}

std::unique_ptr<Node>  Parser::parseExpressionExpr() {
    std::unique_ptr<Node> lhs = parseFactorExpr();
    
    if (tokens[index].type == TokenType::plus || tokens[index].type == TokenType::hyphen) {
        TokenType type = tokens[index].type;
        index++;
        std::unique_ptr<Node> ptr = parseExpressionExpr();
        return std::unique_ptr<BinaryOpNode> { new BinaryOpNode {lhs, type, ptr} };
    }
    
    return lhs;
}

std::unique_ptr<Node>  Parser::parseFactorExpr() {
   std::unique_ptr<Node> lhs = parseExponentExpr();
    
    if (tokens[index].type == TokenType::star || tokens[index].type == TokenType::slash || tokens[index].type == TokenType::mod) {
        TokenType type = tokens[index].type;
        index++;
        std::unique_ptr<Node> ptr = parseFactorExpr();
        return std::unique_ptr<BinaryOpNode> { new BinaryOpNode {lhs, type, ptr} };
    }
    
    return lhs;
}

std::unique_ptr<Node>  Parser::parseExponentExpr() {
   std::unique_ptr<Node> lhs = parseUnaryExpr();
    
    
    if (tokens[index].type == TokenType::exponent) {
        TokenType type = tokens[index].type;
        index++;
        std::unique_ptr<Node> ptr = parseExponentExpr();
        return std::unique_ptr<BinaryOpNode> { new BinaryOpNode {lhs, type, ptr} };
    }
    
    return lhs;
}

std::unique_ptr<Node>  Parser::parseUnaryExpr() {
    if (tokens[index].type == TokenType::hyphen) {
        TokenType type = tokens[index].type;
        index++;
        std::unique_ptr<Node> expr = parseLiteralExpr();
        return std::unique_ptr<UnaryNode> { new UnaryNode{type, expr} };
    }
    return parseLiteralExpr();
}

std::unique_ptr<Node>  Parser::parseLiteralExpr() {
    
    if (tokens[index].type == TokenType::integerLiteral || tokens[index].type == TokenType::doubleLiteral) {
        double digit = stod(tokens[index].lexeme);
        index++;
        return std::unique_ptr<NumberNode> { new NumberNode{digit} };
    }
    
    if (tokens[index].type == TokenType::openParen) {
        index++;
        std::unique_ptr<Node>  expr = parse();
        if (tokens[index].type != TokenType::closeParen) throw "Expected )";
        index++;
        return expr;
    }
    
    throw "Unexpected character";
}
