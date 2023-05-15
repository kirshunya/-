﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include < time.h >
#include <string.h>
#include "Source.h"
#include "tree.h"


void log_message(char* message) {
    FILE* file = fopen("log.txt", "a");
    time_t now = time(NULL);
     char* time_str = ctime_r(&now, time_str); //преобразования значения time_t в строку, содержащую текстовое представление времени и даты.
    strtok_r(time_str, "\n", NULL); // remove newline character
    fprintf(file, "[%s] %s\n", time_str, message);
    fclose(file);
}

void log_message_object(char* message, char* object) {
    FILE* file = fopen("log.txt", "a");
    time_t now = time(NULL);
    char* time_str = ctime_r(&now, time_str); //преобразования значения time_t в строку, содержащую текстовое представление времени и даты.
    strtok_r(time_str, "\n", NULL); // remove newline character
    fprintf(file, "[%s] %s : %s\n", time_str, message, object);
    fclose(file);
}
