#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char **argv) {
    int a = atoi(argv[1]);

    switch(a) {
        case 1: 
            a = 1; 
            break;
        case 2: 
            a = 2; 
            break;
        case 10:
            a = 10; 
            break;
        case 3: 
            a = 3; 
            break;
        case 4:
        case 5:
        case 6:
            a = 4+5+6;
            break;
        default:
            a = 0;
            break;
    }

    printf("%d\n", a);
    return 0;
}
