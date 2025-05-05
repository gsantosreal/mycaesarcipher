#include <iostream>
#include <cctype>
#include <string>
using namespace std;

string caesarCipher(string& message, int shift) {
	string encrypted = "";
	int letterCount = 0;
	shift = shift % 26;

	for (char c : message) {
		char encryptedChar = ((toupper(c) - 'A' + shift) % 26) + 'A';
		encrypted += encryptedChar;
		letterCount++;

		if (letterCount % 5 == 0) encrypted += ' ';
		if (letterCount % 50 == 0) encrypted += '\n';
	}

	return encrypted;
}

int main(int arc, char* argv[]) {
	int shift = atoi(argv[1]);
	string message;
	string input;
	while (getline(cin, input)) {
		message += input;
	}

	string encrypted = caesarCipher(message, shift);
	cout << encrypted << endl;

	return 0;
}
