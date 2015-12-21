#include <iostream>
#include <string>

/* Function prototype */
void string_reverse1(char *);
void string_reverse2(const char *);

void main(int argc, char *argv[])
{
	string input;
	std::cin >> input;

	std::cout << "string_reverse1() = " << string_reverse1(input);
	std::cout << "string_reverse2() = " << string_reverse2(input);

	return EXIT_SUCCESS;
}

/* Function definition */
void string_reverse1(char *string)
{

}

void string_reverse2(const char *string)
{

}
