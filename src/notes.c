#include <stdio.h>
#include <stdlib.h>
#include "notes.h"

struct Remainder R;

char checkNote(int dd, int mm) {
    FILE *fp;
    fp = fopen("note.dat", "rb");
    if (fp == NULL) {
        printf(" ");
    }
    while (fread(&R, sizeof(R), 1, fp) == 1) {
        if (R.dd == dd && R.mm == mm) {
            fclose(fp);
            return '*';  // Note exists
        }
    }
    fclose(fp);
    return ' ';  // Note does not exist
}

void AddNote() {
    FILE *fp;
    fp = fopen("note.dat", "ab+");
    printf("Enter the date (DD MM): ");
    scanf("%d%d", &R.dd, &R.mm);
    printf("Enter the Note (50 character max): ");
    fflush(stdin);
    scanf("%[^\n]", R.note);
    if (fwrite(&R, sizeof(R), 1, fp)) {
        puts("Note is saved successfully");
        fclose(fp);
    } else {
        puts("\aFail to save!!");
    }
}

void showNote(int mm) {
    FILE *fp;
    int i = 0, isFound = 0;
    fp = fopen("note.dat", "rb");
    if (fp == NULL) {
        printf("Error in opening the file");
    }
    while (fread(&R, sizeof(R), 1, fp) == 1) {
        if (R.mm == mm) {
            printf("\nNote %d Day = %d: %s\n", i + 1, R.dd, R.note);
            isFound = 1;
            i++;
        }
    }
    if (isFound == 0) {
        printf("\nThis Month contains no note\n");
    }
    fclose(fp);
}
