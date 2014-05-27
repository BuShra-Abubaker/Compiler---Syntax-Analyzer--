#include <iostream>
#include <vector>

#include "Parser.h"

using namespace std;

int main()
{

    Parser parser;
    vector<string> log = parser.get_parse_table("grammarInput.txt" , "");
    for (int i =0 ; i<log.size();i++)
        cout<<log[i]<<endl;

    return 0;
}
