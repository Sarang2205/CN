#include <stdio.h>
#include <string.h>

int main() {
    char a[20], b[20];
    char sum[20], complement[20];
    int i, length;
    
    printf("Enter first binary string\n");
    scanf("%19s", a); // Use %19s to avoid buffer overflow
    printf("Enter second binary string\n");
    scanf("%19s", b); // Use %19s to avoid buffer overflow
    
    if (strlen(a) == strlen(b)) {
        length = strlen(a);
        char carry = '0';
        
        // Perform binary addition
        for (i = length - 1; i >= 0; i--) {
            if (a[i] == '0' && b[i] == '0' && carry == '0') {
                sum[i] = '0';
                carry = '0';
            } else if (a[i] == '0' && b[i] == '0' && carry == '1') {
                sum[i] = '1';
                carry = '0';
            } else if (a[i] == '0' && b[i] == '1' && carry == '0') {
                sum[i] = '1';
                carry = '0';
            } else if (a[i] == '0' && b[i] == '1' && carry == '1') {
                sum[i] = '0';
                carry = '1';
            } else if (a[i] == '1' && b[i] == '0' && carry == '0') {
                sum[i] = '1';
                carry = '0';
            } else if (a[i] == '1' && b[i] == '0' && carry == '1') {
                sum[i] = '0';
                carry = '1';
            } else if (a[i] == '1' && b[i] == '1' && carry == '0') {
                sum[i] = '0';
                carry = '1';
            } else if (a[i] == '1' && b[i] == '1' && carry == '1') {
                sum[i] = '1';
                carry = '1';
            }
        }
        
        sum[length] = '\0'; // Null-terminate the sum array
        
        // If there is a carry, add it back to the sum
        if (carry == '1') {
            for (i = length - 1; i >= 0; i--) {
                if (sum[i] == '1') {
                    sum[i] = '0';
                } else {
                    sum[i] = '1';
                    carry = '0'; // Reset carry as it's been added
                    break;
                }
            }
        }
        
        printf("\nSum=%s", sum);
        
        // Generate the complement of the sum
        for (i = 0; i < length; i++) {
            if (sum[i] == '0') 
                complement[i] = '1';
            else 
                complement[i] = '0';
        }
        
        complement[length] = '\0'; // Null-terminate the complement array
        printf("\nChecksum=%s", complement);
    } else {
        printf("\nWrong input strings");
    }

    return 0;
}
