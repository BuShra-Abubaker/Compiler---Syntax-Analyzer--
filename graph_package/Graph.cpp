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

void Graph::add_node(string name){
    if(nodeMap.find(name) == nodeMap.end()){
        CircleNode new_node = CircleNode();
        nodeMap.insert(pair<string, CircleNode>(name, new_node));
    }
}

void Graph::add_child(string  source , vector<string> destination)
{
    add_node(source);
    SquareNode curNode;

    for(int i = 0 ; i < destination.size() ; i++){
        add_node(destination[i]);
        curNode.add_circle_node(nodeMap[destination[i]]);
    }

    nodeMap[source].add_square_node(curNode);


}

vector<SquareNode> Graph::get_child(string  node_name)
{
    return nodeMap[node_name].get_childs();
}



Graph::~Graph(){
    //Destructor
}
