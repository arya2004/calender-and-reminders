
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include<string.h>
/*struct Date{  
    int dd;  
    int mm;  
    int yy;  
};  
struct Date date;*/  
  
struct Remainder{  
    int dd;  
    int mm;  
    char note[50];  
};  
struct Remainder R;  
char checkNote(int dd, int mm);
int calender[42];

int leap(int year){
    if (year % 4 == 0 && year % 100 != 0 && year % 400 != 0 || year % 4 == 0 && year % 100 == 0 && year % 400 == 0 ){
        return 366 % 7;
    }
    else{
        return 365 % 7;
    }
}

int jan_first_day(int year){
    int day = 1; //sunday is 0 //initially assumed 0. 1 was found by trial and error
    for (int i = 1; i < year; i++){
        day = day + leap(i);
    }
    return day % 7 ;
}

int month_first_day(int year, int month){
    int day = jan_first_day(year);
    int mod_days_in_months_leapyear[11] = {31%7,29%7,31%7,30%7,31%7,30%7,31%7,31%7,30%7,31%7,30%7};
    int mod_days_in_months_notleapear[11] = {31%7,28%7,31%7,30%7,31%7,30%7,31%7,31%7,30%7,31%7,30%7};
    if (leap(year) == 366 % 7){
        for (int i = 0; i < month - 1; i++){
            day = day + mod_days_in_months_leapyear[i];
        }
        return day % 7;
    }
    else if (leap(year) == 365 % 7){
        for (int i = 0; i < month - 1; i++){
            day = day + mod_days_in_months_notleapear[i];
        }
        return day % 7;
    }
}

void calendar_printer(int year, int month){
    int days_in_months_leapyear[12] = {31,29,31,30,31,30,31,31,30,31,30, 31};  
    int days_in_months_notleapear[12] = {31,28,31,30,31,30,31,31,30,31,30, 31};
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    int number = 1;
    for (int i = 0; i < month_first_day(year , month) ; i++){
        calender[i] = 0;
}
    if (leap(year) == 366%7){
        for (int e = 1; e <= days_in_months_leapyear[month - 1] ; e++){
            calender[month_first_day(year , month) + e -1] = e;
        }
    }

    else if (leap(year) == 365%7){
        for (int e = 1; e <= days_in_months_notleapear[month - 1] ; e++){
        calender[month_first_day(year , month) + e -1] = e;
        }
    }
//Below prints days
    for (int row1 = 0; row1 <7 ; row1++){
        if (calender[row1] == 0){
            printf(" \t");
        }
        else if (checkNote(calender[row1],month) == '*'){
            printf("%3i*\t",calender[row1]);
        }
        else if (calender[row1] != 0){
            printf("%3i\t",calender[row1]);
        }
    }
        printf("\n");
    for (int row2 = 7; row2 <14 ; row2++){
        if (checkNote(calender[row2],month) == '*'){
            printf("%3i*\t",calender[row2]);
        }
        else if (calender[row2] != 0){
            printf("%3i\t",calender[row2]);
        }
    }
        printf("\n");
    for (int row3 = 14; row3 <21 ; row3++){
                if (checkNote(calender[row3],month) == '*'){
            printf("%3i*\t",calender[row3]);
        }
        else if (calender[row3] != 0){
            printf("%3i\t",calender[row3]);
        }
    }
        printf("\n");
    for (int row4 = 21; row4 <28 ; row4++){
                if (checkNote(calender[row4],month) == '*'){
            printf("%3i*\t",calender[row4]);
        }
        else if (calender[row4] != 0){
            printf("%3i\t",calender[row4]);
        }
    }
        printf("\n");
    for (int row5 = 28; row5 <35 ; row5++){
                if (checkNote(calender[row5],month) == '*'){
            printf("%3i*\t",calender[row5]);
        }
        else if (calender[row5] != 0){
            printf("%3i\t",calender[row5]);
        }
        
    }
        printf("\n");
    for (int row6 = 35; row6 <42 ; row6++){
        if (checkNote(calender[row6],month) == '*'){
            printf("%3i*\t",calender[row6]);
        }
        else if (calender[row6] != 0){
            printf("%3i\t",calender[row6]);
        }
        
    }
}

char checkNote(int dd, int mm){  
    FILE *fp;  
    fp = fopen("note.dat","rb");  
    if(fp == NULL){  
        printf(" ");  
    }  
    while(fread(&R,sizeof(R),1,fp) == 1){  
        if(R.dd == dd && R.mm == mm){  
            fclose(fp);  

            return '*';  
        }  
    }  

    fclose(fp);  
    return ' ';  
}  
  
  
void AddNote(){  
    FILE *fp;  
    fp = fopen("note.dat","ab+");   
    printf("Enter the date (DD MM): ");  
    scanf("%d%d",&R.dd, &R.mm);   
    printf("Enter the Note(50 character max): ");  
    fflush(stdin);  
    scanf("%[^\n]",R.note);  
    if(fwrite(&R,sizeof(R),1,fp)){   
        puts("Note is saved sucessfully");  
        fclose(fp);  
    }else{   
        puts("\aFail to save!!\a");  
    }  

}  
  
void showNote(int mm){  
    FILE *fp;  
    int i = 0, isFound = 0;  
    fp = fopen("note.dat","rb");  
    if(fp == NULL){  
        printf("Error in opening the file");  
    }  
    while(fread(&R,sizeof(R),1,fp) == 1){  
        if(R.mm == mm){ 
            printf("\nNote %d Day = %d: %s\n", i+1, R.dd,  R.note);  
            isFound = 1;  
            i++;  
        }  
    }  
    if(isFound == 0){  
        printf("\nThis Month contains no note\n");  
    }   

  
}  
int main(){    
    int choice;  
    char ch = 'a';  
    int year;
    int month;
    int mm;

    int dd;
    while(1){      
        printf("\n0. EXIT \n1. Print the calendar\n2. Add Remainder\n3.Show Remainder\n"); 
        printf("ENTER YOUR CHOICE : ");  
        scanf("%d",&choice);    
        switch(choice){    
            case 1 :  
                printf("Enter month(MM) : ");  
                scanf("%i",&month);
                printf("Enter year (YYYY) : ");  
                scanf("%i",&year);      
                calendar_printer(year,month); 
                break;  
            case 2:  
                AddNote();  
                break; 
            case 3:  
                printf("Enter month(MM) : ");  
                scanf("%i",&mm);
                showNote(mm);  
                break;  
            case 0 :  
    			return 0;  
            default	:
                printf("\nEnter Your Correct Choice.\n");
                continue;
    }
        }  
      

    //printf("%c",checkNote(02,02));
    return 0;  
}
