#define _CRT_SECURE_NO_WARNINGS
#define CONST256 256
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Source.h"
#include "tree.h"


int main()
{
	log_message("Program started");
	char* buffer = (char*)malloc(CONST256 * sizeof(char));

	tree* tree = NULL;

	FILE* read = fopen("questions.txt", "r");
	int c = fgetc(read);
	if (c == EOF) {
		log_message("Creating new tree");
		printf("Insert first object\n");
		char object[CONST256];
		fgets(object, CONST256, stdin);
		strtok(object, "\n");
		printf("Insert question for this object: %s \n", object);
		char question[CONST256];
		fgets(question, CONST256, stdin);
		strtok(question, "\n");
		tree = create(question, read);
		tree->mark = question;
		tree->right = create(object, read);
		printf("Insert second object\n");
		fgets(object, CONST256, stdin);
		strtok(object, "\n");
		tree->left = create(object, read);
		
		log_message("Finished creating new tree");
	}
	else {
		log_message("Loading tree");
		fseek(read, 0, SEEK_SET);
		
		tree = create(buffer, read);
		tree = insert(read);
		
		log_message("Finished loading tree from file");
	}

	

	ask(tree, read);

	read = fopen("questions.txt", "w");
	if (read == NULL) {
		printf("Cant open file!");
		 free(buffer);
		return 0;
	}

	
	log_message("Saving tree to file");
	save_tree(read, tree);
	fclose(read);
	log_message("Finished saving tree to file");

	log_message("Program finished");

	FILE* logfile = fopen("log.txt", "a");
	fprintf(logfile, "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        free(buffer);
	fclose(logfile);
	return 0;
}
