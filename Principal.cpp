#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>

//added
#include <iostream>
#include <string>
#include "UPolinomiolistapuntero.h"
#include "UListapuntero.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{   /* POLINOMIO LISTA PUNTERO
	PolinomioLP* pol = new PolinomioLP();
	//ListaP* l=new ListaP();
	PolinomioLP* P1 = new PolinomioLP();
	PolinomioLP* P2 = new PolinomioLP();
	PolinomioLP* C = new PolinomioLP();
	P1->ponertermino(3,2);
	P1->ponertermino(4,8);
	P1->ponertermino(5,7);
	P2->ponertermino(1,2);
	P2->ponertermino(8,8);
	P2->ponertermino(6,7);
	cout << P1->mostrar_polinomio() << endl;
	cout << P2->mostrar_polinomio() << endl;
	C->restar(P1,P2,C);
	cout << C->mostrar_polinomio() << endl;*/




	system("pause");
	return 0;
}
