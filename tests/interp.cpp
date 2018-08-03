#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;



template<typename S, typename... Args>
string interpolate( const S& orig , const Args&... args)
{
  string out{orig};

   auto va {args...};
   vector<string> v{va};
   
   size_t i = 1;
   
   for( string s: v)
     {
       string is = std::to_string(i);
       string t = "{" +  is + "}";
       try
	 {
	   auto pos = out.find(t);

	   if ( pos != out.npos)
	     {
	       out.erase(pos, t.length());
	       out.insert( pos, s); 
	     }
	   i++;
	 }
	 catch( std::exception& e)
	   {
	     std::cerr << e.what() << std::endl;
	   }


     } // for

   return out;
}


int main()
{

  string s{"this is {4} and {2} and {3}."};

  string a{"one"}, b{"two"} , c{"three"}, d{"four"};

  string t = interpolate( s , a , b, c , d);


  std::cout << t << std::endl;


}
