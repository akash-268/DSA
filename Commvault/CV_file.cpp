#include <bits/stdc++.h>
using namespace std;

class cvFile
{

    string fileName;

public:
    string getFileName()
    {
        return fileName;
    }

    cvFile(string path, string content)
    {
        cout << "constructor called" << endl;

        ofstream f;
        f.open((string)path);
        f << content;
        fileName = path;
        f.close();
    }

    void modify(string content)
    {
        ofstream f;
        f.open(fileName);
        f << content;
        f.close();
    }

    int read(int rev,string content){
        string str=fileName+"_"+to_string(rev);
        ifstream(str);
        // if()
    }
};

int main()
{
    cvFile *f1 = new cvFile("D:/File1.txt", "Welcome to Commvault 1!");
    cvFile *f2 = new cvFile("D:/File2.txt", "Welcome to Commvault 2!");
    cvFile *f2_1 = new cvFile("D:/File2_1.txt", "Welcome to Commvault 2!");
    cvFile *f3 = new cvFile("D:/File3.txt", "Welcome to Commvault 3!");
    cvFile *f4 = new cvFile("D:/File4.txt", "Welcome to Commvault 4!");
    cvFile *f5 = new cvFile("D:/File5.txt", "Welcome to Commvault 5!");
    // cout << f1->getFileName() << endl;
    return 0;
}