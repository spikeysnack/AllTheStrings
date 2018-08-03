#include <iostream>
#include "HMS.h"


int main( int argc, char* argv[])
{
  using namespace std;


  HMS t( 7246);
  HMS u( "34:123:312");


  cout << t << endl;

  cout << u << endl;

  cout << "add:\t" << t + u << endl;

  cout << "subt:\t" << t - u << endl;

  cout << "mult:\t" << t * u << endl;

  cout << "div:\t" << t / u << endl;

  cout << "equal:\t" <<(t == u) << endl;


  cout << "gt:\t" << (t > u) << endl;

  cout << "lt:\t" << (t < u) << endl;

  cout << "compare:\t" << t.compare(u) << endl;
    

  cout << "[x]:\t" << t[0] << endl;

  return 0;
}

