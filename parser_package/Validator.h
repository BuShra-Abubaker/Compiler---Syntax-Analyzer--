#ifndef Validator_h
#define Validator_h

#include "vector"
#include "unordered_map"
#include <iostream>

#include "Parsing_table_gen.h"

using namespace std;
class Validator {

 public:
    Validator(Parsing_table_gen  parsingtable, unordered_map<string , int> terminals , unordered_map<string , int> non_terminals);
    virtual vector<string> get_derivations(string  token);

    virtual ~Validator();

};

#endif // Validator_h
