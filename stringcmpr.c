int main()
{
	char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
	int result;


	char* courseName1, *courseName2, *courseName3;

	courseName1 = malloc(sizeof * courseName1);
	
	courseName2 = malloc(sizeof * courseName2);

	courseName3 = malloc(sizeof * courseName3);


	courseName1 = "IT";

	courseName2 = "BSN";

	courseName3 = "LAW";

	// comparing strings str1 and str2
	result = strcmp(courseName1, courseName2);
	printf("strcmp(str1, str2) = %d\n", result);

	// comparing strings str1 and str3
	result = strcmp(courseName1, courseName3);
	printf("strcmp(str1, str3) = %d\n", result);

	return 0;
}
