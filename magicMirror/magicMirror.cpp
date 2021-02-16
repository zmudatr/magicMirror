/*
@author Robert Zmuda Trzebiatowski
https://github.com/zmudatx

magic_mirror.cpp: This file contains the 'main' function. Program execution begins and ends there.

To generate different right - rotations of a word, write the word in a circle in clockwise order,
then start reading from any given character in clockwise order till you have covered all the characters.

For example: in word "sample" if we start with "p" we get right rotated word as "plesam".
There are six such of "sample" including itself.

The inputs of the program consists of two strings: word1 and word2 separated by comma.
The function returns 1 if word1 and word2 are right rotations of the same word and -1 if they are not.

Examples:
Input: abc, abcd					Output:	-1
Input: abc, cba						Output:	-1
Input: abc, bca						Output:	 1
Input: sample, plesam				Output:  1
Input: magicMirror, cMirrormagi		Output:  1


*/


#include <iostream>
#include <string>

using namespace std;

int isSameReflection(char* word1, char* word2)  // my first solution - "ad hoc"
{
	//	printf("Words to check: \"%s\" oraz \"%s\"\n", word1, word2);
	int length = strlen(word1);

	//	int length=0;	//while (word1[length] != '\0') length++;

	//	printf("Length of words = %i. So there are %i possible rotations. \n", length, length);

	int out = strcmp(word1, word2);

	for (int i = 0; i < length; i++)
	{
		out = strcmp(word1, word2);
		//	printf("Checking words \"%s\" and \"%s\" in %i iteration\n", word1, word2, i+1);

		if (out == 0) i = length;
		else
		{
			char temp = word2[0];
			for (int j = 1; j < length; j++)
			{
				word2[j - 1] = word2[j];
			}
			word2[length - 1] = temp;
		}
	}
	if (out == 0) return 1;
	else return -1;
}


int isSameReflection2(char* word1, char* word2)  // second, better solution
{
	//	printf("Words to check: \"%s\" oraz \"%s\"\n", word1, word2);
	int length = strlen(word1);
	//	printf("Length %i \n", length);

	char* new_string = new char[2 * length + 1];
	strcpy_s(new_string, 2 * length + 1, word1);
	strcat_s(new_string, 2 * length + 1, word1);

	//	printf("new_string = \"%s\" \n", new_string);
	bool result = strstr(new_string, word2);
	//printf("Result = %i \n", result);

	delete[] new_string;
	if (result == 1) return 1;
	else return -1;
}

int main()
{
	system("cls");
	string word1;
	string word2;

	getline(cin, word1, ',');
	(void)getchar();  // read unnecessary char
	getline(cin, word2);


	int word1_length = word1.length();
	int word2_length = word2.length();

	//	printf("Words to check \"%s\"(%i) and \"%s\"(%i)\n", word1.c_str(),word1_length, word2.c_str(),word2_length);

	if (word1.length() == word2.length())
	{
		/*
		First attempt to send strings as char*
		char* str1 = (char*)malloc(word1.length() + 1);
		char* str2 = (char*)malloc(word2.length() + 1);

		if (str1 && str2)
		{
			for (int i = 0; i <= word1_length; i++) {
				str1[i] = word1[i];
				str2[i] = word2[i];
			}
		}*/

		char* str1 = &word1[0];
		char* str2 = &word2[0];

		//	printf("Result of first implementation isSameReflection = %i \n", isSameReflection(str1, str2));
		//	printf("Result of second implementation isSameReflection2 = %i \n", isSameReflection2(str1, str2));

		//	printf("%i", isSameReflection(str1, str2));

		printf_s("%i", isSameReflection2(str1, str2));
	}
	else
	{
		printf_s("-1");
	}
}

