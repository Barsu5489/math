#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <errno.h> 
#include <string.h>


void sort(int arr[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main(int argc, char* argv[]){
    FILE *file_read;
    char line[100]; 
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return (-1);
    }
    if (strcmp(argv[1], "data.txt") != 0) {
       printf("use file name data.txt\n");
        return (-1);
    }
    file_read = fopen(argv[1], "r");
     if (file_read == NULL) {
       printf("Error opening the file\n");
        return (-1);
    }
    int line_num = 0;
    int i = 0;
    while(fgets(line, sizeof(line), file_read)){
        line_num ++;
      
    }
    int num_array[line_num];
    rewind(file_read);
    while(fgets(line, sizeof(line), file_read)){
        
    
        long double num = atoi(line);
        num_array[i++] = num;
    }
    sort(num_array, line_num);
 
   long double median = 0;
   long double variance = 0;
   long double total = 0;
 
     for ( int i = 0; i < line_num; i++){
        total += num_array[i];
      
     }
    //  printf("%d total \n",total);
    //  printf("%d line num \n",line_num);
    long double  average = total/line_num;
      for ( int i = 0; i < line_num; i++){
      
        variance += (num_array[i]-average) * (num_array[i]-average);
       
       
     }
     variance = variance/line_num;
     long double std_dev = sqrt(variance);
    
     if (line_num % 2 == 0) {
        median = (num_array[line_num/2] + num_array[line_num/2 + 1]) / 2;
     } else {
        median = num_array[line_num/2];
     }

    printf("Average: %.0Lf\n", (long double)round(average));
    printf("Median: %.0Lf\n", (long double)ceil(median));
    printf("Variance: %.0Lf\n", (long double)round(variance));
    printf("Standard Deviation %.0Lf\n", (long double)round(std_dev));
    fclose(file_read);
  
    
    return 0;
}
