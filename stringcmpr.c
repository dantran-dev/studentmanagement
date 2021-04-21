#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
	int result1, result2;


	char* courseName1, *courseName2, *courseName3, *courseName4;

	courseName1 = malloc(sizeof * courseName1);
	
	courseName2 = malloc(sizeof * courseName2);

	courseName3 = malloc(sizeof * courseName3);

	courseName4 = malloc(sizeof *courseName4);


	courseName1 = "ABC";

	courseName2 = "DEF";

	courseName3 = "MACDONALD";

	courseName4 = "KFC";



	// comparing strings str1 and str2
	result1 = strcmp(courseName1, courseName4);
	printf("strcmp(str1, str4) = %d\n", result1);

	// comparing strings str1 and str3
	result2 = strcmp(courseName2, courseName4);
	printf("strcmp(str2, str4) = %d\n", result2);

	if(result1 > result2)
	{
		printf("result 1 > result2 \n");
	}
	else
	{
		printf("result2 > result 1 \n");
	}

	return 0;
}
