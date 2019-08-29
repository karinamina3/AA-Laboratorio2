#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *sig;
    Nodo *prev;
} *inicio, *fin;

class ListaEnlazada {
    public: 
        Nodo* crearNodo(int valor) {
            Nodo *n = new Nodo;
            n->dato = valor;
            n->sig = nullptr;
            n->prev = nullptr;
            return n;
        }
               
        void mostrarListaAdelante() {
            Nodo *temp = inicio;
            if(!inicio)
                cout << "La lista no posee elementos" << endl;
            else {
                while(temp) {
                    cout << temp->dato << ", ";
                    temp = temp->sig;
                }
            }
        }
        
        void mostrarListaAtras() {
            Nodo *temp = fin;
            if(!inicio)
                cout << "La lista no posee elementos" << endl;
            else {
                while(temp) {
                    cout << temp->dato << ", ";
                    temp = temp->prev;
                }
            }
        }
        
        void agregarElemento(int valor) {
            Nodo *n = crearNodo(valor);
            if(!inicio) {
                inicio = n;
                fin = n;
            } else {
                fin->sig = n;
                n->prev = fin;
                fin = n;
            }
        }
        
        void eliminarElemento(int valor) {
            Nodo *temp = inicio;
            if(!inicio)
                cout << "La lista no posee elementos" << endl;
            else {
                while (temp) {
                    if (temp->dato == valor) {
                        if (temp == inicio) {
                            cout << "No hay nodo para eliminar ";
                            break;
                        }
                        if (temp == inicio->sig) {
                            inicio = temp;
                            free(temp->prev);
                            break;
                        }
                        Nodo *temp2 = temp->prev; 
                        temp->prev->prev->sig = temp;
                        temp->prev = temp->prev->prev;
                        free(temp2);
                        break;
                    }
                    temp = temp->sig;
                }
            }
        }
        
        ListaEnlazada calcularProm() {            
            Nodo *temp = inicio;                 
            if (!inicio) {
               cout << "La lista no posee elementos" << endl;                                          
            } else {
               int suma = 0;
               int n = 0;
               float promedio = 0;               
                while(temp) {
                    suma += temp->dato;
                    n++;
                    temp = temp->sig;
                }
                promedio = suma/n;
                cout << endl << "El promedio es: " << promedio << endl;
                temp = inicio;
                ListaEnlazada L2;
                while(temp) {
                    if (temp->dato > promedio){
                        L2.agregarElemento(temp->dato);
                    }  
                    temp = temp->sig;
                }                                
            }
        }
           
    ListaEnlazada() {
        inicio = nullptr;
        fin = nullptr;
    }   
};

int main() {
    ListaEnlazada L1;
  
    L1.agregarElemento(1);
    L1.agregarElemento(2);
    L1.agregarElemento(3);
    L1.agregarElemento(4);
    L1.agregarElemento(5);
    L1.mostrarListaAdelante();
    
    ListaEnlazada L2 = L1.calcularProm();
    L2.mostrarListaAdelante();
    
    return 0;
}
