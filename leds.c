#include "pin_io.c"

void reset_pins(void);
void export_pins(int);

int led_pins[] = {17, 18, 27, 22, 23, 24, 14, 4};
int led_states[] = {1, 0, 1, 0, 1, 0, 1, 0};

int main()
{
    export_pins(0);
    export_pins(1);
    for (int i = 0; i < 8; i++)
    {
        setup_pin(led_pins[i]);
    }

    while (1)
    {
        for (int i = 0; i < 8; i++)
        {
            set_pin(led_pins[i], 1);

            if ((i - 1) < 0)
                set_pin(led_pins[7], 0);
            else
                set_pin(led_pins[i - 1], 0);
            sleep(1);
        }
    }

    return 0;
}

void export_pins(int state)
{
    for (int i = 0; i < 8; i++)
    {
        export_pin(led_pins[i], state);
        sleep(1);
    }
}