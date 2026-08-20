#include <stdio.h>
#include <string.h>

int main() {
    char str[20];
    char keyword[][20] = {
        "int","float","double","char","if","else","for",
        "while","do","switch","case","break","continue","return"
    };

    int i, found, count = 0;

    FILE *fp = fopen(""C:\Users\chand\OneDrive\Documents\z.txt"", "r");

    if (fp == NULL) {
        printf("File not found.\n");
        return 1;
    }

    while (fscanf(fp, "%s", str) != EOF) {
        found = 0;

        for (i = 0; i < 14; i++) {
            if (strcmp(str, keyword[i]) == 0) {
                found = 1;
                break;
            }
        }

        if (found == 1) {
            count++;
        }
    }

    fclose(fp);

    printf("Total keywords = %d\n", count);

    return 0;
}