#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char write_log(float, int);

void main(void)
{
    float temperatuur;
    int licht, i;

    for  (i = 0; i < 1; i++)
    {
        char line = "[01-01-2023 00:00:00] Temperature: 25°C, Light Intensity: 14\n";
        temperatuur = 25;
        licht = 14;

        if (strcmp(line, write_log(temperatuur, licht)) == 0)
        {
            printf("ok");
        }
        else
        {
            printf("%c niet oke", line);
        }
    }
}

char write_log(float temp, int light)
{
    FILE* logFile;
    logFile = fopen("logfile.txt", "a");

    char output[70];
    char temperatuur[10];
    char licht[10];

    sprintf(temperatuur, "%f", temp);
    sprintf(licht, "%d", light);

    strcat(output, "[01-01-2023 00:00:00] Temperature: ");
    strcat(output, temperatuur);
    strcat(output, "°C, Light Intensity: ");
    strcat(output, licht);
    strcat(output, "\n");

    if (logFile == NULL)
    {
        printf("Error opening the logfile.\n");
    }

    // Get current time
    time_t NOW = time(NULL);
    struct tm* TMINFO = localtime(&NOW);
    char TIME[20];
    strftime(TIME, sizeof(TIME), "%d-%m-%Y %H:%M:%S", TMINFO);

    // Write to the logfile
    fprintf(logFile, "[%s] Temperature: %.2f°C, Light Intensity: %d\n", TIME, temp, light);

    // Flush the buffer to ensure immediate write
    fflush(logFile);
    fclose(logFile);
    return output;
}