#include "Parsing_table_gen.h"

Parsing_table_gen::Parsing_table_gen(First_gen *first , Follow_gen *follow ,
                                     unordered_map<string , int> *terminals , unordered_map<string , int> *non_terminals)
{

    this->first =first;
    this->follow = follow;
    this->terminals = terminals;
    this->non_terminals = non_terminals;

}
string Parsing_table_gen::getProduction(SquareNode node)
{
    vector <CircleNode>nods=node.get_nodes();
    int i=0;
    string production="";
    while(i<nods.size())
    {
        production=production+""+nods[i].get_name();
        production=production+"";
        i++;

    }
    return production;
}

vector<vector<string>>Parsing_table_gen::get_parsing_table()
{
    vector <vector<string> > table;
    unordered_map<string,int>::const_iterator itr1;
    unordered_map<string,int>::const_iterator itr2;
    unordered_set<string>::const_iterator itr4;
    unordered_set<string> *follows;
    unordered_set<string>::const_iterator itr3;
    int terminal_index=0;
    int non_terminal_index=0;
    string first_element;
    string production;
    itr1=non_terminals->begin();
    itr2=terminals->begin();
//fill the vector with spaces
    for(int i=0; i<=non_terminals->size(); i++)
    {
        vector <string> temp ;
        for (int j=0; j<=terminals->size(); j++)
        {
            temp.push_back("");
        }
        table.push_back(temp);

    }
    int x1=non_terminals->size();
    int x2=terminals->size();
    //fill first row with terminal and first col with nonterminal in parsingTable
    for(int i=1; i<=non_terminals->size(); i++)
    {

        table[(*non_terminals)[itr1->first]][0]=itr1->first;
        itr1++;
    }
    for(int i=1; i<=terminals->size(); i++)
    {
        table[0][(*terminals)[itr2->first]]=itr2->first;

        itr2++;
    }


    table[0][0]="start";
    for(int i=1; i<=non_terminals->size(); i++)
    {
        vector<my_node>firsts=(*first->get_first(table[i][0]));
        for(int j=0; j<firsts.size(); j++)
        {
            production=getProduction(firsts[j].sq_node);
            first_element = firsts[j].first;
            terminal_index=(*terminals)[first_element];
            non_terminal_index=(*non_terminals)[table[i][0]];
            if(first_element=="\\L")
            {
                follows=follow->get_follow(table[i][0]);
                itr4= follows->begin();
                for(int j=0; j<follows->size(); j++)
                {
                    terminal_index=(*terminals)[*itr4];
                    itr4++;



                    if(table[non_terminal_index][terminal_index]=="")
                    {
                        table[non_terminal_index][terminal_index]="\\l";
                    }
                    else
                    {
                        is_LL_one=false;
                    }

                }
            }
            else
            {

                if(table[non_terminal_index][terminal_index]=="")
                {
                    table[non_terminal_index][terminal_index]=production;
                }
                else
                {
                    is_LL_one=false;
                    break;
                }

            }
        }

    }

    for(int i=1; i<=non_terminals->size(); i++)
    {

        follows=follow->get_follow(table[i][0]);
        itr4= follows->begin();
        for(int j=0; j<follows->size(); j++)
        {

            terminal_index=(*terminals)[*itr4];
            itr4++;

            if(table[i][terminal_index]=="")
            {
                table[i][terminal_index]="sync";

            }


        }

    }

  for(int i = 0 ; i <table.size() ; i++ )
    {
        for(int j = 0 ; j < table[i].size() ; j++ )
        {
            cout<< table[i][j]<<endl ;
        }
        cout<<"new row"<<i<<endl;
    }

    return table;
}



bool Parsing_table_gen::is_LL()
{
    if(is_LL_one==true)
    {
        cout<<"It Is LL(1)"<<endl;
        return true;
    }
    else
        cout<<"It Is not LL(1)"<<endl;
    return false;



}

Parsing_table_gen::~Parsing_table_gen()
{
    //dtor
}


