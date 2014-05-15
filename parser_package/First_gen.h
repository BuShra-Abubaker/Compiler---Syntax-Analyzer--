#ifndef First_gen_h
#define First_gen_h

#include <iostream>
#include <vector>

#include "../graph_package/Node.h"
#include "../graph_package/Graph.h"

using namespace std;
class First_gen {

 public:
    First_gen(Graph *graph);

    virtual vector<Node> get_first(string  node_name);

    virtual~First_gen();
 private:
    Graph *graph;

    virtual void generate_firsts();

};

#endif // First_gen_h
