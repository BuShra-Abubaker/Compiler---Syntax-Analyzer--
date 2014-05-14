#ifndef Parser_h
#define Parser_h

#include "CFG_Reader.h"
#include "First_gen.h"
#include "Follow_gen.h"
#include "Graph.h"
#include "Pharsing_Table_Gen.h"
#include "Validator.h"


class Parser {

 public:
    Graph graph;

 public:

    /**
     * @element-type CFG_Reader
     */
    CFG_Reader myCFG_Reader;

    /**
     * @element-type Follow_gen
     */
    Follow_gen myFollow_gen;

    /**
     * @element-type First_gen
     */
    First_gen myFirst_gen;


    /**
     * @element-type Validator
     */
    Validator myValidator;

    /**
     * @element-type Pharsing_Table_Gen
     */
    Pharsing_Table_Gen myPharsing_Table_Gen;
};

#endif // Parser_h
