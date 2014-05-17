#include "CircleNode.h"



string CircleNode::get_name(){
    return name;
}

void CircleNode::add_square_node(SquareNode new_square_node){
    childs.push_back(new_square_node);
}

vector<SquareNode> CircleNode::get_childs(){
    return childs;
}

void CircleNode::remove_square(int idx)
{
    childs.erase(childs.begin() + idx);
}


CircleNode::CircleNode(string new_name)
{
    name = new_name;
}

CircleNode::~CircleNode()
{
    //dtor
}
