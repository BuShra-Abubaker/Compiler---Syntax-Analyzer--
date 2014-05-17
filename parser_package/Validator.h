#ifndef Validator_h
#define Validator_h

#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <sstream>
#include <iterator>

using namespace std;
class Validator
{

public:
    Validator( vector < vector <string> >parsing_table ,unordered_map<string , int> *terminals , unordered_map<string , int> *non_terminals,string start_symbol);
    virtual vector<string> get_derivations(string  token);
    virtual ~Validator();

private :

    unordered_map <string , int> *terminal ;
    unordered_map <string , int> *non_terminal ;
    vector < vector <string> > table ;
    string start ;

};

#endif // Validator_h
