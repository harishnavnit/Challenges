#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int count = 0; //array index counter
	char word[20] = " "; //current word
	char **array = NULL;
	
	char *term = "q"; //termination character
	char *prnt = "print";
	
	while (strcmp(term, word) != 0)
	{
		printf("Enter a string.  Enter q to end.  Enter print to print array\n");
		// fgets(word, sizeof(word), stdin); adds a newline character to the word.  wont work in this case
		scanf("%s", word);
		
		//printf("word: %s\nterm: %s\n",word, term);
		
		if (strcmp(term, word) == 0)
		{
			printf("Terminate\n");
		} 
		
		else if (strcmp(prnt, word) == 0)
		{
			printf("Enumerate\n");
			
			int i;
			
			for (i=0; i<count; i++)
			{
				printf("Slot %d: %s\n",i, array[i]);
			}
			
		}
		else
		{
			printf("String added to array\n");
			count++;
			array = (char**)realloc(array, (count+1)*sizeof(*array));
			array[count-1] = (char*)malloc(sizeof(word));
			strcpy(array[count-1], word);
		}
		
	}
	
	return 0;
}