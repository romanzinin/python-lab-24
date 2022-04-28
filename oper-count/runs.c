#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int delay;
    float avg;
} call;

int main () {

    call blank; //пустая операция
    call total;

    total.delay = 0;
    blank.delay = 0;

    //opers - число операций
    //tests - число прогонов по opers
    //<...>.delay - общее время всех прогонов
    //<...>.avg - среднее время теста

    int tests, opers, hz;

    FILE* enter = fopen ("input.txt", "r");
    fscanf (enter, "%d %d", &hz, &opers);

    tests = opers;

    call curr;
    curr.delay = 0;

    clock_t tb, dtb, to, dto;

    tb = clock ();

    for (int j = 0; j < tests; j++) {
        int i = 0;
        while (i < opers) i++;
    }

    dtb = clock ();

    blank.delay = (float)((dtb - tb) / CLOCKS_PER_SEC);
    blank.avg = (float)blank.delay / (float)tests / (float)opers;

    int ix = rand () % 32767, iy = rand () % 32767;
    float fx = (float)rand() / (float)RAND_MAX * ix, fy = (float)rand() / (float)RAND_MAX * iy;
    double dx = (double)rand() / (double)RAND_MAX * ix, dy = (double)rand() / (double)RAND_MAX * iy;

    to = clock ();

    for (int j = 0; j < tests; j++) {
        int i = 0;
        while (i < opers) {

                i++;
                ix += iy;
        }
    }

    dto = clock ();

    curr.delay = (float)((dto - to) / CLOCKS_PER_SEC);
    curr.avg = (float)curr.delay / (float)tests / (float)opers;

    total.avg = (curr.avg - blank.avg) * 1000000;
    total.delay = curr.delay - blank.delay;
    float ticks = total.avg * (float)hz;

    printf ("%d %d\n", curr.delay, blank.delay);

    printf ("\nAverage operation time: %f ms (%f cycles)\nTotal time: %d s", total.avg, ticks, total.delay);
}
