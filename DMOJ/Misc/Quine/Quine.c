// Quine in C

#include <stdio.h>
const char* s =
    "%c%c Quine in C%c%c#include<stdio.h>%cconst char*s=%c%s%c;%cint "
    "main(){printf(s,47,47,10,10,10,34,s,34,10,10);}%c";
int main() { printf(s, 47, 47, 10, 10, 10, 34, s, 34, 10, 10); }