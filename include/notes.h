#ifndef NOTES_H
#define NOTES_H

struct Remainder {
    int dd;
    int mm;
    char note[50];
};

extern struct Remainder R;

char checkNote(int dd, int mm);
void AddNote();
void showNote(int mm);

#endif // NOTES_H
