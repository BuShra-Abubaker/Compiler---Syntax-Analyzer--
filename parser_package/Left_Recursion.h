#ifndef LEFT_RECURSION_H
#define LEFT_RECURSION_H

#include <../graph_package/Graph.h>
#include "../graph_package/CircleNode.h"
#include "../graph_package/SquareNode.h"


class Left_Recursion
{
    public:
        Left_Recursion();

        Graph* eleminate_left_recursion();

        virtual ~Left_Recursion();
    protected:
    private:
        Graph *graph;
        CircleNode start_node;
};

#endif // LEFT_RECURSION_H
