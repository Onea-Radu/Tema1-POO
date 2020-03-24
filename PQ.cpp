#include "PQ.h"

using namespace std;

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
{
 delete[] v;

}

PQ::PQ(const PQ& pq){
capacity=pq.capacity;
 v=new obj[capacity+1];
    siz=pq.siz;
    for(int i=1;i<=siz;i++)
        v[i]=pq.v[i];
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




//punem la final comparam cu tatal daca e mai mare le facem swap apoi tot asa
void PQ::push(int val,int prio)
{
    if(siz>capacity)throw PQover();
    siz++;
    obj a(val,prio);
    v[siz]=a;
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

int PQ::peek() const
{
    if(siz)return v[1].value;
    else throw PQgol();
}



//heap standard pop pe vector ultimul element devine primul si apoi se compara cu fii lui si ii ia locul celui mai mare asta se intampla pana cand fii sunt mai mari decat tatal
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




int PQ::length() const
{
    return siz;
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
return pq;
}


PQ& PQ::operator++()
{
for(int i=1;i<=siz;i++)
    v[i].priority=v[i].priority+1;

    return *this;
}

PQ PQ::operator++(int n)
{
    ++(*this);
    return *this;
}

//face ce a cerut
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

PQ PQ::operator--(int n)
{
    --*this;
    return *this;
}


//returneaza valoarea elementului maxim
int PQ::maxElement() const
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



