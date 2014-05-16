#ifndef First_gen_h
#define First_gen_h
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../graph_package/Node.h"
#include "../graph_package/Graph.h"

struct my_node {string first; squreode sq_node;};
using namespace std;
class First_gen {

 public:
    First_gen(Graph *graph);
    vector<my_node> node_vector;

    virtual unordered_map<string, node_vector > firsts;
    virtual vector<string> get_first(string  node_name);

    ~First_gen();
 private:
    Graph *graph;

    Node* start_node;
    void generate_firsts();

};

#endif // First_gen_h
