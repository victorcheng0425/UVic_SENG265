#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 100
#define MAXCHAR 80
#define WORD_CHAR 20
#define WORDLINES 500

int e_flag = 0; //check if dash e exist
char star_flag[WORDLINES];//check if more than one char in one line
int occur[WORDLINES]; //keep check of the lines (word occur in which line) 
int max_length = 0; //variable for maximum word length 

//copy "word" from Lines to word
void extract_word(char line[MAXLINES][MAXCHAR], char words[WORDLINES][WORD_CHAR], char exc_word[MAXLINES][MAXCHAR]);

////selection sort, sort the word array, star_flag array(keep track of *), occur array(Line number) concurrently
//combine two words if they are on the same line,and update star_flag array
//finally turn all words to uppercase letter
void selection_sort(char words[WORDLINES][WORD_CHAR]);

//put spaces after word, to display on the screen as requirement
void alignment(char words[WORDLINES][WORD_CHAR]);

//print result
void print_final_output(char line[MAXLINES][MAXCHAR], char words[WORDLINES][WORD_CHAR]);


int main(int argc, char *argv[]){
  FILE* exc;   
  FILE* input;
  char exclusion[MAXLINES][MAXCHAR];
  char word[WORDLINES][WORD_CHAR];
  char Lines[MAXLINES][MAXCHAR];
  
  if(argc <= 1){
    printf("No parameters\n");             //test printf, test argc number
    return 0;
  }
  //find dash e and read file
  for(int x = 1; x < argc; x++){
    if(strcmp(argv[x], "-e") == 0){
      //printf("found -e\n");                 //test printf, test -e

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
      break;
    }
    else{
      input = fopen(argv[1], "r");
    }
  }
  //copy the exclusion file
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

  //copy input file
  if(input != NULL){
    int x = 0;
    while(fgets(Lines[x], MAXCHAR, input)){
      x++;
    }
   }else if(input == NULL){
	printf("Can't read input file\n");
	return 0;
    }  
   //extract word from lines to word
   extract_word(Lines, word, exclusion);
   //sort the word array
   selection_sort(word);
   //adjust the alignment in word array
   alignment(word);
   //print the output as desired
   print_final_output(Lines, word);

   //close file
  if(exc != NULL){
   fclose(exc);
  }

  if(input != NULL){
   fclose(input);
  }

  return 0;

}

//functions 
void extract_word(char line[MAXLINES][MAXCHAR], char words[WORDLINES][WORD_CHAR], char exc_word[MAXLINES][MAXCHAR]){

  int num = 0;//keep track of the index of occur list
  for(int x = 0; x < MAXLINES; x++){
    if(line[x][0] == '\0'){ //if the array is empty, end the loop
	break;
    }
    char temp[MAXCHAR];//temp char array to extract lines by lines
    char *t; //pointer for strtok
    int flag = 0;// flag to check if the word exist in exclusion list

    strncpy(temp, line[x], MAXCHAR);
    t = strtok(temp, " ");
    while( t != NULL ){
      flag = 0;
      char *temp;
      if((temp = strchr(t, '\n'))){ //remove next line from  the word
	*temp = '\0';
      }
      if(e_flag == 1){ //if e_flag was set, compare the word to exclusion list
        for(int y = 0; y < MAXLINES ; y++){
	  if(strcmp(exc_word[y], t) == 0){
            flag = 1; //flag was set if the word is in the exclusion list
	    break;
	  }
        }
      } 
      if(flag==0){   //if the flag == 0, means the word is not in the exclusion list     
	strncpy(words[num], t, WORD_CHAR); //copy the word(string) to array
	if(strlen(words[num]) > max_length){max_length = strlen(words[num]);} //find max length of word
	occur[num] = x+1; //store line number (x) to occur array
	num++;
      }            
      t = strtok(NULL, " ");
    }
}
}

void selection_sort(char words[WORDLINES][WORD_CHAR]){
//selection sort for word list
//also sort the occur list, which match the two list
   for(int x = 0; x < WORDLINES; x++){
     if(words[x][0] == '\0'){break;}
     int min = x;
     star_flag[min] = 0;
     char temp[WORD_CHAR]; //store temp char*
     for(int y = x+1; y < WORDLINES; y++){
	if(words[y][0] == '\0'){break;}
	if(strcmp(words[min],words[y]) > 0){
	 min = y;
	}else if(strcmp(words[min], words[y]) == 0){ //if two words are same, check lines
	    if(occur[min] == occur[y]){ //if lines are also the same
	      for(int z = y; z < WORDLINES-1; z++){
		occur[z] = occur[z+1];
		strcpy(words[z], words[z+1]);
          }
	      star_flag[min] = '*';
	    }else if(occur[min] > occur[y]){
			min = y;
		}
	}
     }
     //switch word
     strcpy(temp, words[min]);
     strcpy(words[min], words[x]);
     strcpy(words[x], temp);

     int tem = 0; //used to switch char
     //switch line number
     tem = occur[min];
     occur[min] = occur[x];
     occur[x] = tem;
     //switch star char
     //char tem_char; 
     if(star_flag[x] == '\0' && star_flag[min] == '*'){
       star_flag[x] = '*';
       star_flag[min] = '\0';
     }else if(star_flag[min] == '\0' && star_flag[x] == '*'){
       star_flag[min] = '*';
       star_flag[x] = '\0';
     }
     //turn upper case letter
     int z = 0;
     while(words[x][z]){
	words[x][z] = words[x][z] - 32;
        z++;
     }
  }
}

void alignment(char words[WORDLINES][WORD_CHAR]){
   for(int x = 0; x < WORDLINES; x++){
     if(words[x][0] == '\0'){break;}
     int y = strlen(words[x]);
     while(strlen(words[x]) < max_length+1){
       words[x][y] = ' '; //put space 
       words[x][y+1] = '\0';
       y++;
       }
   }
}

void print_final_output(char line[MAXLINES][MAXCHAR], char words[WORDLINES][WORD_CHAR]){
   for(int x = 0; x < WORDLINES; x++){
     if(words[x][0] == '\0'){break;}
     char *temp;
     if((temp = strchr(line[occur[x]-1], '\n'))){
	*temp = '\0';
     }
     //printf("%d\n", max_length);
     if(star_flag[x] == '*'){
       printf("%s %s (%d%c)\n",  words[x], line[occur[x]-1], occur[x], star_flag[x]);
     }else if(star_flag[x] == '\0'){
       printf("%s %s (%d)\n",  words[x], line[occur[x]-1], occur[x]);
     }
   }
}
