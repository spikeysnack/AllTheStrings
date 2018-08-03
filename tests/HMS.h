/* HMS.h */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

#include "AllTheStrings.h"

#ifndef HMS_H
#define HMS_H

class HMS
{
private:
  size_t duration;
  size_t hrs;
  size_t mins;
  size_t secs;
  
public:

  HMS(size_t d): duration(d)
  {
    hrs = duration / 3600;
    mins = (duration - (hrs*3600))/60;
    secs = duration - (hrs*3600) - (mins*60);
  }


  HMS( size_t h, size_t m, size_t s):  hrs(h), mins(m), secs(s) 
  {
    duration = (hrs * 3600) + (mins*60) + secs;
    
    hrs = duration / 3600;
    
    mins =   (duration - (hrs*3600) )/ 60;

    secs = duration - (hrs*3600) - (mins*60);        
  }


  operator double() { return double(duration); }  


  size_t operator[](size_t n)
  {
    size_t ret;
    switch(n)
      {
      case 0: ret =  duration; break;
      case 1: ret =  hrs;      break;
      case 2: ret =  mins;     break;
      case 3: ret =  secs;     break;
      default:
	std::cerr << "Invalid index: " << n << std::endl;
	ret = 0;
      }
    
    return ret;
  }

  HMS operator=(const HMS& other)
  {  
    if ( &other == this) return *this;
    
    hrs  = other.hrs;
    mins = other.mins;
    secs = other.secs;
    duration = (hrs * 3600) + (mins*60) + secs;
    return *this;   
  }


  HMS( const std::string& s)
  {
    *this =  HMS( s.c_str() );
  }

  HMS( const char*  hms)
  {
    std::cerr << "contructor(const char*)" <<  hms << "\n";
    size_t h,m,s;
    h = m = s = 0;
    std::sscanf( hms, "%zu:%zu:%zu" , &h, &m , &s);
 
    std::cerr <<"h:" << h << " m:" << m << " s:" << s << "\n";

   *this = HMS(h,m,s);
  }
  

  HMS operator=( const char* hms ) 
  {
    
    std::cerr << "= const char*" << std::endl;

    size_t h,m,s;

    std::sscanf( hms, "%zu:%02zu:%02zu" , &h, &m , &s);

    return HMS( h,m,s);
  }


  size_t seconds() { return duration; }
  size_t minutes() { return hrs*60 + mins; }
  size_t hours()   { return hrs; }


  bool operator==(const HMS& t)
  {
    return duration == t.duration;
  }

  bool operator<(const HMS& t)
  {
    return duration < t.duration;
  }

  bool operator>(const HMS& t)
  {
    return duration > t.duration;
  }

  int compare(const HMS& t)
  {
    if ( duration > t.duration) return  1;
    if ( duration < t.duration) return -1;
    return 0;
  }

  HMS operator*(const HMS& t)
  {
    return HMS( duration * t.duration); 
  }

  HMS operator/(const HMS& t)
  {
    if (t.duration == 0) return HMS(t);

    return HMS( duration / t.duration);    
  }


  HMS operator+(const HMS& t)
  {
    return HMS( duration + t.duration); 
  }


  HMS operator-(const HMS& t)
  {
    if ( t.duration > duration) 
      return HMS(t.duration - duration);
    else
      return HMS(duration - t.duration);
  }


  string to_string() const
  {
    std::stringstream ss;
    ss << std::setfill('0'); 
    ss << std::setw(2) << hrs << ":" ;
    ss << std::setw(2) << mins << ":";
    ss << std::setw(2) << secs;
    return ss.str();
  }


};


std::ostream& operator<<(std::ostream& os , const HMS& hms)
{
  os << hms.to_string();
  return os;
} 



#endif

/* END */

/* Local Variables: */
/* mode: C++        */
/* End:             */

/* vim: setlocal ft=cpp */

