#include <stdio.h>
#include <cs50.h>
#include <math.h>

_Bool isLuhns(long long card_number) {
    long long temp_card_number = card_number;
    int sum = 0;
    _Bool is_every_other = false;
    
    while(temp_card_number > 0) {
        if(!is_every_other) {
            int digit = temp_card_number % 10;
            sum += digit;
            temp_card_number /= 10;
            is_every_other = true;
        }
        
        else {
            int digit = temp_card_number % 10;
            int times_two = 2 * digit;
            
            while (times_two >= 10) {
                sum += (times_two % 10);
                times_two /= 10;
            }
            
            sum += times_two;
            temp_card_number /= 10;
            is_every_other = false;
        }
    }

    return sum % 10 == 0;
}

int getFirstTwoDigits(long long card_number) {
    long long digits_left = card_number;
    
    while(floor(log10(llabs(digits_left))) + 1 > 2) {
        digits_left /= 10;
    }
    return digits_left;
}

int getLength(long long card_number) {
    return floor(log10(llabs(card_number))) + 1;
}

int main(void) {
    printf("number: ");
    long long card_number = GetLongLong();
    
    _Bool checkLuhns = isLuhns(card_number);
    int first_two = getFirstTwoDigits(card_number);
    int length = getLength(card_number);
    
    if(!checkLuhns) {
        printf("INVALID\n");
    }
    
    else {
        if((first_two == 34 || first_two == 37) && length == 15) {
            printf("AMEX\n");
        }
        else if((first_two >= 51 && first_two <= 55) && length == 16) {
            printf("MASTERCARD\n");
        }
        else if((first_two >= 40 && first_two <= 49) && (length == 13 || length == 16)) {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }
}