#include <time.h>

void write_log(float, int);

void write_log(float temp, int light)
{
    FILE *logFile;

    logFile = fopen("logfile.txt", "a");
    if (logFile == NULL)
    {
        printf("Error opening the logfile.\n");
    }

    // Get current time
    time_t NOW = time(NULL);
    struct tm *TMINFO = localtime(&NOW);
    char TIME[20];
    strftime(TIME, sizeof(TIME), "%d-%m-%Y %H:%M:%S", TMINFO);

    // Write to the logfile
    fprintf(logFile, "[%s] Temperature: %.2f°C, Light Intensity: %d\n", TIME, temp, light);

    // Flush the buffer to ensure immediate write
    fflush(logFile);
    fclose(logFile);
    return;
}