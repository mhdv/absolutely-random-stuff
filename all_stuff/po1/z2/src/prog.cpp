#include <iostream>

using namespace std;

enum Symbol {e, a, b};

Symbol PrzeciwnyWzgDodawania(Symbol Arg)
{
  Symbol TabSymb[3] = {e, a, b};
  int Ind;
  for (Ind=0; Ind < 3; ++Ind)
    {
      if(TabSymb[Ind] + Arg == e)
	{ return TabSymb[Ind];
	}
    }
}

  
