//
//  Vm.cpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 12/11/20.
//  Copyright © 2020 Gabriel Igliozzi. All rights reserved.
//

#include "Vm.hpp"

std::unique_ptr<Node> VirtualMachine::pop() {
    return nullptr;
}

std::unique_ptr<Node> VirtualMachine::peek() {
    return nullptr;
}

void VirtualMachine::push(std::unique_ptr<Node> node) {
    //move the ip (instruction pointer) and the stacktop one ahead
    // have to check for an overflow
}

void VirtualMachine::run(std::unique_ptr<Node> node) {
    //here we run the commands
}
