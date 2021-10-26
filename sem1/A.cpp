#include <stdio.h>
#include <stdlib.h>

int main () {
    size_t N;
    scanf("%zu", &N);
    ssize_t *W = (ssize_t *) calloc (N, sizeof (ssize_t));
    ssize_t total = 0;
    for (size_t i = 0; i < N; i++) {
        scanf ("%zu", W + i);
        total += W[i];
    }
    ssize_t min = (1ull << 62);
    for (size_t gen = 0; gen < (1u << N); gen ++) {
        ssize_t sum = 0;
        for (size_t i = 0; i < N; i++) {
            if (gen & (1u << i)) {
                sum += W[i];
            }
        }
        ssize_t diff = (total - sum) - sum;
        if (diff < 0)
            diff = -diff;
        if (diff < min)
            min = diff;
    }
    printf ("%zu\n", min);
    free (W);
}