#include "First_gen.h"

First_gen::First_gen(){
    //Constructor
    generate_firsts();
}

vector<string> First_gen::get_first(string  node_name)
{
    return get_firsts.find(node_name);
}

void First_gen::generate_firsts()
{

}

First_gen::~First_gen(){
    //Destructor
}
