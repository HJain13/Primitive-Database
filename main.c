#include <stdio.h>
#include <stdlib.h>

#include "adlist.h"

adlist_t read_details_for_add_listing(void)
{
    adlist_t adlist;

    printf(" %s\n\n", "Hint: Use acronym for subject name "
           "and don't include spaces in Book Name.");
    printf(" %s\n", "Enter Details:");

    printf(" %s ", "Your Name:");
    scanf("%s %s", adlist.fname, adlist.lname);

    printf(" %s ", "Mobile No:");
    scanf("%ld", &(adlist.mobile));

    printf(" %s ", "Subject:");
    scanf("%s", adlist.subject);

    printf(" %s ", "Book Name:");
    scanf("%s", adlist.bname);

    printf(" %s ", "Price:");
    scanf("%d", &(adlist.price));

    return adlist;
}

adlist_t read_details_for_search_listings(void)
{
    adlist_t adlist;

    printf(" %s\n\n", "Hint: Use acronym for subject and "
           "entering 0 removes respective criteria from search.");
    printf(" %s\n", "Enter Details:");

    printf(" %s ", "Subject:");
    scanf("%s", adlist.subject);

    printf(" %s ", "Book Name:");
    scanf("%s", adlist.bname);

    printf(" %s ", "Maximum Price:");
    scanf("%d", &(adlist.price));

    return adlist;
}

const char menu[] =
    " +----------------------+\n"
    " | PREVIOUS YEAR BOOKS  |\n"
    " |         MENU         |\n"
    " +----------------------+\n"
    " | 1: Sell Books        |\n"
    " | 2: Search for Books  |\n"
    " | 9: Exit              |\n"
    " +----------------------+";

int main(int argc, char **argv)
{
    FILE *database = fopen("adlist.txt", "a+");

    int choice = 0;

    /* main loop */
    while (1) {
        printf("%s\n", menu);

        /* Read number of choice */
        printf(" Enter Choice: ");
        scanf("%d", &choice);

        printf("\n");

        adlist_t adlist;

        switch (choice) {
            /* Add new listing */
            case 1:
                adlist = read_details_for_add_listing();
                add_listing(database, &adlist);
                rewind(database);

                break;

            /* Search listing */
            case 2:
                adlist = read_details_for_search_listings();
                search_listings(database, &adlist);
                rewind(database);

                break;

            /* Exit programm */
            case 9:
                printf(" Exiting....\n");
                fclose(database);

                return EXIT_SUCCESS;

            /* Unknown option */
            default:
                continue;
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}
