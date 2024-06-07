CC = gcc
CFLAGS = -I./include
DEPS = ./include/calendar.h ./include/notes.h
OBJ = ./src/calendar.o ./src/notes.o ./src/main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

calendar_app: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f ./src/*.o calendar_app
