#include "SquareNode.h"


SquareNode::SquareNode()
{
    //ctor
}

void SquareNode::add_circle_node(CircleNode new_node){
    nodes.push_back(new_node);
}

vector<CircleNode> SquareNode::get_nodes(){
    return nodes;
}

SquareNode::~SquareNode()
{
    //dtor
}
