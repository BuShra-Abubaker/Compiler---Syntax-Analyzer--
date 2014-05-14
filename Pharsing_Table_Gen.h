#ifndef Pharsing_Table_Gen_h
#define Pharsing_Table_Gen_h

#include "Array[][].h"


class Pharsing_Table_Gen {

 public:

    virtual void Parsing_Table_Gen(void  first, void  follow, void  terminals, void  nonTerminals);

 private:

    virtual Array[][] get_parsing_table();

};

#endif // Pharsing_Table_Gen_h
