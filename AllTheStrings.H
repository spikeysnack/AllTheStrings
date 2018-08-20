/*
 _____ _ _    _____ _          _____ _       _             
|  _  | | |  |_   _| |_ ___   |   __| |_ ___|_|___ ___ ___ 
|     | | |    | | |   | -_|  |__   |  _|  _| |   | . |_ -|
|__|__|_|_|    |_| |_|_|___|  |_____|_| |_| |_|_|_|_  |___|
                                                  |___|    

*/


/**
   AllTheStrings.H  
   
   single header library version

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

// #define USE_SMALL_WORDS


#define _GNU_SRC

#ifndef ALLTHESTRINGS_H
#define ALLTHESTRINGS_H

/* libC */
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cctype>
#include <cstring>
#include <cstdarg>
#include <chrono>
#include <ctime>
#include <cerrno>
#include <cassert>
#include <errno.h>

/* STL */
#include <ios>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>
#include <ctime>
#include <utility>
#include <type_traits>

#ifdef USE_COLOR
    #include <map>
#endif

#ifdef USE_EXCEPTIONS
    #include <exception>
    #include <stdexcept>
#endif



namespace AllTheStrings
{


  using std::string;
  using svector = std::vector<std::string>;


/***************************************************************************/
/* preliminaries / setups */

#if ! defined(__cplusplus)
   #error " This library needs a C++ compiler."
#else
   #if ( __cplusplus < 201103L )
   #error "C++11 or greater required."
   #endif
#endif


  /* Override for systems that do not have std::defaultfloat */

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



#if defined(_WIN64) || defined(_WIN32)
   #define _WIN 1    /* Microsoft Windows */
#endif


  // error print
#define eprintf(format, ...) \
  fprintf (stderr, format __VA_OPT__(,) __VA_ARGS__)


void print(string const &s) { std::cout << s; }

void println(string const &s) { std::cout << s << "\n"; }



/*********************************************************/
/* just so we can refer by name */
enum { TAB=9, SPACE=32, VTAB=11 };


  const string ats_ascii_banner{
R"BANNER(

 _____ _ _    _____ _          _____ _       _
|  _  | | |  |_   _| |_ ___   |   __| |_ ___|_|___ ___ ___
|     | | |    | | |   | -_|  |__   |  _|  _| |   | . |_ -|
|__|__|_|_|    |_| |_|_|___|  |_____|_| |_| |_|_|_|_  |___|
                                                  |___|

)BANNER"};


/* Note:
 * If the symbol USE_SMALL_WORDS is defined
 * -D USE_SMALL_WORDS on the compilation line
 * or here as a preprocessor directive
 * then small words such as a,an, the, of ,
 * will not be capitalized in title_case.
 */

#ifdef USE_SMALL_WORDS
/* from : New York Times Manual of Style */

const svector ats_small_words =
  {
    "A", "An", "And", "As", "At", " But", "By",
    "En" , "For", "If", "In", "Is" ,
    "Of", "On", "Or", "The", "To", "Via", "Vs"
  };

#endif


  /* an alphanumeric string for ASCII */

const char ats_alphanumeric[] =
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz"
  "0123456789"
  "!@#$%^&*";





/*************************************************/


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
  //size_t word_count(const string& in );
size_t word_count(const string& in,  const string sep);
string repeat( const string &in, size_t n );


/*************************************************/
 __attribute__ ((format (printf, 1, 2))) string format(const char *fmt, ...);



/*************************************************/
/****************** TEMPLATES ********************/

  template<typename T>
  T value( const std::string& s)
  {
    T t;
    std::stringstream ss;
    ss << s;
    ss >> t;
    return t;
  }


// floating point string format
template <class T>
string fprep(T const &t, size_t prec=8, std::ios_base& (*fmt)(std::ios_base&) = defaultfloat )
{

  std::stringstream ss;

      ss.precision(prec);
      ss << fmt;
      ss << t;
      return ss.str();
} // rep



// non-fp rep
template <class T>
string rep(T const &t, size_t prec=8, std::ios_base& (*fmt)(std::ios_base&) = defaultfloat )
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
   auto va {args...};
   std::vector<string> v{va};

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






/* Check if the word is surrounded by spaces.
 * true means the word is surrounded
 * on both sides by a space character.
*/
bool check_spaces( const string& in , const string& match )
{

  auto b = in.find(match);

  if ( b == in.npos) return false;   // not found

  auto e = b + match.length();

  if  ( (b == 0 ) || ( e == in.length() ) ) return false;

  return ( std::isspace(in[b-1]) && std::isspace(in[e]) );

} // check_spaces



bool check_spaces( const string& in , const char*  match )
{
  return check_spaces( in, string{match} );
}


bool check_spaces( const char* in , const char*  match )
{
  return check_spaces( string{in}, string{match} );
}


/* check if string is surrounded  by double-quotes */
bool is_quoted(const string& in)
{

  auto start = in.begin();
  auto end   = in.end();

  if (( *start == '\"') && ( *(end-1) == '\"') )
    return true;
  else
    return false;
} // is_quoted


/* check if string is surrounded  by double-quotes */
bool is_quoted(const char* cin)
{
  return is_quoted(string{cin});
} // is_quoted



/* check for capital first letter and period at end */
bool is_sentence(const string& in)
{

  enum
  {
    PERIOD    = '.',
    QUESTION  = '?',
    EXCLMARK  = '!'
  };

  bool quoted   = false;
  bool sentence = false;

  auto start     = in.begin();
  auto end       = in.end();


  quoted = is_quoted(in);

  /* handle double-quoted sentence */
  if (! quoted )
    { start = in.begin(); end = in.end()-1; }
  else
    { start = in.begin()+1; end = in.end()-2; }


  /* check capitalization of the first char */
  if ( std::islower(*start) )  goto fin;

  /* check end char */
  if (     (*end == PERIOD)
	   || (*end == QUESTION)
	   || (*end == EXCLMARK) )
    sentence = true;

 fin:
  return sentence;
} // is_sentence


bool is_sentence(const char* cin)
{
  return is_sentence( string{cin} );
}



/* returns a copy of a string with
 * double-quotes around it,
 * unless it is already quoted then a straight copy */
string quote( const string& in)
{
  string qt("\"");
  string out{in};

  if ( ! is_quoted(out) )
    out =  qt + out + qt;
  return out;
} //quote


string quote( const char* in)
{
  return quote( string{in} );

}



/* returns a copy of a string with
 * the quotes removed  or a copy if
 * it is not quoted */
string unquote( const string& in)
{

  string out = in;

  if (! is_quoted(in) ) return out;

  out = string(out.begin()+1 , out.end()-1);

  return out;

} //unquote



/* carriage returns and newline characters
 * are removed throughout the whole string.
 * The null char "\0" at the end is retained.
 */
string chomp( const string& in)
{
  string out{in};

  out.erase( std::remove( out.begin() , out.end(), '\t'), out.end());

  out.erase( std::remove( out.begin() , out.end(), '\r'), out.end());

  out.erase(std::remove(out.begin(), out.end(), '\n'), out.end());

  out = rm_dblspaces(out);

  return out;

} // chomp


bool begins_with(  const string& in, const string& match)
{
    if (in.compare(0, match.length(), match) == 0) return true;
    return false;
} // begins_with


bool begins_with(  const string& in, const char* m)
{
  return begins_with( in, string{m} );
}


bool ends_with(  const string& in, const string& match)
{
  size_t len = match.length();

  string cmp( (in.end()-len), in.end() );

  return cmp.compare(match) == 0;

} // ends_with


bool ends_with(  const string& in, const char* m)
{
  return ends_with( in, string{m} );
}


string ltrim( const string& in, const string& match )
{
  string out{in};

  while( begins_with(out, match) )
      out = string( out.begin() + match.length() , out.end() );

  return out;

} // ltrim


string ltrim( const string& in, const char* m)
{
  return ltrim( in, string{m} );
}

  /*
string ltrim( const string& in )
{
  return ltrim(in, " ");
} // ltrim
  */


string rtrim( const string& in, const string& match)
{
  string out{in};

  while ( ends_with( out, match) )
    out = string( out.begin() , out.end() - match.length() );

  return out;
} // rtrim


string rtrim( const string& in, const char* m)
{
  return rtrim( in, string{m} );
}


string trim( const string& in, const string& match)
{
  return rtrim( ltrim( in, match), match );
}

string trim( const string& in, const char* m)
{
  return trim(in , string{m});
}

/* pad string(right) with n ' ' (space) characters */
string pad( const string& in, size_t n, const char p , size_t side )
{
  string out{in};

  size_t len = out.length();

  out.reserve( len + n);

  switch(side)
    {
    case 0:   { out.insert(len, n, p);          break; }
    case 1:   { out.insert(out.begin(), n, p);  break; }
    case 2:
      {
	out.reserve( len + 2*n);
	out.insert(out.begin(), n, p);
	out.insert(len, n, p);
      }
    }

  return out;
} // pad


string pad( const string& in, size_t n, const char p , string s )
  {
    string out;
    if ( s.compare("left")  == 0 )  out = pad(in, n, p, 0);
    if ( s.compare("right") == 0 )  out = pad(in, n, p, 1);
    if ( s.compare("both")  == 0 )  out = pad(in, n, p, 2);

    if ( out.empty() ) return string{in};

    return out;
  }



/* Remove runs of spaces of two or more.
 * The string is scanned until all
 * double spaces are removed.
 */
string rm_dblspaces( const string& in )
{
  string dblspc{"  "}; // len 2
  string spc{" "};     // len 1

  string out{in};
  size_t f;
do
  {
    f = out.find(dblspc);
    if ( f != out.npos) out.erase(f, 1);
  } while(f != out.npos);

  return out;

} //rm_dblspaces


/* returns a copy of a  string& cut off at n chars
 * ( truncate is a file length function in unistd.h
 * so truncate_string  will have to serve as a function name.) */
string truncate( const string& in, size_t n )
{
  auto b = in.begin();

  n = (n>in.length())? in.length() : n;

  string out(b, b+n);

  return out;

} // truncate




/* returns a copy of a string with every letter capitalized */
string all_caps( const string& in)
{
 string out{in};

  std::transform(out.begin(), out.end(), out.begin(),
		 [](unsigned char c){ return std::toupper(c); });

  return out;

} // all_caps



// capitalize each word
string capitalize( const string& in )
{
  string out{in};

  auto p = out.begin();
  auto q = p+1;

  while(q != out.end())
    {
      if ( std::isblank(*p) )
	  *q = std::toupper(*q);

      p++;
      q++;
    }

  return out;
} // capitalize


/* Uncapitalise every letter in string */
string uncapitalize( const string& in )
{
 string out{in};

  std::transform(out.begin(), out.end(), out.begin(),
		 [](unsigned char c){ return std::tolower(c); });

  return out;

} // uncapitalize



string sentence_case( const string& in)
{
  string out{in};


  out[0] = std::toupper(out[0]);

  auto p = out.begin()+1;

  while(p != out.end())
    {
      *p = std::tolower(*p);
      p++;
    }

  return out;
} // sentence_case



/* Capitalise every word in the string.
 * If USE_SMALL_WORDS is defined then
 * the words in the small_words list
 * are not capitalized.
 */
string title_case( const string& in)
{
  // make all capitalized
  string out{capitalize(in)};

#ifdef USE_SMALL_WORDS
  // check small words list
  std::vector<size_t> positions;
  size_t pos;

  for( auto s : ats_small_words )
    {
      pos = out.find(s, 0);
      if ( pos == out.npos) continue;

      bool firstchar = (pos == 0);      // first char or surrounded by spaces
      bool spaced = check_spaces(out, s);

      if ( firstchar || spaced )// must be a standalone word
	{
	  while(pos != out.npos)
	    {
	      positions.push_back(pos);
	      pos = out.find(s, pos+1);
	      if ( pos == out.npos) continue;
	    }
	}
      else
	continue;
    }

  for(size_t p : positions) out[p] = std::tolower(out[p]);

#endif
  return out;

} // title_case


string title_case( const char* s)
{
  return title_case( string{s} );
}


/* a string is added to the beginning of a string */
string prepend ( const string& in , const string beg )
{
  return string (beg  + in );

} // prepend

string prepend ( const string& in , const char* s )
{
  return prepend( in, string{s} );
}

/* A string is added to the end of a string
 * A new string is returned. */
string append ( const string& in , const string& end )
{
  return string(in + end );
} // append


string append ( const string& in , const char* s )
{
  return append( in, string{s} );
}


/* inserts a string in the middle of another string
 * at pos letters in. The string is split and the
 * end part is attached after the inserted string */

string insert( const string& in, const string& s , size_t pos )
{
  string out{in};

  out.insert(pos,s);

  return out;

} // insert


string insert( const string& in, const char* s , size_t pos )
{
  return insert( in , string{s} , pos);
}



/* Like insert above,  but inserts spaces
 * on both sides of the word.
 */

string insert_word( const string& in, const string& word, size_t pos )
{
  size_t end = pos + word.length();

  string out{in};

  string w{word};

  const string spc(" ");

  if( out[end] != ' ') w = w + spc;

  if( out[pos] == ' ')
    pos++;
  else
    w = spc + w;

  return insert( in, w, pos);

} //insert_word


string insert_word( const string& in, const char*  wordp, size_t pos )
{
  return insert_word(in, string{wordp} , pos);
}


/* removes a word from a string and resizes to proper size.
 * if the string is a sentence, and the words we want to remove
 * is at the end, we check for commas and periods
 * and chop them out.
 */

string remove_word( const string& in, const string& match )
{

  size_t pos;

  string out{in};

  pos = out.find(match);

  if (pos != string::npos)
    out.erase(pos, match.length());

  out = rm_dblspaces(out);

  return out;

}// remove_word */



/* The word is searched for a match,
 * and the match is replaced with the new string.
 * The string is split and the end is reattached
 * after the insert, with according lengthening
 * or shortening.
 *
 */
string replace_word( const string& in , const string& match, const string& replacement )
{
  string out{in};

  size_t f = out.find(match);

  if ( f != out.npos)
    {
      out.replace(f, match.length(), replacement);
    }

  return out;

} // replace_word



/***************************************************/
/* find a substring and return it */

string find( const string& in , const string& match)
{

  string out{in};;

  size_t f = out.find(match);

  if (f != out.npos)
    {
      out = match;
    }

  return out;
}


bool contains( const string& in , const string& match)
{
  size_t f = in.find(match);

  return  (f < in.npos);
}




string basename( const string& in , const char delim)
{

  // std::cerr << "basename(string, char)\n";
  string base{in};

  auto last = base.find_last_of(delim);

  if ( last == base.npos )
    {
      return base;
    }

  auto tail = base.begin() + last +1;
  return std::string( tail , base.end() );
}



string basename( const string& in , const string& suffix, const char delim)
{
  string base{in};
  string suff{suffix};

  const char* d = &delim;

  if (*d != '\0') suff = string{d} + suff;

  size_t pos = base.rfind(suffix);

  if ( pos != base.npos )
    if ( ends_with(base, suffix) ) base.erase(pos-1);

  return base;
}





/* find a substring and return the rest of the  string after it */
string after(const string& in , const string& match )
{
  string out{in};

  size_t f = out.find(match);

  if (f != out.npos) out = string( out.begin() + f +match.length() , out.end() );
  else
    out = {};

  return out;
}




/* find a substring and return the substring before it */
string before (const string& in , const string& match )
{
  string out{in};

  auto beg = out.begin();

  size_t f = out.find(match);

  if (f != out.npos)
    {
      out = string( beg , beg+f);
    }
  else
    out = {};

  return out;

} // before



int compare(const string& a , const string& b , bool case_sensitive)
{

  if (case_sensitive)
    return a.compare(b);
  else
    return lowercase(a).compare( lowercase(b) );

} // compare



string reverse( string& in )
{
  //  std::cerr << "reverse(" << in << ")\n";

  string out{in};

  size_t i = 0;
  size_t m = out.length();
  size_t n = m/2;

  while (i < n)
    {
      std::swap( out[i], out[m -i -1] );
      i++;
    }

  return out;
} // reverse




svector split(const string& in)
{

  std::stringstream ss{in};
  svector svec;

  for( string s ; ss >> s;) svec.push_back(s);

  return svec;
} // split





svector tokenize( const string  &in, const string& sep )
{
  size_t b{0}, e{0};

  svector svec;

  while ( (b = in.find_first_not_of(sep, b) ) != in.npos )
    {
      e = in.find_first_of(sep, b);
      svec.push_back( in.substr( b, e-b) );
      b = e;
    }

  return svec;
} // split



string join(const svector& v, const string& delim)
{
  string out;

  for( auto s : v)
    {
      out += s;
      out +=delim;
    }

  out.erase(out.end()-1);

  return out;
} // join




string random(size_t n=1, const char in[]=ats_alphanumeric)
{

  // static const char ats_alphanum[] =
  //   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  //   "abcdefghijklmnopqrstuvwxyz"
  //   "0123456789"
  //   "!@#$%^&*";

  size_t len{strlen(in)};
  std::random_device rd;
  std::mt19937 mt{rd()};
  std::uniform_int_distribution<size_t> dist(0, len) ;

  char c;
  string out;

 for (size_t i = 0; i < n ; i++)
   {
     c = in[dist(mt) % len];
     out += c;
   }

 return out;
} // random


string random(const string& in)
{
  return random( in.length(), in );
}

string random(const string& in, size_t n)
{
  return random( n , in );
}


string random(size_t n=1)
{
  return random(n, ats_alphanumeric);
}

string random(size_t n=1, const string& in = ats_alphanumeric)
{
  return random(n, in.c_str() );
}

/* how many chars c in string? */
size_t count(const string& in, const char c)
{
  return std::count(in.begin(), in.end(), c);
}


size_t count(const string& in, const string& s)
{
  size_t n{0};

  for (char c : s)
    {
      n += count(in, c);
    }

  return n;
}


// size_t word_count(const string& in)
// {
//   return word_count(in, " ");
// }


size_t word_count(const string& in,  const string sep=" ")
 {
   auto v = tokenize( in, sep );
   return v.size();
 }




string repeat( const string &in, size_t n )
{
   string out;
   size_t len{in.length()};
   out.reserve(n*len);
   for ( size_t i=0 ; i <n ;i++ ) out += in ;
   return out;
} // repeat


/* take a paragraph string and format it for a page output */
string repaginate(string& in, size_t len , size_t indent, bool indentall, size_t indentfirsttoo )
{

  string out;

  svector words{split(chomp(in))};
  svector lines;
  std::vector<size_t> word_len;
  string indentspaces(indent, ' ');
  string firstindent (indentfirsttoo, ' ');
  bool noindent =  indentspaces.empty();
  if ( indent > 0) words[0] = words[0].insert(0, indentspaces);
  if ( indentall & (indentfirsttoo > 0) ) words[0].insert( 0, firstindent);

  bool firstline{true};
  size_t charlen{0}, wordlen{0};

  // determine words/line
  for ( auto s: words )
    {
      wordlen += 1;
      charlen += s.length();

      if(charlen > len)
	{
	  word_len.push_back(wordlen);
	  wordlen = 0;
	  charlen = 0;	
	}

    }

  word_len.push_back(wordlen); // last line

  svector::iterator current = words.begin();
  string joined;

  for( size_t n : word_len)
    {
      svector v( current, current+n);
      joined = join(v, " ");
      lines.push_back( join(v) );
      joined.clear();
      v.clear();

      current = current+n;
    }

  firstline = true;

  for( auto s : lines)
    {
      if  ( (!noindent) && indentall )
	{
	  if ( ! firstline) out += indentspaces;
	  firstline=false;
	}

      out += s + "\n";
    }

  return out;
}// repaginate


  /* a case-sensitive less-than for use in sorting functions */
struct less_sensitive : public std::binary_function< char,char,bool >
 {
   bool operator () (char a, char b) const
   {
     unsigned char x(static_cast<unsigned char>(a));
     unsigned char y(static_cast<unsigned char>(b));
     return  x < y;
   }
};


  /* a case-insensitive less-than for use in sorting functions */
struct less_insensitive : public std::binary_function< char,char,bool >
 {
   bool operator () (char a, char b) const
   {
     unsigned char x(static_cast<unsigned char>(a));
     unsigned char y(static_cast<unsigned char>(b));
     return std::toupper(x) < std::toupper(y);
   }
};



bool less(const string &a, const string &b)
 {
   return std::lexicographical_compare( a.begin(), a.end(), b.begin(), b.end(), AllTheStrings::less_sensitive() );
 }


bool less_insensive(const string &a, const string &b)
 {
   return std::lexicographical_compare( a.begin(), a.end(), b.begin(), b.end(), AllTheStrings::less_insensitive() );
 }


void ats_banner( std::ostream& os){ os << ats_ascii_banner; }


  /* File I/O */
#ifdef USE_EXCEPTIONS

/* my own private ats exception */
struct ats_Exception : public std::runtime_error
{
  ats_Exception(const string& what) : std::runtime_error( string{"ats_exception:\t"} + what ) {}
};
#endif


string readFile( const string& filename)
{
#ifdef USE_EXCEPTIONS
  try
    {
#endif
      std::ifstream in(filename, std::ios::in);

#ifdef USE_EXCEPTIONS
      in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
#endif

      in.seekg(0, std::ios::end);

      size_t len = in.tellg();

      string contents(len+1, '\0');

      in.seekg(0);

      in.read(&contents[0], len);

      return contents;
#ifdef USE_EXCEPTIONS
    }

  catch(...)
    {
      std::throw_with_nested( ats_Exception( string{"can't read file: "} + filename ) );
    }
#endif

}// readFile


svector readLines( const string& filename, const string& sep )
{

  string contents{readFile(filename)};

  return tokenize( contents, sep );
}



size_t writeFile( const string& filename , const string& data, std::ios_base::openmode mode)
{
  size_t written{0};

#ifdef USE_EXCEPTIONS
try
  {
#endif

  if (data.empty() ) return 0;

  std::ofstream outfs(filename, mode );

#ifdef USE_EXCEPTIONS
  outfs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
#endif

  outfs << data;

  written = data.size();

  outfs.close();

  return written;

#ifdef USE_EXCEPTIONS
  }

 catch(const std::ofstream::failure& f)
   {
     std::throw_with_nested( ats_Exception( string ("writeFile:\t") + filename + f.what() ) );
   }
 catch(string& err)
   {
     std::throw_with_nested( ats_Exception( err ) );
   }
 catch(std::exception&  se )
   {
     std::throw_with_nested( ats_Exception( string{"An error occurred:"} + se.what() ));
   }
#endif


} // writeFile

  // format
__attribute__ ((format (printf, 1, 2))) string format(const char *fmt, ...)
  {

    string out;

    char buffer [512];

    std::va_list args;

    va_start(args, fmt);

    std::vsnprintf(buffer, 512, fmt, args);

    va_end(args);

    size_t sz = std::strlen(buffer) + 1;

    out.resize( sz);

    out.assign( buffer,  buffer + sz);

    return out;
  }

/** ANSI COLOR ABILITIES */

#ifdef USE_COLOR

#define ANSI_RED     "\033[31m"
#define ANSI_GREEN   "\033[32m"
#define ANSI_YELLOW  "\033[33m"
#define ANSI_BLUE    "\033[34m"
#define ANSI_MAGENTA "\033[35m"
#define ANSI_CYAN    "\033[36m"
#define ANSI_PURPLE "\033[0;35m"
#define ANSI_BROWN  "\033[0;33m"
#define ANSI_GRAY   "\033[0;37m"
#define ANSI_DARKGRAY  "\033[1;30m"
#define ANSI_WHITE   "\033[1;37m"
#define ANSI_RESET  "\033[0m"
#define ANSI_BOLD   "\033[1m"

string color16( color_16  c)
{
 std::stringstream ss;
 ss << "\033[0;38;5;" << c << "m";
 return ss.str();
}


string color256( color_256 c)
{
  std::stringstream ss;
   ss << "\033[0;38;5;" << c << "m";
  return ss.str();
}


string colorstring(const string& s, color_256 n)
{
  string color{color256(n)};
  string normal{ANSI_RESET};
   return color + s + normal;
}


std::map<string,string> ats_color_init()
{
  std::map<string,string> color;

  color["normal"]  = ANSI_RESET;
  color["red"]     = ANSI_RED;
  color["green"]   = ANSI_GREEN;
  color["blue"]    = ANSI_BLUE;
  color["cyan"]    = ANSI_CYAN;
  color["magenta"] = ANSI_MAGENTA;
  color["yellow"]  = ANSI_YELLOW;
  color["purple"]  = ANSI_PURPLE;
  color["brown"]   = ANSI_BROWN;
  color["gray"]    = ANSI_GRAY;
  color["white"]   = ANSI_WHITE;
  color["bold"]    = ANSI_BOLD;

 return color;
}

#endif // color

} // namespace AllTheStrings


/* automatically adds */
using namespace AllTheStrings;

#endif // ALLTHESTRINGS_H





/*END*/


/* Local Variables: */
/* mode: C++        */
/* End:             */

/* vim: setlocal ft=cpp */
