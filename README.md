# Calendar and Reminder

This C project allows you to manage reminders and display a calendar for any month of any year. The reminders are stored in a binary file and can be accessed later. The program marks dates on the calendar with a star (*) if there is a reminder set for that day.

## Features

- Create and view reminders.
- Display a calendar for any month and year.
- Mark dates with reminders on the calendar.
- Save reminders in a binary file for future use.

## Getting Started

1. Clone the repository to your local machine.
   ```shell
   git clone https://github.com/arya2004/Calender-and-Reminders.git
   ```

2. Compile the source code using a C compiler.
   ```shell
   gcc 1.c
   ```
3. Run the executable.
   ```shell
   ./a.exe
   ```

## Usage

The program provides a command-line interface (CLI) for interaction. Once you run the executable, follow the on-screen instructions to perform various actions.

### Commands

- `add`: Add a new reminder.
- `show`: Show a reminder.
- `calendar`: Display the calendar for a specific month and year.
- `exit`: Exit the program.

### Adding a Reminder

To add a reminder, use the `add` command and provide the date, month and description of the reminder when prompted.


### Viewing a Reminder

To view a reminder, use the `view` command and provide  month of the reminder you want to view.

### Displaying a Calendar

To display the calendar for a specific month and year, use the `calendar` command and provide the month and year when prompted.

### Exiting the Program

To exit the program, use the `exit` command.

## File Structure

- `1.c`: The main source code file.
- `note.dat`: The binary file where reminders are stored.

## Contributing

Contributions to the project are always welcome. If you find a bug or have any suggestions for improvement, please open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements

- The project was inspired by the need for a simple calendar and reminder system.

Feel free to customize and enhance this readme file to better suit your project's requirements.
