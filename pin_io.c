#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int fd;

void export_pin(int, int);
void setup_pin(int);
void set_pin(int, int);

void export_pin(int pin, int export_state)
{
    char pin_str[2];
    sprintf(pin_str, "%d", pin);

    if (export_state)
    {
        printf("Exporting pin: %d\n", pin);
        int fd = open("/sys/class/gpio/export", O_WRONLY);

        if (write(fd, pin_str, 2) != 2)
        {
            perror("Error writing to /sys/class/gpio/export");
        }
    }
    else
    {
        printf("Unexporting pin: %d\n", pin);
        fd = open("/sys/class/gpio/unexport", O_WRONLY);

        if (write(fd, pin_str, 2) != 2)
        {
            perror("Error writing to /sys/class/gpio/unexport");
        }
    }

    close(fd);
}

void setup_pin(int pin)
{
    char path[50];
    sprintf(path, "/sys/class/gpio/gpio%d/direction", pin);

    FILE *direction_file = fopen(path, "w");
    if (direction_file == NULL)
    {
        perror("Unable to open GPIO direction file");
        exit(1);
    }

    if (fprintf(direction_file, "out") < 0)
    {
        perror("Error writing to GPIO direction file");
        exit(1);
    }

    fclose(direction_file);
}

void set_pin(int pin, int state)
{
    char path[50];
    sprintf(path, "/sys/class/gpio/gpio%d/value", pin);

    char state_str[2];
    if (!state)
    {
        strcpy(state_str, "0");
    }
    else
    {
        strcpy(state_str, "1");
    }

    FILE *value_file = fopen(path, "w");
    if (value_file == NULL)
    {
        perror("Unable to open GPIO direction file");
        exit(1);
    }

    if (fprintf(value_file, state_str) < 0)
    {
        perror("Error writing to GPIO direction file");
        exit(1);
    }

    fclose(value_file);
}