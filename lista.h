//# ifndef LISTA_H
# define Lista_H
# include<iostream>
using namespace std;
template<class T>
struct nodo{
	nodo <T>*apuntador;
	T valor;
};
template<class T>
class lista{
	nodo <T>*sig;
	int tam;
	public :
		lista(){
			tam=0;
			sig=NULL;
		}
		void insertar_final(T info);
		bool lista_vacia();
		int tamano_lista();
		void insertar(T valor,int pos);
		void eliminar(int pos);
		void imprimir_lista();
		void imprimir_dato(int pos);
};
template<class T>
bool lista <T>:: lista_vacia(){
	if (tam==0){
		return true;
	}else{
		return false;
	}	
}
template<class T>
int lista <T> :: tamano_lista(){
	return tam;	
}
template<class T>
void lista <T> :: insertar(T info,int pos){
	nodo <T>*nuevo= new nodo <T>;
	nodo <T>*aux;
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
template<class T>
void lista <T> :: insertar_final(T info){
	nodo <T>*nuevo=new nodo <T>;
	nuevo->valor = info;
	nuevo->apuntador = NULL;
	nodo <T> *aux=sig;
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
template<class T>
void lista <T>:: imprimir_lista(){
	nodo <T>*aux = sig;
	for (int i=0;i<tam;i++){
		cout<<aux->valor<<endl;
		aux= aux->apuntador;
	}
}
template<class T>
void lista <T>:: eliminar(int pos){
	nodo <T>*aux;
	nodo <T>*eliminar;
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
template<class T>
void lista <T> :: imprimir_dato(int pos){
	nodo <T>*aux = sig;
	if (pos>tam){
		cout<<"No existe esa posicion dentro del arreglo "<<endl;
	}else{
		for (int i=0;i<pos-1;i++){
			aux= aux->apuntador;
		}
		cout<<aux->valor<<endl;
	}
}
