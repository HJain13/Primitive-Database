#ifndef ADLIST_H
#define ADLIST_H

#include <stdio.h>

typedef struct {
    char fname[10];
    char lname[10];
    long int mobile;
    char subject[5];
    char bname[30];
    int price;
} adlist_t;

/* Add new listing to database */
void add_listing(FILE *database, const adlist_t *adlist);

/* Search for existing book in database */
void search_listings(FILE *database, adlist_t *adlist);

#endif
