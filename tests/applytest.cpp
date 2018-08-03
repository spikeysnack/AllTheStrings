#include <iostream>
#include <string>
#include <cstdio>
#include <map>

#include "AllTheStrings.h"


namespace test
{
  using std::string;
  using std::cout;
  using std::endl;
};


int main()
{
using namespace test;

cout << "*************** apply test *****************\n";

 string t = apply( reverse , "dog" , "cat", "bird", "fish", "banana");
 cout << t << "\n";
   
 svector v = applytoall( all_caps ,"dog" , "cat", "bird", "fish", "banana");
 
 for (string s: v)
   cout << s << "\n";


return 0;
}





