//---------------------------------------------------------------------------

#ifndef UPolinomiomemoriaH
#define UPolinomiomemoriaH
//---------------------------------------------------------------------------
//added
#include <iostream>
#include <string>
#include "Umemoria.h"

using namespace std;

const string datosPM = "coef,exp,sig";
const string coefPM = "->coef";
const string expPM = "->exp";
const string sigPM = "->sig";

class PolinomioSM{
	private:
		CSMemoria* mem;
		int Ptr_Poli;
		int Nt;
		int buscarexponente(int exp);
		int buscartermino(int i);

	public:
		PolinomioSM();
		bool escero();
		int grado();
		int coeficiente(int exp);
		void asignarcoeficiente(int coef,int exp);
		void ponertermino(int coef,int exp);
		int numeroterminos();
		int exponente(int nroter);
		void sumar(PolinomioSM* P1, PolinomioSM* P2,PolinomioSM* sum);
		void restar(PolinomioSM* P1, PolinomioSM* P2,PolinomioSM* res);
		string mostrar();
};
#endif
