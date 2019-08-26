//
//  Token.hpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/20/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//
#pragma once
#ifndef Token_hpp
#define Token_hpp

#include <string>

#endif /* Token_hpp */

typedef enum class TokenType {
    integerLiteral,
    doubleLiteral,
    openParen,
    closeParen,
    star,
    slash,
    hyphen,
    plus
} TokenType;

struct Token {
    TokenType type;
    std::string lexeme;
};
