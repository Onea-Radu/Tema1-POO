#ifndef OBJ_H
#define OBJ_H
#include "PQ.h"
#include <iostream>
using namespace std;
class obj
{
    int value,priority;
    public:
        obj(int,int);
        obj();
        obj(obj&);
    int getValue();
    int getPriority();
    void setValue(int);
    void setPriority(int);
    friend class PQ;
    friend ostream& operator <<(ostream&,const obj&);
    friend istream& operator >>(istream&,obj&);
};

#endif // OBJ_H
