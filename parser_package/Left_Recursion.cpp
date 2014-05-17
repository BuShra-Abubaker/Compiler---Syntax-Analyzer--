#include "Left_Recursion.h"

Left_Recursion::Left_Recursion(Graph *graph)
{
    //Constructor
    this->graph = graph;
    non_terminals = cfg_reader->get_non_terminals();
}
void Left_Recursion::eliminate_left_recursion(string current_node)
{
    vector<CircleNode> circle_nodes_child;
    unordered_map<string,int>::const_iterator it = non_terminals->begin();
    while( it != non_terminals->end())
    {
        current_node = it->first;
        vector<SquareNode> square_nodes_child = graph->get_child(current_node);
        for (int i = 0 ; i < square_nodes_child.size() ; i++)
        {
            circle_nodes_child = square_nodes_child[i].get_nodes();
            if (circle_nodes_child[0].get_name() == current_node)
            {
                // left recursion
                SquareNode sq_node;
                string name = "temp" + i ; // choose serial names
                CircleNode new_node = CircleNode(name);
                for (int j = 0 ; j < square_nodes_child.size(); j++)
                {
                    // add new_node to every square_node (beta) that not has left recursion
                    if (circle_nodes_child[0].get_name() != current_node)
                    {
                        square_nodes_child[j].add_circle_node(new_node); // push back
                        // add children to new_node (new rule)
                        new_node.add_square_node(sq_node);
                        for(int k = 1 ; k < circle_nodes_child.size(); k++)
                            sq_node.add_circle_node(circle_nodes_child[k]); //push back
                        sq_node.add_circle_node(new_node);
                        SquareNode epson_square_node;
                        string epson_node_name = "\\L";
                        CircleNode epson_node = CircleNode(epson_node_name);
                        epson_square_node.add_circle_node(epson_node);
                    }
                }

                graph->remove_square(current_node, i);
                i--;
            }
        }
    }
}

Left_Recursion::~Left_Recursion()
{
    //dtor
}
