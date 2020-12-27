//
//  main.cpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/20/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//

#include <iostream>

#include "Lexer.hpp"
#include "Parser.hpp"
#include "Codegen.hpp"

void Log(Node* node) {
    if (NumberNode* result = dynamic_cast<NumberNode*>(node)) {
        std::cout << result->digit;
    }
        
    if (UnaryNode* result = dynamic_cast<UnaryNode*>(node)) {
        Log(result->expr.get());
    }
    
    if (BinaryOpNode* result = dynamic_cast<BinaryOpNode*>(node)) {
        std::cout << result->op << '\n';
        Log(result->rhs.get());
        std::cout << " ";
        Log(result->lhs.get());
    }
    
}

int main(int argc, const char * argv[]) {
    std::string data;
    
    while (true) {
        std::cout << "> ";
        getline(std::cin, data);
        
        std::vector<Token> tokens = Lexer(data).tokenize();
        std::unique_ptr<Node> node = Parser(tokens).parse();
        
        //Just to visualize the ast
        Log(node.get());
        std::cout << '\n';
        
        //Create chunk to store the bytecode
        Chunk chunk;
        Codegen codegen = Codegen(node, &chunk);
        codegen.generate();
        
        for (auto op: chunk.code) {
            std::cout << op;
        }
    
        
    }
}
