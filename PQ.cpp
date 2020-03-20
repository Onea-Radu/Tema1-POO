#include "PQ.h"
#include "obj.h"
#include <iostream>
#include <exception>
using namespace std;

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


PQ::PQ()
{
    capacity=10;
    v=new obj[capacity+1];
    v[0]=obj(0, INT_MAX);
    siz=0;
}


PQ::PQ(int cap)
{
    capacity=cap;
    v=new obj[cap+1];
    v[0]=obj(0, INT_MAX);
    siz=0;
}

PQ::~PQ()
{//nu mergea "delete[] v;" pentru ca v e degradat in pointer
 for(int i=0;i<=capacity;i++)
 {delete v;
 v++;
 }
}

PQ::PQ(const PQ& pq){
capacity=pq.capacity;
 v=new obj[capacity+1];
    siz=pq.siz;
    for(int i=1;i<=siz;i++)
        v[i]=pq.v[i];
}


void PQ::push(int val,int prio)
{
    if(siz>capacity)throw PQover();
    siz++;
    obj a(val,prio);//aveam facut un constructor de copiere asa ca de ce nu
    v[siz]=a;
    delete &a;
   int i=siz;
     while(v[i].priority>v[i/2].priority)
    {
        obj aux=v[i/2];
        v[i/2]=v[i];
        v[i]=aux;
        i/=2;
    }
}
void PQ::push(obj o)
{
    push(o.value,o.priority);
}

int PQ::peek()
{
    if(siz)return v[1].value;
    else throw PQgol();
}

int PQ::pop()
{
    if(siz)
    {
        int a=v[1].value;
        int i=1;
        v[1]=v[siz];
        siz--;
        while(true)
        {
            if(i*2+1<=siz)
            {
                if(v[i*2+1].priority>v[i*2].priority)
                {
                    i=i*2+1;
                    obj aux=v[i/2];
                    v[i/2]=v[i];
                    v[i]=aux;
                }
                else
                {
                    i=i*2;
                      obj aux=v[i/2];
                    v[i/2]=v[i];
                    v[i]=aux;
                }

            }
            else if(i*2<=siz)
            {
                i=i*2;
                  obj aux=v[i/2];
                v[i/2]=v[i];
                v[i]=aux;
            }
            else break;
        }
   return a;
    }

else throw PQgol();
}




int PQ::length()
{
    return siz;
}


PQ& PQ::operator =(const PQ& p)
{
if(this!=&p)
{
    capacity=p.capacity;
    siz=p.siz;
    v=new obj[capacity+1];
    for(int i=1;i<=siz;i++)
        v[i]=p.v[i];



}
    return *this;
}






PQ operator +(const PQ& p,const PQ& q)
{
 PQ pq(p.capacity+q.capacity);
 int i;
 for(i=1;i<=p.siz;i++)
 {pq.v[i]=p.v[i];
 pq.siz++;
 }
 for(i=1;i<=q.siz;i++)
 pq.push(q.v[i].getValue(),q.v[i].getPriority());
}


PQ& PQ::operator++()
{
for(int i=1;i<=siz;i++)
    v[i].priority++;


    return *this;
}

PQ& PQ::operator++(int n)
{
    ++*this;
    return *this;
}


PQ& PQ::operator--()
{

    int nrOfRemoved=0;
for(int i=1;i<=siz;i++)
    {v[i].priority--;
    if(v[i].priority)
    v[i-nrOfRemoved]=v[i];

    else   nrOfRemoved++;
    }
  siz-=nrOfRemoved;




    return *this;
}

PQ& PQ::operator--(int n)
{
    --*this;
    return *this;
}

int PQ::maxElement()
{
 int m=INT_MIN;
  if(siz)
  for(int i=1;i<=siz;i++)
    m=max(m,v[i].value);
   else throw PQgol();
   return m;
}


istream& operator >>(istream& in,PQ& p)
{
    int n;
    in>>n;
for(int i=0;i<n;i++)
  {obj o;
  in>>o;
  p.push(o);
  }
  return in;
}


ostream& operator <<(ostream& out,const PQ& p)
{

  for(int i=1;i<=p.siz;i++)
   out<<p.v[i]<<" ";
  out<<endl;
  return out;
}











