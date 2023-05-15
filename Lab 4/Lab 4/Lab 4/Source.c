#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include < time.h >
#include <string.h>
#include "Source.h"
#include "tree.h"


void log_message(char* message) {
    FILE* file = fopen("log.txt", "a");
    time_t now = time(NULL);
     char* time_str = ctime(&now); //преобразования значения time_t в строку, содержащую текстовое представление времени и даты.
    strtok(time_str, "\n"); // remove newline character
    fprintf(file, "[%s] %s\n", time_str, message);
    fclose(file);
}

void log_message_object(char* message, char* object) {
    FILE* file = fopen("log.txt", "a");
    time_t now = time(NULL);
    char* time_str = ctime(&now); //преобразования значения time_t в строку, содержащую текстовое представление времени и даты.
    strtok(time_str, "\n"); // remove newline character
    fprintf(file, "[%s] %s : %s\n", time_str, message, object);
    fclose(file);
}
