#include "Test_CFG_Reader.h"

#include <queue>
#include <vector>

#include "../graph_package/CircleNode.h"
#include "unordered_set"
#include "../graph_package/SquareNode.h"

Test_CFG_Reader::Test_CFG_Reader()
{
    //ctor
}

void Test_CFG_Reader::start_test()
{
    CFG_Reader reader("grammarInput.txt");
    Graph *graph = reader.get_cfg_graph();

    cout << graph->size() << endl;

    queue<string> q;
    unordered_set<string> v;

    q.push(graph->get_start_node().get_name());

    string node_name;
    v.insert(graph->get_start_node().get_name());

    while(!q.empty())
    {
        node_name = q.front();
        q.pop();

        cout<< node_name <<endl;

        vector<SquareNode> vs = graph->get_child(node_name);
        for( int i = 0 ; i < vs.size() ; i++ )
        {
            vector<CircleNode> vc = vs[i].get_nodes();
            for(int j = 0 ; j < vc.size() ; j++)
                if( v.find(vc[j].get_name()) == v.end() ){ // add to queue
                    q.push(vc[j].get_name());
                    v.insert(vc[j].get_name());

                }
        }

    }

}

Test_CFG_Reader::~Test_CFG_Reader()
{
    //dtor
}
