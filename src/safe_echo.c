/*
 * Day 1 — Safe Integer Echo
 *
 * Program name: safe_echo
 *
 * Requirements:
 *
 * 1. Accept exactly one command-line argument.
 * 2. Interpret the argument as a base-10 integer.
 * 3. Print the integer to stdout.
 *
 * Error conditions (must handle all):
 * - No argument provided 
 * - More than one argument provided
 * - Argument is not a valid integer
 * - Integer overflows or underflows
 *
 * On error:
 * - Print an error message to stderr
 * - Exit with a non-zero status
 *
 * Required headers:
 *   <stdio.h>
 *   <stdlib.h>
 *   <errno.h>
 *
 * Required functions (must use):
 *   strtol
 *   fprintf
 *   exit
 *
 * Rules:
 * - Must detect invalid input properly
 * - Must detect overflow properly
 * - Must check errno
 * - Must not use atoi
 * - Must compile clean with:
 *     -Wall -Wextra -Werror
 *
 * What this trains:
 * - Command-line argument handling
 * - Safe numeric parsing
 * - Proper error handling discipline
 * - Using errno correctly
 * - Writing to stderr
 * - Correct exit codes
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>

 //allows us to debug




 int main(int argc, char *argv[]){

    //first lets handle if the user inputs =! number of arguments
    //argc is the # of items passed in the arg line
   

    //strtol, allows us to convert a string into an integer

    if(argc != 2){
        //print usage, print     
        printf("Enter One Argument - Usage: safe_echo <integer>");

        fprintf(stderr, "Exiting program with error, %d\n", errno);

        return EXIT_FAILURE;

    }
    
    //grab string
    char *integer_string = argv[1];

    char *endptr;

    //good practice to set errno back to 0 as some functions dont set errno back to 0 after failures
    errno = 0;

    long value = strtol(integer_string, &endptr, 10);

    if (endptr == integer_string){

        fprintf(stderr, "Please Enter an Integer\n");

        return EXIT_FAILURE;

    }

    if(*endptr != '\0'){

        fprintf(stderr, "Invalid Integer Entered, Trailing Garbage\n");

        return EXIT_FAILURE;
    }

    if(errno == ERANGE){

        fprintf(stderr, "Overflow/Underflow ERR\n");

        return EXIT_FAILURE;
    }


    printf("Digit Entered %ld\n", value);


    return EXIT_SUCCESS;
 }