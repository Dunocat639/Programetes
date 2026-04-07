#include <stdio.h>

int main(void) {

    char esciure[100];
    char llegir[100];
    FILE *pfile;

    // Escriure
    pfile = fopen("cosetes.txt", "w");
    fprintf(pfile, "bueno dia");

    // Llegir
    pfile = fopen("cosetes.txt", "r");
    
    while (fgets(llegir, sizeof(llegir), pfile)) {
        printf("%s", llegir);
    }

    fclose(pfile);


    return 0;
}