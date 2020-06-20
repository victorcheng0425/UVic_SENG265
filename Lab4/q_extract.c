#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 80

/*
 * Complete the implementation of extract_frequency
 * Fill out the parameters appropriately. Note how the function is called in the main.
 * extract_frequency will extract the frequency from the RRULE string (char array)
 * for the example line in the main, the information the function should extract is WEEKLY
 */

void extract_frequency(char *line, char *extract)
{
  //strcpy(extract, line);
  char *temp1;
  temp1 = strstr(line, "FREQ=");
  strcpy(extract, temp1);

  //char *p;
  char *temp;
    if((temp = strchr(extract, ';'))){
      *temp = '\0';
    }


  if((temp = strchr(extract, '='))){
    temp += 1;
    }

   strcpy(extract, temp);
  strcpy(line, temp);

}

/*
 * Practice writing other functions that will extract other information.
 * For example, write a function that will extract the data until which the RRULE applies. 
 */




int main()
{
        // This is the line from which the frequency is extracted
    char line[MAX_STRING_LEN] =
        "RRULE:FREQ=WEEKLY;WKST=MO;UNTIL=20190707T235959;BYDAY=TU";

        // This stores the final extracted frequency
    char extract[MAX_STRING_LEN];

    /* Note that the call to memset() is **not** identical to writing:
     *
          extract = "";
     *
     * Rather, it zeros out *all* of the bytes set aside for the
     * array named 'extract'.
     */
    memset(extract, '\0', MAX_STRING_LEN);
    extract_frequency(line, extract);

    printf("%s\n", extract);
    // Output of this print statement should be "WEEKLY", printed on console.
    return 0;
}
