//---------------------------------------------------------------------------

#ifndef UPolinomiolistapunteroH
#define UPolinomiolistapunteroH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UListapuntero.h"


//typedef int direccionLP;

class PolinomioLP  {
	private:
		// clase variable
		ListaP*	 pol;
		direccionP buscarexponente(int exp);//
		direccionP buscartermino(int i);//
	public:
		PolinomioLP();
		bool escero();//
		int grado();//
		int coeficiente(int exp);//
		void asignacoeficiente(int coef, int exp);//
		void ponertermino(int coef, int exp);//
		int numeroterminos();//
		int exponente(int nroter);//
		void sumar(PolinomioLP* P1, PolinomioLP* P2,PolinomioLP* sum);
		void restar(PolinomioLP* P1, PolinomioLP* P2,PolinomioLP* res);
		void multiplicar(PolinomioLP* P1, PolinomioLP* P2);
		string mostrar_polinomio();
};
#endif
