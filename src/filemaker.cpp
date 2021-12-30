#include <fstream>
#include <filemaker.h>
#include <xorenc.h>
bool filemaker::iscreated;
fstream filemaker::textfile;
fstream filemaker::keyfile;
string filemaker::filename;
string filemaker::keyFileName;

//Checking if the open operation wasn't successfull, or else we create the file.
void filemaker::checkfile() {
    iscreated = false;

     while(filename.size() == 0) {
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
     }
        
       textfile.close();
}

//making input text file
void filemaker::makefile() {
    textfile.open(filename, ios::out);
    textfile.close();
    textfile.open(filename, ios::in | ios::out);
    textfile.close();
}

//making file to store encryption key.
void filemaker::makeKeyFile() {
    //clearing file name from previous usage. This avoid to overwrite the previous key file.
    keyFileName.clear();

    while(keyFileName.size() == 0) {
          cout << "Insert file name for key." << endl
               << "You will be promped here again if the same name for the first file it's used" << endl;
                getline(cin, keyFileName);
        
                    if(keyFileName == filename) {
                         keyFileName.clear();
        }
    }

    keyfile.open(keyFileName, ios::out);
    keyfile.close();
    keyfile.open(keyFileName, ios::in | ios::out);
    keyfile.close();
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

//creating a new file to store the encryption key. will have same name as initial file with key on it's name.
void filemaker::savekey() {
    keyfile.open(keyFileName);
    keyfile << xorenc::key << endl;
    cout << "Encryption key saved" << endl;
    keyfile.close();
}


void filemaker::readkey() {
    cout << "Insert key file name" << endl;

    getline(cin, keyFileName);
    keyfile.open(keyFileName);

    if (keyfile.fail()){
        cout << "No key file was found, unable to proceed" << endl;
        system("pause");
        exit(0);
   
    } else {
        cout << "READING KEY FOR FILE..." << endl;
          getline(keyfile, xorenc::key);
          keyfile.close();
    }
}
