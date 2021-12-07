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

string s("Dogs are man's best friend.");
cout << s << "\n";
cout << endl;  
string t(s);

string tmp{"best"};
cout << endl;
// all caps
cout << "all_caps:\t" << all_caps(t) << "\n";
cout << endl;
// quote
cout << "quote:\t" << quote(t) << "\n";
cout << endl;
// unquote
cout << "unquote:\t" <<  unquote(quote(t)) << "\n";


cout << endl;
bool b = is_sentence(t);

if (b) cout << "is_sentence" <<  endl;

cout << endl;
string x = "  This \n string Has  \r probelms \n  .\n  ";

cout << x << "\n";
cout << endl;
// chomp
cout << "chomp:\t" << chomp(x) << "\n";

cout << endl;
if ( ends_with(s, ".") ) cout << "ends_with:\t .\n";
 
cout << endl;
string y;
y = "                (y)            ";

if ( begins_with(y, " ") )  
  cout << "begins with \" \"" << "\n";

cout << endl;
cout << "trim:\t" << "[" << trim(y) << "]\n";

string z  = pad(y, 20, 'X' );

cout << "pad:\t"<<  "[" << z << "]\n";

cout << endl;

cout << "[" <<  y  << "]\n";
cout << "rem+_dblspaces:\t" << "[" << rm_dblspaces(y)  << "]\n";

cout << endl;
z = " [ q w  t e  e  4 5 66 7 77     7 888 ]";
cout << "[" <<  z  << "]\n";
cout << "[" << rm_dblspaces(z)  << "]\n";


cout << endl;
z = "1234567890aBcDeFgHiKlMnOpQrStUvWxYz";
cout <<"truncate:\t " << "[" << truncate(z, 10)  << "]\n";
cout << "all_caps:\t" << "[" << all_caps(z)  << "]\n";
cout << "incapitalize:\t" << "[" << uncapitalize(z)  << "]\n";
cout << endl;

s = "This Dog has no REASON to love men.";
cout << "[" << s  << "]\n";
cout << "sentence_case:\t" << "[" << sentence_case(s)  << "]\n";
cout << "title_case:\t" << "[" << title_case(s)  << "]\n";
cout << "[" << title_case(uncapitalize(s))  << "]\n";
cout << endl;

    
s = insert(s , "good " , 16);
cout << "insert 16:\t" << "[" << s  << "]\n";

s = insert_word(s , "bad" , 4);
cout << " insert 4:\t" << "[" << s  << "]\n";

s = remove_word (s, "bad");
cout << "remove \"bad\":\t" << "[" << s  << "]\n";

  
s = replace_word (s, "REASON", "reason");
 
cout << "replace REASON reason:\t" << "[" << s  << "]\n";

s = capitalize(s);
cout << "capitalize:\t" << "[" << s  << "]\n";

s = title_case(s);
cout << "title_case" << "[" << s  << "]\n";
  
cout << endl;
cout << "prepend:\t" << prepend( s, "Some " ) << endl;
cout << "append:\t"  << append( s, " So some say." ) << endl;
cout << "quote:\t" << quote(s) << endl;

string t1 = after(s, "man's");
cout << "after man's :\t" << t1 << endl;

auto r  =  reverse(s);

cout << "reverse:\t" << "[" << r  << "]\n";
  
cout << endl;
cout << " split" << endl;
auto v = split(s);
for( auto s : v)
  cout << s << "\t";
cout << endl;

cout << "join";
cout << endl;
t1 = join(v, ":");
cout << t1 << endl;

cout << endl;
cout << "tokenize:\t"; 
auto u = tokenize(t1, ":; ");
for( auto s : u)
  cout << s << endl;
auto w = tokenize(r, ":; ");
for( auto s : w)
  cout << s << endl;

 
cout << "random:\n";
for( size_t i = 0; i < 40 ; i++)
  cout << random(t,5) << "\t";
cout << "\n";

cout << "count o:\t";
cout << count(t, "o")  << endl;
cout << "count :\t";
cout << word_count(t, ":")  << endl;

cout << word_count(s)  << endl;

auto aa = repeat("X X" , 10);
cout << aa << "\n";


int xi =5 , yi = 100;
float af = 10.103, bf=-9.99e16;
string dd{"some enchanted evening"};

auto rv =  applytoall( reverse , xi ,yi, af, bf , dd);

for (auto s : rv)
  cout << s << "\n";

cout << rep(xi ,yi, af, bf , dd) << endl;

auto jj = join(rv, "/");

cout << jj << endl;

auto rjj = reverse(jj);

auto jjv = tokenize( rjj, "/");

for (auto s: jjv)  cout << s << "\t";

cout << endl;

string P = R"WHAT(
      This is a long paragraph that may or may not have
      a bunch of words that don't make a lot of sense, but that is just because 
      you don't have a clue as  to what is going on here. This is what we call a 
      RAW string. It has an R\"<TOKEN>( text )<TOKEN>\" enclosing it. Weird, but effective.
      I set the pagination to a small screen 40 chars.)WHAT";

cout << P << "\n" << endl;

auto Q = repaginate(P, 40, 6 , true, 5);

cout << Q << endl;


//    string sy = rep(10.2333 + 4545.4333);
//    cout << sy << endl;


cout <<  " double:\t" << std::setprecision(20) <<  fprep( 11.000002 * 35.5387, 20, std::scientific) << endl;


const double PI = 3.141592653589793;

cout << std::fixed << PI << "\n";

ats_banner();

string rf = readFile("words.txt");
 
cout << rf << endl;

 auto l = readLines( "words.txt");

 for ( auto x : l)
   cout << "line:\t" << x << endl;


 size_t wrt = writeFile( "banner.ifo" , ats_ascii_banner );

 cout << "wrote " << wrt << "bytes to banner.ifo\n";
 	
 string bann = readFile("banner.ifo");

  cout << "got all bytes " << bann.size() << "\n" ;

 cout << bann << endl;

if ( remove("banner.ifo") == 0)
  {	
   cout << "banner.ifo deleted" <<endl;
  }


 try
   {
    auto nf = readLines( "Nofile");
   }
 catch(std::exception& ex)
   {
     std::cerr <<  "Oops that failed\n" << ex.what() << endl; 
   }


return 0;

}




