#ifndef CFG_Reader_h
#define CFG_Reader_h

#include <fstream>
#include <iostream>
#include <sstream>

#include "unordered_map"
#include "unordered_set"

#include "../graph_package/Graph.h"

using namespace std;

class CFG_Reader {


 public:
    CFG_Reader(string file_path);

    //Return the rules graph
    Graph *get_cfg_graph(){
        return &graph;
    }

    //Return all the terminals
    unordered_map<string,int> *get_terminals(){
        return &terminals;
    }

    //Return all the non terminals
    unordered_map<string,int> *get_non_terminals(){
        return &non_terminals;
    }

    //Return map of all the non terminals which goes to epson directly
    unordered_set<string> *get_epson_non_terminals(){
        return &epson_non_teminals;
    }

    virtual~CFG_Reader();
 private:
    Graph graph;
    string currnet_node;

    int teminals_count = 1;
    int non_teminals_count = 1;

    bool first_node = true;

    unordered_map<string,int> terminals;
    unordered_map<string,int> non_terminals;

    unordered_set<string> epson_non_teminals;

    void generate_cfg(string  file_path);
    void handle_new_rule(string line);
    void handle_RHS(string line , int i , string non_terminal_name);


};

#endif // CFG_Reader_h
