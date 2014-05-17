#ifndef PARSING_TABLE_GEN_H
#define PARSING_TABLE_GEN_H

#include "Follow_gen.h"
#include "First_gen.h"
#include <string>

#include "unordered_map"
using namespace std;

class Parsing_table_gen
{
    public:
        Parsing_table_gen(First_gen *first , Follow_gen *follow , unordered_map<string , int> *terminals , unordered_map<string , int> *non_terminals);
        vector<vector<string>>*get_parsing_table();
        virtual bool is_LL();
        virtual ~Parsing_table_gen();

    protected:
    private:
    string getProduction(SquareNode node);
    unordered_map<string , int> *terminals;
    unordered_map<string , int> *non_terminals;
    First_gen *first ;
    Follow_gen *follow;
    bool is_LL_one=true;
};

#endif // PARSING_TABLE_GEN_H
