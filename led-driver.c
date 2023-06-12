#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define int fd;
void exportpins(void);
void setoutput(void);
void LED1H(void);
void LED1L(void);
void unexport(void);

int main()
{
    
    exportpins();
    setoutput();
    LED1H();
    sleep(20);
    unexport();
    return 0;
}   
 
void exportpins(void){
// Export the desired pin by writing to /sys/class/gpio/export

    int fd = open("/sys/class/gpio/export", O_WRONLY);

    for (int i = 0; i < 8; i++) {
        char gpioNumber[2];
        sprintf(gpioNumber, "%d", i);

        if (write(fd, gpioNumber, 2) != 2) {
            perror("Error writing to /sys/class/gpio/export");
            exit(1);
        }

        printf("Exported GPIO %d\n", i);

        // Additional operations on the GPIO can be performed here

        sleep(1); // Wait for 1 second before exporting the next GPIO
    }

    close(fd);

}

    void setoutput(void){

    for (int i = 0; i < 8; i++) {
        char gpioPath[50];
        sprintf(gpioPath, "/sys/class/gpio/gpio%d/direction", i);

        FILE* directionFile = fopen(gpioPath, "w");
        if (directionFile == NULL) {
            perror("Unable to open GPIO direction file");
            exit(1);
        }

        if (fprintf(directionFile, "out") < 0) {
            perror("Error writing to GPIO direction file");
            exit(1);
        }

        fclose(directionFile);

        printf("Set GPIO %d direction to out\n", i);

        // Additional operations on the GPIO can be performed here

        sleep(1); // Wait for 1 second before setting the direction for the next GPIO
    }
    }
    void LED1H(void) {
        fd = open("/sys/class/gpio/gpio0/value", O_WRONLY);
        if (fd == -1) {
        perror("Unable to open /sys/class/gpio/gpio0/value");
        exit(1);
        }

        // Toggle LED 500 ms on, 50ms off, 100 times (10 seconds)

    
        if (write(fd, "1", 1) != 1) {
        perror("Error writing to /sys/class/gpio/gpio0/value");
        }


    close(fd);
    }



    void LED1L(void) {
        fd = open("/sys/class/gpio/gpio0/value", O_WRONLY);
        if (fd == -1) {
            perror("Unable to open /sys/class/gpio/gpio0/value");
            exit(1);
        }

        // Toggle LED 500 ms on, 50ms off, 100 times (10 seconds)


        if (write(fd, "0", 1) != 1) {
            perror("Error writing to /sys/class/gpio/gpio0/value");
        }


        close(fd);
    }
    
    void unexport(void) {
        for (int i = 0; i <= 24; i++) {
            char gpioNumber[3];
            sprintf(gpioNumber, "%d", i);

            fd = open("/sys/class/gpio/unexport", O_WRONLY);
            if (fd == -1) {
                perror("Unable to open /sys/class/gpio/unexport");
                exit(1);
            }

            if (write(fd, gpioNumber, 2) != 2) {
                perror("Error writing to /sys/class/gpio/unexport");
                exit(1);
            }

            close(fd);

            printf("Unexported GPIO %d\n", i);
        }
    }

