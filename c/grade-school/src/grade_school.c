#include "grade_school.h"
#include <stdio.h>
#include <string.h>

static roster_t roster = { 0 };
static const roster_t empty;

roster_t get_roster(){
    return roster;
}

void clear_roster() {
    roster = empty;
}

int add_student(char *name, uint8_t grade) {
    int i;

    for (i=0; i<MAX_STUDENTS; i++) {
        if (roster.students[i].grade == 0) {
            roster.students[i].grade = grade;
            strcpy(roster.students[i].name, name);
            roster.count++;
            return 1;
        }
    }
    return 0;
}

roster_t get_grade(uint8_t grade) {
    roster_t temp = roster;
    clear_roster();
    size_t i;

    for (i=0; i<temp.count; i++) {
        if(temp.students[i].grade == grade){
            if (add_student(temp.students[i].name, temp.students[i].grade) == 1) {
                continue;
            } else {
                printf("something went wrong in adding users");
            }
        }
    }

    return roster;
}

int cmp(const void *s1, const void *s2) {
    student_t *e1 = (student_t *)s1;
    student_t *e2 = (student_t *)s2;

    if (e1->grade == e2->grade) {
        return strcmp(e1->name, e2->name);
    } else {
        return e1->grade - e2->grade;
    }
}








