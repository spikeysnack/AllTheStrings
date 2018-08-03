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

  cout << "*************** value test *****************\n";

  string s;
  int i;
  float f;
  double d;
  char c;
  
  s = "3.14159";
  i = value<int>(s);
  f = value<float>(s);
  d = value<double>(s);
  c = value<char>(s);
  
  std::cout <<"string: " <<  s << "\n";   
  std::cout <<"int: "    <<  i << "\n";   
  std::cout <<"float: "  <<  f << "\n";   
  std::cout <<"double: " <<  d << "\n";   
  std::cout <<"char: "   <<  c << "\n"; 

  std::cout << std::endl; 

  
  s = "ABCDEFG";

  i = value<int>(s);
  f = value<float>(s);
  d = value<double>(s);
  c = value<char>(s);

  std::cout <<"string: "  <<  s << "\n";   
  std::cout <<"int: "     <<  i << "\n";   
  std::cout <<"float: "   <<  f << "\n";   
  std::cout <<"double: "  <<  d << "\n";   
  std::cout <<"char: "    <<  c << "\n"; 
  std::cout << std::endl; 

  
  return 0;

}





