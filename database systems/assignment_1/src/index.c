#include"ops.c"
#include"color.c"

/* 
    Write a file handling menu driven program in C programming Language 
        to display your postcom marks and grade of any course you have completed 
        in last three semesters. 
        You should also display the MGPA for each semester and overall CGPA. 
        Make your program as user friendly as possble.

    You need to submit a zip file with all data files and c program files. 
*/
void printPerson(char* personName, float cgpa) {
        clear();
        red();
        printf("Name: %s\n", personName);
        yellow();
        printf("CGPA: %.2f\n\n", cgpa);
        reset();
}

int main(int argc, char const *argv[])
{
    char contd;
    float cgpa = 0;
    int sem = -1;
    Name personName;
    Symbol courseSymbol;

    {

        char* name = (char*)malloc(sizeof(char) * 100);
        char* course = (char*)malloc(sizeof(char) * 5);
        char* grade = (char*)malloc(sizeof(char) * 3);
        int semester;
        int units;
        float marks;

        while(1) {
            printf("\n\n Enter your name: ");
            scanf(" %s", name);
            printf(" Enter the course code: ");
            scanf(" %s", course);
            printf(" Enter the grade: ");
            scanf(" %s", grade);
            printf(" Enter the semester: ");
            scanf(" %d", &semester);
            printf(" Enter the units: ");
            scanf(" %d", &units);
            printf(" Enter the marks: ");
            scanf(" %f", &marks);

            // store
            store(name, course, grade, semester, units, marks);

            // do you wanna add another record?
            printf("\n\nDo you wanna add another record? (y/n): ");
            scanf(" %c", &contd);
            if(contd == 'n') break;

            clear();
        }

        free(name);
        free(course);
        free(grade);
    }
    /* read data from file */

    /* basic configuration input */
    clear();
    getName(personName);
    cgpa = findCg(personName, 8);

    /* a while loop with options */
    do {

        printPerson(personName, cgpa);

        sem = getSemester();
        getCourse(courseSymbol);

        Record rec = retrieve(personName, sem, courseSymbol, 1);
        // print marks and grade from rec
        if(rec.isEmpty) {
            red();
            printf("\n\nNo record found\n");
            reset();
        }
        else {
            printf("\n\nGrade: %s\n", rec.grade);
            printf("Marks: %.2f\n", rec.marks);

            // print sg
            Sg sg;
            findSg(personName, sem, sg);
            printf("SG: %.2f\n", sg[0] / sg[1]);
        }
        // wanna continue?
        printf("\n\nDo you wanna continue? (y/n): ");
        scanf(" %c", &contd);

    } while (contd != 'n');
    /* a switch statement to do the operation */
    return 0;
}
