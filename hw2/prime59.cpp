#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

#define K_MAX 20000000

static inline char is_prime (size_t a)
{
    static char erat[K_MAX + 1] = {};
    static bool is_init = 0;
    if (!is_init) {
        size_t i = 2;
        while (i < K_MAX + 1) {
            for (size_t j = i + i; j < K_MAX + 1; j += i)
                erat[j] = 1;
            do {
                i++;
            } while (erat[i]);
        }
        is_init = 1;
    }

    return !erat[a];
}

int main ()
{
    size_t N = 0, M = 0;
    scanf ("%zu%zu", &M, &N);
    if (!N) {
        if (!M)
            printf ("2\n");
        else
            printf ("-1\n");
        return 0;
    }
    std::queue<char> are_prime;
    size_t Smax = 0;
    char is_prm = 0;
    for (size_t i = 2; i < N + 2; i++) {
        is_prm = is_prime (i);
        Smax += is_prm;
        are_prime.push (is_prm);
    }
    if (M > Smax) {
        printf ("-1\n");
        return 0;
    }
    size_t S = Smax;
    for (size_t i = 2; i < K_MAX - N; i++) {
        if (S == M) {
            printf ("%zu\n", i);
            return 0;
        }
        S -= are_prime.front ();
        are_prime.pop ();
        is_prm = is_prime (i + N);
        S += is_prm;
        are_prime.push (is_prm);
    }
    printf ("-1\n");
    return 0;
}