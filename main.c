#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

void testingComplex() {

    double complex z1 = 1.0 + 3.0 * I;
    double complex z2 = 1.0 - 4.0 * I;

    printf("Trabalhando com números complexos:\n");

    printf("Valores iniciais: Z1 = %.2f + %.2fi Z2 = %.2f %+.2fi\n", creal(z1), cimag(z1), creal(z2), cimag(z2));

    double complex sum = z1 + z2;
    printf("A soma: Z1 + Z2 = %.2f %+.2fi\n", creal(sum), cimag(sum));

    double complex difference = z1 - z2;
    printf("A diferença: Z1 - Z2 = %.2f %+.2fi\n", creal(difference), cimag(difference));

    double complex product = z1 * z2;
    printf("O produto: Z1 x Z2 = %.2f %+.2fi\n", creal(product), cimag(product));

    double complex quotient = z1 / z2;
    printf("O quociente: Z1 / Z2 = %.2f %+.2fi\n", creal(quotient), cimag(quotient));

    double complex conjugate = conj(z1);
    printf("O conjugado de Z1 = %.2f %+.2fi\n", creal(conjugate), cimag(conjugate));
}

void mandelbrotIteracao(double complex c, int it) {
    int i;
    double complex z = 0.0 + 0.0 * I;


    for(i = 0; i < it; i++) {
        printf("%i = %.2f + %.2fi\n", i, creal(z), cimag(z));
        z = (z * z) + c;
    }
}

int main() {

    testingComplex();

    double complex c = 1.0 + 0.0 * I;

    mandelbrotIteracao(c, 6);

    return 0;
}
