//
//  Lexer.hpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/20/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#ifndef Lexer_hpp
#define Lexer_hpp

#include <vector>
#include "Token.hpp"

#endif /* Lexer_hpp */

class Lexer {
private:
    std::string data;
    int index;
    
    Token getNumberToken();
    Token getToken();
    
public:
    Lexer(std::string data);
    ~Lexer() {};
    std::vector<Token> tokenize();
};