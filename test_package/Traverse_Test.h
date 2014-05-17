#ifndef TRAVERSE_TEST_H
#define TRAVERSE_TEST_H
#include <queue>
#include "../graph_package/Graph.h"
#include <unordered_set>
#include "CFG_Reader.h"
#include "First_gen.h"
#include <iostream>

class Traverse_Test
{
    public:
        Traverse_Test();
        void build(Graph *graph,CFG_Reader reader);
        void bfs_traverse(Graph *graph);
        virtual ~Traverse_Test();
    protected:
    private:
};

#endif // TRAVERSE_TEST_H
