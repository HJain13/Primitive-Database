#include<stdio.h>
#include<string.h>
// So much hacky code, This is going to be hell to maintain whole semester.
typedef struct
{
      char fname[10];
      char lname[10];
      long int mobile;
      char subject[5];
      char bname[30];
      int price;
} adlist;
adlist a;
FILE *fp;

int numDigits(int a) {
    if (a < 10) return 1;
    return 1 + numDigits(a / 10);
}

void addListing() {
	  int i; 
   	  printf("\nHint: Use acronym for subject name and don't include spaces in Book Name.\n\n");
      fp = fopen("adlist.txt","a+");
      printf(" Enter Details:\n");
      printf(" Your Name: ");     scanf("%s %s", a.fname, a.lname);
      printf(" Mobile No: ");     scanf("%ld", &a.mobile);
      printf(" Subject: ");       scanf("%s", a.subject); 
      printf(" Book Name: ");     scanf("%s", a.bname); 
      printf(" Price: ");         scanf("%d", &a.price);
      fprintf(fp, "%s\t%s\t%ld\t%s\t%s\t%d\n", a.fname,a.lname,a.mobile,a.subject,a.bname,a.price);
      fclose(fp);
      rewind(fp);
      printf("\n\n");
}

void searchListings(){
   char bookname[30], sub[5];
   int priceCeiling,res,j;
   printf("\nHint: Use acronym for subject and entering 0 removes respective criteria from search.\n\n");
   printf("Enter Details -\nSubject: ");          scanf("%s", sub);
   printf("Book Name: ");        scanf("%s", bookname);
   printf("Maximum Price: ");    scanf("%d", &priceCeiling);
   printf("\nResults: \n\n");
   printf(" +------------------------+------------+");
   if(!strcmp(sub,"0")) printf("---------+");
   if(!strcmp(bookname,"0")) printf("-------------------------------+");
   printf("-------+");
   printf("\n |          Name          |   Mobile   |");
   if(!strcmp(sub,"0")) printf(" Subject |");
   if(!strcmp(bookname,"0")) printf("           Book Name           |");
   printf(" Price |");
   printf("\n +------------------------+------------+");
   if(!strcmp(sub,"0")) printf("---------+");
   if(!strcmp(bookname,"0")) printf("-------------------------------+");
   printf("-------+");
   printf("\n");
   fp = fopen("adlist.txt", "r");
   res = 0;
   while (fscanf(fp, "%s\t%s\t%ld\t%s\t%s\t%d\n", a.fname, a.lname, &a.mobile, a.subject, a.bname, &a.price) != EOF) {
	   for(int i = 0; a.subject[i]; i++) { a.subject[i] = tolower(a.subject[i]); }	   
      if(((!strcmp(sub,a.subject))||(!strcmp(sub,"0")))&&((!strcmp(bookname,a.bname))||(!strcmp(bookname,"0")))&&((priceCeiling>=a.price)||(priceCeiling==0))){
		 printf(" | %s %s", a.fname, a.lname); for (j=0; j<(22-strlen(a.fname)-strlen(a.lname));j++) { printf(" "); }
         printf("| %ld ", a.mobile);
		 if(!strcmp(sub,"0")) { printf("| %s", a.subject);  for (j=0; j<(8-strlen(a.subject));j++) { printf(" "); } }
	  	 if(!strcmp(bookname,"0")) { printf("| %s ", a.bname); for (j=0; j<(29-strlen(a.bname));j++) { printf(" "); } }
		 printf("| %d ", a.price); for (j=0; j<5-numDigits(a.price);j++) { printf(" "); }
		 printf("|\n");
         res++;
      }
   }
   printf(" +------------------------+------------+");
   if(!strcmp(sub,"0")) printf("---------+");
   if(!strcmp(bookname,"0")) printf("-------------------------------+");
   printf("-------+");
   printf("\n");
   printf("\n Total Results Found = %d\n___________________________________________________________________\n",res);
   fclose(fp);
   rewind(fp);
}

int main()
{
   int i = 0, choice=0, data = 0, searchcrt = 0;
   while (choice!=9) {
      printf("\n +----------------------+\n");
      printf(" | PREVIOUS YEAR BOOKS  |\n");
      printf(" |         MENU         |\n");
      printf(" +----------------------+\n");
      printf(" | 1: Sell Books        |\n");
      printf(" | 2: Search for Books  |\n");
      printf(" | 9: Exit              |\n");
      printf(" +----------------------+\n\n");
      printf(" Enter Choice: ");
      scanf("%d",&choice);
      if (choice==1) { addListing(); }
      if (choice==2) { searchListings(); }
      if (choice==9) printf("\n Exiting....\n\n");
   }
   return 0;
}
