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
float Area(PolinomioLP* pol,float a, float b);
float potencia(float num,int exp);

int _tmain(int argc, _TCHAR* argv[])
{   //POLINOMIO LISTA PUNTERO
	PolinomioLP* pol = new PolinomioLP();
	pol->ponertermino(2,0);
	cout<<"ss: "<<Area(pol,-2,2);
	//ListaP* l=new ListaP();
	 /*
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


float Area(PolinomioLP* pol,float a, float b){
 float res=0;
 float operA=0;
 float operB=0;
 float exp;
 for (int i = 1; i <= pol->numeroterminos() ; i++) {
   exp = pol->exponente(i)+1;
   operA= operA + potencia(a,exp) * (pol->coeficiente(pol->exponente(i))/exp);
 }                  //2

  for (int i = 1; i <= pol->numeroterminos() ; i++) {
   exp = pol->exponente(i)+1;
   operB= operB + potencia(b,exp) * (pol->coeficiente(pol->exponente(i))/exp);
 }

 (b<0)? res= abs(operA)+abs(operB) : res= abs(operA)-abs(operB);
 return res;
}

float potencia(float num,int exp){
float resp=num;
	if (exp==0){
	resp=1;
	}
	else{
		for (int i = 1; i < exp; i++) {
		resp= resp*num;
		}
	}
return resp;
}
