#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Member {
    int a;
    string n;
    int regist;
};

bool age(Member x, Member y) {
    if (x.a < y.a) return true;
    else if (x.a == y.a)
        if (x.regist < y.regist) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<Member> arr;
    for (int i = 0; i < n; i++) {
        Member person;
        int age;
        string name;
        cin >> age >> name;
        person.a = age;
        person.n = name;
        person.regist = i + 1;
        arr.push_back(person);
    }
    sort(arr.begin(), arr.end(), age);

    for (int i = 0; i < n; i++) {
        cout << arr[i].a << ' ' << arr[i].n << '\n';
    }


    return 0;
}