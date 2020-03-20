#include "obj.h"
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



obj::obj()
{
 priority=0;
 value=0;
}
obj::obj(int v,int p)
{
if(p<1)throw NegativePriority();
priority=p;
value=v;
}

obj::obj(obj& o)
{
priority=o.priority;
value=o.value;

}
void obj::setPriority(int p)
{
 priority=p;
}

int obj::getValue()
{
    return value;
}

void obj::setValue(int v)
{
    value=v;
}
int obj::getPriority()
{
    return priority;
}

ostream& operator <<(ostream& out,const obj& o)
{
  out<<"( "<<o.value<<" ; "<<o.priority<<" )";
}
istream& operator >>(istream& in,obj& o)
{
  in>>o.value;
  in>>o.priority;
}
