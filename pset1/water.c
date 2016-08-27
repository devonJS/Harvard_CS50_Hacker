#include <stdio.h>
#include <cs50.h>

int main(void) {
    printf("minutes: ");
    int min = GetInt();
    
    while(min <= 0) {
        printf("minutes: ");
        min = GetInt();
    }
    
    int bottles = (int)((min * 1.5 * 128) / 16);
    printf("bottles: %i\n", bottles);
}