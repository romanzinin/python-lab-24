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

    int p = get_p ();
    int res_num = (p - 1) / 2;
    int res [res_num], repeat = 0, curr_res = 0;

    for (int x = 1; x <= res_num; x++) {
        res [x] = x*x % p;
    }

    int bol = 0, stats = 0;

    for (int z = 1; z < p; z++) {

        for (int num = 0; num <= res_num; num++) {
            if ((z % p) == res [num]) bol++;
        }
        stats += bol;
        printf ("%d\n", stats);
        bol = 0;
    }

    printf ("\n%d %d", stats, p);
}
