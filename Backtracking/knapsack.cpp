#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct obj{
	int value;
	int weight;
	int vsp;
};

bool compare(const obj &a, const obj &b){
    return a.vsp > b.vsp;
}

vector <obj> datos(10);
int n, peso, valop = 0;

void moch(int indice, int valacum, int pesacum){
    if(pesacum <= peso){
        if(valop < valacum){
            valop = valacum;
        }
        int valpos = valacum;
        int pesTemp = pesacum;
        int pos = indice;

        while(pesTemp + datos[pos].weight <= peso && pos < n){
            valpos += datos[pos].value;
            pesTemp += datos[pos].weight;
            pos++;
        }

        valpos += (datos[pos].vsp * (peso - pesTemp));
        if(valpos > valop){
            moch(indice + 1, valacum + datos[indice].value, pesacum + datos[indice].weight);
            moch(indice + 1, valacum, pesacum);
        }
    }
}

int main(){
	cin >> n >> peso;

	for (int i=0; i<n; i++){
		cin >> datos[i].value >> datos[i].weight;
		datos[i].vsp = datos[i].value/datos[i].weight;
	}
	sort(datos.begin(), datos.end(), compare);
/*
	for (int i=0; i<n; i++){
		cout << i << ": "<< datos[i].value << " " << datos[i].weight << " "<< datos[i].vsp<<endl;
	}
*/
	moch(0,0,0);
	cout << valop<<endl;
}