#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LINES 1000
char *lines[MAX_LINES];
int   num_lines;


int compare(const void *s, const void *t)
{
    return strcmp(*(char **)s, *(char **)t);
}


int main(int argc, char *argv[])
{
    int i;
    FILE *infile;
    char *buffer;

    /* size_t is really another name for an int, but using
     * this silences a compiler warning when using getline().
     */
    size_t buffer_len;


    if (argc < 2) {
        fprintf(stderr, "usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    infile = fopen(argv[1], "r");
    if (infile == NULL) {
        fprintf(stderr, "%s: cannot open %s\n", argv[0], argv[1]);
        exit(1);
    }

    for (i = 0; i < MAX_LINES; i++) {
        lines[i] = NULL;
    }

    num_lines = 0;
    buffer = NULL;
    int number = 0;

    char *temp_line;
    while((number = getline(&buffer, &buffer_len, infile)) != -1){
      buffer[strlen(buffer)-1] = '\0';
	printf("Readline: size:%d, bufferlen:%zu, content: %s \n", number, buffer_len, buffer);
	temp_line = (char *)malloc(strlen(buffer)+1);
	strncpy(temp_line, buffer, strlen(buffer)+1);
	lines[num_lines] = temp_line;
	num_lines++;

      }
      for (i = 0; i < num_lines; i++){
	printf("%s\n", lines[i]);
	  }
      qsort(lines, num_lines, sizeof(char *), compare);
    
for (i = 0; i < num_lines; i++){
	printf("after sort: %s\n", lines[i]);
	  }
    // HINT: Use getline()

      for(i = 0; i < num_lines; i++){
	free(lines[i]);
      }
      free(temp_line);
	     free(buffer);
    fclose(infile);
    return 0;
}
