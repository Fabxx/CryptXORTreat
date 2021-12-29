#include <fstream>
#include <filemaker.h>
#include <xorenc.h>
bool filemaker::iscreated;
fstream filemaker::textfile;
string filemaker::filename;

//Checking if the open operation wasn't successfull, or else we create the file.
void filemaker::checkfile() {
        iscreated = false;
        cout << "Insert the name of the file to open. Type 'q' to quit" << endl;
        getline(cin, filename);
        if (filename == "q"){
            cout << "Exiting program..." << endl;
            exit(0);
        } else {
            textfile.open(filename);
            if (!textfile.fail()) {
                cout << "File already created, aborting makefile." << endl;
                iscreated = true;
            } else {
                 cout << "File not found, making one..." << endl;
            }
        }
       textfile.close();
}

void filemaker::makefile() {
    textfile.open(filename, ios::out);
    textfile.close();
    textfile.open(filename, ios::in | ios::out);
    textfile.close();
}

void filemaker::writefile() {
    textfile.open(filename);
    textfile << xorenc::string1 << endl;
    textfile.close();
}

void filemaker::readfile() {
    textfile.open(filename);
    getline(textfile, xorenc::string1); 
    textfile.close();
}
