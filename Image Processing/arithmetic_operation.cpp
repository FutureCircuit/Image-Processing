#include <iostream>
#include "BMP.h"
#include "arithmetic_operation.h"
using namespace std;

void arithmeticOperation(BMPData** img) {
	cout << "Enter operator(+, -, *, /) and value \n" << "Ex: + 60, * 0.5, / 2 \n";
	char c;
	double num;
	cin >> c >> num;

	BYTE** data = (*img)->getImgData();
	switch (c) {
	case '-':
		num *= -1;
	case '+':
		for (int i = 0; i < (*img)->getBmpHeight(); i++) {
			for (int j = 0; j < (*img)->getBmpWidth(); j++) {
				data[i][j] += num;
				if (data[i][j] >= (*img)->getColors()) data[i][j] = (*img)->getColors() - 1;
			}
		}
		break;
	case '/':
		num = 1 / num;
	case '*':
		for (int i = 0; i < (*img)->getBmpHeight(); i++) {
			for (int j = 0; j < (*img)->getBmpWidth(); j++) {
				data[i][j] *= num;
				if (data[i][j] >= (*img)->getColors()) data[i][j] = (*img)->getColors() - 1;
			}
		}
		break;
	default:
		cout << "Can't operate this command. try again. \n";
	}
	
}