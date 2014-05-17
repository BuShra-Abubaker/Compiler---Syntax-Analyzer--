#ifndef CIRCLENODE_H
#define CIRCLENODE_H

#include <vector>
#include <iostream>
#include "SquareNode.h"

using namespace std;

class SquareNode;
class CircleNode
{
    public:
        CircleNode(string new_name);
        CircleNode(){};
        virtual ~CircleNode();
        string get_name();
        void remove_square(int idx);
        void add_square_node(SquareNode new_square_node);
        vector<SquareNode> get_childs();
    protected:
    private:
        vector<SquareNode> childs;
        string name;
};

#endif // CIRCLENODE_H
