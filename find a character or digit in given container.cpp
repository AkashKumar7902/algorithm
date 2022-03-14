#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<stack>
using namespace std;

int main() {
    int val=42;
    vector<int> v={1,24,56,42};
    auto it=find(v.cbegin(),v.cend(),val);
    cout<<"the value "<<val<<
        (it==v.cend()?" is not present":" is present")<<endl;
}

/*
The  first  two  arguments  to  find  are  iterators  denoting  a  range  of  elements,  
and  the third  argument  is  a  value.
  find  compares  each  element  in  the  given  range  to  the given  value.
  It  returns  an  iterator  to  the  first  element  that  is  equal  to  that  value. 
 If there  is  no  match,  find  returns  its  second  iterator  to  indicate  failure.
  Thus,  we  can determine  whether  the  element  was  found  by  comparing 
 the  return  value  with  the second  iterator  argument.
  We  do  this  test  in  the  output  statement,
 which  uses  the conditional  operator  (§  4.7,  p.  151)
  to  report  whether  the  value  was  found.
*/
