
# Calendar Application

## Overview

This is a simple calendar application that allows users to:
1. Print the calendar for a given month and year.
2. Add reminders (notes) to specific dates.
3. Display reminders for a specific month.

## Directory Structure

```
calendar_app/
├── include/
│   ├── calendar.h
│   ├── notes.h
├── src/
│   ├── calendar.c
│   ├── notes.c
│   ├── main.c
├── Makefile
└── README.md
```

## Files

### `include/calendar.h`

Contains declarations for calendar-related functions:
- `void calendar_printer(int year, int month);`
- `int leap(int year);`
- `int jan_first_day(int year);`
- `int month_first_day(int year, int month);`

### `include/notes.h`

Contains declarations for notes-related functions and structure:
- `struct Remainder`
- `extern struct Remainder R;`
- `char checkNote(int dd, int mm);`
- `void AddNote();`
- `void showNote(int mm);`

### `src/calendar.c`

Contains implementations for calendar-related functions:
- `leap`
- `jan_first_day`
- `month_first_day`
- `calendar_printer`

### `src/notes.c`

Contains implementations for notes-related functions:
- `checkNote`
- `AddNote`
- `showNote`

### `src/main.c`

Contains the main program logic for user interaction and to call the relevant functions based on user input.

### `Makefile`

Defines the build process for the project.

## How to Build and Run

### Prerequisites

- `gcc` compiler

### Build

To build the project, navigate to the `calendar_app` directory and run:

```sh
make
```

This will compile the source files and create an executable named `calendar_app`.

### Clean

To clean up the build files, run:

```sh
make clean
```

### Run

To run the application, use:

```sh
./calendar_app
```

## Usage

1. **Print the calendar**

   Choose option `1` and enter the month and year for which you want to print the calendar.

2. **Add a reminder**

   Choose option `2`, then enter the date (day and month) and the note (up to 50 characters).

3. **Show reminders**

   Choose option `3` and enter the month to display all reminders for that month.

4. **Exit**

   Choose option `0` to exit the application.


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspiration and guidance from various online resources and tutorials.
