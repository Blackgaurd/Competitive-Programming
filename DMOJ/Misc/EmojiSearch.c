// Emoji Search

#include <stdio.h>

char c;
int emoji = 0;
int main() {
    while ((c = getchar()) != '\n') {
        if (c == ':') {
            emoji++;
            if (!(emoji & 1)) putchar('\n');
        } else if (emoji & 1)
            putchar(c);
    }

    return 0;
}