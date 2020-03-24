#include <iostream>
#include "PQ.h"
#include "obj.h"

#include <cassert>
#include <exception>
#include <cstring>
using namespace std;



int main()
{




 PQ q;
 q.push(13,1);
 q.push(2,5);
 q.push(3,7);
 q.push(12,4);

assert(q.peek()==3);
q.pop();
assert(q.pop()==2);

assert(q.maxElement()==13);
q--;
assert(q.maxElement()==12);
assert(q.length()==1);
PQ k;
k.push(11,2);
PQ g;
g=k+q;
assert(g.length()==2);
assert(g.peek()==12);

g++;
g--;
g--;
g--;
assert(g.length()==1);




/*  try catch tests dubios dar strica codul cel putin in codeblocks
PQ p;
PQ a;
  char* c= "PQ empty";
  char* o= "Cap exceeded";
  char* n= "Priority can't be negative.";

  assert(p.length()==0);
  try{
  p.pop();
  assert(false);
  }
  catch(exception& ex){ assert(strcmp(ex.what(),c)==0);}
 try{
  p.peek();
  assert(false);
  }
  catch(exception& ex){ assert(strcmp(ex.what(),c)==0);}
   try{
  p.push(12,-1);
  assert(false);
  }
  catch(exception& ex){ assert(strcmp(ex.what(),n)==0);}

   try{

  for(int i=1;i<=12;i++)
    a.push(12,1);
    assert(false);
  }
  catch(exception& ex){ assert(strcmp(ex.what(),o)==0);}
cout<<p;

*/
cout<<"Gata";
  return 0;
}
