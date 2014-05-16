#include "First_gen.h"

First_gen::First_gen(Graph *graph, unordered_set<string> *epson_non_teminals ){
    //Constructor
    this->graph = graph;
    start_node = graph->get_start_node();
    this->epson_non_teminals = epson_non_teminals;
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
        vector<my_node> node_vector;
        circle_nodes_child = square_nodes_child[i].get_nodes();
        for(int j = 0 ; j < circle_nodes_child.size() ; j++)
        {
            if (graph->get_child(circle_nodes_child[j].get_name()).size() == 0 )
            {
                my_node node;
                node.first=circle_nodes_child[j].get_name();
                node.sq_node = square_nodes_child[i];
                node_vector.push_back(node);
                if(epson_non_teminals->find(circle_nodes_child[j].get_name()) == epson_non_teminals->end())
                    continue;
            }
            else
                generate_firsts(circle_nodes_child[j].get_name());
        }
         first_set.insert(pair<string,vector<my_node>>(current_node, node_vector));
    }
}

First_gen::~First_gen(){
    //Destructor
}
