// WC '18 Contest 1 S2 - Essay Generator

#include <bits/stdc++.h>
using namespace std;

string words[11000] = {""};
int main() {
    int tmp = 0;
    for (int i = 0; i < 26; i++) words[i] += (char)(i + 'a');
    for (int i = 26; i < 702; i += 26) {
        for (int j = 0; j < 26; j++) words[i + j] += (char)(tmp + 'a');
        tmp++;
    }
    tmp = 0;
    for (int i = 26; i < 702; i += 26) {
        for (int j = 0; j < 26; j++) words[i + j] += (char)(j + 'a');
    }
    for (int i = 702; i < 10000; i += 676) {
        for (int j = 0; j < 676; j++)
            words[i + j] += (char)(tmp + 'a') + words[j + 26];
        tmp++;
    }
    int w;
    cin >> w;
    for (int i = 0; i < w; i++) cout << words[i] << " ";
    return 0;
}