#ifndef First_gen_h
#define First_gen_h
#include <iostream>
#include <unordered_map>
#include <vector>

#include "../graph_package/Node.h"
#include "../graph_package/Graph.h"

using namespace std;
//struct myNode {string production; vector<string> first;};
class First_gen {

 public:
    First_gen();

    virtual vector<Node> get_first(string  node_name);

    ~First_gen();
 private:
    Graph graph;

    vector<Node> firsts;
    void generate_firsts();

};

#endif // First_gen_h
