#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct Date{
    short year;
    short moth;
    short day;
    short hour;
    short minute;
    short second;
};
typedef struct Date Date;

Date getCurrentDate(){
    time_t current_time = time(NULL);
    struct tm *tm_local = localtime(&current_time);
    Date d;
    d.year = tm_local->tm_year + 1900;
    d.moth = tm_local->tm_mon + 1;
    d.day = tm_local->tm_mday;
    d.hour = tm_local->tm_hour;
    d.minute = tm_local->tm_min;
    d.second = tm_local->tm_sec;
    return d;
}

void print_date(Date date){
    printf("%i/%i/%i  -  %i:%i:%i\n", date.day, date.moth, date.year, date.hour, date.minute, date.second);
}

struct Recove{
    short size;
    Date date;
    struct Recove* Prox;
};
typedef struct Recove Recove;

Recove* create_Recove(){
    Recove* r = (Recove*) malloc(sizeof(Recove));
    r->size = 1;
    r->date = getCurrentDate();
    r->Prox = NULL;
    return r;
}

void print_recove(Recove* r){
    printf("Recove length -> %i\n", r->size);
    for (; r != NULL; r = r->Prox){
        print_date(r->date);
    }
}

Recove* Recove_pop(Recove* r){
    Recove* g = r;
    r = r->Prox;
    free(g);
    return r;
}

Recove add_new_point_date(Recove* r){
    r->size++;
    if (r->Prox == NULL)    r->Prox = create_Recove();
    else                    add_new_point_date(r->Prox);
}