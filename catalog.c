/**
 * 
 * @file catalog.c
 * @author Chris Rutayisire
*/
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *department;
    char *number;
    char *days;
    char *timeslot;
    char *name;
} Course;

typedef struct {
    Course **courses;
    size_t capacity;
    size_t size;
} Catalog;

Catalog *makeCatalog() {
    Catalog *catalog = (Catalog *) malloc(sizeof(Catalog));
    catalog->courses = (Course **) malloc(8 * sizeof(Course *));
    catalog->size = 0;
    catalog->capacity = 8;
    return catalog;
}

void freeCatalog( Catalog *catalog ) {
    for (int i = 0; i < catalog->size; i++) {
        free(catalog->courses[i]);
    }
    free(catalog->courses);
    free(catalog);
}

void readCourses(char const *filename, Catalog *catalog) {
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t capacity = 0;
    size_t length;

    while ((length = readLine(file)) != NULL) {
        Course *course = (Course *) malloc(sizeof(Course));
        char *
    }
}