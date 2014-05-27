#include "Test_validator.h"

Test_validator::Test_validator()
{
    //ctor
}

void Test_validator::test()
{
    vector < vector <string> > table ;
    unordered_map <string , int > non_terminal ;
    unordered_map <string , int> terminal ;
    string start_symbol ;
    vector <string > log ;
    vector <string > temp ;
    //add data to parsing table
    temp.push_back("A b S");
    temp.push_back("");
    temp.push_back("A b S");
    temp.push_back("");
    temp.push_back("e");
    temp.push_back("\\L");
    table.push_back(temp);
    temp.clear();
    temp.push_back("a");
    temp.push_back("sync");
    temp.push_back("c A d");
    temp.push_back("sync");
    temp.push_back("");
    temp.push_back("");
    table.push_back(temp);

    //add data to terminal unorder_map
    terminal["a"]=1;
    terminal["b"]=2;
    terminal["c"]=3;
    terminal["d"]=4;
    terminal["e"]=5;
    terminal["$"]=6;

    // add data to non_terminal unorder_map
    non_terminal["S"]=1;
    non_terminal["A"]=2;

    start_symbol = "S";

    cout <<"************ Start test validator ************"<<endl;
    Validator valid (table , &terminal ,&non_terminal,start_symbol);
//    log = valid.get_derivations("c e a d b $");
    int x = log.size();
    for (int i =0 ; i<log.size();i++)
        cout<<log[i]<<endl;

    cout <<"******************* END *********************"<<endl;
}

Test_validator::~Test_validator()
{
    //dtor
}
