#include <xorenc.h>
#include <filemaker.h>
string xorenc::key;
string xorenc::string1;
random_device xorenc::nameofseed;

void xorenc::textinput() {
    cout << "Insert string to write on file" << endl;
    getline(cin, string1);
}

/*generating integers that will be treated as string characters, will be used to XOR the input 
string. the key must be the same lenght as the file content.Using a range that generates characters 
allowed by windows in ASCII.*/
void xorenc::keyrandomizer() {
       mt19937 mt(nameofseed());
       uniform_int_distribution<int> dist(65, 125);
       
       for (size_t i = 0; i < string1.size(); i++){
           //on string type the static cast to char is automatic with numbers. 
               key.push_back((dist(mt)));
        }  
}

void xorenc::encrypt_decrypt() {
    for (size_t i = 0; i < string1.size(); i++){
        string1[i] ^= key[i];
    }
} 

