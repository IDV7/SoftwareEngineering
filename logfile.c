#include <stdio.h>
#include <time.h>
#include <unistd.h> // For sleep function

int main() {
   
} 
void check_time(){
    time_t startTime = time(NULL);  // Get the starting time
    time_t currentTime;

    
        currentTime = time(NULL);  // Get the current time

        // Check if a minute has passed since the last execution of the task
        if (currentTime - startTime >= 60) {
            write_log();               // Call the task function
            startTime = currentTime;  // Update the starting time
        }
        
        
}
void write_log(){
FILE* logFile;

    logFile = fopen("logfile.txt", "a");
    if (logFile == NULL) {
        printf("Error opening the logfile.\n");
        return 1;
    }

        // Get current time
        time_t NOW = time(NULL);
        struct tm* TMINFO = localtime(&NOW);
        char TIME[20];
        strftime(TIME, sizeof(TIME), "%d-%m-%Y %H:%M:%S", TMINFO);

        // Simulated temperature and light intensity values
        float TEMP = get_temp();
        int LIGHT = 500;

        // Write to the logfile
        fprintf(logFile, "[%s] Temperature: %.2f�C, Light Intensity: %d\n", TIME, TEMP, LIGHT);

        // Flush the buffer to ensure immediate write
        fflush(logFile);

       

    fclose(logFile);
    return ;
    }