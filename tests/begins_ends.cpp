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
}


int main()
{
using namespace test;

 string s{"Dogs are man's best friend."};
cout << s << "\n";

 if( begins_with( s, "Dogs") )
   cout << "begins_with [Dogs] -- success\n";
 else
   cout << "begins_with [Dogs] -- FAIL\n";

 if( begins_with_ci( s, "DOGS") )
   cout << "begins_with_ci [DOGS] -- success\n";
 else
   cout << "begins_with_ci [DOGS] -- FAIL\n";

 if( ends_with( s, "friend.") )
 else
   cout << "ends_with [friend.] -- FAIL\n";

 if( ends_with_ci( s, "FRIEND.") )
   cout << "ends_with_ci [FRIEND.] -- success\n";
 else
   cout << "ends_with_ci [FRIEND.] -- FAIL\n";

 
 
}


