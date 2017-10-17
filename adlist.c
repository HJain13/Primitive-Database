#include <string.h>
#include <ctype.h>

#include "adlist.h"

int numDigits(int a)
{
    if (a < 10) {
        return 1;
    }

    return 1 + numDigits(a / 10);
}

void add_listing(FILE *database, const adlist_t *adlist)
{
    fprintf(database, "%s\t%s\t%ld\t%s\t%s\t%d\n", adlist->fname, adlist->lname,
            adlist->mobile, adlist->subject, adlist->bname, adlist->price);
}

void search_listings(FILE *database, adlist_t *adlist)
{
    printf("\nResults: \n\n");

    printf(" +------------------------+------------+");

    if (!strcmp(adlist->subject, "0")) {
        printf("---------+");
    }

    if (!strcmp(adlist->bname, "0")) {
        printf("-------------------------------+");
    }

    printf("-------+");
    printf("\n |          Name          |   Mobile   |");

    if (!strcmp(adlist->subject, "0")) {
        printf(" Subject |");
    }

    if (!strcmp(adlist->bname, "0")) {
        printf("           Book Name           |");
    }

    printf(" Price |");
    printf("\n +------------------------+------------+");

    if (!strcmp(adlist->subject, "0")) {
        printf("---------+");
    }

    if (!strcmp(adlist->bname, "0")) {
        printf("-------------------------------+");
    }

    printf("-------+");
    printf("\n");

    int res = 0;
    int j;
    adlist_t temp;

    while (fscanf(database, "%s\t%s\t%ld\t%s\t%s\t%d\n", temp.fname, temp.lname, &temp.mobile, temp.subject, temp.bname, &temp.price) != EOF) {
        for (int i = 0; temp.subject[i]; i++) {
            temp.subject[i] = tolower(temp.subject[i]);
        }

        if (((!strcmp(adlist->subject, temp.subject)) || (!strcmp(adlist->subject, "0"))) && ((!strcmp(adlist->bname, temp.bname)) || (!strcmp(adlist->bname, "0"))) && ((adlist->price >= temp.price) || (adlist->price == 0))) {
            printf(" | %s %s", temp.fname, temp.lname);
            for (j = 0; j < (22 - strlen(temp.fname) - strlen(temp.lname)); j++) {
                printf(" ");
            }
            printf("| %ld ", temp.mobile);
            if (!strcmp(adlist->subject, "0")) {
                printf("| %s", temp.subject);
                for (j = 0; j < (8 - strlen(temp.subject)); j++) {
                    printf(" ");
                }
            }
            if (!strcmp(adlist->bname, "0")) {
                printf("| %s ", temp.bname);
                for (j = 0; j < (29 - strlen(temp.bname)); j++) {
                    printf(" ");
                }
            }
            printf("| %d ", temp.price);
            for (j = 0; j < 5 - numDigits(temp.price); j++) {
                printf(" ");
            }
            printf("|\n");
            res++;
        }
    }

    printf(" +------------------------+------------+");
    if (!strcmp(adlist->subject, "0")) {
        printf("---------+");
    }
    if (!strcmp(adlist->bname, "0")) {
        printf("-------------------------------+");
    }
    printf("-------+");
    printf("\n");
    printf("\n Total Results Found = %d\n___________________________________________________________________\n", res);
}
