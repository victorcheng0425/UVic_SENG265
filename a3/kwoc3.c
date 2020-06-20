/*
 * kwoc3.c
 * Victor Cheng
 * Starter file provided to students for Assignment #3, SENG 265,
 * Spring 2020
 */

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emalloc.h"
#include "listy.h"

//extract word from line and exception file
node_t* extract_word(node_t *line, node_t *words, node_t *exc_word){
  node_t *curr_line; //pointer to keep track of line list
  node_t *curr_exe; //pointer to keep track of exception list
  int flag = 0; //flag to check if word exist in exception list
  int num = 1; //keep track of line number      free(temp_line);       free(temp_line); 

  //creat temp_line to get the line for further purpose
  for(curr_line = line; curr_line != NULL; curr_line = curr_line->next){
    char *temp_line = (char *)malloc(sizeof(char)*100); //max size is 100 
    strncpy(temp_line, curr_line->text, LIST_MAXLEN_TEXT);
	
	//turn the line to lower case
	for(int i = 0; i < strlen(temp_line); i++){ 
		if(temp_line[i] <= 90 && temp_line[i] >= 65){
		  //printf("%c\n", temp_line[i]);
			temp_line[i] += 32;
		}
	}
	
    char *t; //pointer to strtok;
    t = strtok(temp_line, " ");
    //extract the key word by scanning exception file
    while(t != NULL){
		if(exc_word != NULL){
			for(curr_exe = exc_word; curr_exe != NULL; curr_exe = curr_exe -> next){
				if(strcmp(curr_exe->text, t) == 0){
					flag = 1; //flag was set if word is in exception list
					break;
				}
			}
		}
		//create new object and add to the list
		node_t *new; 
		if(flag==0){ //add to words if flag = 0
			new = (node_t *)emalloc(sizeof(node_t));
			structure *temp = (structure *)emalloc(sizeof(structure));
			temp->star = ' '; //initialize the star
			strncpy(temp->word, t, LIST_MAXLEN_TEXT);
			strncpy(temp->line, curr_line->text, LIST_MAXLEN_TEXT);
			temp->line_number = num;
			new->node = temp;
			words = add_inorder(words, new);
		}
		t = strtok(NULL, " ");
		flag = 0;
    }
    num++;
    free(temp_line);
  }
 
  return words;
}

//find max length of the word	
int max_length(node_t *node){
	node_t *curr;
	int max = 0;
	for(curr = node; curr != NULL; curr = curr->next){
		if (strlen(curr->node->word) > max){
			max = strlen(curr->node->word);
		}
	}
	return max;
}

//formatting, add empty space after word
void formatting(node_t *node, int max){
	max += 2; //add two more spaces
	node_t *curr;
	for(curr = node; curr != NULL; curr = curr->next){
		char *pt;
		while(strlen(curr->node->word) < max){
			int temp = strlen(curr->node->word);
			pt = curr->node->word;
			pt = pt + temp;
			*pt = ' ';
			*(pt+1) = '\0';
		}
	}
}

//for debugging
void print_word(node_t *node, void *arg)
{
    char *format = (char *)arg;
    printf(format, node->text);
}

//print final result 
//two condition, if '*' exist, use the first printf
//if '*' doesn't exist, use the second printf
void final_print(node_t *node, void *arg)
{
    char *format = (char *)arg;
    if(node->node->star == '*'){
      printf(format, node->node->word, node->node->line, node->node->line_number, node->node->star);
    }else{
      printf(format, node->node->word, node->node->line, node->node->line_number);
    }
	  
}

int main(int argc, char *argv[])
{
    char *exception_file = NULL; //get exception file name
    char *input_file = NULL; //get input file name
    int i;
    int e_flag = 0;
    //int number = 0; //used to keep track of number of char in line
    node_t *exception = NULL; //exception list
    node_t *input = NULL; //input list
    node_t *word = NULL; //word list
    FILE *exe; //exeception file, and input file
    FILE *in; //input file

    for (i = 1; i < argc; i++) {
/* UPDATE: 13-March-2020. The inequality in the line below
 * needs to be changed from < to <= in order for it to
 * work correctly.
        if (strcmp(argv[i], "-e") == 0 && i+i < argc) {
*/
        if(strcmp(argv[i], "-e") == 0 && i+i <= argc) {
			e_flag = 1;
            exception_file = argv[++i];
        } else {
            input_file = argv[i];
        }
    }
    if(e_flag == 1 && exception_file != NULL){ 
      // exception = emalloc(sizeof(node_t));
      exe = fopen(exception_file, "r");
    }
    if(input_file != NULL){
      in = fopen(input_file, "r");
    }
    
    char *buffer = NULL; //for getline
    node_t *temp = NULL; //for creating new object and add to the list
    size_t input_len;
	//read input file
    while((getline(&buffer, &input_len, in)) != -1){
      buffer[strlen(buffer)-1] = '\0';
      temp = (node_t *)emalloc(sizeof(node_t));
      strncpy(temp->text, buffer, 100);//max length 100
      input = add_end(input, temp);
    }
	//read exception file
    while(e_flag == 1 && (getline(&buffer, &input_len, exe)) != -1){
      buffer[strlen(buffer)-1] = '\0';
      temp = (node_t *)emalloc(sizeof(node_t));
      strncpy(temp->text, buffer, 100);//max length 100
      exception = add_end(exception, temp);
    }
    free(buffer);//free the memory!

	//extract word via function
    word = extract_word(input, word, exception);
	//get max length of word
    int max = max_length(word);
	//formatting
    formatting(word, max);

    apply(word, final_print, "%s%s (%d%c)\n", "%s%s (%d)\n");
	
    //free memory
    while(input!=NULL){
      node_t *fre = input; //used to free memory (line)
      input = input->next;
      free(fre);
    }  
    while(exception!=NULL){
      node_t *fre = exception; //used to free memory (input)
      exception = exception->next;
      free(fre);
    }
    while(word!=NULL){
      structure *fr = word->node; //used to free memory (word(structure))
      node_t *fre = word; //used to free memory (word(node_t))
      word = word->next;
      free(fr);
      free(fre);
    }
/* 
 * Showing some simple usage of the linked-list routines.
 */
	if(e_flag == 1){
		fclose(exe);
	}

	fclose(in);


#ifdef DEBUG
    //_demo();
#endif

    exit(0);
}
