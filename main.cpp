#include <iostream>
using namespace std;
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
		cout<<"4.Ingresar un nuevo elemento al final de la lista"<<endl;
		cout<<"5.Mostrar la lista"<<endl;
		cout<<"6.Eliminar elemento"<<endl;
		cout<<"7.Salir del menu"<<endl;
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
			cout<<"Ingrese el nuevo valor "<<endl;
			cin>>valor;
			a.insertar_final(valor);
		}else if(n==5){
			cout<<"La lista es "<<endl;
			a.imprimir_lista();
		} else if(n==6){
			cout<<"Ingresar la posicion que desea eliminar "<<endl;
			cin>>pos;
			a.eliminar(pos);
		}else if(n==7){
			aux=aux+1;
		} else{
			cout<<"Opcion incorrecta"<<endl;
		}
		
	}while(aux==0);
	return 0;
}
