#ifndef Graph_h
#define Graph_h

#include <iostream>

using namespace std;

class Graph {

 public:
    Graph();
    virtual void add_child(string  name);
    virtual void get_child(string  name);
    virtual~Graph();
 private:

};

#endif // Graph_h
