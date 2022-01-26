#ifndef DEFINITIONS
#define DEFINITIONS

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>

    #define NAME_SIZE 100
    #define SYMBOL_SIZE 10
    #define GRADE_SIZE 4

    typedef char Name[NAME_SIZE];
    typedef char Symbol[SYMBOL_SIZE];
    typedef char Grade[GRADE_SIZE];
    typedef unsigned short IsEmpty;
    typedef unsigned int Semester;
    typedef unsigned int Units;
    typedef float Marks;
    typedef struct {
        Name name;
        Symbol symbol;
        Grade grade;
        Semester semester;
        Units units;
        IsEmpty isEmpty;
        Marks marks;
    } Record;

    Record makeEmpty(){
        Record rec;
        rec.isEmpty = 1;

        return rec;
    }

    int pointFromGrade(char* grade){
        if(!strcmp(grade, "A")) return 10;
        else if(!strcmp(grade, "A-")) return 9;
        else if(!strcmp(grade, "B")) return 8;
        else if(!strcmp(grade, "B-")) return 7;
        else if(!strcmp(grade, "C")) return 6;
        else if(!strcmp(grade, "C-")) return 5;
        else if(!strcmp(grade, "D")) return 4;
        else if(!strcmp(grade, "E")) return 3;
        else return -1;
    }

#endif