#ifndef First_gen_h
#define First_gen_h
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../graph_package/Graph.h"

using namespace std;
class First_gen {

 public:
    First_gen();

    unordered_map<string, vector<string> > get_firsts;

    vector<string> get_first(string  node_name);

    ~First_gen();
 private:
    Graph graph;

    vector<string> children;
    void generate_firsts();

};

#endif // First_gen_h
