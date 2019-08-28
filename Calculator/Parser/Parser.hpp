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
    
    std::unique_ptr<Node> parseLiteralExpr();
    std::unique_ptr<Node> parseUnaryExpr();
    std::unique_ptr<Node> parseExponentExpr();
    std::unique_ptr<Node> parseFactorExpr();
    std::unique_ptr<Node> parseExpressionExpr();
    
public:
    Parser(const std::vector<Token>& tokens): tokens(tokens), index(0) {}
    ~Parser() {}
    
    std::unique_ptr<Node> parse();
};
