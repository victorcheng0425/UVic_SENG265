#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 100
#define MAXCHAR 80
#define WORD_CHAR 20
#define WORDLINES 500

int e_flag = 0; //check if dash e exist
char star_flag[WORDLINES];//check if more than one char in one line
int occur[WORDLINES]; //keep check of the lines 
char exclusion[MAXLINES][MAXCHAR];
char word[WORDLINES][WORD_CHAR];
char Lines[MAXLINES][MAXCHAR];


int main(int argc, char *argv[]){
  FILE* exc;   
  FILE* input;
  int max_length = 0; //variable for maximum word length 
  
  if(argc <= 1){
    printf("No parameters\n");             //test printf, test argc number
    return 0;
  }
  
  for(int x = 1; x < argc; x++){
    if(strcmp(argv[x], "-e") == 0){
      printf("found -e\n");                 //test printf, test -e
      exc = fopen(argv[x+1], "r");
      if(!exc){
	printf("Can't read exclusion file\n"); //test printf read exclusion file
      }
      if(x == 1){
	input = fopen(argv[3], "r");
      }else if(x == 2){
	input = fopen(argv[1], "r");
      }
      e_flag = 1;// set e flag 
    }
    else{
      input = fopen(argv[1], "r");
    }
  }
  //read and copy the exclusion file
  if(exc != NULL && e_flag == 1){
    int x = 0;
    while(fgets(exclusion[x], MAXCHAR, exc)){
     //printf("%s", exclusion[x]);
     char *temp;
     if((temp = strchr(exclusion[x], '\n'))){
	*temp = '\0';
     }
      x++;
    }
  }
  
  for(int x = 0; x < MAXLINES; x++){             //test printf, print exclusion list
     if(exclusion[x][0] == '\0'){
      break;
     }
     printf("%s\n", exclusion[x]);
    }
  //read input file
  if(input != NULL){
    int x = 0;
    while(fgets(Lines[x], MAXCHAR, input)){
      x++;
    }  
    for(int x = 0; x < MAXLINES; x++){            //test printf, print lines list
    printf("%s", Lines[x]);
   }
  
  }

  //copy "word" from Lines to word
  int num = 0;
  for(int x = 0; x < MAXLINES; x++){
    if(Lines[x][0] == '\0'){
	break;
    }
    char temp[MAXCHAR];
    char *t;
    int flag = 0;// flag to check if the word exist in exclusion list

    strncpy(temp, Lines[x], MAXCHAR);
    t = strtok(temp, " ");
    while( t != NULL ){
      flag = 0;
      char *temp;
      if((temp = strchr(t, '\n'))){
	*temp = '\0';
      }
      if(e_flag == 1){
        for(int y = 0; y < MAXLINES ; y++){
	  if(strcmp(exclusion[y], t) == 0){
	    flag = 1;
	    break;
	  }
        }
      } 
      if(flag==0){        
	strncpy(word[num], t, WORD_CHAR); //copy the word(string) to array
	if(strlen(word[num]) > max_length){max_length = strlen(word[num]);} //find max length 
	occur[num] = x+1; //store line number (x) to occur array
	num++;
      }            
      t = strtok(NULL, " ");
    }
  }
//selection sort for word list
//also sort the occur list, which match the two list
   for(int x = 0; x < WORDLINES; x++){
     if(word[x][0] == '\0'){break;}
     int min = x;
     star_flag[min] = 0;
     char temp[WORD_CHAR]; //store temp char*
     for(int y = x+1; y < WORDLINES; y++){
	if(word[y][0] == '\0'){break;}
	if(strcmp(word[min],word[y]) > 0){
	 min = y;
	}else if(strcmp(word[min], word[y]) == 0){ //if two words are same, check lines
	    if(occur[min] == occur[y]){ //if lines are also the same
	      for(int z = y; z < WORDLINES-1; z++){
		occur[z] = occur[z+1];
		strcpy(word[z], word[z+1]);

	      star_flag[x] = '*';
	      }              
	    }
	} 
     }
     //switch word
     strcpy(temp, word[min]);
     strcpy(word[min], word[x]);
     strcpy(word[x], temp);
     int tem = 0; //used to switch char
     //switch line number
     tem = occur[min];
     occur[min] = occur[x];
     occur[x] = tem;
      //turn upper case letter
     int z = 0;
     while(word[x][z]){
	word[x][z] = word[x][z] - 32;
        z++;
     }
  }

//testing, print word list
for(int x = 0; x < WORDLINES; x++){
 if(word[x][0] == '\0'){break;}
 printf("Word[%d]: %s, Occur[%d]: %d%c\n", x, word[x], x, occur[x], star_flag[x]);
}

//put spaces after word
   for(int x = 0; x < WORDLINES; x++){
     if(word[x][0] == '\0'){break;}
     int y = strlen(word[x]);
     printf("y: %d\n", y);
     while(strlen(word[x]) < max_length+1){
       word[x][y] = ' '; //put space 
       word[x][y+1] = '\0';
       y++;
       }
   }
     
//print result
   for(int x = 0; x < WORDLINES; x++){
     if(word[x][0] == '\0'){break;}
     char *temp;
     if((temp = strchr(Lines[occur[x]-1], '\n'))){
	*temp = '\0';
     }
     //printf("%d\n", max_length);
     printf("%s %s (%d%c)\n",  word[x], Lines[occur[x]-1], occur[x], star_flag[x]);
   
   }

   fclose(exc);
   fclose(input);

  return 0;

}
