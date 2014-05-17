#include "Test_CFG_Reader.h"
#include <queue>
#include <vector>
#include "../graph_package/CircleNode.h"
#include "unordered_set"
#include "../graph_package/SquareNode.h"
#include "First_gen.h"
#include "Traverse_Test.h"
#include "Left_Recursion.h"
#include "Parsing_table_gen.h"
#include "Validator.h"


Test_CFG_Reader::Test_CFG_Reader()
{
    //ctor
}

void Test_CFG_Reader::start_test()
{
    CFG_Reader reader("grammarInput.txt");
    Graph *graph = reader.get_cfg_graph();

    cout<< endl <<"************ CFG READER TEST ***************" << endl;
    cout<< "- Graph Size = " << graph->size() << endl;

    cout << "- Graph Traverse:" << endl << endl;

    // BFS
    queue<string> q;
    unordered_set<string> v;

    q.push(graph->get_start_node().get_name());
    v.insert(graph->get_start_node().get_name());

    string node_name;
    int i= 1;
    while(!q.empty())
    {
        node_name = q.front();
        q.pop();

        cout<< i++ << ") " << node_name <<endl;

        vector<SquareNode> vs = graph->get_child(node_name);
        for( int i = 0 ; i < vs.size() ; i++ )
        {
            vector<CircleNode> vc = vs[i].get_nodes();
            for(int j = 0 ; j < vc.size() ; j++)
                if( v.find(vc[j].get_name()) == v.end() )  // add to queue
                {
                    q.push(vc[j].get_name());
                    v.insert(vc[j].get_name());
                }
        }

    }
    cout<< "**************** END OF TRAVERSE ***************" << endl;

    Traverse_Test traverse;
    traverse.build(graph,reader);
    traverse.bfs_traverse(graph);
    Left_Recursion left_recursion(graph);
    left_recursion.eliminate_left_recursion("");



    cout <<"************ Start test validator ************"<<endl;
    vector <string > log ;
    Validator valid (parse_table, reader.get_terminals() ,non_terminals,parse_table[1][0]);
    log = valid.get_derivations("c e a d b $");
    int x = log.size();
    for (int i =0 ; i<log.size();i++)
        cout<<log[i]<<endl;

    cout <<"******************* END *********************"<<endl;
}

Test_CFG_Reader::~Test_CFG_Reader()
{
    //dtor
}
