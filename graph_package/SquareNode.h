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
    protected:
    private:
        vector<CircleNode> nodes;
};

#endif // SQUARENODE_H
