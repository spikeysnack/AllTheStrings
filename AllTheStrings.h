/**

 _____ _ _    _____ _          _____ _       _             
|  _  | | |  |_   _| |_ ___   |   __| |_ ___|_|___ ___ ___ 
|     | | |    | | |   | -_|  |__   |  _|  _| |   | . |_ -|
|__|__|_|_|    |_| |_|_|___|  |_____|_| |_| |_|_|_|_  |___|
                                                  |___|    

*/


/**
   AllTheStrings.h


   @author  Chris Reid <spikeysnack@gmail.com>
   @license Free for all purposes
   @copyright 2018- Chris Reid

   A collection of string utility functions
   not built-in to C  standard library

*/


/* Note:
 * If the symbol USE_SMALL_WORDS is defined
 * -D USE_SMALL_WORDS on the compilation line
 * or here as a preprocessor directive
 * then small words such as a,an, the, of ,
 * will not be capitalized in title_case.
 */

//#define USE_SMALL_WORDS



#define _GNU_SRC

#ifndef ALLTHESTRINGS_H
#define ALLTHESTRINGS_H


#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <ios>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <type_traits>

#ifdef USE_COLOR
#include <map>
#endif

#include <cassert>
#include <errno.h>
//#include <typeinfo>
//#include <cxxabi.h>





/***************************************************************************/
/* preliminaries / setups */

#if ! defined(__cplusplus)
   #error " This library needs a C++ compiler."
#else
   #if ( __cplusplus < 201103L )
   #error "C++11 or greater required."
   #endif
#endif


#if defined(_WIN64) || defined(_WIN32)
   #define _WIN 1    /* Microsoft Windows */
#endif



/* just so we can refer by name */
enum { TAB=9, SPACE=32, VTAB=11 };

const std::vector<std::string> ats_small_words;


namespace AllTheStrings
{

  using string = std::string;
  using svector = std::vector<std::string>;




  const string ats_ascii_banner{
R"BANNER(

 _____ _ _    _____ _          _____ _       _
|  _  | | |  |_   _| |_ ___   |   __| |_ ___|_|___ ___ ___
|     | | |    | | |   | -_|  |__   |  _|  _| |   | . |_ -|
|__|__|_|_|    |_| |_|_|___|  |_____|_| |_| |_|_|_|_  |___|
                                                  |___|

)BANNER"};


/***************************************************************/

  template<typename T>
  T value( const std::string& s)
  {
    T t;
    std::stringstream ss;
    ss << s;
    ss >> t;
    return t;
  }


/* function definitions */



/* information functions */
bool check_spaces( const string& in , const string& match );
bool check_spaces( const string& in , const char*  match );
bool check_spaces( const char* in , const char*  match );

bool is_quoted( const string& in);
bool is_quoted( const char* cin);

bool is_sentence( const string& in);
bool is_sentence( const char* cin);

  /* comparisons */
bool less( const string &a, const string &b );
bool less_insensive( const string &a, const string &b);
int compare(const string& a , const string& b , bool case_sensitive=true);

bool begins_with (  const string& in, const string& match);
bool begins_with (  const string& in, const char* m);
bool ends_with   (  const string& in, const string& match);
bool ends_with   (  const string& in, const char* m);


/* alteration functions */
string quote  ( const string& in);
string quote  ( const char* in);
string unquote( const string& in);

string chomp( const string& in);
string pad ( const string& in, size_t n, const char p=' ', size_t side = 0);
string rm_dblspaces( const string& in );
string truncate( const string& in , size_t n );

string rtrim( const string& in, const string& match=" ");
string ltrim( const string& in, const string& match=" ");
string trim ( const string& in, const string& match=" ");

string rtrim( const string& in, const char* m);
string ltrim( const string& in, const char* m);
string trim ( const string& in, const char* m);

string all_caps( const string& in);
#define uppercase all_caps

string uncapitalize( const string& in );
string capitalize( const string& in );
#define lowercase uncapitalize


string sentence_case( const string& in);
string title_case( const string& in);
string title_case( const char* s);

/* searching */
bool contains(const string& in , const string& match);
string find( const string& in , const string& match);
string after(const string& in , const string& match );
string before (const string& in , const string& match );



/* files with paths */
#if defined (_WIN)
string basename( const string& in , const char delim='\\');
#else
string basename( const string& in , const char delim='/');
#endif

string basename( const string& in , const string& suffix , const char delim='.');


/* multi-string  functions */
string prepend ( const string& in , const string beg );
string prepend ( const string& in , const char* s );
string append ( const string& in , const string& end );
string append ( const string& in , const char* s );

string insert( const string& in, const string& s, size_t pos );
string insert( const string& in, const char* s, size_t pos );

string insert_word( const string& in, string& word, size_t pos );
string insert_word( const string& in, const char*  wordp, size_t pos );
string remove_word( const string& in, const string& match );

string replace_word( const string& in , const string& match, const string& _replacement );
string reverse( string& s );



  /* large string operations */
std::vector<string> split(const string& in);
std::vector<string> tokenize( const string &in, const string& sep="," );
string join(const std::vector<string>& v, const string& delim=" ");
string repaginate(string& in, size_t len=80, size_t indent=0, bool indentall=false, size_t indentfirsttoo=0 );


/* generate random strings or jumbles */
string random(size_t n);
string random(size_t n, const char in[] );
string random(size_t n, const string& in);
string random(const string& in, size_t n);
string random(const string& in);



/* count characters and strings */
size_t count(const string& in, const char c);
size_t count(const string& in, const string& c);
size_t word_count(const string& in );
size_t word_count(const string& in,  const string sep);
string repeat( const string &in, size_t n );

/*  time  */


  // formatting


 __attribute__ ((format (printf, 1, 2))) string format(const char *fmt, ...);



  /* Override for systems
     that do not have std::defaultfloat
  */

// this is gcc 4.8 or less
#if defined(__GNUC__)  && (__GNUC__ <= 5 && __GNUC_MINOR__ < 1)
#define NEED_DEFAULTFLOAT
#endif


#if defined(__clang__)  && (__clang_major__ <= 3 && __clang_minor__ < 6)
#define NEED_DEFAULTFLOAT
#endif


#if defined(NEED_DEFAULTFLOAT)
// std::ios_base& (*f)(std::ios_base&)
static inline std::ios_base&
defaultfloat(std::ios_base& __base)
{
  __base.unsetf(std::ios_base::floatfield);
  return __base;
}
#endif






// floating point string format
template <class T>
string fprep(T const &t, size_t prec=8, std::ios_base& (*fmt)(std::ios_base&) = std::defaultfloat )
{

  std::stringstream ss;

      ss.precision(prec);
      ss << fmt;
      ss << t;
      return ss.str();
} // rep



// non-fp rep
template <class T>
string rep(T const &t, size_t prec=8, std::ios_base& (*fmt)(std::ios_base&) = std::defaultfloat )
{

  std::stringstream ss;

  if ( std::is_floating_point<T>::value ) return fprep( t, prec, fmt);

  ss << t;
  return ss.str();
} // rep


// multiple args

template<typename T, typename... Args>
string rep(T arg, const Args&... args)
{
    return rep(arg) + " " + rep(args...);
} // rep


/* functional */
template<typename F, typename... Args>
string apply (F &func, const Args&... args)
{
    string buffer = rep(args...);
    return func(buffer);
} // apply




template<typename F, typename... Args>
std::vector<string> applytoall (F &func, const Args&... args)
{
    string buffer = rep(args...);

    std::vector<string> svec = split(buffer);

    for( auto& s :svec)
      s = func(s);

   return svec;
} // applytoall


/** interpolate tokens in a string and replace them with an argument list.

   interpolate( "This is {1} and {2} and {3}." , "one" , "two", "three")

   yields

   "This is one  and two and three."

*/
template<typename S, typename... Args>
string interpolate( const S& orig , const Args&... args)
{
   string out(orig);

   // populate vector from argument list
   //auto va {args...};
   //std::vector<string> v{va};
   std::vector<string> v{args...};

   size_t i = 1;

   for( string s: v)
     {
       string is = std::to_string(i);
       string t = "{" +  is + "}";  // "{1}", "{2}", ...
       try
	 {
	   auto pos = out.find(t);

	   if ( pos != out.npos)  // found token
	     {
	       out.erase(pos, t.length()); //erase token
	       out.insert( pos, s);       // insert arg
	     }
	   i++;                           // next
	 }
	 catch( std::exception& e)
	   {
	     std::cerr << e.what() << std::endl;
	   }

     } // for

   return out;
}



/* misc */
void ats_banner( std::ostream& os = std::cout );
void print(string const &s);
void println(string const &s);
#define eprintf(format, ...) \
  fprintf (stderr, format __VA_OPT__(,) __VA_ARGS__)



  /* FIle IO  */
string readFile( const string& filename);

std::vector<string> readLines( const string& filename, const string& sep="\n" );

size_t writeFile( const string& filename , const string& data, std::ios_base::openmode mode = std::ios::out);

#define appendFile( f , d ) writeFile( f, d ,  std::ios::out|std::ios::app)



#ifdef USE_COLOR

/* these output ANSI COLOR STRINGS */
enum color_16
  {
    BLACK=0, RED = 1, GREEN=2, YELLOW=3, BLUE=4, MAGENTA=5, CYAN=6,  WHITE=7,
    GRAY=8, BRIGHTRED=9,  BRIGHTGREEN=10,BRIGHTYELLOW=11, BRIGHTBLUE=12,
    BRIGHTMAGENTA=13, BRIGHTCYAN=14, BRIGHTWHITE=15,
    black=BLACK, yellow=YELLOW, red=RED, green=GREEN, blue=BLUE, cyan=CYAN,
    gray=GRAY, white=WHITE, bold=BRIGHTWHITE, normal=white
  };

string color16( color_16  c);

// 256-color ANSI strings
typedef unsigned short color_256;


string color256( color_256 c);

// color a string and return to normal after
string colorstring(const string& s, color_256 n);

// returns a map of color strings -- color["red"], color["blue"], ...
std::map<string,string> ats_color_init();



#endif // USE_COLOR


} // namespace AllTheStrings

/* automatically adds */
using namespace AllTheStrings;

#endif // ALLTHESTRINGS_H


/* END */

/* Local Variables: */
/* mode: C++        */
/* End:             */

/* vim: setlocal ft=cpp */
