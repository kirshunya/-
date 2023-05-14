#define _CRT_SECURE_NO_WARNINGS
#define CONST 128


#include "Source.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main()
{
	struct node* head = NULL;
	
	char* wshort = (char*)malloc(CONST * sizeof(char) + 1);
	char* wlong = (char*)malloc(CONST * sizeof(char) + 1);
	char* word = (char*)malloc(CONST * sizeof(char) + 1);
	char* buffer = (char*)malloc(CONST * sizeof(char) + 1);
	int count = 0;
	int count1 = 0;
	int count_word = 0;
	size_t n = 0;
	int i = 0;

	FILE* in;
	in = fopen("stas.txt", "r");
	if (in == NULL) {
		printf("Cannot open file \n");
		exit(1);
	}
	char* temp = (char*)malloc(ftell(in) * sizeof(char) + 1);

	FILE* copy;
	copy = fopen("copy.txt", "w+");

	FILE* out;
	out = fopen("archive.txt", "w+");

	while (fscanf(in, "%s", word) != EOF)
		count++;
	printf("Number of words in file is %d\n", count);


	fseek(in, 0, SEEK_SET);
	while (fscanf(in, "%s", buffer) != EOF){
		head = push(head, buffer, count);
	    fprintf(copy, "%s ", buffer);
	}

	int k = 0;
	int use_s = 0;
	int use_l = 0;
	fseek(copy, 0, SEEK_SET);
	while (k != 1)
	{
		search(head, &wlong, &wshort, buffer, &k, &temp);
;		while (fscanf(copy, "%s", buffer) != EOF)
		{
			
				for (node* p = head; p != NULL; p = p->next)
			    {
				
						if (p->use_search == 1)
						{

							if (strcmp(wlong, buffer) == 0 && p->use_change == 0)
							{
							fprintf(out, "%s ", wshort);
							count_word++;
							use_s++;
							
							break;
							}
							if (strcmp(wshort, buffer) == 0 && p->use_change == 0)
							{
							fprintf(out, "%s ", wlong);
							count_word++;
							use_l++;
							
							break;
							}
							else
							{
							fprintf(out, "%s ", buffer);
							count_word++;
							break;
							}

							if (count_word == count - 1)
							{
							if (strcmp(wlong, buffer) == 0 && p->use_change == 0)
							{
								fprintf(out, "%s ", wshort);
								count_word++;
								use_s++;
								
								break;
							}
							if (strcmp(wshort, buffer) == 0 && p->use_change == 0)
							{
								fprintf(out, "%s ", wlong);
								count_word++;
								use_l++;
								
								break;
							}
							else
							{
								fprintf(out, "%s ", buffer);
								count_word++;
								break;
							}

						    }	
					    }	
			    }
		}
		fclose(copy);
		copy = fopen("copy.txt", "w+");
		fseek(out, 0, SEEK_SET);
		while (fscanf(out, "%s", buffer) != EOF) {
			fprintf(copy, "%s ", buffer);
		}
		fclose(out);
		out = fopen("archive.txt", "w+");
		fclose(copy);
		copy = fopen("copy.txt", "r");

	}

	fseek(out, 0, SEEK_SET);
	fseek(copy, 0, SEEK_SET);
	while (fscanf(copy, "%s", buffer) != EOF) {
		fprintf(out, "%s ", buffer);
	}
	fclose(copy);
	copy = fopen("copy.txt", "r+");
	
	fprintf(out, "%s", "\n 1) ");
	fputs(temp, out);

	int copy_size = 0;
	fseek(out, 0, SEEK_SET);
	while (fscanf(out, "%s", buffer) != EOF)
	{
		if (strcmp(buffer, "1)") == 0)
		{
			break;
		}
		else {
			copy_size = strlen(buffer) + 1 + copy_size;
		}
	}
	printf("The first file : %d\n", ftell(in));
	printf("The archive file : %d\n", copy_size);
	
			delete_stack2(&head);
			free(wshort);
			free(wlong);
			free(buffer);
			free(word);
			fclose(in);
			printf("See you next time...^^\n");
			printf("(/__/) \n"
				   "(='.'=)\n"
				   "(')_(')\n");

	
}

