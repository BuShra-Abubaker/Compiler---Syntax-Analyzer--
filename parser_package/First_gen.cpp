#include "First_gen.h"

First_gen::First_gen(Graph *graph, unordered_set<string> *epson_non_teminals)
{
    //Constructor
    this->graph = graph;
    this->epson_non_teminals = epson_non_teminals;
}

vector<my_node> *First_gen::get_first(string  node_name)
{
    generate_firsts(node_name);
    return &(first_set[node_name]);
}

vector<my_node> First_gen::generate_firsts(string current_node)
{
    if( first_set.find(current_node) != first_set.end() )
        return first_set.find(current_node)->second;

    vector<CircleNode> circle_nodes_child;
    vector<SquareNode> square_nodes_child = graph->get_child(current_node);
    vector<my_node> node_vector;
    unordered_set<string> visited;
    for(int i = 0 ; i < square_nodes_child.size() && is_LL_1 ; i++)
    {
        circle_nodes_child = square_nodes_child[i].get_nodes();
        for(int j = 0 ; j < circle_nodes_child.size() ; j++)
        {
            if (graph->get_child(circle_nodes_child[j].get_name()).size() == 0 )
            {
                if(visited.find(circle_nodes_child[j].get_name()) != visited.end())
                {
                    if( circle_nodes_child[j].get_name() == "\\L" )
                        continue;

                    is_LL_1 = false;
                    cout<< "not LL (1)"<<endl;
                    return node_vector;
                }
                my_node node;
                node.first=circle_nodes_child[j].get_name();
                node.sq_node = square_nodes_child[i];
                node_vector.push_back(node);
                visited.insert(node.first);

                if(epson_non_teminals->find(circle_nodes_child[j].get_name()) == epson_non_teminals->end())  // not found in epson state
                    break;

            }
            else
            {
                vector<my_node> children_first = generate_firsts(circle_nodes_child[j].get_name());

                if( !is_LL_1 )
                    break;

                for(int i = 0 ; i < children_first.size(); i++){
                    node_vector.push_back(children_first[i]);
                    visited.insert(children_first[i].first);
                }

                if( !children_first.empty())
                    break;
            }
        }
    }

    if(!is_LL_1)
        return node_vector;
    first_set.insert(pair<string,vector<my_node>>(current_node, node_vector));
    return node_vector;
}

First_gen::~First_gen()
{
    //Destructor
}
