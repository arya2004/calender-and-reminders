#include <stdio.h>
#include "calendar.h"
#include "notes.h"

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
