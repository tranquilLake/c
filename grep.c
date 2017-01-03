#include <stdio.h>
#define LINE_MAX_COUNT 1000

int get_line(char line[]);
int index_of(char source[], char target[]);

char pattern[] = "ould";
 
int main(void) {
    int found = 1;
    char line[LINE_MAX_COUNT];

    while (get_line(line) > -1) {
        if (index_of(line, pattern) > -1) {
            printf("%s", line);
            found = 0;
        }
    }

    return found;
}

/* get next line from stand io */
int get_line(char line[]) {
    int current_char;                                   // current readed char
    int i;                                              // current index of char []

    // read until the the current_char is '\n' or EOF or out of LINE_MAX_COUNT
    for(i = 0, current_char = getchar();                 
            i < LINE_MAX_COUNT && current_char != '\n' && current_char != EOF; current_char = getchar(), i++) {
        line[i] = current_char;
    }

    if(current_char == '\n')                            // add '\n' if needed
        line[i++] = current_char;
    
    line[i] = '\n';                                     // end the string 
}

/* index of substring */
int index_of(char source[], char target[]) {
    int s_char;                                         // current charactor of string source
    int t_char;                                         // current charactor of string target
    int s_i = 0;                                        // current index 0f string source
    int t_i = 0;                                        // current index of string target
    int start = 0;                                      // current match start index

    // check source current charactor,
    // if it match target charactor, than check next source charactor and next target charactor
    // if all matched, than return the start position

    for(s_char = source[s_i], t_char = target[t_i]; 
            s_i < LINE_MAX_COUNT && s_char != '\0'; s_char = source[++s_i], t_char = target[t_i]) {

        if (t_i == 0)                                   // record the start position
            start = s_i;

        if (t_char == '\0')                             // all match, return
            return start;
        else if (s_char == t_char)                      // match, check next
            t_char ++;
        else                                            // not match, reset target to check again
            t_i = 0;
    }
    
    return -1;                                          // all checked, but not match, return -1
}