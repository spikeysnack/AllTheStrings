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

 cout << "********** ATS BASIC FUNCTIONS ***********\n";

 string s{"Dogs are man's best friend."};
cout << s << "\n";
cout << endl;  


string t{s};
string tmp{"best"};

cout << endl;
// all caps
cout << "all_caps:\t" << all_caps(t) << "\n";

cout << endl;
// quote
cout << "quote:\t" << quote(t) << "\n";

cout << endl;
// unquote
cout << "unquote:\t" <<  unquote(quote(t)) << endl;
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
cout << "uncapitalize:\t" << "[" << uncapitalize(z)  << "]\n";

string fn("A file name.txt");
fn = basename( fn , "txt");
cout << "[" << fn << "]\n";


string fn2("Another-file name.txt");
fn2 = basename( fn2 , "txt", '.' );
cout << "[" << fn2 << "]\n";


string fn3("c:\\a\\long path\\for \\a\\file\\Another-filename.txt");
cout << "[" << fn3 << "]\n";

fn3 = basename( fn3 ,  '\\' );
cout << "[" << fn3 << "]\n";


string fn4("c:/a/long path/for/a/file/filename.txt");
cout << "[" << fn4 << "]\n";

 fn4 = basename( fn4 );

cout << "[" << fn4 << "]\n";

cout << endl;
return 0;
}






