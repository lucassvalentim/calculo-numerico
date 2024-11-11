#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(-(x*x)) - cos(x);
}

double derivada_f(double x){
    return (-2)*exp(-(x*x))*x + sin(x);
}


int main(){

    //intervalo
    int a = 1;
    int b = 2;

    //precisao
    double erro = 1e-4;

    double x_anterior = 1.5;
    double x_atual = x_anterior - (f(x_anterior)/derivada_f(x_anterior));
    
    int k = 0;
    printf("==================== iteracao %d ====================\n", k);
    printf("X%d = %lf\n", k, x_anterior);
    printf("f(%lf) = %lf\n", x_atual, f(x_atual));
    printf("\n");
    
    while((f(x_atual) < 0 ? f(x_atual) * (-1.0) : f(x_atual)) > erro){
        
        x_anterior = x_atual;
        x_atual = x_anterior - (f(x_anterior)/derivada_f(x_anterior));
        k++;
        
        printf("==================== iteracao %d ====================\n", k);

        printf("X%d = %lf\n", k, x_anterior);
        printf("f(%lf) = %.9lf\n", x_atual, f(x_atual));
        printf("\n");
    }

    printf("X%d = %lf\nNumero de iteracoes: %d\n", k+1, x_atual, k+1);
    printf("f(x) = %.9lf\n", f(x_atual));
    return 0;
}