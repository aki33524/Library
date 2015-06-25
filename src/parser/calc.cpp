//AOJ0109

#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

typedef string::const_iterator State;
class ParseError {};

int expression(State &begin);

int number(State &begin) {
	/*
	 * N -> [0-9]+
	 */

    int ret = 0;

    while (isdigit(*begin)) {
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }

    return ret;
}

// 括弧か数をパースして、その評価結果を返す。
int factor(State &begin) {
	/*
	 *  F -> (E) | N
	 */

    if (*begin == '(') {
        begin++;
        int ret = expression(begin);
        begin++;
        return ret;
    }else{
        return number(begin);
    }
}

int term(State &cur) {
	/*
	 * T -> F | T*F | T/F
	 * を
	 * T -> F(('*'|'/')F)*
	 * と置き換える
	 */

    int ret = factor(cur);

    while(*cur=='*' || *cur=='/'){
        if (*cur == '*') {
            cur++;
            ret *= factor(cur);
        } else if (*cur == '/') {
            cur++;
            ret /= factor(cur);
        }
    }

    return ret;
}

int expression(State &cur) {
	/*
	 * E -> T | E+T | E-T
	 * を
	 * E -> T(('+'|'-')T)*
	 * と置き換える
	 */

    int ret = term(cur);

    while(*cur=='+' || *cur=='-'){
        if (*cur == '+') {
            cur++;
            ret += term(cur);
        } else if (*cur == '-') {
            cur++;
            ret -= term(cur);
        }
    }

    return ret;
}

int main(void) {
    int N; cin >> N;
    while(N--){
        string s;
        cin >> s;
        State cur = s.begin();
        cout << expression(cur) << endl;
    }
    return 0;
}
