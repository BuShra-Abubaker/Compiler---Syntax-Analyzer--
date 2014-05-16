#ifndef CIRCLENODE_H
#define CIRCLENODE_H

#include <vector>
#include "SquareNode.h"

using namespace std;

class SquareNode;
class CircleNode
{
    public:
        CircleNode();
        virtual ~CircleNode();
    protected:
    private:
        vector<SquareNode> childs;
};

#endif // CIRCLENODE_H
