//
//  Parser.hpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/21/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include <vector>

#include "Token.hpp"
#include "Node.hpp"

#endif /* Parser_hpp */

class Parser {
private:
    std::vector<Token> tokens;
    int index;
    
    Node* parseLiteralExpr();
    Node* parseUnaryExpr();
    Node* parseFactorExpr();
    Node* parseExpressionExpr();
    
public:
    Parser(const std::vector<Token>& tokens): tokens(tokens), index(0) {}
    ~Parser() {}
    
    Node* parse();
};
