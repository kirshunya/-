#define _CRT_SECURE_NO_WARNINGS
#define CONST256 256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "Source.h"
#include "tree.h"

tree* create(char* w, FILE* file) {
    tree* node = (tree*)malloc(sizeof(tree));
    node->mark = (char*)malloc(strlen(w) * sizeof(char) + 1);
    if (node->mark != NULL)
    {
        strcpy(node->mark, w);
    }
    int i = 0;
    while (w[i] != '\n' && w[i] != '\0') {
        i++;
    }

    node->right = NULL;
    node->left = NULL;
    return node;
}

tree* insert(FILE* file)
{
    char buffer [CONST256];
    if (fgets(buffer, strlen(buffer), file) == NULL)
        return NULL;
    if (strcmp(buffer, "^\n") == 0)
        return NULL;
    tree* tree = create(buffer, file);
    tree->right = insert(file);
    tree->left = insert(file);
    return tree;
}

void add(tree* tree, char* question, char* object, FILE* file) {
    char* old_question = tree->mark;
    tree->mark = question;
    tree->left = create(old_question, file);
    tree->right = create(object, file);
    log_message("Added new question and object to tree");
}

void ask(tree* tree, FILE* file) {
    if (tree == NULL) {
        printf("NULL\n");
        return;
    }
    
    if (tree->right == NULL && tree->left == NULL) {
        printf("It can be....  %s\n", tree->mark);
        printf("Am I right?\n");
        char answer[4];
        scanf("%s", answer);

        if (strcmp(answer, "yes") == 0) {
            printf("I guess!\n");
            log_message("Akinator guessed right.");
            return;
        }

        else 
        {
            printf("I didn't guess which object you made up?\n");
            char object[CONST256];
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            fgets(object, CONST256, stdin);
            strtok(object, "\n");
            printf("What is a question that distinguishes %s from %s?\n", object, tree->mark);
            char question[CONST256];
            fgets(question, CONST256, stdin);
            strtok(question, "\n");
            char q1[CONST256] ;
            q1 =  _strdup(question);
            char obj1[CONST256] ;
            obj1 = _strdup(object);
            add(tree, q1, obj1, file);
            printf("Thank you! I'll remember that for next time.\n");
            log_message("A new object has been added .");
            log_message_object("Object", object);
            free(q1);
            free(obj1);
            return;
        }
    }
   
    printf("%s\n", tree->mark);
    char answer[4];
    scanf("%s", answer);
    if (strcmp(answer, "yes") == 0) {
        ask(tree->right, file);
    }
    else if (strcmp(answer, "no") == 0) {
        ask(tree->left, file);
    }
    else {
        printf("Answer must be 'yes' or 'no'\n");
        ask(tree, file);
    }
}

void save_tree(FILE* file, tree* current_node) {
    if (current_node == NULL) {
        fprintf(file, "^\n"); 
        return;
    }
    fprintf(file, "%s\n", current_node->mark);
    save_tree(file, current_node->right);
    save_tree(file, current_node->left);
}

