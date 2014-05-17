#include "Follow_gen.h"

Follow_gen::Follow_gen( First_gen *first ,Graph *graph)
{
    //Constructor
    this->first = first;
    this->graph = graph;

    unordered_set<string> start_node_set;
    start_node_set.insert("$");

    follows.insert(pair<string, unordered_set<string> >(graph->get_start_node().get_name() , start_node_set));

    generate_follows();
}

unordered_set<string>* Follow_gen::get_follow(string  node_name)
{
    return &follows[node_name];
}

void Follow_gen::generate_follows()
{
    while(updated)
    {
        updated = false;

        queue<string> q;
        unordered_set<string> v;

        string current_node = graph->get_start_node().get_name();
        q.push(current_node);
        v.insert(current_node);

        while(!q.empty())
        {
            current_node = q.front();
            q.pop();
            vector<SquareNode> cur_square = graph->get_child(current_node);
            for(int i = 0 ; i < cur_square.size() ; i++)
            {
                vector<CircleNode> cur_circle = cur_square[i].get_nodes();
                for(int j = 0 ; j < cur_circle.size() - 1; j++)
                {
                    if( v.find(cur_circle[j].get_name())== v.end() ){
                        q.push(cur_circle[j].get_name());
                        v.insert(cur_circle[j].get_name());
                    }

                    int l = j +1;
                    while( l < cur_circle.size() && add_follow(cur_circle[j].get_name() , cur_circle[l].get_name()) )  // has epson in
                    {
                        l++;
                    }
                    if( l == cur_circle.size() )  // all the next nodes has epson in their firsts
                    {
                        add_follow_of_my_parent(cur_circle[j].get_name()  , current_node);
                    }
                }
            }
        }
    }
}

// Add follow to the current node , return true if has epson in first
bool Follow_gen::add_follow(string name , string follow_node)
{
    bool has_epson = false;

    vector<my_node> *firsts = first->get_first(follow_node);
    unordered_set<string> temp_follows;

    if( follows.find(name) != follows.end()) // found
        temp_follows = follows[name];

    for( int i = 0 ; i < firsts->size() ; i++)  // add to all the first of the next node to my follow
    {
        if((*firsts)[i].first != "\\L" )
        {
            if(temp_follows.find((*firsts)[i].first) == temp_follows.end() )  // not found add it
            {
                temp_follows.insert((*firsts)[i].first);
                updated = true;
            }
        }
        else
            has_epson = true;
    }

    follows.insert(pair<string, unordered_set<string> >(name, temp_follows));
    return has_epson;
}

// Add all the follow of my parent to my follow
void Follow_gen::add_follow_of_my_parent(string name , string parent_name)
{
    unordered_set<string>  parent_follows = follows[parent_name];

    unordered_set<string> temp_follows = follows[name];
    unordered_set<string>::const_iterator it;

    for( it = parent_follows.begin() ; it != parent_follows.end() ; it++)  // add all the follows to my follow
    {
        if( temp_follows.find(*it) == temp_follows.end() )
        {
            temp_follows.insert(*it);
            updated = true;
        }
    }

    follows.insert(pair<string, unordered_set<string> >(name, temp_follows));
}

Follow_gen::~Follow_gen()
{
    //Destructor
}
