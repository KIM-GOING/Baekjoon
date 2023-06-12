#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string subject[20] = { "" };	//과목명 담는 배열
	double level[20] = { 0.0 };	//학점 담는 배열
	string Ascore[20] = { "" };	//알파벳 등급 담는 배열
	double score[20] = { 0.0 };	//숫자 등급 담는 배열

	string al_score[10] = { "A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "P", "F" };
	double num_score[10] = { 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0, 0.0 };

	//과목, 학점, 등급 입력받기
	for (int i = 0; i < 20; i++) {
		string testcase[3] = { "" };
		string tc;
		getline(cin, tc);
		stringstream ss(tc);
		string s1;
		int num = 0;
		while (ss >> s1) {
			testcase[num] = s1;
			num += 1;
		}

		string sb = testcase[0];
		string s_l = testcase[1];
		string a_sc = testcase[2];

		double sc = 1.0;
		Ascore[i] = a_sc;	//알파벳 등급 배열에 등급 입력
		for (int j = 0; j < 10; j++) {
			if (a_sc == al_score[j]) {
				sc = num_score[j];
				break;
			}
		}
		score[i] = sc;	//숫자 등급 배열에 등급 입력
		subject[i] = sb;	//과목 배열에 과목 입력
		level[i] = stod(s_l);	//학점 배열에 학점 입력
		
	}

	double sum = 0.0;
	for (int i = 0; i < 20; i++) {
		if (Ascore[i] == "P") {
			continue;
		}
		sum += level[i] * score[i];
	}

	double all_level = 0.0;
	for (int i = 0; i < 20; i++) {
		if (Ascore[i] == "P")
			break;
		all_level += level[i];
	}

	double average = 0.0;
	average = sum / all_level;
	cout.precision(7);
	cout << average;

	return 0;
}