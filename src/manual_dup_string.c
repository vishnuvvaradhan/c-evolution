#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){


    if(argc != 2){
        fprintf(stderr, "too many arguments passed: usage: ./manual_dup_string <string>\n");
        return EXIT_FAILURE;
    }

    size_t length = strlen(argv[1]);

    char *arr = argv[1];


    //allocate enough space on heap! add one for delimiter space, char is one byte
    char *ptr = malloc(length + 1);


    //malloc returns null ptr
    if(ptr == NULL){

        fprintf(stderr, "allocation failed\n");

        return EXIT_FAILURE;
    }


    char *old_ptr = ptr;


    do {
        *ptr = *arr;
        ptr++;
    } while (*arr++ != '\0');

    printf("string: %s\n", old_ptr);

    free(old_ptr);



    return EXIT_SUCCESS;
}



