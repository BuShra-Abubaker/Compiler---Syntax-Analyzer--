#ifndef PARSER_H
#define PARSER_H

#include "CFG_Reader.h"
#include "First_gen.h"
#include "Follow_gen.h"
#include "Parsing_table_gen.h"
#include "Validator.h"

#include <vector>

#include <iostream>

using namespace std;
class Parser
{
    public:
        Parser();
        vector<string> get_parse_table(string grammarInput , string tokenFile);
        virtual ~Parser();
    protected:
    private:
        vector<string> read_token_file(string tokenFileName);
};

#endif // PARSER_H
