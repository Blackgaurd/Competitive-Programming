// A Long Problem

#include <bits/stdc++.h>
using namespace std;

// 1
int divide(int a, int b) {
    return a / b;
}

// 2
int count_occurrences(string s, string pattern) {
    int n = pattern.size();
    int ret = 0;
    for (int i = 0; i < s.size() - n + 1; i++) {
        if (s.substr(i, n) == pattern) ret++;
    }
    return ret;
}

// 3
vector<int> sort_array(vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

// 4
int max_size_k(vector<int> arr, int k) {
    int sum = 0, ret = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (i >= k - 1) {
            if (i >= k) sum -= arr[i - k];
            ret = max(ret, sum);
        }
    }
    return ret;
}

// 5
char find_upper(char ch) {
    return ch - 'a' + 'A';
}

// 6
bool is_prime(int n) {
    if (n <= 2) return n == 2;
    if (!(n & 1)) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// 7
int distinct_integers(vector<int> arr) {
    unordered_set<int> nums;
    for (int i : arr) nums.insert(i);
    return nums.size();
}

// 8
bool is_inside(int x, int y, int rx, int ry, int w, int h) {
    return rx >= x && ry >= y && rx <= x + w && ry <= y + h;
}

// 9
bool is_even(int n) {
    return !(n & 1);
}

// 10
bool is_bit_on(int bit, int num) {
    return num & (1 << bit);
}

// 11
int create_max(vector<int> dig) {
    int ret = 0;
    sort(dig.begin(), dig.end(), greater<int>());
    for (int i : dig) {
        ret = (ret << 3) + (ret << 1) + i;
    }
    return ret;
}

// 12
int factorial(int n, int m) {
    if (n >= m) return 0;
    long long ret = 1;
    for (int i = 2; i <= n; i++) {
        ret = (ret * i) % m;
    }
    return ret;
}

// 13
bool should_feed(int h, int m, int th) {
    return h * m >= th;
}

// 14
pair<int, int> lowest_terms(int num, int denom) {
    int c = gcd(num, denom);
    return {num / c, denom / c};
}

// 15
int find_sum(int n) {
    return n * (n + 1) / 2;
}

// 16
string find_type(int type) {
    switch (type) {
        case 1:
            return "max, do";
        case 2:
            return "dhruv, fold";
        case 3:
            return "abayomi, open";
        case 4:
            return "snjezana, write";
        case 5:
            return "yuxuan, close";
        case 6:
            return "mohamed, move";
        case 7:
            return "scarlet, crush";
        case 8:
            return "anastasia, tear";
        case 9:
            return "aksana, press";
        case 10:
            return "alejandro, cut";
    }
}

// 17
string largest_lex(vector<string> arr) {
    return *max_element(arr.begin(), arr.end());
}

// 18
vector<int> add_colours(vector<int> c1, vector<int> c2) {
    return {min(255, c1[0] + c2[0]), min(255, c1[1] + c2[1]), min(255, c1[2] + c2[2])};
}

// 19
string remove_occurrences(string s, string pattern) {
    string ret = "";
    int n = pattern.size();
    for (int i = 0; i < s.size();) {
        if (i < s.size() - n + 1 && s.substr(i, n) == pattern) {
            i += n;
        } else {
            ret += s[i];
            i++;
        }
    }
    return ret;
}

// 20
bool AC() {
    return true;
}