#include <stdio.h>
#include <string.h>

int findSubstring(const char *mainString, const char *subString) {
    int mainLen = strlen(mainString);
    int subLen = strlen(subString);

    for (int i = 0; i <= mainLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (mainString[i + j] != subString[j]) {
                break;
            }
        }
        // printf("%d",j);
        if (j == subLen) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    char mainString[100], subString[50];

    printf("Enter the main string: ");
    gets(mainString);

    printf("Enter the substring to find: ");
    gets(subString);

    int index = findSubstring(mainString, subString);

    if (index != -1) {
        printf("Substring '%s' found at index %d in the main string.\n", subString, index);
    } else {
        printf("Substring '%s' not found in the main string.\n", subString);
    }

    return 0;
}