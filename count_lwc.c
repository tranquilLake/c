#include <stdio.h>

#define IN	1
#define OUT	0

int main(){
	int current_char;

	int char_count = 0;
	int word_count = 0;
	int line_count = 0;

	int is_in_word = OUT;
	
	while ((current_char = getchar()) != EOF){
		char_count ++;

		if (current_char == '\n'){
			line_count ++;
			is_in_word = OUT;
		}else if(current_char == ' ' || current_char == '\t'){
			is_in_word = OUT;
		}else if(is_in_word == OUT){
			is_in_word == IN;
			word_count ++;
		}
		
	}
	
	printf("%d %d %d", line_count, word_count, char_count);
	
	return 0;
}

