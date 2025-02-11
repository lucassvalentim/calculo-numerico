#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double ERRO_TOLERANCIA = 0.05;

// Função para criar uma matriz quadrada de tamanho n inicializada com zeros
double **criarMatriz(int n) {
    double **matriz = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0.0;
        }
    }
    return matriz;
}

// Função para ler os elementos de uma matriz do teclado
void lerMatriz(double **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
}

// Função para imprimir uma matriz na saída padrão
void imprimirMatriz(double **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.5lf ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para criar um vetor de tamanho n inicializado com zeros
double *criarVetor(int n) {
    double *vetor = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        vetor[i] = 0.0;
    }
    return vetor;
}

// Função para ler os elementos de um vetor do teclado
void lerVetor(double *vetor, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vetor[i]);
    }
}

// Função para imprimir um vetor na saída padrão
void imprimirVetor(double *vetor, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%.5lf%s", vetor[i], (i < n - 1) ? ", " : "");
    }
    printf("]\n");
}

// Função para liberar a memória de uma matriz
void liberarMatriz(double **matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função para criar a matriz de iteração C do método de Gauss-Jacobi
double **calcularMatrizIteracao(double **A, int n) {
    double **C = criarMatriz(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = (i == j) ? 0.0 : -A[i][j] / A[i][i];
        }
    }
    return C;
}

// Função para criar o vetor de iteração g do método de Gauss-Jacobi
double *calcularVetorIteracao(double **A, double *b, int n) {
    double *g = criarVetor(n);
    for (int i = 0; i < n; i++) {
        g[i] = b[i] / A[i][i];
    }
    return g;
}

// Função para resolver a equação de iteração x = Cx + g
double *resolverEquacao(double **C, double *x, double *g, int n) {
    double *resultado = criarVetor(n);
    for (int i = 0; i < n; i++) {
        resultado[i] = g[i];
        for (int j = 0; j < n; j++) {
            double produto = C[i][j] * x[j];

            if (isinf(resultado[i] + produto) || isnan(resultado[i] + produto)) {  // Verifica infinito ou NaN
                printf("Erro numérico detectado! C[%d][%d] * x[%d] gerou um valor inválido.\n", i, j, j);
                free(resultado);
                return NULL;
            }

            resultado[i] += produto;
        }
    }
    return resultado;
}

// Função para calcular a diferença absoluta entre dois números
double calcularDiferencaAbsoluta(double a, double b) {
    return (a > b) ? (a - b) : (b - a);
}

// Função para verificar se o erro entre iterações é maior que a tolerância
int verificarErro(double *xAtual, double *xAnterior, int n) {
    double maiorErro = 0.0;
    for (int i = 0; i < n; i++) {
        double diferenca = calcularDiferencaAbsoluta(xAtual[i], xAnterior[i]);
        if (diferenca > maiorErro) {
            maiorErro = diferenca;
        }
    }
    return maiorErro > ERRO_TOLERANCIA;
}

// Implementação do método de Gauss-Jacobi
double *gaussJacobi(double **C, double *xInicial, double *g, int n) {
    double *xAtual = xInicial;
    double *xAnterior;
    
    do {
        xAnterior = xAtual;
        xAtual = resolverEquacao(C, xAnterior, g, n);
        if(xAtual == NULL) break;
        imprimirVetor(xAtual, n);
    } while (verificarErro(xAtual, xAnterior, n));
    
    return xAnterior;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Leitura da matriz A e vetor b
    double **A = criarMatriz(n);
    lerMatriz(A, n);
    printf("Matriz A:\n");
    imprimirMatriz(A, n);

    double *b = criarVetor(n);
    lerVetor(b, n);
    printf("Vetor b:\n");
    imprimirVetor(b, n);
    printf("\n");

    // Cálculo das estruturas para o método de Gauss-Jacobi
    double **C = calcularMatrizIteracao(A, n);
    printf("Matriz C:\n");
    imprimirMatriz(C, n);

    double *g = calcularVetorIteracao(A, b, n);
    printf("Vetor g:\n");
    imprimirVetor(g, n);
    printf("\n");

    // Execução do método de Gauss-Jacobi
    printf("Iterações do método de Gauss-Jacobi:\n");
    double *xInicial = criarVetor(n);
    double *resultado = gaussJacobi(C, xInicial, g, n);
    printf("Solução final:\n");
    imprimirVetor(resultado, n);

    // Liberação de memória
    liberarMatriz(A, n);
    liberarMatriz(C, n);
    free(b);
    free(g);
    free(xInicial);
    free(resultado);

    return 0;
}
