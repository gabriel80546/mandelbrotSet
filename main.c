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

double complex mandelbrotIteracao(double complex c, int it) {
    int i;
    double complex z = 0.0 + 0.0 * I;


    for(i = 0; i < it; i++) {
        // printf("%i = %.2f + %.2fi\n", i, creal(z), cimag(z));
        z = (z * z) + c;
    }
    return z;
}

void printMandelbrot(int x, int y) {
    int i, j;
    //  2 -2 |  2 2
    // -2 -2 | -2 2
    double complex esquerdaMax   = (-2.0 + 0.0 * I);
    double complex esquerdaBaixo = ( 2.0 + 0.0 * I);
    double complex direitaMax   = ( 0.0 + 2.0 * I);
    double complex direitaBaixo  = ( 0.0 - 2.0 * I);
    double complex width = esquerdaMax;
    double complex widthPlus = esquerdaBaixo / (x/2);
    double complex height = direitaMax;
    double complex heightPlus = direitaBaixo / (y/2);
    double complex c = 0.0 + 0.0 * I;

    for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            // printf("Z1 = %.2f + %.2fi Z2 = %.2f %+.2fi", creal(width), cimag(width), creal(hight), cimag(hight));
            // printf("(%.2f + %.2f)", creal(width), cimag(height));
            c = creal(width) + cimag(height) * I;

            c = mandelbrotIteracao(c, 100);
            // printf("(%.2f + %.2f)", creal(c), cimag(c));

            if((creal(c) * creal(c)) + (cimag(c) * cimag(c)) < 4) {
                printf("*");
            }
            printf(" ");
            width += widthPlus;
        }
        height += heightPlus;
        width = esquerdaMax;
        printf("\n");
    }
    height = direitaMax;
}



int main() {

    testingComplex();

    double complex c = 1.0 + 0.0 * I;

    // mandelbrotIteracao(c, 6);

    printMandelbrot(80, 80);
    return 0;
}
