#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin;
int main() {
	vector<int>chisl;
	fin.open("input.txt");
	if (!fin) {
		cout << "Ошибка открытия файла" << endl;
		return 0;
	};
	int n;
	while (fin.peek() != EOF) {
		fin >> n;
		chisl.push_back(n);
	};
	sort(chisl.begin(), chisl.end());
	for (auto iter = chisl.begin(); iter < chisl.end(); iter++) {
		cout << *iter << " ";
	};
	return 0;
}
