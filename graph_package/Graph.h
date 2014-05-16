#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <vector>
#include <map>
#include "CircleNode.h"
#include "SquareNode.h"

using namespace std;




class Graph {

 public:
    Graph();
    CircleNode get_start_node();
    virtual bool add_start_node(string node_name);
    virtual void add_child(string  source , vector<string> destination);
    virtual void get_child(string  node_name);
    virtual~Graph();
 private:
     map<string, CircleNode> nodeMap;
     CircleNode start_node;

};

#endif // Graph_h
