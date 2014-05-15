#ifndef CFG_Reader_h
#define CFG_Reader_h

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

 public:

    /**
     * @element-type Graph
     */
    Graph myGraph;

};

#endif // CFG_Reader_h
