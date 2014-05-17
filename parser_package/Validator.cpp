#include "Validator.h"




Validator::Validator( vector < vector <string> >parsing_table ,unordered_map<string , int> *terminals , unordered_map<string , int> *non_terminals,string start_symbol)
{
    //Constructor
    //assumtion we need to one indexing to avoid if element not found in map
    //missing parsing table i will act as i has it till tomorrow
    this->terminal = terminals;
    this->non_terminal = non_terminals;
    this->start = start_symbol;
    this->table= parsing_table;
}

vector<string> Validator::get_derivations(string  token)
{
    vector <string> log ;
    /**
     * split token with space to determine each terminal
     */
    istringstream buf(token);
    istream_iterator<string> beg(buf), end;
    vector<string> tokens(beg, end);
    /**
     * craet validator stack and push at top start symbol
     */
    stack <string> valid_stack ;
    valid_stack.push("$");
    valid_stack.push(start);
    //counter to determine at any token we stop
    int token_counter =0;
    int size_temp = tokens.size();
    while (valid_stack.size()>0 && tokens.size()>token_counter)
    {
        string l ;
        if (valid_stack.top()==tokens[token_counter])
        {
            valid_stack.pop();
            token_counter++;
            continue;
        }

        int row = (*non_terminal)[valid_stack.top()]-1;
        int cloumn = (*terminal)[tokens[token_counter]]-1;

        if (row==-1)
        {
             log.push_back("Error : illegal missing "+valid_stack.top());
             valid_stack.pop();
        }

        else if (row !=-1 && cloumn!=-1 )
        {
            string production = table[row][cloumn];

            if (production=="")
            {
                log.push_back("Error : illegal discard "+tokens[token_counter]);
                token_counter++;
            }
            else if (production == "sync" || production == "\\L" )
            {   if (production=="\\L")
                    log.push_back(production);
                valid_stack.pop();
            }
            else
            {
                valid_stack.pop();
                istringstream buf(production);
                log.push_back(production);
                istream_iterator<string> beg(buf), end;
                vector<string> productions(beg, end);
                for (int i =productions.size()-1 ;i>=0;i--)
                    valid_stack.push(productions[i]);
            }
        }
    }
    if (valid_stack.size()!=0)
        while(valid_stack.size()>0)
        {
            log.push_back("Error : illegal missing "+valid_stack.top());
            valid_stack.pop();
        }
    else if (token_counter<tokens.size())
        while(token_counter<tokens.size())
        {
            log.push_back("Error : illegal discard "+tokens[token_counter]);
            token_counter++;
        }
    log.push_back("accepted");
    return log;
}

Validator::~Validator(){
    //Destructor
}
