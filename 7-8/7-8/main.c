#include <stdio.h>
#include<stdlib.h>
#include "lib.h"
void task1(int argc, char** argv);
void task2(int argc, char** argv);
void task3(int argc, char** argv);
void stop(int argc, char** argv);

void main(int argc, char** argv)
{
	void(*tasks[4])(int, char**) = { task1 , task2 , task3 , stop };
	int oper=0 ;
	while(oper!=4){
	menu();
	oper = input_oper(&oper);
	system("cls");
	tasks[(int)oper - 1](argc, argv);
	clear_and_stop_console();
	}
	
}
void task1(int argc, char** argv) {
	char* string={0};
	int len=0;
	printf("Input string:\n");
	string = get_string(&len);
	string_output(string);
	down_first(string,len);
	printf("The result of programm:\n");
	string_output(string);
}
void task2(int argc, char** argv) {
	int len1 = 0; int len2 = 0; int len3 = 0;
	int n1 = 0; int n2 = 0;
	char* s1 = { 0 };
	char* s2 = { 0 };
	char* s3 = { 0 };
	printf("Input n1:\n");
	n1 = input_num(&n1);
	printf("Input n2:\n");
	n2 = input_num(&n2);
	printf("Input string 1:\n");
	s1 = get_string(&len1);
	printf("Input string 2:\n");
	s2 = get_string(&len2);
	s3=input_new_string(s1, s2, s3, n1, n2,len2);
	//string_output(s3);
	printf("%s", s3);
}
void task3(int argc, char** argv) {
	printf("\n30");
}
void stop(int argc, char** argv) {
	printf("\n40");
}