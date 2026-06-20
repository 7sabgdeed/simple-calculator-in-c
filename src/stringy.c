#include <ctype.h>
#include <string.h>

void trim(char* str) {

    //   LEFT TRIM   //

    char* start = str;
    
    while (*start && isspace((unsigned char)*start)) {
        
        start++;
    }
    
    
    if (*start == '\0') {
        
        str[0] = '\0';
        return;
    }
    
    //__ LEFT TRIM __ //
    

    //   RIGHT TRIM   //

    char* end = start + strlen(start) - 1;

    
    while (end > start && isspace((unsigned char) *end)) {

        end--;
    }
    

    *(end + 1) = '\0';
    
    //__ RIGHT TRIM __ //

    memmove(str, start, strlen(start) + 1);
}