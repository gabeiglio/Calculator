//
//  Lexer.cpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/20/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include "Lexer.hpp"

Token Lexer::getToken() {
    while (data[index] == ' ')
        index++;
    
    if (isdigit(data[index]))
        return getNumberToken();
    
    switch (data[index]) {
        case '(': index++; return {TokenType::openParen, data.substr(index - 1, 1)};
        case ')': index++; return {TokenType::closeParen, data.substr(index - 1, 1)};
        case '*': index++; return {TokenType::star, data.substr(index - 1, 1)};
        case '+': index++; return {TokenType::plus, data.substr(index - 1, 1)};
        case '-': index++; return {TokenType::hyphen, data.substr(index - 1, 1)};
        case '/': index++; return {TokenType::slash, data.substr(index - 1, 1)};
        default: throw "Unexpected character";
    }
}

Token Lexer::getNumberToken() {
    TokenType type = TokenType::integerLiteral;
    std::string lexeme;
    
    while (isdigit(data[index]) || data[index] == '.') {
        if (data[index] == '.') type = TokenType::doubleLiteral;
        lexeme += data[index];
        index++;
    }
    
    return {type, lexeme};
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    
    while (index < data.size())
        tokens.push_back(getToken());
    
    return tokens;
}
