#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define true   1
#define false  0
#define MAX   20
#define FINAL 50

// Global variables
int i, j, string_count = 0;
char **final;

// Function prototypes
void display_strings();
void insert_new_string(char [MAX]);
bool check_duplicates();

// Main method
int main(int argc, char *argv[])
{
	int string_count = 0;
	char action[MAX/2], current_string[MAX];

	printf("\nEnter a command : ");
	scanf("%s", action);
	getchar();

	while (strcmp(action, "Q") != 0 || strcmp(action, "q") != 0) {
		if (strcmp(action, "Print") == 0 || strcmp(action, "print") == 0) {
			//Print the strings in the array
			display_strings();
		} else if (strcmp(action, "Insert") == 0 || strcmp(action, "insert") == 0) {
			// Insert a new string to the array
			printf("\nEnter string to be inserted : ");
			scanf("%s", current_string);
			insert_new_string(current_string);
		} else if (strcmp(action, "duplicates") == 0 || strcmp(action, "Duplicates") == 0) {
			if (check_duplicates()) printf("\nInternal matches found");
			else printf("\nNo matches found");			
		} else {
			printf("\nUnknown command. Terminating !");
			exit(0);
		}
		printf("\nEnter next command : ");
		scanf("%s", action);
	}

	return 0;
}

// Function definitions
void display_strings()
{
	char **itr = final;
	while(*itr != NULL) {
		printf("%s", **itr);
		++itr;
	}
}

void insert_new_string(char new_string[MAX])
{
	printf("Inserting %s \n", new_string);

	++string_count;
	final = (char **)realloc(final, (string_count + 1) * sizeof(*new_string));
	final[string_count - 1] = (char *)malloc(sizeof(new_string));
	strcpy(final[string_count - 1], new_string);
}

bool check_duplicates()
{
	for (i = 0; i < string_count; i++) {
		for (j = i+1; j < string_count; j++) {
			if (strcmp(final[i], final[j]) == 0) {
				return true;
				break;
			}
		}
	}
	return false;
}