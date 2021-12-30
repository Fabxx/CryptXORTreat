#ifndef BB46913E_372A_4B20_BD2C_4C693F5BE920
#define BB46913E_372A_4B20_BD2C_4C693F5BE920
#include <iostream>
using namespace std;
#include <fstream>

class filemaker {
           
    public:
            static fstream textfile;
            static fstream keyfile;
            static bool iscreated;
            static string filename;
            static string keyFileName;
           
            static void checkfile();
            static void makefile();
            static void makeKeyFile();
            static void writefile();
            static void readfile();
            static void savekey();
            static void readkey();
};

#endif /* BB46913E_372A_4B20_BD2C_4C693F5BE920 */
