float get_temp(void);

float get_temp()
{
    FILE *file = fopen("/tmp/tmpValue", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 0.0;
    }

    float temperature;
    fscanf(file, "%f", &temperature);

    fclose(file);
    return temperature;
}
