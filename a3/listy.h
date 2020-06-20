#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#define LIST_MAXLEN_TEXT 100

typedef struct structure {
    int line_number;
    char star;
    char line[LIST_MAXLEN_TEXT];
    char word[LIST_MAXLEN_TEXT];
} structure;

typedef struct node_t {
    char text[LIST_MAXLEN_TEXT];
    struct structure *node;
    struct node_t  *next;
} node_t;


node_t *new_node(char *);
node_t *add_front(node_t *, node_t *);
node_t *add_end(node_t *, node_t *);
node_t *peek_front(node_t *);
node_t *remove_front(node_t *);
void    apply(node_t *, void(*fn)(node_t *, void *), void *arg, void *arg2);
node_t *add_inorder(node_t *head, node_t *newnode);

#endif
