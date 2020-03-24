#ifndef PQ_H
#define PQ_H
#include "obj.h"
#include <exception>
#include <iostream>
using namespace std;
class obj;//compilatorul nu stia ca o sa existe referinta la clasa


class PQover: public exception
{
    virtual const char* what() const throw()
    {
        return "Cap exceeded";
    }
};
class PQgol: public exception
{
    virtual const char* what() const throw()
    {
        return "PQ empty";
    }
};



class PQ
{

    int capacity;
    int siz;
    obj *v;
    void push(obj);
    public:
        PQ(int);
        PQ(const PQ&);
        PQ();
        void push(int,int) ;
        int peek() const;
        int pop() ;
        virtual ~PQ();
        int maxElement() const;
        int length() const;
        friend PQ operator +(const PQ&,const PQ&);
        PQ& operator ++();
        PQ operator ++(int);
        PQ& operator --();
        PQ operator --(int);
        friend istream& operator >>(istream&,PQ&);
        friend ostream& operator <<(ostream&,const PQ&);
        PQ& operator =(const PQ&);

};

#endif // PQ_H
