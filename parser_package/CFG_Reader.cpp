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
    }
    else   // Error in opening file
        cout << "Unable to open file!";


}

void CFG_Reader::handle_new_rule(string line)
{
    int i  = 0;
    while(i < line.length() && (line[i] == ' ' || line[i] == '\t') ) // Skip white space
        i++;

    stringstream new_non_terminal;
    if( line[i] == '#' ) // New Rule
    {
        while(i < line.length() && line[i] != ' ' && line[i] != '\t') // non terminal name
            new_non_terminal << line[i++];

        while(i < line.length() && (line[i] == ' ' || line[i] == '\t') ) // Skip white space
            i++;

        if( line[i] != '=') // Error
        {
            cout<< "ERROR: The following line don't have '=':"<<endl << line << endl;
            return; //skip line
        }

        // No Error >>

        string node_name = new_non_terminal.str();

        //Create new node with new non terminal name
        //if( graph.add_new_node(node_name) )
          //  non_terminals.insert(pair<string,int>( node_name,  non_teminals_count++ )); // Add the non terminal to non_terminal list


        for(; i < line.length() ; i++)
        {
            if( line[i] == ' ' || line[i] == '\t') // skip white space
                continue;

            if(line[i] == '\''){ // Start of Terminal
            }
        }
    }
    else   // Old Rule
    {

    }



}

Graph CFG_Reader::get_cfg_graph()
{
}

CFG_Reader::~CFG_Reader()
{
    //Destructor
}
