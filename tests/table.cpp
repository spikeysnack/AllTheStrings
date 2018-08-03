//Here is a possible implementation using C++11 (here I expect all vectors to have the same size):
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <exception>

#include "StringTable.h"


int main()
{

 using namespace ats_string_table;
 
 StringTable st{ "A", "B", "C"};

 st.addRow( "1", "2", "3");
 st.addRow( "4", "5", "6");
 st.addRow( "7", "8", "9");


 std::cout << st.header() << "\t";

 std::cout << std::endl;

 svec sv = st.col(1);

 for (string s: sv )
   std::cout << s << "\t";

 std::cout << std::endl;

 sv = st.row(1);

 for (string s: sv )
   std::cout << s << "\t";

 std::cout << std::endl;
 std::cout << std::endl;

 string tabbed = st.tabular();
 
 std::cout << tabbed << std::endl;

 std::cout << std::endl;


 string mid = st.get(1,1);

 std::cout << "mid: " << mid << std::endl;


 auto f = st[2];

 for ( auto s :f)
   std::cout << s << ", ";

 std::cout << std::endl;



 std::cout << st.get(0,2) << std::endl;

 st.addRow("10","11","12");

 
 tabbed = st.tabular();
   
std::cout << tabbed << std::endl;

 st.remove_row(3);
 tabbed = st.tabular();

std::cout << std::endl;
std::cout << tabbed << std::endl;

 auto x = st[2][2];

 std::cout << x << std::endl;

 st = 
   StringTable(
	         {
		   {"ANIMALS", "", "" }, // header
		   {"dog", "cat", "owl"},         //table
		   {"bear", "fox", "salmon"},
		   {"worm", "bat", "mouse"}
	         }
	       );

   
tabbed = st.tabular();

std::cout << std::endl;

 std::cout << st.header() << std::endl;


std::cout << tabbed << std::endl;


 st += {"Add", "This" , "too"};

tabbed = st.tabular();

std::cout << tabbed << std::endl;




  return 0;
}

