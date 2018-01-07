#include <iostream>
#include <cstdlib>

using namespace std;

//###################################################
/*
Deklaracja Symbolu oraz Elementu przeciwnego
*/
//###################################################
enum Symbol {e,a,b,c,d};
Symbol ElemPrzeciwny[]={e,b,a,d,c};
//###################################################
/*
Funkcja wyswietlajaca symbole
*/
//###################################################
void Wyswietl(Symbol Arg)
{
	const char *tekst="eabcd";
	cout<<tekst[Arg]<<endl;
}
ostream & operator << (ostream & StrmWy, Symbol Arg)
{
	StrmWy << "eabcd"[Arg];
	return StrmWy;
}
//###################################################
/*
Funkcja wczytujaca symbole
*/
//###################################################
bool WczytajSymbol(Symbol &Arg)
{
	Symbol tabsym[]={e,a,b,c,d};
	const char tab[]="eabcd";
}
//###################################################
/*
Zadeklarowane tabliczki dzialan na symbolach
*/
//###################################################
Symbol TabliczkaDzialan[5][5]={{e,a,b,c,d},
			       {a,d,e,b,c},
			       {b,e,c,d,a},
			       {c,b,d,a,e},
			       {d,c,a,e,b}};
Symbol TabliczkaDzialanMnozenie[5][5]={{e,e,e,e,e},
				       {e,a,b,c,d},
				       {e,b,a,d,c},
				       {e,c,d,b,a},
				       {e,d,c,a,b}};							   
//###################################################
/*
Funkcja dodawania oraz przeciążenie operatora
*/
//###################################################
Symbol Dodaj(Symbol Arg1, Symbol Arg2)
{
	return TabliczkaDzialan[Arg1][Arg2];
}
Symbol operator + (Symbol Arg1, Symbol Arg2)
{
	return TabliczkaDzialan[Arg1][Arg2];
}
Symbol operator + (Symbol Arg)
{
	return Arg;
}
//###################################################
/*
Funkcja mnozenia
*/
//###################################################
Symbol Mnoz(Symbol Arg1, Symbol Arg2)
{
	return TabliczkaDzialanMnozenie[Arg1][Arg2];
}
Symbol operator * (Symbol Arg1, Symbol Arg2)
{
	return TabliczkaDzialanMnozenie[Arg1][Arg2];
}
//###################################################
/*
Funkcja odejmowania oraz przeciążenie operatora
*/
//###################################################
Symbol Odejmij(Symbol Arg1, Symbol Arg2)
{
	Symbol przeciwna=e;
	while(Arg2+przeciwna!=e)
		przeciwna=przeciwna+a;
	return Arg1+przeciwna;
}
Symbol operator - (Symbol Arg1, Symbol Arg2)
{
	Odejmij(Arg1,Arg2);
}
Symbol operator - (Symbol Arg)
{
	return ElemPrzeciwny[Arg];
}
//###################################################
/*
Funkcja dzielenia, z uwzględnieniem braku możliwości dzielenia
przez element e=0
*/
//###################################################
Symbol Dziel(Symbol Arg1, Symbol Arg2)
{
	if(Arg2==0)
	{
		cerr<<"Nie mozna dzielic przez zero!"<<endl;
		exit(0);
	}
	Symbol odwrotna=e;
	while(Arg2*odwrotna!=a)
		odwrotna=odwrotna+a;
	return Arg1*odwrotna;
}
Symbol operator / (Symbol Arg1, Symbol Arg2)
{
	Dziel(Arg1, Arg2);
}
//###################################################
/*
Funkcja porównująca otrzymane wyniki (domyślnie w programie)
*/
//###################################################
void Porownaj(Symbol wynik_alg, Symbol wynik_ope, Symbol wynik_fun)
{
 cout << ((wynik_alg == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia algebraicznego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_fun) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i funkcyjnego." << endl;

 cout << ((wynik_ope == wynik_alg) ? "Identyczne" : "Rozne") 
      << " wyniki wyrazenia operatorowego i algebraicznego." << endl;
}
//###################################################
/*
Funkcja main, zawarte w niej działania wykorzystujące poszczególne funkcje
programu
*/
//###################################################
int main()
{
 Symbol wynik_alg, wynik_ope, wynik_fun;

system("clear");


wynik_alg = a*b-c; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = Mnoz(a,Odejmij(b,c)); // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = operator * (a, operator - (b,c)); // <- Wyrażenie z jawnym wywołaniem operatorów 
Porownaj(wynik_alg,wynik_ope,wynik_fun);
cout<<"a*b-c="<<endl;

Wyswietl(wynik_alg);
Wyswietl(wynik_fun);
Wyswietl(wynik_ope);
//###################################################
wynik_alg = a*a*c+b*d; // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = Mnoz(a, Mnoz(a, Dodaj(c, Mnoz(b,d)))); // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = operator * (a, operator * (a, operator +(c, operator * (b,d)))); // <- Wyrażenie z jawnym wywołaniem operatorów 
Porownaj(wynik_alg,wynik_ope,wynik_fun);
cout<<"a*a*c+b*d="<<endl;

Wyswietl(wynik_alg);
Wyswietl(wynik_fun);
Wyswietl(wynik_ope);
//###################################################
wynik_alg = (d+e)*(a-b); // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = Mnoz(Dodaj(d,e), Odejmij(a,b));; // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = operator * (operator + (d,e), operator - (a,b)); // <- Wyrażenie z jawnym wywołaniem operatorów 
Porownaj(wynik_alg,wynik_ope,wynik_fun);
cout<<"(d+e)*(a-b)="<<endl;

Wyswietl(wynik_alg);
Wyswietl(wynik_fun);
Wyswietl(wynik_ope);
//###################################################
wynik_alg = a/(a+b+c); // <- Wyrażenie zapisane w sposób zwyczajowy
 wynik_fun = Dziel(a, Dodaj(a, Dodaj(b,c))); // <- Wyrażenie wykorzystujące funkcje
 wynik_ope = operator / (a, operator + (a, operator + (b,c))); // <- Wyrażenie z jawnym wywołaniem operatorów 
Porownaj(wynik_alg,wynik_ope,wynik_fun);
cout<<"a/(a+b+c)="<<endl;

Wyswietl(wynik_alg);
Wyswietl(wynik_fun);
Wyswietl(wynik_ope);
//###################################################


 return 0;
}
