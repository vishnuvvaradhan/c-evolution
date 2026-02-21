/*
 * Day 2 — Safe String Copy (Heap Intro)
 *
 * Program name: dup_string
 *
 * Requirements:
 *
 * 1. Accept exactly one command-line argument.
 * 2. Allocate heap memory large enough to store a copy of the string.
 * 3. Copy the string into the allocated memory.
 * 4. Print the copied string.
 * 5. Free the allocated memory before exiting.
 *
 * Required headers:
 *   <stdio.h>
 *   <stdlib.h>
 *   <string.h>
 *
 * Required functions (must use):
 *   malloc
 *   free
 *   strlen
 *   strcpy
 *
 * Error conditions (must handle):
 * - Incorrect number of arguments
 * - malloc fails
 *
 * On error:
 * - Print an error message to stderr
 * - Return EXIT_FAILURE
 *
 * Rules:
 * - Do NOT use stack allocation for the copy
 * - Must check result of malloc
 * - Must free memory exactly once
 * - Must compile clean with:
 *     -Wall -Wextra -Werror -fsanitize=address
 *
 * What this trains:
 * - Heap allocation
 * - Ownership discipline
 * - Checking allocation failure
 * - Matching malloc with free
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){

    if(argc != 2){

        fprintf(stderr, "Incorrect Number of Arguments: Usage: ./dup_string <string>");

        return EXIT_FAILURE;
    }

    char *string_to_copy = argv[1];

    //size_t needed as strlen returns size_t
    size_t str_length = strlen(string_to_copy);


    //add one for terminating /0
    char *p = malloc((str_length) + 1);

    if(p == NULL){

        fprintf(stderr, "Could not allocate memory");

        return EXIT_FAILURE;
    } 

    strcpy(p, string_to_copy);

    printf("String Copied Sucessfully: %s\n", p);

    free(p);

    return EXIT_SUCCESS;
}


