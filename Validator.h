#ifndef Validator_h
#define Validator_h

#include "Parser.h"
#include "vector<string>.h"


class Validator {

 public:

    virtual void Validator(void  parsingtable, void  terminals, void  nonTerminals);

 private:

    virtual vector<string> get_derivations(void  tokens);

 public:

    /**
     * @element-type Parser
     */
    Parser myParser;

};

#endif // Validator_h
