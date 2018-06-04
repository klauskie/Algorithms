#include <iostream>
using namespace std;

int arreglo[12] = {4,7,1,12,8,2,3,9,6,11,10,5 };
int aux[12] ={};

void Union(int inicio, int mitad, int fin){
    int i = inicio, j = mitad + 1, k = inicio;
    while(i <= mitad && j<= fin){
        if(arreglo[i] < arreglo[j]){
            aux[k] = arreglo[i];
            i++;
        }else{
            aux[k] = arreglo[j];
            j++;
        }
        k++;
    }
    if(i>mitad){
        for(int a = j; a <= fin; a++){
            aux[k++] = arreglo[j++];
        }
    }else{
        for(int a = i; a <= mitad; a++){
            aux[k++] = arreglo[i++];
        }
    }
    for(int a = inicio; a < fin; a++){
            arreglo[a] = aux[a];
        }
}

void MergeSort(int inicio, int fin){
    if(inicio<fin){
        int mitad = (inicio + fin) / 2;
        MergeSort(inicio, mitad);
        MergeSort(mitad+1, fin);
        Union(inicio, mitad, fin);
    }
}

int main(){
    MergeSort(0,11);
    for(int i = 0; i < 12; i++){
        cout << arreglo[i] << ", ";
    }
    return 0;
}