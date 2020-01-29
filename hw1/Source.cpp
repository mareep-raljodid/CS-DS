#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#define MAXCHAR 120

using namespace std;

struct ContentsInfo {
          string title;
          string authorName;
          int wordCount;
          double letterFrequency[MAXCHAR];
          int lineCount;
}file;

int main() {
	string inputFileName;
	string outputFileName;

file_reenter:
	cout << "Enter the file name: ";
	cin >> inputFileName;
	fstream data;
	
	data.open(inputFileName, ios::in);

	if (data.fail()) {
		cout << "The file name entered in not valid. Please enter a valid file name. ";
		cin >> inputFileName;
        goto file_reenter;
	}
    
    getline(data, file.title);
    getline(data, file.authorName);
    int ch;
    int ctar[4] = {0,0,0,0};
    while (EOF != (ch = getchar())) {
        toupper(ch);
        if (ch == ' ')
            ctar[0]+=1;
        if (ch == 'A')
            ctar[1]+=1;
        if (ch == 'B')
            ctar[2]+=1;
        if (ch == 'C')
            ctar[3]+=1;
    }
    cout << ctar[0];



	return 0;
}
