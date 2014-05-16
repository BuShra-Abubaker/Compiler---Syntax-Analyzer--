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
        CircleNode();
        virtual ~CircleNode();
        string get_name();
    protected:
    private:
        vector<SquareNode> childs;
        string name;
};

#endif // CIRCLENODE_H
