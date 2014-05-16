#include "Graph.h"






Graph::Graph(){
    //Constructor
}



// if the node was already exist return false else add to the graph and return true
bool Graph::add_start_node(string node_name){
    start_node = CircleNode();
    nodeMap.insert(pair<string, CircleNode> (node_name, start_node));
}

CircleNode Graph::get_start_node(){
    return start_node;
}

void Graph::add_child(string  source , vector<string> destination)
{

}

void Graph::get_child(string  node_name)
{

}



Graph::~Graph(){
    //Destructor
}
