#ifndef Follow_gen_h
#define Follow_gen_h

#include <iostream>
#include <vector>
#include "unordered_set"
#include "unordered_map"
#include "../graph_package/Graph.h"
#include "First_gen.h"
#include <queue>

using namespace std;
class Follow_gen {

 public:
    Follow_gen(First_gen *first, Graph *graph);

    virtual unordered_set<string>*get_follow(string  node_name);

    virtual~Follow_gen();
 private:
    Graph *graph;
    First_gen *first;

    bool updated = true;

    unordered_map< string , unordered_set<string> > follows;

    virtual bool add_follow(string name , string follow_node);
    virtual void add_follow_of_my_parent(string name , string parent_name);
    virtual void generate_follows();

};

#endif // Follow_gen_h
