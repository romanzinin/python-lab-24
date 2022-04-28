#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int get_p (int lim) {

    int a, prime = 0, compos = 0;
    while (!prime) {

        a = rand() % lim;
        for (int j = 2; j <= sqrt (a); j++) {

            if (!(a % j)) {
                compos = 1;
                break;
            }
        }
        if (!compos && (a > 2)) {
            return a;
            break;
        }
    }
}

int main () {

    int p = 110017, residues = (p - 1) / 2;
    int stats = 0, v = 0, bol = 0;

    for (int z = 1; z < p; z++) {

        for (int num = 1; num <= residues; num++) if ((z*num % p) > p/2) v++;
        bol = floor (fabs (pow (-1, v) + (1.0/2.0)));

        stats += bol;
        bol = 0;
        v = 0;
    }

    printf ("\n%d %d", stats, p);
}
