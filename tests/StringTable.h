/* Stringtable.h */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>
#include <exception>

#ifndef ATS_STRING_TABLE
#define ATS_STRING_TABLE

namespace ats_string_table
{
  using std::string;
  using std::vector;
  using std::map;
  using svec = std::vector<std::string>;


  class StringTable
  {

  private:
    svec _header;
    std::vector<svec>rows;
    size_t numcolumns;
    size_t numrows;

    void init()
    {
      numcolumns = _header.size();
    }

  public:
    StringTable() = default;
    StringTable(const StringTable& st) = default; 
  


  StringTable(const svec& sv): _header(sv) 
    { 
      init();
    }

  StringTable( const std::vector<svec> svv): numcolumns(svv[0].size()), numrows(svv.size())
      {
	_header = svv[0];
	rows =  std::vector<svec>( svv.begin()+1, svv.end() );
      }


    template<typename S, typename... Args>
      StringTable( const S& s1 , const Args&... args) 
    {
      _header = svec{ s1, args...};
      init();
    }
   
    const svec& get_header()
    {
      return _header;
    }


    StringTable& operator+=(const svec& sv)
      {
	this->addRow(sv);
	return *this;
      }


    StringTable operator=(std::vector<svec>& svv)
      {

	return StringTable(svv);
      }

    const svec& operator[](size_t x)
    {
      if (rows.size() >= x)  return rows[x];
      else throw std::out_of_range("operator[]");
    }

    const svec& row(size_t r)
    {
      if (rows.size() >= r )  return rows[r];
      else throw std::out_of_range("row(siz_t)");
    }


    const svec col(size_t c)
    {
      if (c > numcolumns ) throw std::out_of_range("col()");
    
      svec localcolumn;
    
      for ( svec& sv : rows)
	{
	  localcolumn.push_back( sv[c] );
	}
      return localcolumn;

    }


    void addEntry( size_t col , size_t row, string& str)
    {

      if( (col > numcolumns) || (row > numrows) ) throw std::out_of_range("addEntry()");

      rows[col][row] = str;

    }


    template<typename S, typename... Args>
      void addRow(const S& s1, const Args... args )
    {
      svec row{ s1, args...};

      if (row.size() < numcolumns) row.resize(numcolumns);
      if (row.size() > numcolumns) throw std::out_of_range("addRow");
	  
      rows.push_back(row); 
      numrows++;
    }


    template<typename I, typename... Args>
      void insertRow(const I& i, const Args... args )
    {
    
      svec tmp{args...};

      tmp.resize(numcolumns);

      if (numrows > i)
	{
	  rows.insert(rows.begin()+i, tmp);	
	}
      numrows++;
    }



    void remove_row( size_t n)
    {
      if ( numrows > n )
	{
	  rows[n].clear();
	  rows.erase(rows.begin() +n );
	  numrows--;
	}
    }


    const string& get( size_t col , size_t row)
    {

      if( (col > numcolumns) || (row > numrows) ) throw std::out_of_range("get(size_t,size_t)");

      return rows[col][row];
    }



    const string tabular()
    {
      string out;
      for (auto r : rows)
	{
	  for ( string s : r)
	    {
	      out += s + "\t";
	    }
	
	  out += "\n";
	}
      return out;

    }


    const string header()
    {
      string out;
      for (auto h : _header)
	{
	  out += h + "\t";
	}
      return out;
    }



  };

} // namespace  ast_string_table

#endif




