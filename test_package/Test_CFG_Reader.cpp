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
    cout<< "**************** END OF CFG Reader Test ***************" << endl;

    cout<< "**************** TRAVERSE TEST  ***************" << endl;
//    Traverse_Test traverse;
//    traverse.build(graph,reader);
//    traverse.bfs_traverse(graph);
//    Left_Recursion left_recursion(graph);
//    left_recursion.eliminate_left_recursion("");

    cout<< "**************** END OF TRAVERSE Test **********" << endl;

    cout<< "********************  PARSE TABLE TEST *************************" << endl;

    cout<< "Epson states :" << endl;
    unordered_set<string> * epsons = reader.get_epson_non_terminals();
    unordered_set<string>::const_iterator it1 = epsons->begin();

    while( it1 != epsons->end())
    {
        cout<< *it1 << endl;
        it1++;
    }

    unordered_map<string ,int> *non_terminals = reader.get_non_terminals();
    unordered_map<string,int>::const_iterator it2 = non_terminals->begin();
    First_gen first( graph ,epsons );
    while( it2 != non_terminals->end() && first.is_LL1_grammar())
    {
        cout<< "Non-Terminals :" << it2->first << endl;
        vector<my_node> *my_first = first.get_first(it2->first);
        for(int i = 0 ; i < my_first->size() ; i++)
        {
            cout<< "First : " << (*my_first)[i].first <<endl;
        }
        it2++;
    }
    cout << "******************Finish First*****************" <<endl;
    Parsing_table_gen table(&first ,  new Follow_gen(&first , graph) , reader.get_terminals() , non_terminals );
    vector<vector<string>>parse_table = table.get_parsing_table();
    int row = parse_table.size() ;
    int column = parse_table[0].size();
    for(int k = 0 ; k < parse_table.size() ; k++ ){

        for(int j = 0 ; j < parse_table[k].size() ; j++ ){
            cout<< parse_table[k][j]<<"\t";
        }
        cout<<endl;
    }


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
