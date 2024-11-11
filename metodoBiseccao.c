#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double x){
    return exp(-(x*x)) - cos(x);
}

int main(){

    double a = 1, b = 2;
    double precisao = 1e-4;

    double M, x;
    long long k = 0;
    while(b - a >= precisao){
        printf("==================== iteracao %lld ====================\n", k);
        printf("[%lf, %lf]\n", a, b);
        M = f(a);
        x = (a + b) / 2;
        printf("x = %lf\n", x);
        printf("f(a) = %lf\n", M);
        printf("f(b) = %lf\n", f(b));
        printf("f(x) = %lf\n", f(x));

        if(M*f(x) > 0)
            a = x;
        else
            b = x;
    
        k++;

        printf("\n");
    }
    printf("[%lf, %lf]\n", a, b);
    printf("Numero de interacoes foram: %lld\n", k);
    printf("Erro: %lf\n", (b-a));
    return 0;
}