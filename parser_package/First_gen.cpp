#include "First_gen.h"

First_gen::First_gen(Graph *graph){
    //Constructor
    this->graph = graph;
    start_node = graph->get_start_node();
    generate_firsts(start_node.get_name());
}

vector<my_node> *First_gen::get_first(string  node_name)
{
    return &(first_set[node_name]);
}

void First_gen::generate_firsts(string current_node)
{
    vector<CircleNode> circle_nodes_child;
    vector<SquareNode> square_nodes_child = graph->get_child(current_node);
    for(int i = 0 ; i < square_nodes_child.size(); i++)
    {
        circle_nodes_child = square_nodes_child[i].childs;
        for(int j = 0 ; j < circle_nodes_child.size() ; j++)
        {
            if (graph->get_child((circle_nodes_child.childs[i])).size() == 0)
                first_set.insert(make_pair<current_node, my_node.first.push(circle_nodes_child.childs[i]));
            else
                generate_firsts((circle_nodes_child.childs[i]));
        }
    }
        else
            first_set.insert(make_pair<current_node, my_node.first.push(circle_nodes_child.childs[i]));
}

First_gen::~First_gen(){
    //Destructor
}
