#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main ()
{
    size_t N = 0;
    scanf ("%zu", &N);
    size_t *day = (size_t *) calloc (1440, sizeof (size_t));
    int hha = 0, mma = 0, hhd = 0, mmd = 0;
    size_t time_a = 0, time_d = 0;
    for (size_t i = 0; i < N; i++) {
        scanf ("%d:%d %d:%d", &hha, &mma, &hhd, &mmd);
        time_a = hha * 60 + mma;
        time_d = hhd * 60 + mmd;
        for (size_t j = time_a; j <= time_d; j++)
            day[j]++;
    }
    size_t S = 0;
    for (size_t j = 0; j < 1440; j++) {
        if (S < day[j])
            S = day[j];
    }
    printf ("%zu\n", S);
}