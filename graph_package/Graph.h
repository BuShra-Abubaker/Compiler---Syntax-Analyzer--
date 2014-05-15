#ifndef Graph_h
#define Graph_h

#include <iostream>

using namespace std;

class Graph {

 public:
    Graph();
    virtual void add_new_node(string node_name);
    virtual void add_child(string  source , string destination);
    virtual void get_child(string  node_name);
    virtual~Graph();
 private:

};

#endif // Graph_h
