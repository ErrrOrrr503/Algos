#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <vector>

#define CHUNK_SIZE 200000
#define MAX_ELEM_SIZE 10000

class tape {
public:
    FILE *data_file;
    size_t elems_num;
    char tape_filename[11] = "tapeXXXXXX";

    tape () = delete;
    void create_tape (const std::vector<char *> &elems)
    {
        for (size_t i = 0; i < elems.size (); i++) {
            fprintf (data_file, "%s\n", elems[i]);
        }
        elems_num = elems.size ();
    }
    tape (const std::vector<char *> &elems)
    {
        data_file = fdopen (mkstemp (tape_filename), "w+");
        create_tape (elems);
    }
    void sort_tapes (const tape &tape1, const tape &tape2)
    {
        char *temp_elem_1 = (char *) malloc (MAX_ELEM_SIZE * sizeof (char));
        char *temp_elem_2 = (char *) malloc (MAX_ELEM_SIZE * sizeof (char));
        fseek (tape1.data_file, 0, SEEK_SET);
        fseek (tape2.data_file, 0, SEEK_SET);
        fscanf (tape1.data_file, "%s", temp_elem_1);
        fscanf (tape2.data_file, "%s", temp_elem_2);
        elems_num = tape1.elems_num + tape2.elems_num;
        for (size_t i1 = 0, i2 = 0; i1 + i2 < elems_num; )
        {
            if (i1 < tape1.elems_num && (strcmp (temp_elem_1, temp_elem_2) <= 0 || i2 == tape2.elems_num)) {
                fprintf (data_file, "%s\n", temp_elem_1);
                if (i1 + 1 < tape1.elems_num)
                    fscanf (tape1.data_file, "%s", temp_elem_1);
                i1++;
            }
            if (i2 < tape2.elems_num && (strcmp (temp_elem_2, temp_elem_1) <= 0 || i1 == tape1.elems_num)) {
                fprintf (data_file, "%s\n", temp_elem_2);
                if (i2 + 1 < tape2.elems_num)
                    fscanf (tape2.data_file, "%s", temp_elem_2);
                i2++;
            }
        }
        free (temp_elem_1);
        free (temp_elem_2);
    }
    tape (const tape &tape1, const tape &tape2)
    {
        data_file = fdopen (mkstemp (tape_filename), "w+");
        sort_tapes (tape1, tape2);
    }
    void output (const char *filename)
    {
        fclose (data_file);
        rename (tape_filename, filename);
    }
    void print () {
        char *temp_str = (char *) malloc (MAX_ELEM_SIZE * sizeof (char));
        fseek (data_file, 0, SEEK_SET);
        for (size_t i = 0; i < elems_num; i++) {
            fscanf (data_file, "%s", temp_str);
            printf ("%zu)%s\n", i + 1, temp_str);
        }
        free (temp_str);
    }
    ~tape ()
    {
        if (access (tape_filename, F_OK) == 0) {
            fclose (data_file);
            unlink (tape_filename);
        }
    }
};

int strcomp (const void *p1, const void *p2)
{
    return strcmp (*(const char **) p1, *(const char **) p2);
}

int main ()
{
    FILE *data = fopen ("input.txt", "r");
    char *chunk = (char *) calloc (CHUNK_SIZE, sizeof (char));
    std::vector<char *> elems;
    std::vector<tape *> tapes;
    int is_eof = 0;
    while (is_eof != EOF) {
        size_t read_sz = 0;
        size_t i = 0;
        elems.clear ();
        elems.push_back (chunk);
        while (1) {
            is_eof = fscanf (data, "%s", elems[i]);
            if (elems[i][0] == '\0')
                is_eof = EOF;
            if (is_eof == EOF || (read_sz += strlen (elems[i]) + 1) >= CHUNK_SIZE - MAX_ELEM_SIZE) {
                if (is_eof == EOF)
                    elems.erase (elems.end () - 1);
                break;
            }
            elems.push_back (chunk + read_sz + 1);
            i++;
        }
        if (elems.size ()) {
            qsort (elems.data (), elems.size (), sizeof (char *), strcomp);
            tapes.push_back (new tape (elems));
        }
    }
    //join tapes
    while (tapes.size () != 1) {
        for (auto it = tapes.begin (); it < tapes.end () - 1; it++) {
                tape *tmp = *it;
                *it = new tape (**it, **(it + 1));
                delete tmp;
                delete *(it + 1);
                tapes.erase (it + 1);
        }
    }
    tapes[0]->output ("output.txt");
    delete tapes[0];
    free (chunk);
    fclose (data);
    return 0;
}