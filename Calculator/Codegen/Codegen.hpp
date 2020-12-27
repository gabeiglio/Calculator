//
//  Codegen.hpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 12/26/20.
//  Copyright © 2020 Gabriel Igliozzi. All rights reserved.
//

#ifndef Codegen_hpp
#define Codegen_hpp

#include "Node.hpp"

enum class OpCode {
    constant,
    add,
    substract,
    divide,
    multiply,
    negate
};

class Chunk {
    int count = 0;
    int capacity = 100;
        
public:
    OpCode* code[100];
    Node* constant[100];
    
    Chunk() {}
    ~Chunk() {}
    
    
    void write(OpCode code);
    void writeConstant(std::unique_ptr<Node>& node);
};

class Codegen {
    Chunk* chunk;
    std::unique_ptr<Node> node;
    
public:
    Codegen(std::unique_ptr<Node>& node, Chunk* code): node(std::move(node)), chunk(code) {}
    void generate();
};



#endif /* Codegen_hpp */
