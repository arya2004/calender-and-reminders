#include <stdio.h>
#include "calendar.h"
#include "notes.h"

int calender[42];

int leap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

int jan_first_day(int year) {
    int day = 1;  // Sunday is 0
    for (int i = 1; i < year; i++) {
        day = (day + leap(i)) % 7;
    }
    return day;
}

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
