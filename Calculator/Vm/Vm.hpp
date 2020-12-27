//
//  Vm.hpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 12/11/20.
//  Copyright © 2020 Gabriel Igliozzi. All rights reserved.
//

#ifndef Vm_hpp
#define Vm_hpp

#include <stdio.h>
#include "Node.hpp"

#define STACK_SIZE 100

class VirtualMachine {
    
    std::unique_ptr<Node> stack[STACK_SIZE]; //The actual stack with a fixed size
    std::unique_ptr<Node> stackTop; //Points to the head of the stack
    std::unique_ptr<Node> ip; //Points to the current instruction to execute
    
public:
    VirtualMachine();
    ~VirtualMachine();
    
    std::unique_ptr<Node> pop();
    std::unique_ptr<Node> peek();
    void push(std::unique_ptr<Node> node); 
    
    void run(std::unique_ptr<Node> node);
    
    
};

#endif /* Vm_hpp */
