#include <stdio.h>
#include <stdlib.h>

int main () {
    size_t N;
    scanf("%zu", &N);
    ssize_t *W = (ssize_t *) calloc (N, sizeof (ssize_t));
    ssize_t total = 0;
    for (size_t i = 0; i < N; i++) {
        scanf ("%zd", W + i);
        total += W[i];
    }
    ssize_t min = (1ull << 62);
    size_t N2 = (1u << N);
    for (size_t gen = 0; gen < N2; gen++) {
        ssize_t sum = 0;
        for (size_t i = 0, u = gen; u != 0; i++, u >>= 1) {
            sum += W[i] & (0ull - (u & 1));
        }
        ssize_t diff = (total - sum) - sum;
        if (diff < 0)
            diff = -diff;
        if (diff < min)
            min = diff;
    }
    printf ("%zd\n", min);
    free (W);
}