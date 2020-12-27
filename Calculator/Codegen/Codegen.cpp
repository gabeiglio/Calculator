//
//  Codegen.cpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 12/26/20.
//  Copyright © 2020 Gabriel Igliozzi. All rights reserved.
//

#include "Codegen.hpp"

void Chunk::write(OpCode opcode) {
    if (capacity > count + 1) {
        code[count] = &opcode;
        count++;
    }
}

void Chunk::writeConstant(std::unique_ptr<Node>& node) {
    constant[count] = node.get();
}

void Codegen::generate() {
    if (NumberNode* result = dynamic_cast<NumberNode*>(node.get())) {
        chunk->writeConstant(node);
        chunk->write(OpCode::constant);
    }
    
    if (UnaryNode* result = dynamic_cast<UnaryNode*>(node.get())) {
        chunk->write(OpCode::negate);
        chunk->writeConstant(node);
        chunk->write(OpCode::constant);
    }
    
    if (BinaryOpNode* result = dynamic_cast<BinaryOpNode*>(node.get())) {
        
    }
}
