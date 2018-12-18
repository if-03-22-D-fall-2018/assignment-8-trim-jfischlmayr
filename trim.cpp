/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			trim.cpp
 * Author:			P. Bauer
 * Due Date:		March 14, 2015
 * ----------------------------------------------------------
 * Description:
 * Test functions for trim.h
 * ----------------------------------------------------------
 */
 #include <string.h>
 #include "trim.h"

 static void get_min(const char* source, int *min);
 static void get_max(const char* source, int *min, int *max);

void trim(const char *source, char *trimmed_string){
  int min = 0;
  int max = strlen(source) - 1;

  get_min(source, &min);
  get_max(source, &min, &max);

  if(max == -1){
    strcpy(trimmed_string, "");
    return;
  }

  int count = 0;

  for(int i = min; i <= max; i++){
    trimmed_string[count] = source[i];
    count++;
  }
}

static void get_min(const char* source, int *min){
  while (source[*min] == ' ') {
    *min = *min + 1;
  }
}

static void get_max(const char* source, int *min, int *max){
  while(*max >= *min && source[*max] == ' '){
    *max = *max - 1;
  }
}
