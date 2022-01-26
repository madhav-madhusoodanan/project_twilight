#include "definitions.c"

int store(char* name, char* symbol, char* grade, int semester, int units, float marks){
    // return 1 for success, 0 for failure

    Record rec = makeEmpty();

    strcpy(rec.name, name);
    strcpy(rec.symbol, symbol);
    strcpy(rec.grade, grade);
    rec.semester = semester;
    rec.units = units;
    rec.marks = marks;
    rec.isEmpty = 0;

    FILE* fp = fopen("../data/data", "rb+");

    if(fp == NULL){
        printf("Error: Storage mechanism failure");
        return 0;
    }
    else {
        fseek(fp, 0, SEEK_END);
        fwrite(&rec, sizeof(rec), 1, fp);
    }

    fclose(fp);
    return 1;
}

Record retrieve(char* name, int semester, char* course, int count) {
    // the strings can be empty also, accordingly the results will be obtained
    // if all strings are empty, then an empty record is returned :)

    Record rec = makeEmpty();
    if(!strcmp(name, "") && semester == -1) return rec;

    FILE* fp = fopen("../data/data", "rb");

    int temp = 0;

    while(temp < count){
        if(fread(&rec, sizeof(rec), 1, fp) != 1) {
            return makeEmpty();
        }

        if(
            !strcmp(name, rec.name) &&
            semester == rec.semester &&
            (!strcmp(course, "") || !strcmp(course, rec.symbol))
        ) temp++;
    }
    fclose(fp);
    return rec;
        

}