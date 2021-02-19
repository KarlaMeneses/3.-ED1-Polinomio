//---------------------------------------------------------------------------

#pragma hdrstop

#include "UPolinomiolistapuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//****ATRIBUTOS PRIVADOS***

direccionP PolinomioLP::buscarexponente(int exp){
	if (!escero()) {
		direccionP dir=pol->siguiente(pol->primero());
		if (dir!=NULL) {
			direccionP dirExp=NULL;
			while (dir!=NULL && dirExp==NULL){
				if (pol->recupera(dir)==exp) {
					dirExp=dir;
				}
				if (dir == pol->fin())  //added recently
					break;
				dir=pol->siguiente(pol->siguiente(dir));
			}
			return dirExp; //direccion de exponente
		}
	}
	else{
		cout<<"Error: El polinomio no tiene terminos"<<endl;
		return NULL;
	}
}

direccionP PolinomioLP::buscartermino(int i){
	if (!escero()) {
		direccionP dir=pol->primero();
		int Nt=0;
		if (dir!=NULL) {
			direccionP dirTer=NULL;
			while (dir!=NULL && dirTer==NULL){
				Nt++;
				if (Nt==i){
					dirTer=dir;
				}
				if (pol->siguiente(dir) == pol->fin())//added recently
					break;
				dir=pol->siguiente(pol->siguiente(dir));
			}
			return dirTer; //direccion de donde inicia el termino que se envio =i
		}
	}
	else{
		cout<<"Error: El polinomio no tiene terminos"<<endl;
		return NULL;
	}
}

//****METODOS DE LA CLASE POLINOMIO****
PolinomioLP::PolinomioLP(){
	pol = new ListaP();
}


bool PolinomioLP::escero(){
	return pol->vacia();
}

int PolinomioLP::grado(){
	if (!escero()) {
		direccionP dir=pol->siguiente(pol->primero());
		if (dir!=NULL) {
			int MaxG=pol->recupera(dir);
			while (dir!=NULL){
				if (pol->recupera(dir)>MaxG) {
					MaxG=pol->recupera(dir);
				}
				if (dir == pol->fin())//added recently
					break;
				dir=pol->siguiente(pol->siguiente(dir));
			}
			return MaxG;
		}
	}
	else {
		cout<<"Error: El polinomio no tiene terminos"<<endl;
	}
}

int PolinomioLP::coeficiente(int exp){
	direccionP dir=buscarexponente(exp);
	if (dir!=NULL){
		return pol->recupera(pol->anterior(dir));
	}
	else {
		cout<<"Error: El polinomio no tiene terminos"<<endl;
	}
}
void PolinomioLP::asignacoeficiente(int coef, int exp){
	direccionP dir=buscarexponente(exp);
	if (dir!=NULL) {
		direccionP dirCoef=pol->anterior(dir);
		pol->modifica(dirCoef,coef);
		if (coef==0) {
			pol->suprime(dir);
			pol->suprime(dirCoef);
		}
	}
	else {
		cout<<"Error: El polinomio no tiene el exponente asignado"<<endl;
	}
}
void PolinomioLP::ponertermino(int coef, int exp){
	if (coef != 0 && exp >= 0) {
		direccionP dirExp=buscarexponente(exp);
		if (dirExp!=NULL) {
			direccionP dirCoef=pol->anterior(dirExp);
			int nuevoCoef = pol->recupera(dirCoef) + coef;//added
			pol->modifica(dirCoef,nuevoCoef);
			if (nuevoCoef==0) {
				pol->suprime(dirExp);
				pol->suprime(dirCoef);
			}
		}
		else{
			pol->inserta_ultimo(exp);
			pol->inserta(pol->fin(),coef);
		}
	}
}
int PolinomioLP::numeroterminos(){
	return pol->longuitud()/2;
}
int PolinomioLP::exponente(int nroter){ //devuelve el exponente del termino dado
	direccionP dir=buscartermino(nroter);
	if (dir!=NULL) {
		return pol->recupera(pol->siguiente(dir));
	}
	else{
		cout<<"No existe ese numero de termino"<<endl;
	}
}

void PolinomioLP::sumar(PolinomioLP* P1, PolinomioLP* P2,PolinomioLP* sum){
	//sum = new PolinomioLP();
	for (int i = 1; i <= P1->numeroterminos(); i++) {
		int ex=P1->exponente(i);
		int co=P1->coeficiente(ex);
		sum->ponertermino(co,ex);
	}
	for (int i = 1; i <= P2->numeroterminos(); i++) {
		int ex=P2->exponente(i);
		int co=P2->coeficiente(ex);
		sum->ponertermino(co,ex);
	}
}
void PolinomioLP::restar(PolinomioLP* P1, PolinomioLP* P2,PolinomioLP* res){
	//res = new PolinomioLP();
	for (int i = 1; i <= P1->numeroterminos(); i++) {
		int ex=P1->exponente(i);
		int co=P1->coeficiente(ex);
		res->ponertermino(co,ex);
	}
	for (int i = 1; i <= P2->numeroterminos(); i++) {
		int ex=P2->exponente(i);
		int co=P2->coeficiente(ex);
		res->ponertermino(-co,ex);
	}
}
void PolinomioLP::multiplicar(PolinomioLP* P1, PolinomioLP* P2){

}
string PolinomioLP::mostrar_polinomio(){
	string s = "";
	for (int i = 1; i <= numeroterminos(); i++) {
		int ex = exponente(i);
		int co = coeficiente(ex);
		if (co > 0)
			s += "+";
		s += to_string(co) + "x^" + to_string(ex);
	}
	return s;
}
