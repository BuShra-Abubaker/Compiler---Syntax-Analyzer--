#include "Parser.h"

Parser::Parser()
{
    //ctor
}

vector<string> Parser::get_parse_table(string grammarInput , string tokenFile){
    CFG_Reader reader(grammarInput);
    Graph *graph = reader.get_cfg_graph();

    First_gen first( graph ,reader.get_epson_non_terminals() ); // First
    Follow_gen follow(&first , graph); // Follow
    Parsing_table_gen parse_table(&first ,  &follow , reader.get_terminals() , reader.get_non_terminals() );
    Validator valid (parse_table.get_parsing_table(), reader.get_terminals() ,reader.get_non_terminals(),graph->get_start_node().get_name());

    return valid.get_derivations(read_token_file(tokenFile));
}

vector<string> Parser::read_token_file(string tokenFileName){
    ifstream tokenFile(tokenFileName.c_str());

    string token;
    vector<string> tokens;

    if (tokenFile.is_open())  // Check if file opened
    {
        while ( getline (tokenFile,token) )
        {
            if( token.empty()) // Empty line or white space
                continue;

            tokens.push_back(token);
        }
    }
    tokens.push_back("$");
    return tokens;
}

Parser::~Parser()
{
    //dtor
}
