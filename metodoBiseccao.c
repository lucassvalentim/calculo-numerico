#include <stdlib.h>
#include <stdio.h>

double f(double x){
    return (x*x*x) - (9*x) + 3;
}

int main(){

    double a = 0, b = 1;
    double precisao = 1e-3;

    double M, x;
    long long k = 0;
    while(b - a >= precisao){
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
    }
    printf("[%lf, %lf]\n", a, b);
    printf("Numero de interacoes foram: %lld\n", k);
    return 0;
}