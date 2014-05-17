#ifndef Follow_gen_h
#define Follow_gen_h

#include <iostream>
#include <vector>
#include "unordered_set"
#include "unordered_map"
#include "../graph_package/Graph.h"

using namespace std;
class Follow_gen {

 public:
    Follow_gen(Graph *graph);
    void init(){
        unordered_set<string> temp;
        temp.insert("$");
       // temp.insert(")");

        follows.insert(pair<string , unordered_set <string> >("S" , temp));
        temp.clear();
        temp.insert("b");
 temp.insert("d");
        follows.insert(pair<string , unordered_set <string> >("A" , temp));
//
//        temp.insert("+");
//
//        follows.insert(pair<string , unordered_set <string> >("T" , temp));
//
//        follows.insert(pair<string , unordered_set <string> >("T'" , temp));
//
//        temp.insert("*");
//
//        follows.insert(pair<string , unordered_set <string> >("F" , temp));
    }
    virtual unordered_set<string> get_follow(string  node_name);

    virtual~Follow_gen();
 private:
    Graph *graph;
    unordered_map<string , unordered_set<string> > follows;
    virtual void generate_follows();

};

#endif // Follow_gen_h
