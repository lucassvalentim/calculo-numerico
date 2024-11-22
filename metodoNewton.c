#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double x){
    // return exp(-(x*x)) - cos(x);
    return (x*x*x) - 3.5*x*x + 4*x - 1.5;
}

double derivada_f(double x){
    // return (-2)*exp(-(x*x))*x + sin(x);
    return 3*x*x - 7*x + 4;
}


int main(){

    //precisao
    double erro = 0.01;

    double x_anterior = 1.496094;
    double x_atual = x_anterior - (f(x_anterior)/derivada_f(x_anterior));
    
    int k = 0;
    printf("==================== iteracao %d ====================\n", k);
    printf("X%d = %lf\n", k, x_anterior);
    printf("X%d = %lf\n", k+1, x_atual);
    printf("f(%lf) = %lf\n", x_atual, f(x_atual));
    printf("\n");
    
    while((f(x_atual) < 0 ? f(x_atual) * (-1.0) : f(x_atual)) > erro){
        
        x_anterior = x_atual;
        x_atual = x_anterior - (f(x_anterior)/derivada_f(x_anterior));
        k++;
        
        printf("==================== iteracao %d ====================\n", k);

        printf("X%d = %lf\n", k, x_anterior);
        printf("X%d = %lf\n", k+1, x_atual);
        printf("f(%lf) = %.9lf\n", x_atual, f(x_atual));
        printf("\n");
    }

    printf("X_aproximado = %lf\nNumero de iteracoes: %d\n", x_atual, k+1);
    printf("f(x) = %.9lf\n", f(x_atual));
    return 0;
}