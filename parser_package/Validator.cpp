#include "Validator.h"




Validator::Validator(Parsing_table_gen  *parsingtable, unordered_map<string , int> *terminals , unordered_map<string , int> *non_terminals)
{
    //Constructor
    this->terminal = *terminals;
    this->non_terminal = *non_terminals;
    this->table = *parsingtable;

}

vector<string> Validator::get_derivations(string  token)
{
    stack <string> valid_stack ;
    valid_stack.push(non_terminal.at(0));
}

Validator::~Validator(){
    //Destructor
}
