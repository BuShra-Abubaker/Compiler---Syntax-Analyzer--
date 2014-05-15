#include "CFG_Reader.h"


CFG_Reader::CFG_Reader(string file_path)
{
    //Constructor
    generate_cfg(file_path);
}


void CFG_Reader::generate_cfg(string  file_path)
{
    ifstream grammar_file (file_path.c_str());
    string line;

    if (grammar_file.is_open())  // Check if file opened
    {
        while ( getline (grammar_file,line) )
        {
            cout << line << endl;

            if( line.empty()) // Empty line or white space
                continue;

            handle_new_rule(line);

        }

        grammar_file.close();
        return get_language_graph();
    }
    else   // Error in opening file
    {
        cout << "Unable to open file";
        return NULL;
    }
}

CFG_Reader::handle_new_rule(string line)
{
    int i  = 0;
    while(i < line.length() && (line[i] == ' ' || line[i] == '\t') ) // Skip white space
        i++;

    for(; i < line.length() ; i++)
    {
        if( line[i] == '#' ) // New Rule
        {

        }
        else   // Old Rule
        {

        }
    }
}

Graph CFG_Reader::get_cfg_graph()
{
}

CFG_Reader::~CFG_Reader()
{
    //Destructor
}
