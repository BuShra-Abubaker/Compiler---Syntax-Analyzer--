#ifndef SQUARENODE_H
#define SQUARENODE_H

#include "CircleNode.h"
#include <vector>

using namespace std;

class CircleNode;
class SquareNode
{
    public:
        SquareNode();
        virtual ~SquareNode();
        void add_circle_node(CircleNode new_node);
        vector<CircleNode> get_nodes();
    protected:
    private:
        vector<CircleNode> nodes;
};

#endif // SQUARENODE_H
