#include "menu.h"

int getMenuNumber(string s) throw() {
	if (s.length() != 1 || !isdigit(s[0])) {
		throw "Please input 1-digit number.";
	}

	int num = s[0] - '0';
	if (num <= 0 || num >= MENU_MAX_NUM) {
		throw "Invalid menu number.";
	}
	return num;
}