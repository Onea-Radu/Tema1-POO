#ifndef PQ_H
#define PQ_H
#include "obj.h"
#include <iostream>
using namespace std;
class obj;//compilatorul nu stia ca o sa existe referinta la clasa

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
        void push(int,int);
        int peek();
        int pop();
        virtual ~PQ();
        int maxElement();
        int length();
        friend PQ operator +(const PQ&,const PQ&);
        PQ& operator ++();
        PQ& operator ++(int);
        PQ& operator --();
        PQ& operator --(int);
        friend istream& operator >>(istream&,PQ&);
        friend ostream& operator <<(ostream&,const PQ&);

};

#endif // PQ_H
