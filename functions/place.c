#include <stdio.h>
#include <sqlite3.h>

int main(void) {
    
    printf("%s\n", sqlite3_libversion()); 
    
    return 0;
}