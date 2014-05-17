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
    int size(){return nodeMap.size();};
    virtual bool add_start_node(string node_name);
    virtual void add_child(string  source , vector<string> destination);
    virtual vector<SquareNode> get_child(string  node_name);
    virtual~Graph();
 private:
     map<string, CircleNode> nodeMap;
     CircleNode start_node;
     void add_node(string name);

};

#endif // Graph_h
