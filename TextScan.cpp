#include <iostream>
#include "TextScan.h"
#include <fstream>
#include <string>

using namespace std;

void TextScaner()
{
    fstream file;
    file.open("Text.txt");

    if (!file.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
        exit(0);
    }

    else
    {
        string line;
        cout << "Все строки в тексте не содержащие двузначные числа" << endl;
        while (!file.eof())
        {
            getline(file, line);

            unsigned short int flagFirst = 0;
            string number;

            for (int id = 0; id < line.size()+1; id++)
            {
                if (isdigit(line[id])) number += line[id];
                else
                {
                    if (number.size() == 2) {flagFirst = 1; break;}
                    else number = "";
                }
            }

            if(!flagFirst) cout << line << endl;
        }
    }

    file.close();
}
