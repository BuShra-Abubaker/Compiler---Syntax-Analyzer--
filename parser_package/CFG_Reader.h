#ifndef CFG_Reader_h
#define CFG_Reader_h

#include <fstream>
#include <iostream>

#include "../graph_package/Graph.h"

using namespace std;
class CFG_Reader {


 private:
    CFG_Reader(string file_path);

    Graph get_cfg_graph();

    virtual~CFG_Reader();
 private:
    Graph graph;

    void generate_cfg(string  file_path);
    void handle_new_rule(string line);


};

#endif // CFG_Reader_h
