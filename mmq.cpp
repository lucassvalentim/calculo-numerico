#include <bits/stdc++.h>
using namespace std;


int main(){

    vector<double> x = {1.0, 2.0, 3.0, 4.5, 6.0, 7.5, 9.0, 10.0, 11.0};
    vector<double> y = {2.0, 25.0, 70, 80, 220, 250, 440, 500, 560};
    int n = x.size(); // quantidade de pontos
    
    int m = 2; // grau do polinomio
    vector<vector<double>> A(m + 1, vector<double>(m + 1));
    vector<double> b(m + 1);
    vector<double> alphas(m + 1, 0);

    int index = 0;
    for(int i = 0; i < m + 1; i++){
        int auxIndex = index;
        for(int j = 0; j < m + 1; j++){
            double somatorio = 0;
            for(int k = 0; k < n; k++){
                somatorio += pow(x[k], auxIndex);
            }

            A[i][j] = somatorio;
            auxIndex++;
        }
        index++;
    }

    for(int i = 0; i < m + 1; i++){
        double somatorio = 0;
        for(int k = 0; k < n; k++){
            somatorio += pow(x[k], i) * y[k];
        }
        b[i] = somatorio;
    }

    // Montagem do arquivo de saida
    cout << m + 1 << endl;
    for(auto x : A){
        for(auto y : x){
            cout << y << ' ';
        }
        cout << endl;
    }
    for(auto bzino : b){
        cout << bzino << endl;
    }

    return 0;
}