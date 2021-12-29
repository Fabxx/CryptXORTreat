#include <iostream>
using namespace std;
#include <string>
#include <xorenc.h>
#include <filemaker.h>

int main() {
	
	while (filemaker::iscreated == false){
		filemaker::checkfile();
		if (filemaker::iscreated == false){
			filemaker::makefile();
			xorenc::textinput();
			xorenc::encrypt_decrypt();
			filemaker::writefile();
			filemaker::readfile();
		} else {
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
