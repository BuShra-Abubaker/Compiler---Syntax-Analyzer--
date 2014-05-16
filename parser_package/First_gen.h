#ifndef First_gen_h
#define First_gen_h
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../graph_package/Node.h"
#include "../graph_package/Graph.h"

using namespace std;
class First_gen {

 public:
    First_gen(Graph *graph);
    unordered_map<string, vector<string> > non-terminals_firsts;
    virtual vector<string> get_first(string  node_name);
e
    ~First_gen();
 private:
    Graph *graph;

    Node* start_node;
    vector<string> firsts;
    void generate_firsts();

};

#endif // First_gen_h
