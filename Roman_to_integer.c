#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    int map[26] = {0};
    map['I' - 'A'] = 1;
    map['V' - 'A'] = 5;
    map['X' - 'A'] = 10;
    map['L' - 'A'] = 50;
    map['C' - 'A'] = 100;
    map['D' - 'A'] = 500;
    map['M' - 'A'] = 1000;

    int result = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        int value = map[s[i] - 'A'];
        int nextValue = (i < length - 1) ? map[s[i + 1] - 'A'] : 0;

        if (value < nextValue) {
            result -= value;
        } else {
            result += value;
        }
    }

    return result;
}

int main() {
    char romanNumeral[] = "XXVII";
    int result = romanToInt(romanNumeral);
    printf("%s = %d\n", romanNumeral, result);

    return 0;
}

