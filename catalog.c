/**
 * 
 * @file catalog.c
 * @author Chris Rutayisire
*/
#include "input.h"
#include "catalog.h"

/**
 * Course struct
*/
typedef struct {
    char *department;
    char *number;
    char *days;
    char *timeslot;
    char *name;
} Course;

/**
 * Catalog struct
*/
typedef struct {
    Course **courses;
    size_t capacity;
    size_t size;
} Catalog;

/**
 * Dynamically allocates storage for the catalog
 * @return a pointer to the new catalog
*/
Catalog *makeCatalog() {
    Catalog *catalog = (Catalog *) malloc(sizeof(Catalog));
    catalog->courses = (Course **) malloc(8 * sizeof(Course *));
    catalog->size = 0;
    catalog->capacity = 8;
    return catalog;
}

/**
 * Frees the memory used to store the given catalog
 * @param catalog catalog of courses
*/
void freeCatalog( Catalog *catalog ) {
    for (int i = 0; i < catalog->size; i++) {
        free(catalog->courses[i]->department);
        free(catalog->courses[i]->number);
        free(catalog->courses[i]->days);
        free(catalog->courses[i]->timeslot);
        free(catalog->courses[i]->name);
        free(catalog->courses[i]);
    }
    free(catalog->courses);
    free(catalog);
}

/**
 * Reads all the courses from a course file with the given name
 * @param filename filename with courses in it
 * @param catalog catalog of courses
*/
void readCourses( char const *filename, Catalog *catalog ) {
    FILE *file = fopen(filename, "r");
    char *line = readLine(file);

    while (line != NULL) {
        Course *course = (Course *) malloc(sizeof(Course));
        char *
    }
}

/**
 * Sorts the courses in the given catalog
 * @param catalog catalog of courses
 * @param compare
*/
void sortCourses( Catalog *catalog, int (* compare) ( void const *va, void const *vb ) ) {
    qsort(catalog->courses, catalog->size, sizeof(Course *), compare);
}

/**
 * Prints all or some of the courses
 * @param catalog catalog of courses
 * @param test 
 * @param str1 
 * @param str2 
*/
void listCourses( Catalog *catalog, bool (*test) ( Course const *course, char const *str1, char const *str2 ), char const *str1, char const *str2 ) {
    for (size_t i = 0; i < catalog->size; i++) {
        if (test(&catalog->courses[i], str1, str2)) {
            printf("%s\n", catalog-courses[i].description);
        }
    }
}