#include "Parser.h"

Parser::Parser()
{
    //ctor
}

vector<string> Parser::get_parse_table(string grammarInput , string inpuFile){
    CFG_Reader reader(grammarInput);
    Graph *graph = reader.get_cfg_graph();

    First_gen first( graph ,reader.get_epson_non_terminals() ); // First
    Follow_gen follow(&first , graph); // Follow
    Parsing_table_gen parse_table(&first ,  &follow , reader.get_terminals() , reader.get_non_terminals() );
    Validator valid (parse_table.get_parsing_table(), reader.get_terminals() ,reader.get_non_terminals(),graph->get_start_node().get_name());

 //   return valid.get_derivations("id + id $");
}

Parser::~Parser()
{
    //dtor
}
