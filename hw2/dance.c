#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

int cmp_int64 (const void *p1, const void *p2) {
    return (*(int64_t *) p1 - *(int64_t *) p2);
}

int main () {
    int N = 0, L = 0;
    scanf ("%d%d", &L, &N);
    int64_t *dots = (int64_t *) malloc (N * sizeof (int64_t));
    for (int i = 0; i < N; i++)
        scanf ("%ld", dots + i);
    qsort (dots, N, sizeof (int64_t), cmp_int64);
    size_t Survived = N;
    int64_t base = dots[0];
    for (int i = 1; i < N; i++) {
        if (dots[i] <= base + L + L) {
            Survived--;
            continue;
        }
        base = dots[i];
    }
    printf ("%zu\n", Survived);
    return 0;
}