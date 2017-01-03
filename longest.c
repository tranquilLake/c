#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[]);
void copy_line(char from[], char to[]);

void main(){
    int current_line_length;
    int longest_line_length;
    char current_line[MAXLINE];
    char longest_line[MAXLINE];

    while ((current_line_length = get_line(current_line)) > 0) {
        if(current_line_length > longest_line_length){
            copy_line(current_line, longest_line);
            longest_line_length = current_line_length;
        }
    }

    if(longest_line_length > 0) {
        printf("longest line:%s\n", longest_line);
        printf("longest line length: %d\n", longest_line_length);
    }
}

void copy_line(char from[], char to[]) {
    int i = 0;
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
}

int get_line(char line[]){
    int current_char;
    int i;

    for(i = 0; i < MAXLINE && (current_char = getchar()) != EOF && current_char != '\n'; i++) {
        line[i] = current_char;     
    }
    if(current_char == '\n') {
        line[i] = current_char;
        i++;
    }
    line[i] = '\0';
    return i;
}