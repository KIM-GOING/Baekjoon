#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string subject[20] = { "" };	//����� ��� �迭
	double level[20] = { 0.0 };	//���� ��� �迭
	string Ascore[20] = { "" };	//���ĺ� ��� ��� �迭
	double score[20] = { 0.0 };	//���� ��� ��� �迭

	string al_score[10] = { "A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "P", "F" };
	double num_score[10] = { 4.5, 4.0, 3.5, 3.0, 2.5, 2.0, 1.5, 1.0, 0.0, 0.0 };

	//����, ����, ��� �Է¹ޱ�
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
		Ascore[i] = a_sc;	//���ĺ� ��� �迭�� ��� �Է�
		for (int j = 0; j < 10; j++) {
			if (a_sc == al_score[j]) {
				sc = num_score[j];
				break;
			}
		}
		score[i] = sc;	//���� ��� �迭�� ��� �Է�
		subject[i] = sb;	//���� �迭�� ���� �Է�
		level[i] = stod(s_l);	//���� �迭�� ���� �Է�
		
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