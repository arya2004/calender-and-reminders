#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Structure to hold a remainder note
struct Remainder {
    int dd;  // Day
    int mm;  // Month
    char note[50];  // Note text
};

// Global variables
struct Remainder R;
int calender[42];  // Calendar array

// Function prototypes
int leap(int year);
int jan_first_day(int year);
int month_first_day(int year, int month);
void calendar_printer(int year, int month);
char checkNote(int dd, int mm);
void AddNote();
void showNote(int mm);

// Function to check if a given year is a leap year
int leap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

// Function to calculate the day of the week for January 1st of a year
int jan_first_day(int year) {
    int day = 1;  // Sunday is 0
    for (int i = 1; i < year; i++) {
        day = (day + leap(i)) % 7;
    }
    return day;
}

// Function to calculate the day of the week for the first day of a month in a year
int month_first_day(int year, int month) {
    int day = jan_first_day(year);
    int days_in_months_leapyear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_months_notleapear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (leap(year)) {
        for (int i = 0; i < month - 1; i++) {
            day = (day + days_in_months_leapyear[i] % 7) % 7;
        }
    } else {
        for (int i = 0; i < month - 1; i++) {
            day = (day + days_in_months_notleapear[i] % 7) % 7;
        }
    }
    return day;
}

// Function to print the calendar for a given year and month
void calendar_printer(int year, int month) {
    int days_in_months_leapyear[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days_in_months_notleapear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    int number = 1;

    for (int i = 0; i < month_first_day(year, month); i++) {
        calender[i] = 0;  // Fill the beginning of the calendar with zeros for empty days
    }

    int* days_in_month = leap(year) ? days_in_months_leapyear : days_in_months_notleapear;

    for (int day = 1; day <= days_in_month[month - 1]; day++) {
        calender[month_first_day(year, month) + day - 1] = day;
    }

    // Print the calendar
    for (int i = 0; i < 42; i++) {
        if (calender[i] == 0) {
            printf(" \t");
        } else {
            printf("%3i\t", calender[i]);
        }
        if ((i + 1) % 7 == 0) {
            printf("\n");
        }
    }
}

// Function to check if a note exists for a given day and month
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

// Function to add a note
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

// Function to display notes for a given month
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

// Main function
int main() {
    int choice;
    int year, month, mm;

    while (1) {
        printf("\n0. EXIT\n1. Print the calendar\n2. Add Reminder\n3. Show Reminder\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter month (MM): ");
                scanf("%i", &month);
                printf("Enter year (YYYY): ");
                scanf("%i", &year);
                calendar_printer(year, month);
                break;
            case 2:
                AddNote();
                break;
            case 3:
                printf("Enter month (MM): ");
                scanf("%i", &mm);
                showNote(mm);
                break;
            case 0:
                return 0;
            default:
                printf("\nEnter Your Correct Choice.\n");
                continue;
        }
    }
    return 0;
}
