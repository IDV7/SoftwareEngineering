#include "pin_io.c"
#include <stdio.h>

void reset_pins(void);
void export_pins(int);
void setup_pins();
int map_to_8(int);

int led_pins[] = {17, 18, 27, 22, 23, 24, 14, 4};
int led_states[] = {1, 0, 1, 0, 1, 0, 1, 0};

void led_indicator(int value)
{
    for (int i = 0; i < value; i++)
    {
        set_pin(led_pins[i], 1);
    }
    for (int i = value; i < 8; i++)
    {
        set_pin(led_pins[i], 0);
    }
}

int map_to_8(int temperature)
{

    int temperature_int = (int)temperature; // Convert temperature to integer

    // Map the temperature to a value between 0 and 8
    int mapped_val = (temperature_int - 20) * 8 / 15;
    // printf("temp int: %d, mapped val: %d", temperature_int, mapped_val);

    // Ensure the mapped value is within the range of 0 to 8
    if (mapped_val < 0)
        mapped_val = 0;
    else if (mapped_val > 8)
        mapped_val = 8;

    return mapped_val;
}

void setup_pins()
{
    export_pins(0);
    export_pins(1);
    for (int i = 0; i < 8; i++)
    {
        setup_pin(led_pins[i]);
    }
}

void export_pins(int state)
{
    for (int i = 0; i < 8; i++)
    {
        export_pin(led_pins[i], state);
        sleep(1);
    }
}