#include <stdlib.h>
#include <stdio.h>

void swap(double *a, double *b){
    double aux = *a;
    *(a) = *(b);
    *(b) = aux;
}

double ** cria_matriz(int n){
    double **matriz = (double**)malloc(n*sizeof(double*));
    for(int i = 0; i < n; i++)
        matriz[i] = (double*)malloc(n*sizeof(double));
    return matriz;
}

void le_matriz(double **matriz, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }
}

void gauss_sem_pivo(double **matriz, int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double factor = matriz[j][i] / matriz[i][i];
            for(int k = 0; k < n; k++){
                matriz[j][k] = matriz[j][k] - (factor*matriz[i][k]);
            }
        }
    }
}

void gauss_pivo_parcial(double **matriz, int n){
    for(int i = 0; i < n; i++){
        // Pivotamento parcial: Encontra a linha com o maior elemento na coluna `i`
        int maxRow = i;

        for(int k = 0; k < n; k++){
            if(abs(matriz[k][i]) > abs(matriz[k][maxRow])){
                maxRow = k;
            }
        }
        
        // Troca a linha atual pela linha com o maior pivô
        if(maxRow != i){
            for(int k = 0; k < n; k++){
                swap(&matriz[i][k], &matriz[maxRow][k]);
            }
        }

        // Realiza a eliminação gaussiana
        for(int j = i + 1; j < n; j++){
            double factor = matriz[j][i] / matriz[i][i];
            for(int k = i; k < n; k++){
                matriz[j][k] = matriz[j][k] - (factor*matriz[i][k]);
            }
        }
    }
}

void gauss_pivo_completo(double **matriz, int n){
    double permutation[n];
    for(int i = 0; i < n; i++) 
        permutation[i] = i;

    for(int i = 0; i < n; i++){
        int maxRow = i, maxCol = i;
        double maxValue = abs(matriz[i][i]);
        // Pivotamento completo: Encontra o maior elemento absoluto na submatriz
        for(int row = i; row < n; row++){
            for(int col = i; col < n; col++){
                if(abs(matriz[row][col]) > maxValue){
                    maxValue = matriz[row][col];
                    maxRow = row;
                    maxCol = col;
                }
            }
        }
        
        // Troca a linha atual pela linha com o maior pivô
        if(maxRow != i){
            for(int k = 0; k < n; k++){
                swap(&matriz[i][k], &matriz[maxRow][k]);
            }
        }

        // Troca a coluna atual pela coluna com o maior pivô
        if(maxCol != i){
            for(int k = 0; k < n; k++){
                swap(&matriz[k][i], &matriz[k][maxCol]);
            }
            swap(&permutation[i], &permutation[maxCol]);
        }

        // Realiza a eliminação gaussiana
        for(int j = i + 1; j < n; j++){
            double factor = matriz[j][i] / matriz[i][i];
            for(int k = i; k < n; k++){
                matriz[j][k] -= (factor*matriz[i][k]);
            }
        }
    }

}

void desalocar(double **matriz, int n){
    for(int i = 0; i < n; i++)
       free(matriz[i]);
    
    free(matriz);
}

int main(){

    int opc; // [1 (sem pivo), 2(pivo parcial), 3(pivo completo)]
    scanf("%d", &opc);

    int n;
    scanf("%d", &n); 

    double ** matriz = cria_matriz(n);
    le_matriz(matriz, n);

    switch (opc){
        case 1:
            gauss_sem_pivo(matriz, n);
            break;
        case 2:
            gauss_pivo_parcial(matriz, n);
            break;
        case 3:
            gauss_pivo_completo(matriz, n);
            break;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%.2lf ", matriz[i][j]);
        }
        printf("\n");
    }

    desalocar(matriz, n);
    return 0;
}