#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cinttypes>

typedef int unint;

int main ()
{
    unint *max_amounts;
    unint *amounts;
    char *elems;
    char *subset;
    std::string set;
    std::cin >> set;
    if (set.empty ()) {
        std::cout << std::endl;
        return 0;
    }
    std::sort (set.begin (), set.end ());
    char last_c = set[0];
    size_t c_amount = 0;
    size_t set_length = set.length ();
    max_amounts = (unint *) malloc (set_length * sizeof (unint));
    amounts = (unint *) malloc (set_length * sizeof (unint));
    elems = (char *) malloc (set_length * sizeof (char));
    subset = (char *) malloc (set_length * sizeof (char));
    size_t len = 0;
    for (size_t i = 0; i < set_length; i++, c_amount++) {
        if (set[i] != last_c) {
            max_amounts[len] = c_amount;
            amounts[len] = 0;
            elems[len] = last_c;
            last_c = set[i];
            c_amount = 0;
            len++;
        }
    }
    max_amounts[len] = c_amount;
    amounts[len] = 0;
    elems[len] = last_c;
    len++;

    size_t state_num = 1;
    size_t subset_i = 0;
    for (size_t i = 0; i < len; i++)
        state_num *= (max_amounts[i] + 1);
    for (size_t i = 0; i < state_num; i++) {
        for (size_t j = 0; j < len; j++) {
            for (size_t k = 0; k < amounts[j]; k++) {
                subset[subset_i] = elems[j];
                subset_i++;
            }
        }
        subset[subset_i] = '\0';
        printf ("%s\n", subset);
        subset_i = 0;
        amounts[0]++;
        for (size_t j = 0; amounts [j] > max_amounts[j] && j < len; j++) {
            amounts[j] = 0;
            amounts[j + 1]++;
        }
    }
    free (elems);
    free (max_amounts);
    free (amounts);
    free (subset);
    return 0;
}