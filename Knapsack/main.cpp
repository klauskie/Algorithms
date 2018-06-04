#include <iostream>

using namespace std;

struct obj{
    int valor;
    int peso;
};

int dynamicP(obj data[10], int P, int n){
    int mat[11][101];

    for(int i= 0; i <= n; i++){
        mat[i][0] = 0;
    }

    for(int j= 0; j <= P; j++){
        mat[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j=1; j<=n; j++){
            mat[i][j] = mat[i-1][j];
            if(data[i-1].peso <= j){
                mat[i][j] = std::max(mat[i][j], mat[i-1][j-data[i-1].peso] + data[i-1].valor);
            }
        }
    }
}

int dyv(obj data[10], int P, int n){
    if(n < 0){
        return 0;
    }
    int si, no = dyv(data, P, n-1);
    if(data[n-1].peso <= P){
        si = dyv(data, P - data[n-1].peso, n-1) + data[n-1].valor;
        return std::max(si, no);
    }
    return no;
}

int main() {

    int P, n;
    obj data[10];

    cin >> P >> n;

    for(int i = 0; i < n; i++){
        cin >> data[i].valor >> data[i].peso;
    }
    if(n * P < 1<<n){
        cout << dynamicP(data, P, n);
    }else{
        cout << dyv(data, P, n);
    }

    return 0;
}