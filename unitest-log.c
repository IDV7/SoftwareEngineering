#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* log_file;
	log_file = fopen("logfile.txt", "r");

	char line[BUFSIZ];
	int i, value = 0;

	if (log_file == NULL)
	{
		printf("Error opening log file.\n");
	}

	fgets(line, BUFSIZ, log_file);

	for (i = 1; line[i] != '\n'; i++)
	{
		while (i < 18)
		{
			if (isdigit(line[i]))
			{
				i += 1;
			}
			if (i == 3 || i == 6 || i == 11 || i == 14 || i == 17)
			{
				i += 1;
			}
			else
			{
				printf("Fault in log file.");
				break;
			}
		}
	}

	if (line[22] == "T")
	{
		if (isdigit(line[35]))
		{
			printf("Log file oke.");
		}
		else
		{
			printf("Fault in log file.");
			break;
		}
	}
	else
	{
		printf("Fault in log file.");
		break;
	}

	fclose();
}