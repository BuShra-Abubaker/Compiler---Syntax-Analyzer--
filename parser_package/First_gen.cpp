#include "First_gen.h"

First_gen::First_gen(Graph *graph){
    //Constructor
    this->graph = graph;
    generate_firsts();
}

unordered_map First_gen::get_first(string  node_name)
{
    sequareNode child = graph->get_child(node_name);
    for(int i = 0 ; i < child.size(); i++)
    {
        if (graph->get_child(child[i]).size() == 0 )
            {
                firsts.push_back(child[i]);
//            if(node_name has Epslion)get_first(child{i+1})
                break;
            }
        else get_first(child[i]);
    }

    return firsts;
}

void First_gen::generate_firsts()
{
//    string start_node;
//    if (Node.type != square_node && Node.type != final_node)
//        get_first(start_node);



}

First_gen::~First_gen(){
    //Destructor
}
