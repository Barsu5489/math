#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "sort.c"

int main(int argc, char *argv[])
{
    FILE *file_read;
    char line[100];
    long double median = 0;
    long double variance = 0;
    long double total = 0;
    int line_num = 0;
    int i = 0;

    // Limit argument s to only two
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (-1);
    }
    // Second argment limited to data.txt
    if (strcmp(argv[1], "data.txt") != 0)
    {
        printf("use file name data.txt\n");
        return (-1);
    }
    // Open and read file
    file_read = fopen(argv[1], "r");
    if (file_read == NULL)
    {
        printf("Error opening the file\n");
        return (-1);
    }
    // Store number of files
    while (fgets(line, sizeof(line), file_read))
    {
        line_num++;
    }
    int num_array[line_num];
    rewind(file_read);
    // Append numbers to slice
    while (fgets(line, sizeof(line), file_read))
    {

        long double num = atoi(line);
        num_array[i++] = num;
    }
    // sort the slie
    sort(num_array, line_num);

    // Calculate the sum
    for (int i = 0; i < line_num; i++)
    {
        total += num_array[i];
    }
    // Calculates the average

    long double average = total / line_num;
    for (int i = 0; i < line_num; i++)
    {

        variance += (num_array[i] - average) * (num_array[i] - average);
    }
    // Calculates the varaince
    variance = variance / line_num;
    // Calculates the standard deviation
    long double std_dev = sqrt(variance);

    if (line_num % 2 == 0)
    {
        median = (num_array[line_num / 2] + num_array[line_num / 2 + 1]) / 2;
    }
    else
    {
        median = num_array[line_num / 2];
    }
    // Output the average, median, variance and standar deviation
    printf("Average: %.0Lf\n", (long double)round(average));
    printf("Median: %.0Lf\n", (long double)round(median));
    printf("Variance: %.0Lf\n", (long double)round(variance));
    printf("Standard Deviation %.0Lf\n", (long double)round(std_dev));
    fclose(file_read);

    return 0;
}
