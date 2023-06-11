#include <stdio.h>
#include <time.h>
#include <unistd.h> // For sleep function

int main() {
    FILE* logFile;

    logFile = fopen("logfile.txt", "a");
    if (logFile == NULL) {
        printf("Error opening the logfile.\n");
        return 1;
    }

    while (1) {
        // Get current time
        time_t now = time(NULL);
        struct tm* TMINFO = localtime(&now);
        char TIME[20];
        strftime(TIME, sizeof(TIME), "%d-%m-%Y %H:%M:%S", TMINFO);

        // Simulated temperature and light intensity values
        float TEMP = get_temp();
        int LIGHT = 500;

        // Write to the logfile
        fprintf(logFile, "[%s] Temperature: %.2f°C, Light Intensity: %d\n", TIME, TEMP, LIGHT);

        // Flush the buffer to ensure immediate write
        fflush(logFile);

        // Sleep for 1 minute
        sleep(60);
    }

    fclose(logFile);
    return 0;
}