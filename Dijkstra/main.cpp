#include <iostream>
#include <stack>
#include <climits>

using namespace std;

#define N 5

// inicializar la matriz de adjacencia con INT_MAX
// excepto la diagonal principal que va con 0
void initMatAdj(int mat[N][N]){
    for(int i = 0; i < N; i++) {
        mat[i][i] = 0;
        for(int j = i+1; j < N; j++) {
            mat[i][j] = INT_MAX;
            mat[j][i] = INT_MAX;
        }
    }
}

// Leer los e arcos, la lectura es base 1, pero la matriz es base 0
void leeMatAdj(int mat[N][N], int e) {
    int desde, hasta, costo;
    for(int i = 0; i < e; i++) {
        cin >> desde >> hasta >> costo;

        mat[desde-1][hasta-1] = mat[hasta-1][desde-1] = costo;
    }
}

void print(int mat[N][N]){
    cout << endl;
    for (int i = 0; i<N; i++){
        for (int j = 0; j<N; j++){
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}


// Implementar el algoritmo de Dijkstra
void Dijkstra(int W[N][N], int L[N], int T[N], int v){
    bool found[N] = { false };

    for(int i = 1; i < v; i++) {
        L[i] = W[0][i];
        T[i] = 0;
    }

    int min, vmin;
    for(int c = 1; c < v; c++) {
        min = INT_MAX;
        // Busca el minimo en esa fila
        for(int i = 1; i < v; i++) {
            if(!found[i] && L[i] < min) {
                min = L[i];
                vmin = i;
            }
        }
        cout << (char)(T[vmin]+'A') << " -> " << (char)(vmin+'A') << endl;
        for(int i = 1; i < v; i++) {
            if(W[vmin][i] != INT_MAX
               && L[vmin] + W[vmin][i] < L[i]) {

                L[i] = L[vmin] + W[vmin][i];
                T[i] = vmin;
            }
        }

        found[vmin] = true;
    }
    cout << endl;
}


// Imprimir por cada nodo (diferente a la salida) el path y el costo.
// Recordar que la matriz la esta manejando en base 0 y la salida debe ser base 1.
void printMenor(int L[N], int T[N], int v){
    for(int i = 1; i < v; i++) {
        cout << (char)(i+'A') << ": " << L[i] << endl;

        int prev;

        stack<char> path;

        prev = T[i];

        path.push(prev+'A');

        while(prev != 0) {
            prev = T[prev];
            path.push(prev+'A');
        }

        while(!path.empty()) {
            cout << path.top() << " -> ";
            path.pop();
        }

        cout << (char)(i+'A') << endl;
    }
}

int main(){
    int mat[N][N];
    int L[N];
    int T[N];
    int v, e;
    cin >> v >> e;
    initMatAdj(mat);
    leeMatAdj(mat,e);
//	print(mat);
    Dijkstra(mat, L, T, v);
    printMenor(L, T, v);
    return 0;
}

// Entra Ejemplo
// Primer linea v y e (nodos y arcos)
// Luego e lineas con el formato  a b c  que indica que de a-b y b-a tiene un costo c


/*
5 8
1 2 2
1 3 12
1 4 10
2 3 9
2 5 5
3 4 6
3 5 3
4 5 7
*/