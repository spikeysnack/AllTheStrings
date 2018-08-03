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

 auto color = ats_color_init();

 cout << color["blue"] << "*************** color test *****************\n";

 string s("Dogs are man's best friend.");

 cout << color["bold"] << s << color["normal"] << "\n";
 cout << endl;  
 string t(s);

 string tmp{"best"};
 cout << endl;
 cout << "all_caps:\t" << color["green"] << all_caps(t) << color["normal"] <<"\n";
 cout << "quote:\t" << color["red"] << quote(t) << color["normal"] << "\n";
 cout << "unquote:\t" <<  color["purple"] << unquote(quote(t)) << color["normal"] << "\n";

 for ( int i = 0; i < 255; i++)
   {

    if( i>0 && !(i%16)) cout << endl; 
     cout << color256( i) <<  "[" << i << "]" << "\t";
   }

 cout << color["normal"] << endl;

 cout << colorstring( "This is a colored string." , 162 ) << endl;
 cout << colorstring( "This is a colored string." , 62 ) << endl;
 cout << colorstring( "This is a colored string." , 148 ) << endl;

 cout << color16(red) << "This should be red." <<  color16(normal) << endl;
 cout << color16(blue) << "This should be blue." <<  color16(normal) << endl;
 cout << color256(92) << "This should be purple." <<  color16(normal) << endl;
 cout << color16(bold) << "This should be white." <<  color16(normal) << endl;


 return 0;
}
