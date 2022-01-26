#include "file.c"
typedef float Sg[2];

void findSg(Name name, Semester sem, Sg arr){
    // take input
    
    Symbol symbol;
    Grade grade;

    // while not end of file
    int count = 1;
    int index = 0;
    float totalGrade = 0, totalUnit = 0;

    Record rec = retrieve(name, sem, "", count++);

    while(!rec.isEmpty){
        // check if the data is the one searched for
        if(!strcmp(name, rec.name) && rec.semester == sem){
            totalGrade += (pointFromGrade(rec.grade) * rec.units);
            totalUnit += rec.units;
            printf("grade: %f\nunit: %f\n\n", totalGrade, totalUnit);
        }

        // load the data
        rec = retrieve(name, sem, "", count++);
        index ++;
    }

    arr[0] = totalGrade;
    arr[1] = totalUnit;
}

float findCg(Name name, Semester lastSem){
    Sg cg = {0 ,0};
    Sg sg = {0 ,0};
    for (int sem = 1; sem <= lastSem; sem++)
    {
        findSg(name, sem, sg);
        cg[0] += sg[0];
        cg[1] += sg[1];
    }
    
    return (cg[0] / cg[1]);
}


void getName(Name personName) {
    printf("\n\n Enter your name: ");
    scanf(" %s", personName);
    printf(" Wow that's a great name you have :)");
}

void getCourse(Symbol courseSymbol) {
    printf("\n\n Enter the course code: ");
    scanf(" %s", courseSymbol);
    printf(" Got it!");
}

int getSemester() {
    int semester;
    printf("\n\n Enter the semester number: ");
    scanf(" %d", &semester);
    printf(" Got it!");

    return semester;
}