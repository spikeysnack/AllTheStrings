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



cout << "*************** format/ interpolation  test *****************\n";

string formatstr("this is a %s string:\t%zu\t%f and all that %s \n");

string bb = format( formatstr.c_str() , "format" , 567 , 3.14159 , "stuff", 13  );
cout << bb ;
 
bb = format( "%f\n", -10.2 );
cout << bb  << endl;

bb = format( "%lf\n", -10.2 );
cout << bb  << endl;


string s{"this is {4} and {2} and {3}."};

string a{"one"}, b{"two"} , c{"three"}, d{"four"};

string t = interpolate( s , a , b, c , d);

std::cout << t << std::endl;


return 0;

}





