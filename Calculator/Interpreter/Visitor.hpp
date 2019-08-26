//
//  Visitor.hpp
//  Calculator
//
//  Created by Gabriel Igliozzi on 8/25/19.
//  Copyright © 2019 Gabriel Igliozzi. All rights reserved.
//
#pragma once
#ifndef Visitor_hpp
#define Visitor_hpp

#include "Node.hpp"

#endif /* Visitor_hpp */

class Visitor {
public:
    virtual double visitNumberNode(Node* node) const = 0;
    virtual double visitUnaryNode(Node* node) const = 0;
    virtual double visitBinaryOpNode(Node* node) const = 0;
};
