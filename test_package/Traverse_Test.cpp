#include "Traverse_Test.h"

Traverse_Test::Traverse_Test()
{
    //ctor
}

void Traverse_Test::build(Graph *graph,CFG_Reader reader)
{
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
        for(int i = 0 ; i < my_first->size() ; i++){
            cout<< "First : " << (*my_first)[i].first <<endl;
        }
        it2++;
    }
}
Traverse_Test::~Traverse_Test()
{
    //dtor
}
