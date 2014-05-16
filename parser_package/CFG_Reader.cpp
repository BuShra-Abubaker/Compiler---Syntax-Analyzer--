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
        i++;
        while(i < line.length() && (line[i] == ' ' || line[i] == '\t') ) // Skip white space
            i++;

        while(i < line.length() && line[i] != ' ' && line[i] != '\t') // non terminal name
            new_non_terminal << line[i++];

        while(i < line.length() && (line[i] == ' ' || line[i] == '\t') ) // Skip white space
            i++;


        if( line[i] != '=') // Error
        {
            cout<< "RULES ERROR: The following line don't have '=':"<<endl << line << endl;
            return; //skip line
        }

        handle_RHS(line , i , new_non_terminal.str());
    }
    else   // Old Rule
    {
        if( currnet_node == "" )  // if there is no LHS
        {
            cout<< "RULES ERROR: This following line don't have LHS:" <<endl << line << endl;
            return;
        }

        handle_RHS(line, i, new_non_terminal.str());
    }
}

void CFG_Reader::handle_RHS(string line , int i , string non_terminal_name)
{
    vector< vector<string> > children;
    vector<string> production;

    for(; i < line.length() ; i++)
    {
        if( line[i] == ' ' || line[i] == '\t') // skip white space
            continue;

        if( line[i] == '|' )  // End of production
        {
            children.push_back(production); // add the production to
            production.clear();
        }
        else if(line[i] == '\'')  // Start of Terminal
        {
            i++;
            stringstream new_terminal;
            while(i < line.length() && line[i] != '\'')
                new_terminal << line[i++];

            if( i == line.length() ) // if line with out end '\''
            {
                cout<< "RULES ERROR: Missing \' for terminal." << endl;
                return; //Skip line
            }

            string new_teminale_name = new_terminal.str();
            if( terminals.find(new_teminale_name) != terminals.end() )//add new non_terminal
                terminals.insert(pair<string,int>( new_teminale_name,  teminals_count++ )); // Add the non terminal to non_terminal list

            production.push_back(new_teminale_name);
        }
        else
        {
            stringstream new_non_terminal;
            while(i < line.length() && line[i] != ' ' && line[i] != '\t')
                new_non_terminal << line[i++];

            string temp_non_terminal = new_non_terminal.str();
            production.push_back(temp_non_terminal);

            if( temp_non_terminal == "\\L") // Add the parent non_terminal as epson non_terminal
                epson_non_teminals.insert(non_terminal_name);
        }
    }

    if( !production.empty() ) // add the last production
        children.push_back(production);

    // No Error >>
    currnet_node = non_terminal_name;

    //Create new node with new non terminal name
    if( non_terminals.find(currnet_node) != non_terminals.end() )//add new non_terminal
        non_terminals.insert(pair<string,int>( currnet_node,  non_teminals_count++ )); // Add the non terminal to non_terminal list

    // Add new non_terminal and it's children
    for(int j = 0; j < children.size() ; j++)
        graph.add_child(currnet_node , children[j]);
}

Graph CFG_Reader::get_cfg_graph()
{
}

CFG_Reader::~CFG_Reader()
{
    //Destructor
}
