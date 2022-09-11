#include <bits/stdc++.h>
using namespace std;
map<string, vector<int>> mp;
class cvFile
{
    string fileName;
public:
    string getFullFileName()
    {
        return fileName;
    }
    string getFileName()
    {
        int end;
        int x = fileName.find_last_of("/");
        int y = fileName.find("_");
        if (y == -1)
            end = fileName.find(".");
        else
            end = y;
        cout << "strt=" << x << " "
             << "end=" << end << endl;
        return fileName.substr(x + 1, end - x - 1);
    }
    cvFile(string path, string content)
    {
        // cout << "constructor called" << endl;
        ofstream f;
        f.open((string)path);
        f << content;
        fileName = path;
        f.close();
        int x = path.find_last_of("/");
        int y = path.find_last_of("_");
        string temp1 = "", temp2 = "";
        int end;
        if (y == -1)
            end = path.find_last_of(".");
        else
            end = y;
        for (int i = x + 1; i < end; i++)
            temp1.push_back(path[i]);
        if (y != -1)
            for (int i = y + 1; path[i] != '.'; i++)
                temp2.push_back(path[i]);
        else
            temp2 = "0";
        mp[temp1].push_back(stoi(temp2));
    }

    void modify(string content)
    {
        ofstream f;
        f.open(fileName);
        f << content;
        f.close();
    }

    int read(int rev, string content)
    {
        string name = this->getFileName();
        cout << name << endl;
        string str = "";
        if (rev != 0)
            str = name + "_" + to_string(rev);
        else
            str = fileName;
        cout << str << endl;
        ifstream fin;
        fin.open(str);
        string line = "";
        if (!fin)
        {
            cout << "No such file found\n";
            return 0;
        }
        while (getline(fin, line))
        {
            cout << line << endl;
        }
    }
};

int main()
{
    cvFile *f1 = new cvFile("D:/File1.txt", "Welcome to Commvault 1!");
    cvFile *f2 = new cvFile("D:/File2.txt", "Welcome to Commvault 2!");
    cvFile *f2_1 = new cvFile("D:/File2_1.txt", "Welcome to Commvault 2!");
    cvFile *f3 = new cvFile("D:/File3.txt", "Welcome to Commvault 3!");
    cvFile *f3_1 = new cvFile("D:/File3_1.txt", "Welcome to Commvault 4!");
    cvFile *f3_2 = new cvFile("D:/File3_2.txt", "Welcome to Commvault 5!");
    for (auto &it : mp)
    {
        cout << it.first << ":";
        for (auto &i : it.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    // cout << f1->getFileName() << endl;
    f1->read(0, "abcd");
    return 0;
}