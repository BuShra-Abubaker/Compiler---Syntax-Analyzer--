#ifndef PARSING_TABLE_GEN_H
#define PARSING_TABLE_GEN_H

#include "Follow_gen.h"
#include "First_gen.h"

#include "unordered_map"

class Parsing_table_gen
{
    public:
        Parsing_table_gen(First_gen *first , Follow_gen *follow , unordered_map<string , int> *terminals , unordered_map<string , int> *non_terminals);
        virtual string** get_parsing_table();
        virtual ~Parsing_table_gen();
    protected:
    private:
    vector<string>* getProduction(SquareNode node);
    unordered_map<string , int> *terminals;
    unordered_map<string , int> *non_terminals;
    First_gen *first ;
    Follow_gen *follow;
};

#endif // PARSING_TABLE_GEN_H
