#include <stdio.h>

int main()
{
	int count = 1;
	int current_char;
	
	while ((current_char = getchar()) != EOF)
	{
		if (current_char == '\n')
		{
			count = count + 1;
		}
	}
	
	printf("%d\n", count);
	
	return 0;
}