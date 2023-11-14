#include <iostream>
#include <string>
#include <cstdio>
#include <map>

#include "../AllTheStrings.H"
#include "StringTable.h"

namespace test
{
  using std::string;
  using std::cout;
  using namespace ats_string_table;
}


void table_test()
{
  using namespace test;
  
  StringTable  st = 
   StringTable(
	         {
		   {"ANIMALS", "", "" }, // header
		   {"dog", "cat", "owl"},         //table
		   {"bear", "fox", "salmon"},
		   {"worm", "bat", "mouse"}
	         }
	       );

   
string tabbed = st.tabular();

cout << "\n";

 cout << st.header() << "\n";


cout << tabbed << "\n";


 st += {"Add", "This" , "too"};

tabbed = st.tabular();

cout << tabbed << "\n";

}




int main()
{
using namespace test;

 auto color = ats_color_init();

 cout << color["purple"] << 
   "*************** singlefile header test *****************"
      << "\n";

 string s{"This way requires no install of libAllTheStrings."};
 
 cout << color["bold"] <<  color["normal"] << s << "\n";

 table_test(); 
	      

return 0;

}

