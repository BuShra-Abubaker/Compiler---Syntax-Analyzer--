#ifndef LEFT_RECURSION_H
#define LEFT_RECURSION_H

#include <../graph_package/Graph.h>
#include "../graph_package/CircleNode.h"
#include "../graph_package/SquareNode.h"
#include "Test_CFG_Reader.h"


class Left_Recursion
{
    public:
        Left_Recursion(Graph *graph);

        void eliminate_left_recursion(string current_name);

        virtual ~Left_Recursion();
    protected:
    private:
        Graph *graph;
        CFG_Reader *cfg_reader;
        unordered_map<string,int> *non_terminals;
        string start_node;
};

#endif // LEFT_RECURSION_H
