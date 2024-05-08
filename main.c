#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int main(int argc, char* argv[]){
     FILE *file_read;
    char line[100];
    file_read = fopen("data.txt", "r");
    int line_num = 0;
    int i = 0;
    while(fgets(line, sizeof(line), file_read)){
        line_num ++;
      
    }
    int num_array[line_num];
    rewind(file_read);
    while(fgets(line, sizeof(line), file_read)){
        
    
        int num = atoi(line);
        num_array[i++] = num;
    }
    qsort(num_array, line_num, sizeof(int), compare);
 
   int median = 0;
   int variance = 0;
   int total = 0;
 
     for ( int i = 0; i < line_num; i++){
        total += num_array[i];
      
        printf("%d \n",num_array[i]);
     }
     printf("%d total \n",total);
     printf("%d line num \n",line_num);
    int  average = total/line_num;
      for ( int i = 0; i < line_num; i++){
      
        variance += (num_array[i]-average) * (num_array[i]-average);
       
       
     }
    
     if (line_num % 2 == 0) {
        median = (num_array[line_num/2] + num_array[line_num/2 + 1]) / 2;
     } else {
        median = num_array[line_num/2];
     }

     printf("Average: %d \n", average);
      printf("Median %d \n", median);
        printf("Variance %d \n", variance/10);
    fclose(file_read);
  
    
    return 0;
}
