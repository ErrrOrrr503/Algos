#include <stdio.h>
#include <stdlib.h>

struct letter {
    char c;
    size_t  freq;
};

static int letter_cmp (const void *p1, const void *p2)
{
    size_t freq_compare = ((struct letter *) p2)->freq - ((struct letter *) p1)->freq;
    if (freq_compare)
        return freq_compare;
    return ((struct letter *) p1)->c - ((struct letter *) p2)->c;
}

int main ()
{
    struct letter freq['Z' - 'A' + 1];
    for (size_t i = 0; i < 'Z' - 'A' + 1; i++) {
        freq[i].freq = 0;
        freq[i].c = 'A' + i;
    }
    char tmp;
    while (scanf ("%c", &tmp) != EOF)
        freq[tmp - 'A'].freq++;
    qsort (freq, 'Z' - 'A' + 1, sizeof (struct letter), letter_cmp);
    for (size_t i = 0; (i < 'Z' - 'A' + 1) && freq[i].freq; i++) {
        printf ("%c %zu\n", freq[i].c, freq[i].freq);
    }
}