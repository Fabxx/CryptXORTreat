#include <iostream>
using namespace std;
#include <string>
#include <xorenc.h>
#include <filemaker.h>

int main() {
	
	while (filemaker::iscreated == false){
		system("cls");
		filemaker::checkfile();
		if (filemaker::iscreated == false){
			filemaker::makefile();
			filemaker::makeKeyFile();
			xorenc::textinput();
			xorenc::keyrandomizer();
			filemaker::savekey();
			xorenc::encrypt_decrypt();
			filemaker::writefile();
		} else {
			filemaker::readkey();
			filemaker::readfile();
			xorenc::encrypt_decrypt();
			filemaker::writefile();
			//resetting flag to return at the initial prompt.
			filemaker::iscreated = false;
		}
	}
		system("pause");
		return 0;
}
