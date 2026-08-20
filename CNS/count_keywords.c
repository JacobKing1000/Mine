#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "int main() { int a; float b; if(a>0) return 0; }";

    char keyword[][20] = {
        "int","float","double","char","if","else","for",
        "while","do","switch","case","break","continue","return"
    };

    int count = 0;

    char *token = strtok(str, " ,;(){}[]\t\n");

    while (token != NULL) {
        for (int i = 0; i < 14; i++) {
            if (strcmp(token, keyword[i]) == 0) {
                count++;
                break;
            }
        }
        token = strtok(NULL, " ,;(){}[]\t\n");
    }

    printf("Total keywords = %d\n", count);

    return 0;
}