#include <iostream>
#include "Evaluator.h"

using namespace std;

int main() {
	string line ="3&&& 5";
	Evaluator A = Evaluator(line);
	cout << A.evaluate();
	system("pause");
}