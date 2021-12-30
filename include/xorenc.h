#ifndef AE932723_F2BB_4DBF_B771_5EE2837E1B5D
#define AE932723_F2BB_4DBF_B771_5EE2837E1B5D
#include <iostream>
using namespace std;
#include <string>
#include <random>

class xorenc {

	public:
            static string string1;
			static string key;
			static random_device nameofseed;
			   
            static void textinput();
			static void encrypt_decrypt();
			static void readkey();
			static void keyrandomizer();
};


#endif /* AE932723_F2BB_4DBF_B771_5EE2837E1B5D */
