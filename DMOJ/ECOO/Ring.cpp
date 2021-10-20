// ECOO '20 P4 - Ring

#include <bits/stdc++.h>
using namespace std;

long long x = 0;
struct Func {
    vector<pair<char, string>> args;
    unordered_map<string, Func *> funcs;
    string pass_args = "";

    void parse(const string &arg) {
        vector<string> parsed_arg;
        char *token = strtok(const_cast<char *>(arg.c_str()), " ");
        while (token != nullptr) {
            parsed_arg.push_back(string(token));
            token = strtok(nullptr, " ");
        }

        if (parsed_arg[0].front() == 'E') {
            pass_args = "";
        } else if (!pass_args.empty()) {
            funcs[pass_args]->parse(arg);
        } else if (parsed_arg[0].front() == 'A') {
            args.emplace_back('+', parsed_arg[1]);
        } else if (parsed_arg[0].front() == 'S') {
            args.emplace_back('-', parsed_arg[1]);
        } else if (parsed_arg[0].front() == 'M') {
            args.emplace_back('*', parsed_arg[1]);
        } else if (parsed_arg[0].front() == 'F') {
            pass_args = parsed_arg[1];
            funcs[pass_args] = new Func();
        } else {
            args.emplace_back('f', parsed_arg[1]);
        }
    }

    void exec(){
        for (auto arg: args){
            if (arg.first == '+'){
                x += stoll(arg.second);
            }
            else if (arg.first == '-'){
                x -= stoll(arg.second);
            }
            else if (arg.first == '*'){
                x *= stoll(arg.second);
            }
            else {
                funcs[arg.second]->exec();
            }
            x %= int(1e9+7);
        }
    }

    void print(){
        printf("%lld\n", x);
        x = 0;
    }
};

int main() {
    Func start = Func();
    int n; cin >> n;
    for (; n--;){
        string t; getline(cin, t);
        start.parse(t);
    }
    start.exec();
    start.print();
}