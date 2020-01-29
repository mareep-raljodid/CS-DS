#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string inputFileName;
	string outputFileName;
	
	cout << "Enter the file name: ";
	cin >> inputFileName;

	fstream data;
	
	data.open(inputFileName, ios::in);

	if (data.fail()) {
		cout << "The file name entered in not valid. Please enter a valid file name: ";
		cin >> inputFileName;
	}

	struct ContentsInfo {
		string title;
		string authorName;
		int wordCount;
		double letterFrequency;
		int lineCount;
	};








	return 0;
}