#ifndef Follow_gen_h
#define Follow_gen_h

#include "Graph.h"
#include "string.h"
#include "void.h"


class Follow_gen {

 public:

    virtual string get_follow(void  name);

 private:

    virtual void generate_follow();


 private:
    Graph graph;

};

#endif // Follow_gen_h
