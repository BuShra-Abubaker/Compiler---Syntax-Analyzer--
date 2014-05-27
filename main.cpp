#include <iostream>
#include <vector>

#include <fstream>

#include "Parser.h"
#include "Test_CFG_Reader.h"

using namespace std;

int main(int arg , char* args[])
{
    Test_CFG_Reader tes;
    tes.start_test();
//    ofstream outputFile;
//    outputFile.open("Syntax_table.txt");
//
//    Parser parser;
//    vector<string> log = parser.get_parse_table("grammarInput.txt" , "");
//    outputFile << "Syntax Tree:" << endl;
//    for (int i =0 ; i<log.size() - 1;i++){
//        cout<<log[i]<<endl;
//        outputFile << log[i] << endl;
//    }
//
//    outputFile << endl<<"State : " << log[log.size()-1] << endl;

    return 0;
}
