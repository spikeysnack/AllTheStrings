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

  cout << "*************** insert/remove tests *****************\n";

  string s = "This Dog LOVES  people for no REASON.";

  cout << s << endl;

  s = insert(s , "good " , 15);
  cout << "insert 16:\t" << "[" << s  << "]\n";

  s = insert_word(s , "bad" , 4);
  cout << " insert 4:\t" << "[" << s  << "]\n";

  s = remove_word (s, "bad");
  cout << "remove \"bad\":\t" << "[" << s  << "]\n";

  s = replace_word (s, "REASON", "reason");

  s = replace_word (s, "LOVES", "tolerates");
 
  cout << "replace REASON reason:\t" << "[" << s  << "]\n";
  cout << "replace bad -> good :\t" << "[" << s  << "]\n";

  return 0;

}





