#include<iostream>
#include<typeinfo>
using namespace std;
struct nodo{
	nodo*apuntador;
	int valor;
};
class lista{
	nodo*sig;
	int tam;
	public :
		lista(){
			tam=0;
			sig=NULL;
		}
		void insertar_final(nodo*apuntador);
		bool lista_vacia();
		int tamano_lista();
		void insertar(int valor,int pos);
		void eliminar(int pos);
		void imprimir_lista();
};
bool lista :: lista_vacia(){
	if (tam==0){
		return true;
	}else{
		return false;
	}	
}
int lista :: tamano_lista(){
	return tam;	
}
void lista :: insertar(int info,int pos){
	nodo *nuevo= new nodo;
	nodo *aux;
	nuevo->valor = info;
	nuevo->apuntador = NULL;
	if (pos>tam){
		insertar_final(nuevo);
	} else{
		aux = sig;
		for (int i =1;i<pos-1;i++){
			aux=aux->apuntador;
		}
		nuevo->apuntador = aux->apuntador;
		aux->apuntador= nuevo;
		tam = tam+1;	
	}	
}
void lista :: insertar_final(nodo *nuevo){
	nodo *aux=sig;
	if (tam==0){
		sig= nuevo;
		tam = tam+1;
	} else {
		for (int i=1;i<tam;i++){
			aux=aux->apuntador;
		}
		aux->apuntador = nuevo;
		tam = tam+1;
	}
}
void lista :: imprimir_lista(){
	nodo *aux = sig;
	for (int i=0;i<tam;i++){
		cout<<aux->valor<<endl;
		aux= aux->apuntador;
	}
}
void lista :: eliminar(int pos){
	nodo *aux;
	nodo *eliminar;
	if (pos>tam){
		cout<<"No existe esta posicion"<<endl;
	} else if(pos==1){
		cout<<"No se puede elimina esta posicion"<<endl;
	}else{
		aux = sig;
		eliminar = sig;
		for (int i =1;i<pos-1;i++){
			aux=aux->apuntador;
		}
		for (int i =1;i<pos;i++){
			eliminar=eliminar->apuntador;
		}
		aux->apuntador = eliminar->apuntador;
		eliminar->apuntador = NULL;
		tam = tam-1;	
	}
}

int main(){
	lista a;
	int aux=0;
	int n;
	int valor;
	int pos;
	do{
		cout<<"1.Saber el tamano de la lista"<<endl;
		cout<<"2.Saber si la lista esta vacia"<<endl;
		cout<<"3.Ingresar un nuevo elemento"<<endl;
		cout<<"4.Mostrar la lista"<<endl;
		cout<<"5.Eliminar elemento"<<endl;
		cout<<"6.Salir del menu"<<endl;
		cin>>n;
		if(n==1){
			cout<<"EL tamano de la lista es: "<<a.tamano_lista()<<endl;
		}else if(n==2){
			if(a.lista_vacia()==0){
				cout<<"La lista no esta vacia"<<endl;
			} else{
				cout<<"La lista esta vacia"<<endl;
			}
		} else if(n==3){
			cout<<"Ingrese el nuevo valor y la posicion en la que se encuentra "<<endl;
			cin>>valor;
			cin>>pos;
			a.insertar(valor,pos);	
		}else if(n==4){
			cout<<"La lista es "<<endl;
			a.imprimir_lista();
		} else if(n==5){
			cout<<"Ingresar la posicion que desea eliminar "<<endl;
			cin>>pos;
			a.eliminar(pos);
		}else if(n==6){
			aux=aux+1;
		} else{
			cout<<"Opcion incorrecta"<<endl;
		}
		
	}while(aux==0);
	return 0;
}
