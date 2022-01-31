#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//structure for key table
typedef struct Table {
    char *Number_words;
    int count;
}KEY_TABLE;

    char *line_string = NULL;
    size_t   String_length = 0;
    int String_Size = 0;

//for showing the table
void display_table(KEY_TABLE table[], int n) {
    int i=0;    
    for (i = 0; i < n; i++) {
        printf("%s:\t%d\n", table[i].Number_words, table[i].count);
    }
}

int main(int argc, char *argv[]) {
  
    int  iNum_arg = argc - 1;
    KEY_TABLE table[iNum_arg];
    int iLoop = 0;
    
   for (iLoop = 1; iLoop < argc; iLoop++){  /* Initializing the table */
        table[iLoop - 1].Number_words = argv[iLoop];
        table[iLoop - 1].count = 0;
    }
     //initializing
    char words[1000]={0};

    //Reading line by line
    while((String_Size = getline(&line_string, &String_length, stdin))>=1) 
	 {
            int key = 0;
             while (key < String_Size){

              char string_char = line_string[key];
            
            if ((string_char == ' ') | (string_char == '\n') |( string_char == '.')) {
                
                for (iLoop = 0; iLoop < iNum_arg ; iLoop++){

                    //checking the words
                   if (strcmp(table[iLoop].Number_words, words) == 0) {
                        
                         table[iLoop].count += 1;
                    }
                }
                words[0] = '\0';
            }
            else {
                strncat(words, &string_char, 1);
            }
            
            key++;
        }
    }

    display_table(table, iNum_arg);
    return 0;
}

/*Github link: https://github.com/pneelesh97/Homework1.git */
