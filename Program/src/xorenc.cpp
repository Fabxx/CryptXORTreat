#include <xorenc.h>
#include <filemaker.h>
string xorenc::key;
string xorenc::string1;

void xorenc::textinput() {
    cout << "Insert string to write on file" << endl;
    getline(cin, string1);
}

void xorenc::encrypt_decrypt() {
    cout << "Insert key for encryption-decryption. If the key is wrong, this will fail." << endl;
    getline(cin, key);
    for (size_t i = 0; i < string1.size(); i++){
        string1[i] = string1[i] ^ key[i]; 
    }
}
