#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#define MAXCHAR 120

using namespace std;


/* This is the structure that holds the 
 * required data of a file
 */
struct ContentsInfo {
    string title;
    string authorName;
    int wordCount;
    double letterFrequency[3];
    int lineCount;
}file;


/* This function takes care of printing
 * the required struct to the file named
 * CardCatalog.txt 
 */
void printToFile(ContentsInfo& file) {
    
    fstream p;
    p.open("CardCatalog.txt", fstream::app);
    p << "Title: " << file.title << endl;
    p << "Full Author: " << file.authorName << endl;
    string s1, s2;
    size_t ss = file.authorName.find(' ');
    size_t sx = file.authorName.find('\n');
    s1 = file.authorName.substr(0, ss);
    s2 = file.authorName.substr(ss, sx); 

    p << "Author First Name: " << s1 << endl;
    p << "Author Last Name: " << s2 << endl;
    p << "Word count: " << file.wordCount << endl;
    p << "Line count: " << file.lineCount << endl;
    p.close();
}

int main() {
	string inputFileName;
	string outputFileName;

    /* Reading the file that is provided by the user */
file_reenter:
    cout << endl;
	cout << "Enter the file name: ";
	cin >> inputFileName;
	fstream data;
	
	data.open(inputFileName, ios::in);

    /* Display the fail message for bad/nonexistent file */

	if (data.fail()) {
		cout << "The file name entered in not valid. Please enter a valid file name. ";
		cin >> inputFileName;
        goto file_reenter;
	}

    /* Get the title and author name */
    
    getline(data, file.title);
    getline(data, file.authorName);
    char ch;

    /* Storing total characters in file */
    float tot = 0;

    /* ctar[4] is {spaces, lines, alphabets ...} */
    int ctar[6] = {0,0,0,0,0,0};
    
    /* Looping to get all characters and checking what they are
     * to calculate letter frequency and number of words and lines
     */
    while (data.get(ch)) {
        tot += 1;
        if (ch == ' ')
            ctar[0]+=1;
        if (ch == '.')
            ctar[4]+=1;
        ch = toupper(ch);
        if (ch == 'A')
            ctar[1]+=1;
        if (ch == 'B')
            ctar[2]+=1;
        if (ch == 'C')
            ctar[3]+=1;
        if (ch == 'D')
            ctar[5]+=1;
    }

    /* Storing the date in the struct */
    file.wordCount = ctar[0]+1;
    file.letterFrequency[0] = ctar[1];
    file.letterFrequency[1] = ctar[2];
    file.letterFrequency[2] = ctar[3];
    file.lineCount = ctar[4];

    /* Print data from the struct to file */
    printToFile(file);
    
    data.close();

    /* Showing the letter frequency */
    char a;
    cout << "Would you like to see letter frequency of the provided file? (y/n): " << endl;
    cin >> a;
    if ((a == 'y') || (a == 'Y')) {
        cout << file.title << " letter frequency: " << endl;
        cout << "a: " << (ctar[1]/tot)*100 << "%" << endl;
        cout << "b: " << (ctar[2]/tot)*100 << "%" << endl;
        cout << "c: " << (ctar[3]/tot)*100 << "%" << endl;
        cout << "d: " << (ctar[5]/tot)*100 << "%" << endl;
    }
    
    /* Looping until user is done with the program */
    cout << "Would you like to parse another file? (y/n): " << endl;
    cin >> a;
    if ((a == 'y') || (a == 'Y'))
        goto file_reenter;

    return 0;
}
