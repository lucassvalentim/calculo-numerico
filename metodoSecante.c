#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(-(x*x)) - cos(x);
}

int main(){

    //intervalo
    int a = 1;
    int b = 2;

    //precisao
    double erro = 1e-4;

    double x_anterior1 = 1;
    double x_anterior2 = 2;

    double derivada_aproximada = (f(x_anterior2) - f(x_anterior1)) / (x_anterior2 - x_anterior1);
    double x_atual = x_anterior2 - f(x_anterior2) / derivada_aproximada;
    
    int k = 0;
    printf("==================== iteracao %d ====================\n", k);
    printf("X%d = %lf\n", k, x_anterior1);
    printf("X%d = %lf\n", k+1, x_anterior2);
    printf("X%d = %lf\n", k+2, x_atual);

    printf("f(%lf) = %lf\n", x_atual, f(x_atual));
    printf("\n");
    
    while((f(x_atual) < 0 ? f(x_atual) * (-1.0) : f(x_atual)) > erro){
        
        x_anterior1 = x_anterior2;
        x_anterior2 = x_atual;

        derivada_aproximada = (f(x_anterior2) - f(x_anterior1)) / (x_anterior2 - x_anterior1);
        x_atual = x_anterior2 - f(x_anterior2) / derivada_aproximada;
        
        k++;
        
        printf("==================== iteracao %d ====================\n", k);

        printf("X%d = %lf\n", k, x_anterior1);
        printf("X%d = %lf\n", k+1, x_anterior2);
        printf("X%d = %lf\n", k+2, x_atual);

        printf("f(%lf) = %.9lf\n", x_atual, f(x_atual));
        printf("\n");
    }

    printf("X_aproximado = %lf\nNumero de iteracoes: %d\n", x_atual, k+1);
    printf("f(x) = %.9lf\n", f(x_atual));
    return 0;
}