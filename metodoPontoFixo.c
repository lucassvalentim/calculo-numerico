#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(-(x*x)) - cos(x);
}

double phi(double x){
    return cos(x) - exp(-(x*x)) + x;
    // return ((x*x*x) + 3) / 9;
}

double derivada_phi(double x){
    return -sin(x) + 2*x*exp(-(x*x)) + 1;
    // return (x*x*x) / 3;
}

int main(){

    //intervalo
    int a = 1;
    int b = 2;

    //precisao
    double erro = 1e-4;

    //verificar de a derivada de phi é menor que um dentre todo o intervalo
    for(double i = a; i < b; i+=0.15){
        if(derivada_phi(i) >= 1){
            printf("Nao eh possivel realizar o metodo, pois: derivada_phi(%lf) > 1\n", i);
        }
    }

    double x_anterior = 1.5;
    double x_atual = phi(x_anterior);
    
    int k = 0;
    printf("==================== iteracao %d ====================\n", k);
    printf("X%d = %lf\n", k, x_anterior);
    printf("phi(%lf) = %lf\n", x_anterior, x_atual);
    printf("f(%lf) = %lf\n", x_atual, f(x_atual));
    printf("\n");
    
    while(f(x_atual) > erro){
        
        x_anterior = x_atual;
        x_atual = phi(x_anterior);
        k++;
        
        printf("==================== iteracao %d ====================\n", k);

        printf("X%d = %lf\n", k, x_anterior);
        printf("phi(%lf) = %lf\n", x_anterior, x_atual);
        printf("f(%lf) = %.9lf\n", x_atual, f(x_atual));
        printf("\n");
    }

    printf("X%d = %lf\nNumero de iteracoes: %d\n", k+1, x_atual, k+1);
    printf("f(x) = %.9lf\n", f(x_atual));
    return 0;
}