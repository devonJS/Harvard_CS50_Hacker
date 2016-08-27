#include <stdio.h>
#include <cs50.h>

int main(void) {
    int height = 50;
    while(height > 23 || height < 0) {
        printf("Height: ");
        height = GetInt();
    }

    string pyr_space = "  ";
    
    for(int i = 1; i < height + 1; i++) {
        for(int j = 0; j < height - i; j++) {
            printf(" ");
        }
        for(int k = 0; k < i; k++) {
            printf("#");
        }
        printf("%s", pyr_space);
        
        for(int l = 0; l < i; l++) {
            printf("#");
        }
        
        printf("\n");
    }
}