#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

class Graph {

 public:
    Graph();
    virtual bool add_new_node(string node_name);
    virtual void add_child(string  source , string destination);
    virtual vector<string> get_child(string  node_name);
    virtual~Graph();
 private:

};

#endif // Graph_h
