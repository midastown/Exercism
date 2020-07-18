#include "meetup.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week, const char *day_of_week) {

    int i, day = getDayInInt(day_of_week);
    char date_str[50] = "1 ";
    char hour[] = "00:00:00";

    sprintf(date_str + strlen(date_str), "%d ", month);
    sprintf(date_str + strlen(date_str), "%d ", year);
    sprintf(date_str + strlen(date_str), "%s", hour);
    struct tm date;
    strptime(date_str, "%d %m %Y %H:%M:%S", &date);
    int days[5] = {0,0,0,0,-1};
    int day_count = 0;

    for (i=1; i<=31; i++) {
        if (date.tm_wday == day) {
            days[day_count] = date.tm_mday;
            day_count++;
        }

        if(strcmp(week, "teenth") == 0 && date.tm_mday <= 19 && date.tm_mday >= 13) {
            if (date.tm_wday == day) {
                return date.tm_mday;
            }
        }
        date.tm_mday += 1;
        mktime(&date);
        if (date.tm_mon + 1 != (int) month) {
            break;
        }
    }

    if (strcmp(week, "first") == 0) {
        return days[0];
    } else if (strcmp(week, "second") == 0) {
        return days[1];
    } else if (strcmp(week, "third") == 0) {
        return days[2];
    } else if (strcmp(week, "fourth") == 0) {
        return days[3];
    } else if (strcmp(week, "fifth") == 0) {
        return days[4];
    } else if (strcmp(week, "last") == 0) {
        if (days[4] == -1) {
            return days[3];
        } else {
            return days[4];
        }
    }

    return 0;

}

int getDayInInt(const char *day) {
    if (strcmp(day, "Monday") == 0 ) {
        return 1;
    } else if (strcmp(day, "Tuesday") == 0) {
        return 2;
    } else if (strcmp(day, "Wednesday") == 0) {
        return 3;
    } else if (strcmp(day, "Thursday") == 0) {
        return 4;
    } else if (strcmp(day, "Friday") == 0) {
        return 5;
    } else if (strcmp(day, "Saturday") == 0) {
        return 6;
    } else if (strcmp(day, "Sunday") == 0) {
        return 0;
    } else {
        printf("You have a typo, or something is wrong");
        return -1;
    }
}

