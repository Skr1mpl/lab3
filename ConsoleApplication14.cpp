#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class String {
	char* s;
	int n;
public:
	void printString();
	int getLen();
	char& operator[](const int index) {
		return s[index];
	}
	void operator++(int i) {
		s[i]++;
	}
	String(char* s1) {
		s = s1;
		n = strlen(s);
	}
	String(const String& s1) {
		s = s1.s;
		n = s1.n;
	}
	~String(){
		delete[]s;
	}
};

int String::getLen() {
	return n;
}

void String::printString() {
	cout << s;
}

int main() {
	setlocale(0, "rus");
	char* s = new char[255];
	cout << "Введите строку = ";
	cin >> s;
	String str(s);
	system("cls");
	while (true) {
		str.printString();
		cout << endl;
		cout << "Введите индекс который икрементировать или -1 = ";
		int kol;
		cin >> kol;
		if (kol < 0) break;
		if (kol < str.getLen()) str[kol]++;
		system("cls");
	}
	return 0;
}