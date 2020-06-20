/*
 * linkedlist.c
 *
 * Based on the implementation approach described in "The Practice 
 * of Programming" by Kernighan and Pike (Addison-Wesley, 1999).
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emalloc.h"
#include "listy.h"


node_t *new_node(char *text) {
    assert( text != NULL);

    node_t *temp = (node_t *)emalloc(sizeof(node_t));

    strncpy(temp->text, text, LIST_MAXLEN_TEXT);
    temp->next = NULL;

    return temp;
}


node_t *add_front(node_t *list, node_t *new) {
    new->next = list;
    return new;
}


node_t *add_end(node_t *list, node_t *new) {
    node_t *curr;

    if (list == NULL) {
        new->next = NULL;
        return new;
    }

    for (curr = list; curr->next != NULL; curr = curr->next);
    curr->next = new;
    new->next = NULL;
    return list;
}


node_t *peek_front(node_t *list) {
    return list;
}


node_t *remove_front(node_t *list) {
    if (list == NULL) {
        return NULL;
    }

    return list->next;
}

//arg2 exist if certain condition required
void apply(node_t *list,
           void (*fn)(node_t *list, void *),
           void *arg, void *arg2)
{
    for ( ; list != NULL; list = list->next) {
		if(list->node != NULL && list->node->star  == '*'){
			(*fn)(list, arg);
		}else{
			(*fn)(list, arg2);
		}
	}
}

//add the object to specific location
node_t *add_inorder(node_t *head, node_t *newnode){
  node_t *curr;
  node_t *prev = NULL;

  //turn word to captal letter
	for(int i = 0; i < strlen(newnode->node->word); i++){
		if(newnode->node->word[i] <= 122 && newnode->node->word[i] >= 97){
		newnode->node->word[i] -= 32;
		}
	}

  //if the list is empty, add to the front
	if(head==NULL){
		curr = add_end(head, newnode);
		return curr;
	}
	//scan through the whole list and insert to proper location
	for(curr = head; curr != NULL; curr = curr->next) {
		if(strcmp(newnode->node->word, curr->node->word) == 0){
			if(newnode->node->line_number == curr->node->line_number){
				curr->node->star = '*';
				free(newnode->node);
				free(newnode); //free newnode if two word is the same
				return head;
			}else if(newnode->node->line_number > curr->node->line_number){
				prev = curr;
			}
		}else if (strcmp(newnode->node->word, curr->node->word) > 0){
			prev = curr;
		}else{
			break;
		}
	}
    if(prev == NULL){
		newnode->next = curr;
		return newnode;
    }else{
		newnode->next = curr;
		prev->next = newnode;
		return head;
    }     
}
