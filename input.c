/**
 * 
 * @file input.c
 * @author Chris Rutayisire
*/

#include "input.h"

char *readLine(FILE *fp) {
    char *line = NULL;
    size_t capacity = 0;
    size_t length = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if (length + 1 >= capacity) {
            if (capacity == 0) {
                capacity = 8;
            }
            else {
                capacity *= 2;
            }
            char *newLine = realloc(line, capacity);
            if (newLine == NULL) {
                free(line);
                return NULL;
            }
            line = newLine;
        }

        line[length] = (char) c;
        length++;

        if (c == '\n') {
            line[length] = '\0';
            return line;
        }
    }

    if (length == 0) {
        return NULL;
    }
    else {
        line[length] = '\0';
        return line;
    }
}