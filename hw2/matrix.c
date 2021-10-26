#include <stdio.h>
#include <stdlib.h>

size_t N, M;

int compare_colons (const void *p1, const void *p2)
{
    const int *v1 = *(const int **) p1;
    const int *v2 = *(const int **) p2;
    for (size_t i = 0; i < N; i++) {
        if (v1[i] > v2[i])
            return 1;
        else if (v1[i] < v2[i])
            return -1;
    }
    return 0;
}

int compare_lines (const void *p1, const void *p2)
{
    const int *v1 = *(const int **) p1;
    const int *v2 = *(const int **) p2;
    for (size_t i = 0; i < M; i++) {
        if (v1[i] > v2[i])
            return 1;
        else if (v1[i] < v2[i])
            return -1;
    }
    return 0;
}

int main ()
{
    scanf ("%zu%zu", &N, &M);

    int **a_lines = (int **) calloc (N, sizeof (int *));
    for (size_t i = 0; i < N; i++)
        a_lines[i] = (int *) calloc (M, sizeof (int));
    int **a_colons = (int **) calloc (M, sizeof (int *));
    for (size_t i = 0; i < M; i++)
        a_colons[i] = (int *) calloc (N, sizeof (int));

    size_t im = 0, jm = 0;
    int m = 0x7FFFFFFF;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            scanf ("%d", a_lines[i] + j);
            if (*(a_lines[i] + j) < m) {
                m = *(a_lines[i] + j);
                im = i;
                jm = j;
            }
        }
    }

    int *tmp = a_lines[0];
    a_lines[0] = a_lines[im];
    a_lines[im] = tmp;
    for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                *(a_colons[j] + i) = *(a_lines[i] + j);
    tmp = a_colons[0];
    a_colons[0] = a_colons[jm];
    a_colons[jm] = tmp;
    for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                *(a_lines[i] + j) = *(a_colons[j] + i);

    char is_sorted = 0;
    while (!is_sorted) {
        is_sorted = 1;
        qsort (a_lines, N, sizeof (int *), compare_lines);
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                *(a_colons[j] + i) = *(a_lines[i] + j);
        qsort (a_colons, M, sizeof (int *), compare_colons);
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < M; j++)
                *(a_lines[i] + j) = *(a_colons[j] + i);

        
        for (size_t i = 0; i < N - 1; i++) {
            if (*(a_lines[i]) > *(a_lines[i + 1])) {
                is_sorted = 0;
                break;
            } 
        }
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M - 1; j++) {
            printf ("%d ", *(a_lines[i] + j));
        }
        printf ("%d\n", *(a_lines[i] + M - 1));
    }

    for (size_t i = 0; i < N; i++)
        free (a_lines[i]);
    free (a_lines);
    for (size_t i = 0; i < M; i++)
        free (a_colons[i]);
    free (a_colons);
    return 0;
}