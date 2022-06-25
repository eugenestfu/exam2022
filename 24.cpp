#include <iostream>
#include <vector>
#include <list>

using namespace std;

void Show(vector<int> &v) {
	for (auto i = v.begin(); i != v.end(); i++) cout << *i << " ";
	cout << "\n";
}

int main() {

	int a[3] = { 1,2,3 };
	vector<int> X;
	
	X.insert(X.begin(), a, a + 3);
	Show(X);

	vector<int> Y;
	Y.insert(Y.begin(), X.begin(), X.end());
	Show(Y);

	list<int> Z;
	Z.insert(Z.begin(), Y.begin(), Y.end());
	for (auto i = Z.begin(); i != Z.end(); i++) cout << *i << " ";
	cout << "\n";


}