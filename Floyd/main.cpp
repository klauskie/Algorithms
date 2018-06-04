#include <iostream>

using namespace std;

void floyd(int D[100][100], int P[100][100], int n){
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (D[i][k] != INT_MAX  && D[k][j] != INT_MAX)
                    if (D[i][k]+D[k][j] < D[i][j]) {
                        P[i][j] = k;
                        D[i][j] = D[i][k]+D[k][j];
                    }

}
void init(int D[100][100], int P[100][100], int n){
    for (int i=0; i<n; i++){
        D[i][i] = 0;
        P[i][i] = 0;
        for (int j=i+1; j<n; j++){
            D[i][j] = D[j][i] = INT_MAX;
            P[i][j] = P[j][i] = 0;
        }
    }
}

void lee(int D[100][100], int P[100][100], int m){
    int a, b, c;
    for (int i=1; i<=m; i++){
        cin >> a >> b >> c;
        D[a-1][b-1] = D[b-1][a-1] = c;
    }
}

void camino (int P[100][100], int inicio, int fin){
    if (P[inicio][fin] != 0) {
        camino(P, inicio, P[inicio][fin]);
        cout << (P[inicio][fin]+1)<<" ";
        camino(P, P[inicio][fin], fin);
    }
}

void consulta(int D[100][100], int P[100][100], int q){
    int a, b;
    for (int i=1; i<=q; i++){
        cin >> a >> b;
        cout << "Costo: " << D[a-1][b-1]<< " Ruta:"<< a << " ";
        camino(P, a-1, b-1);
        cout << b << endl;
    }
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    int D[100][100], P[100][100];
    init(D, P, n);
    lee(D, P, m);
    floyd(D, P, n);
    consulta(D, P, q);
}

/*
5 8 1
1 2 2
1 3 12
1 4 10
2 3 9
2 5 5
3 4 6
3 5 3
4 5 7
*/