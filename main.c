#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    // const char fileName[] = "out.txt";
    // FILE *file_output;
     FILE *file_read;
    // file_output = fopen(fileName,"w");
    // fprintf (file_output, "string dadddcta new\n");
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
   
     for ( int i = 0; i < line_num; i++){
        printf("%d \n",num_array[i]);
        // printf("d");
     }
    fclose(file_read);
    // printf("You have entered %d arguments\n", argc);
    
    // for (int i = 1; i < argc; i++){
    //     printf("%s\n", argv[i]);
    // }
    
    return 0;
}