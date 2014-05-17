#ifndef First_gen_h
#define First_gen_h
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../graph_package/CircleNode.h"
#include "../graph_package/Graph.h"
#include "../graph_package/SquareNode.h"

struct my_node {string first; SquareNode sq_node;};
using namespace std;
class First_gen {

 public:
    First_gen(Graph *graph, unordered_set<string> *epson_non_teminals);

    virtual vector<my_node> *get_first(string  node_name);
    unordered_map<string, vector<my_node> >*get_firsts(){
        return &first_set;
    }

    bool is_LL1_grammar(){
        return is_LL_1;
    }

    virtual ~First_gen();
 private:
    Graph *graph;
     bool is_LL_1 = true;

    unordered_set<string> *epson_non_teminals;
    unordered_map<string, vector<my_node> > first_set;

    vector<my_node> generate_firsts(string current_node);
};

#endif // First_gen_h
