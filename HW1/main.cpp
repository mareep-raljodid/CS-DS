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
    float tot = 0;

    /* ctar[4] is {spaces, lines, alphabets ...} */
    int ctar[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    /* Looping to get all characters and checking what they are
     * to calculate letter frequency and number of words and lines
     */
    while (data.get(ch)) {
        tot += 1;
        if (ch == ' ')
            ctar[0] += 1;
        if (ch == '.')
            ctar[4] += 1;
        ch = toupper(ch);
        if (ch == 'A')
            ctar[1] += 1;
        if (ch == 'B')
            ctar[2] += 1;
        if (ch == 'C')
            ctar[3] += 1;
        if (ch == 'D')
            ctar[5] += 1;
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
    }

    /* Storing the date in the struct */
    file.wordCount = ctar[0] + 1;
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
        cout << "a: " << (ctar[1] / tot) * 100 << "%" << endl;
        cout << "b: " << (ctar[2] / tot) * 100 << "%" << endl;
        cout << "c: " << (ctar[3] / tot) * 100 << "%" << endl;
        cout << "d: " << (ctar[4] / tot) * 100 << "%" << endl;
        cout << "e: " << (ctar[5] / tot) * 100 << "%" << endl;
        cout << "f: " << (ctar[6] / tot) * 100 << "%" << endl;
        cout << "g: " << (ctar[7] / tot) * 100 << "%" << endl;
        cout << "h: " << (ctar[8] / tot) * 100 << "%" << endl;
        cout << "i: " << (ctar[9] / tot) * 100 << "%" << endl;
        cout << "j: " << (ctar[10] / tot) * 100 << "%" << endl;
        cout << "k: " << (ctar[11] / tot) * 100 << "%" << endl;
        cout << "l: " << (ctar[12] / tot) * 100 << "%" << endl;
        cout << "m: " << (ctar[13] / tot) * 100 << "%" << endl;
        cout << "n: " << (ctar[14] / tot) * 100 << "%" << endl;
        cout << "o: " << (ctar[15] / tot) * 100 << "%" << endl;
        cout << "p: " << (ctar[16] / tot) * 100 << "%" << endl;
        cout << "q: " << (ctar[17] / tot) * 100 << "%" << endl;
        cout << "r: " << (ctar[18] / tot) * 100 << "%" << endl;
        cout << "s: " << (ctar[19] / tot) * 100 << "%" << endl;
        cout << "t: " << (ctar[20] / tot) * 100 << "%" << endl;
        cout << "u: " << (ctar[21] / tot) * 100 << "%" << endl;
        cout << "v: " << (ctar[22] / tot) * 100 << "%" << endl;
        cout << "w: " << (ctar[23] / tot) * 100 << "%" << endl;
        cout << "x: " << (ctar[24] / tot) * 100 << "%" << endl;
        cout << "y: " << (ctar[25] / tot) * 100 << "%" << endl;
        cout << "z: " << (ctar[26] / tot) * 100 << "%" << endl;
    }

    /* Looping until user is done with the program */
    cout << "Would you like to parse another file? (y/n): " << endl;
    cin >> a;
    if ((a == 'y') || (a == 'Y'))
        goto file_reenter;

    return 0;
}
