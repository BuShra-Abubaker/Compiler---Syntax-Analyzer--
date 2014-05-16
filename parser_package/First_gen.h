#ifndef First_gen_h
#define First_gen_h
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../graph_package/CircleNode.h"
#include "../graph_package/Graph.h"
#include "../graph_package/SquareNode.h"

struct my_node {string first; SquareNode sq_node;};
using namespace std;
class First_gen {

 public:
    First_gen(Graph *graph);

    virtual vector<my_node> *get_first(string  node_name);

    ~First_gen();
 private:
    Graph *graph;
    CircleNode start_node;
    unordered_map<string, vector<my_node> > first_set;

    void generate_firsts(string current_node);

};

#endif // First_gen_h
