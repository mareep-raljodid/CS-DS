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
    double letterFrequency[26];
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
    double tot = 0;

    /* ctar[4] is {spaces, lines, alphabets ...} */
    double ctar[28] = {0};
    
    /* Looping to get all characters and checking what they are
     * to calculate letter frequency and number of words and lines
     */
    while (data.get(ch)) {
        tot += 1;
        if (ch == ' ')
            ctar[0]+=1;
        if (ch == '.')
            ctar[1]+=1;
        ch = toupper(ch);
        if (ch == 'A')
            ctar[2]+=1;
        if (ch == 'B')
            ctar[3]+=1;
        if (ch == 'C')
            ctar[4]+=1;
        if (ch == 'D')
            ctar[5]+=1;
         if (ch == 'E')
            ctar[6] += 1;
        if (ch == 'F')
            ctar[7] += 1;
        if (ch == 'G')
            ctar[8] += 1;
        if (ch == 'H')
            ctar[9] += 1;
        if (ch == 'I')
            ctar[10] += 1;
        if (ch == 'J')
            ctar[11] += 1;
        if (ch == 'K')
            ctar[12] += 1;
        if (ch == 'L')
            ctar[13] += 1;
        if (ch == 'M')
            ctar[14] += 1;
        if (ch == 'N')
            ctar[15] += 1;
        if (ch == 'O')
            ctar[16] += 1;
        if (ch == 'P')
            ctar[17] += 1;
        if (ch == 'Q')
            ctar[18] += 1;
        if (ch == 'R')
            ctar[19] += 1;
        if (ch == 'S')
            ctar[20] += 1;
        if (ch == 'T')
            ctar[21] += 1;
        if (ch == 'U')
            ctar[22] += 1;
        if (ch == 'V')
            ctar[23] += 1;
        if (ch == 'W')
            ctar[24] += 1;
        if (ch == 'X')
            ctar[25] += 1;
        if (ch == 'Y')
            ctar[26] += 1;
        if (ch == 'Z')
            ctar[27] += 1;
        if (ch == '\0')
            break;
    }

    /* Storing the date in the struct */
    file.wordCount = ctar[0]+1;
    file.lineCount = ctar[1];
    file.letterFrequency[0] = ctar[2];
    file.letterFrequency[1] = ctar[3];
    file.letterFrequency[2] = ctar[4];
    file.letterFrequency[3] = ctar[5];
    file.letterFrequency[4] = ctar[6];
    file.letterFrequency[5] = ctar[7];
    file.letterFrequency[6] = ctar[8];
    file.letterFrequency[7] = ctar[9];
    file.letterFrequency[8] = ctar[10];
    file.letterFrequency[9] = ctar[11];
    file.letterFrequency[10] = ctar[12];
    file.letterFrequency[11] = ctar[13];
    file.letterFrequency[12] = ctar[14];
    file.letterFrequency[13] = ctar[15];
    file.letterFrequency[14] = ctar[16];
    file.letterFrequency[15] = ctar[17];
    file.letterFrequency[16] = ctar[18];
    file.letterFrequency[17] = ctar[19];
    file.letterFrequency[18] = ctar[20];
    file.letterFrequency[19] = ctar[21];
    file.letterFrequency[20] = ctar[22];
    file.letterFrequency[21] = ctar[23];
    file.letterFrequency[22] = ctar[24];
    file.letterFrequency[23] = ctar[25];
    file.letterFrequency[24] = ctar[26];
    file.letterFrequency[25] = ctar[27];
 
    

    /* Print data from the struct to file */
    printToFile(file);
    
    data.close();

    /* Showing the letter frequency */
    char a;
    cout << "Would you like to see letter frequency of the provided file? (y/n): " << endl;
    cin >> a;
    cout << file.title << " letter frequency: " << endl;
    if ((a == 'y') || (a == 'Y')) {
        for (size_t i =0; i < 26; i++) {
        size_t f= i + 65;
        cout << (char)f << " : " << (file.letterFrequency[i]/tot)*100 << "%" << endl;
        }
    }
    
    /* Looping until user is done with the program */
    cout << "Would you like to parse another file? (y/n): " << endl;
    cin >> a;
    if ((a == 'y') || (a == 'Y'))
        goto file_reenter;

    return 0;
}
