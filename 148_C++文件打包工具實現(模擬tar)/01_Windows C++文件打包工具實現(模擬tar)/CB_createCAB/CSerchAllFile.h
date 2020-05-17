#ifndef CSERCHALLFILE_H
#define CSERCHALLFILE_H

#include <string>

#include <vector>

#include <fstream>

#include <windows.h>

#include <iostream>

#include <conio.h>




using namespace std;


class CSerchAllFile
{
public:

    CSerchAllFile(void);

    ~CSerchAllFile(void);

    static CSerchAllFile *getInstance();

public:

    /*void find(char *lpPath);

    void _find(string path);*/




    void get_filelist(char *foldname,vector<string> &filelist);

    void ReadFile(const char* fileName);

    void WriteFile(string fileName);
};

#endif // CSERCHALLFILE_H
