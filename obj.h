#ifndef OBJ_H
#define OBJ_H
#include "PQ.h"
#include <exception>
#include <iostream>
using namespace std;

class NegativePriority: public exception
{
    virtual const char* what() const throw()
    {
        return "Priority can't be negative.";
    }
};

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
    bool operator ==(obj);
    friend class PQ;
    friend ostream& operator <<(ostream&,const obj&);
    friend istream& operator >>(istream&,obj&);

};

#endif // OBJ_H
