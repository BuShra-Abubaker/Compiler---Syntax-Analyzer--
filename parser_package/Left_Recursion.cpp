#include "Left_Recursion.h"

Left_Recursion::Left_Recursion(){
    //Constructor
    this->graph = graph;
    this->start_node = graph->get_start_node();
}

Graph* Left_Recursion::eleminate_left_recursion()
{
    vector<SquareNode> left_recursion_nodes;
    vector<CircleNode> circle_nodes_child;
    vector<SquareNode> square_nodes_child = graph->get_child(start_node.get_name());
    for (int i = 0 ; i < square_nodes_child.size() ; i++)
    {
        circle_nodes_child = square_nodes_child[i].get_nodes();
        if (circle_nodes_child[0].get_name() == start_node.get_name())
        {
            // left recursion
            SquareNode sq_node;
            string name = "temp";
            CircleNode new_node = CircleNode(name);
            for (int j = 0 ; j < square_nodes_child.size(); j++)
            {
                if (circle_nodes_child[0].get_name() != start_node.get_name())
                {
                    square_nodes_child[j].add_circle_node(new_node); // push_back
                    new_node.add_square_node(sq_node);
                    for(int k = 1 ; k < circle_nodes_child.size())
                        sq_node.add_circle_node(circle_nodes_child[k]);
                    sq_node.add_circle_node(new_node);

                    //delete the first square node
                }
            }
        }
    }

}

Left_Recursion::~Left_Recursion()
{
    //dtor
}
