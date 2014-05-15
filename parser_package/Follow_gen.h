#ifndef Follow_gen_h
#define Follow_gen_h

#include <iostream>
#include <vector>
#include "../graph_package/Graph.h"

using namespace std;
class Follow_gen {

 public:
    Follow_gen();

    virtual vector<string> get_follow(string  node_name);

    virtual~Follow_gen();
 private:
    Graph graph;

    virtual void generate_follows();

};

#endif // Follow_gen_h
