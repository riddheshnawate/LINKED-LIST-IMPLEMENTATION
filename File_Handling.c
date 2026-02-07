#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

   
    fp = fopen("data.txt", "w");   
    if (fp == NULL) {
        printf("File cannot be created!\n");
        return 1;
    }

    fprintf(fp, "Hello, this is the first line.\n");
    fprintf(fp, "File handling in C language.\n");
    fclose(fp);

    printf("Data written to file successfully.\n\n");

   
    fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("File cannot be opened for appending!\n");
        return 1;
    }

    fprintf(fp, "This line is appended to the file.\n");
    fclose(fp);

    printf("Data appended successfully.\n\n");

    
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File cannot be opened for reading!\n");
        return 1;
    }

    printf("Reading data from file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);

    return 0;
}
