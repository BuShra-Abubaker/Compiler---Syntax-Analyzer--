#include "Parsing_table_gen.h"

Parsing_table_gen::Parsing_table_gen(First_gen *first , Follow_gen *follow ,
 unordered_map<string , int> *terminals , unordered_map<string , int> *non_terminals)
{

 this->first =first;
 this->follow = follow;
 this->terminals = terminals;
 this->non_terminals = non_terminals;

}
string getProduction(SquareNode node){
string production="";

return production;
}

string** Parsing_table_gen::get_parsing_table(){
string table[non_terminals->size()][terminals->size()];
unordered_map<string,int>::const_iterator itr1;
unordered_map<string,int>::const_iterator itr2;
my_node firstN;
int terminal_index=0;
int non_terminal_index=0;
string first_element;
string production;
itr1=non_terminals->begin();
itr2=terminals->begin();
table[0][0]="start";
for(int i=1;i<non_terminals->size();i++,itr1++,itr2++){
table[i][0]=itr1->first;
table[0][i]=itr2->first;
}

for(int i=0;i<non_terminals->size();i++){
vector<my_node>firsts=(*(first->get_first(table[i][0])));
production=getProduction(firsts[i].sq_node);
first_element = firsts[i].first;
terminal_index=terminals->find(first_element);
non_terminal_index=non_terminals->find(table[i][0]);
if(first_element=="\\l"){
   for(int j=0;j<)
}else
{
if(production==NULL)
{
   if(follow->get_follow(first_element)/*is found*/){
       table[non_terminal_index][terminal_index]="Sync";
   }else
   table[non_terminal_index][terminal_index]="Null";

}


}



}


return &table;
}
Parsing_table_gen::~Parsing_table_gen()
{
    //dtor
}
