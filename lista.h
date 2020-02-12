//# ifndef LISTA_H
# define Lista_H
# include<iostream>
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
		void insertar_final(int info);
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
	if (pos>tam || pos<=0){
		insertar_final(info);
	}else if(pos==1){
		aux = sig;
		nuevo->apuntador=sig;
		sig=nuevo;
	}else{
		aux = sig;
		for (int i =0;i<pos-1;i++){
			aux=aux->apuntador;
		}
		nuevo->apuntador = aux->apuntador;
		aux->apuntador= nuevo;
		tam = tam+1;	
	}	
}
void lista :: insertar_final(int info){
	nodo *nuevo=new nodo;
	nuevo->valor = info;
	nuevo->apuntador = NULL;
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
	if (pos>tam || pos<=0){
		cout<<"No existe esta posicion"<<endl;
	} else if(pos==1){
		aux=sig;
		aux=aux->apuntador;
		sig->apuntador=NULL;
		sig = aux;
		tam = tam-1;
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
