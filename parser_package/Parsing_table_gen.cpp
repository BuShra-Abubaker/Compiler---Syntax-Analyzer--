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

vector<vector<string>>* Parsing_table_gen::get_parsing_table()
{
    vector <vector<string> > table;
    unordered_map<string,int>::const_iterator itr1;
    unordered_map<string,int>::const_iterator itr2;
    unordered_set<string> follows;
    unordered_set<string>::const_iterator itr3;
    int terminal_index=0;
    int non_terminal_index=0;
    string first_element;
    string production;
    itr1=non_terminals->begin();
    itr2=terminals->begin();
//fill the vector with spaces
    for(int i=0; i<non_terminals->size(); i++)
    {
        vector <string> temp ;
        for (int j=0; j<terminals->size(); j++)
        {
            temp.push_back("");
        }
        table.push_back(temp);

    }
    //fill first row with terminal and first col with nonterminal in parsingTable
    for(int i=1; i<non_terminals->size(); i++,itr1++,itr2++)
    {
        table[i][0]=itr1->first;
        table[0][i]=itr2->first;
    }
    table[0][0]="start";
    for(int i=1; i<non_terminals->size(); i++)
    {
        vector<my_node>firsts=(*first->get_first(table[i][0]));
        for(int j=0; j<firsts.size(); j++)
        {
            production=getProduction(firsts[j].sq_node);
            first_element = firsts[j].first;
            if(first_element=="\\l")
            {
            int x =j;
             follows=follow->get_follow(table[i][0]);
               for(int j=x+1; j<firsts.size(); j++)
                 {
                     first_element = firsts[j].first;
                     terminal_index=(*terminals)[first_element];
                     non_terminal_index=(*non_terminals)[table[i][0]];
                     itr3 = follows.find (first_element);

                if ( itr3 != follows.end() )
                {
                    if(table[non_terminal_index][terminal_index]=="")
                    {
                        table[non_terminal_index][terminal_index]="\\l";
                    }is_LL_one=false;
                }
                    }
                }

            if(table[non_terminal_index][terminal_index]=="")
            {
                table[non_terminal_index][terminal_index]=production;
            }
            else
                is_LL_one=false;
            break;


        }

    }

    for(int i=1; i<non_terminals->size(); i++)
    {
        vector<my_node>firsts=(*first->get_first(table[i][0]));
        for(int j=0; j<firsts.size(); j++)
        {
            first_element = firsts[j].first;
            terminal_index=(*terminals)[first_element];
            non_terminal_index=(*non_terminals)[table[i][0]];

            follows=follow->get_follow(table[i][0]);
            itr3 = follows.find (first_element);
            if(first_element=="\\l"){
            i++;
            }
            if((table[non_terminal_index][terminal_index]==""))
            {
                if ( itr3 != follows.end() )
                {
                    table[non_terminal_index][terminal_index]="Sync";

                }
                table[non_terminal_index][terminal_index]="Null_element";
            }

        }

    }



    return &table;
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

