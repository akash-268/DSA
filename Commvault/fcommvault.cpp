#include <bits/stdc++.h>
using namespace std;
class CVFile
{
private:
    string fileName; // poora directory path
    string content;

public:
    CVFile(string filePathName, string content);
    void CVModifyFile(string content);
    int CVReadFile(int revision, string content);
    int CVTrim();
    string getPathName()
    {
        return fileName;
    }
    string getFileName()
    {
        int x = fileName.find_last_of("\\");
        return fileName.substr(x + 1);
    }
};
class CV_SIOManager
{
public:
    CV_SIOManager() {}
    CVFile *CVGetFile(string StringfilePthName);
    void CVDisplayStats();
    int CVDeleteFile(string filePathName);
    int CVMoveFile(string sourcePathName, string targetPathName);
    int CVCopyFile(string sourcePathName, string targetPathName);
};
unordered_map<string, vector<string>> mp;
unordered_map<string, CVFile *> m;
CVFile::CVFile(string filePathName, string content)
{
    m[filePathName] = this;
    ofstream f;
    f.open((string)filePathName);
    f << content;
    fileName = filePathName;
    f.close();
}
void CVFile::CVModifyFile(string content)
{
    mp[this->getFileName()].push_back(this->content);
    ofstream f;
    f.open(fileName);
    f << content;
    f.close();
}
int CVFile::CVReadFile(int revision, string content)
{
    // print content
    int x = mp[fileName].size() - revision - 1;
    if (x < 0)
    {
        cout << "" << endl;
        return 0;
    }
    content = mp[fileName][x];
    cout << content << endl;
    return 0;
}
int CVFile::CVTrim()
{
    mp[fileName].clear();
}
CVFile *CV_SIOManager::CVGetFile(string StringfilePthName)
{
    return m[StringfilePthName];
}
void CV_SIOManager::CVDisplayStats()
{
    for (auto i : mp)
    {
        cout << "File Name: " << i.first << endl;
        cout << "Number of revisions: " << i.second.size() << endl;
    }
}
int CV_SIOManager::CVDeleteFile(string filePathName)
{
    remove(filePathName.c_str());
}
int CV_SIOManager::CVMoveFile(string sourcePathName, string targetPathName)
{
    rename(sourcePathName.c_str(), targetPathName.c_str());
}
int CV_SIOManager::CVCopyFile(string sourcePathName, string targetPathName)
{
    ifstream inputFile(sourcePathName);
    string str;
    ofstream outputFile(targetPathName);
    while (getline(inputFile, str))
    {
        outputFile << str;
    }
    inputFile.close();
    outputFile.close();
}
class SIOManagerDriver
{
public:
    int main()
    {
        CV_SIOManager *sm = new CV_SIOManager();
        string contentInFile = "";
        CVFile *fx;
        CVFile *f1 = new CVFile("C:\\File1.txt",
                                "Welcome to Commvault 1!");
        CVFile *f2 = new CVFile("C:\\File2.txt",
                                "All The Best 2!");
        CVFile *f2_1 = new CVFile("C:\\File2_1.txt",
                                  "All The Best 2!");
        CVFile *f9 = new CVFile("C:\\File9.txt", "This is File 9");
        sm->CVDisplayStats();
        CVFile *f4 = new CVFile("C:\\File4.txt", "Good Luck 4!");
        CVFile *f4_1 = new CVFile("C:\\File4_1.txt", "Good Luck 4!");
        sm->CVDisplayStats();
        CVFile *f10 = new CVFile("D:\\File10.txt", "Good Luck 10!");
        CVFile *f20 = new CVFile("D:\\File20.txt",
                                 "Welcome to Commvault 20!");
        CVFile *f50 = new CVFile("D:\\File50.txt",
                                 "Best Place to Work 50!");
        CVFile *f20_1 = new CVFile(
            "D:\\File20_1.txt", "Welcome to Commvault 20!");
        sm->CVDisplayStats();
        CVFile *f60 = new CVFile("D:\\File60.txt",
                                 "All THE Best 60!");
        CVFile *f70 = new CVFile("D:\\File70.txt",
                                 "All The Best 70!");
        CVFile *f70_1 = new CVFile("D:\\File70.txt", "Commvault 70!");
        sm->CVDisplayStats();

        fx = sm->CVGetFile("D:\\File60.txt");
        if (NULL != fx)
        {
            fx->CVReadFile(-5, contentInFile);
            // cout << (contentInFile) << endl;
        }
        f4->CVModifyFile("Welcome to Commvault 4!");
        fx = sm->CVGetFile("C:\\File4.txt");
        if (NULL != fx)
        {
            fx->CVReadFile(0, contentInFile);
            // cout << (contentInFile) << endl;
        }
        fx = sm->CVGetFile("C:\\File4.txt");
        if (NULL != fx)
        {
            fx->CVReadFile(-1, contentInFile);
            // cout << (contentInFile) << endl;
        }
        sm->CVDisplayStats();
        sm->CVMoveFile("C:\\File9.txt", "D:\\File30.txt");
        sm->CVMoveFile("C:\\File4.txt", "D:\\File2.txt");
        sm->CVDisplayStats();
        sm->CVCopyFile("C:\\File4.txt", "D:\\File21.txt");
        sm->CVCopyFile("C:\\File3.txt", "C:\\File40.txt");
        sm->CVDisplayStats();
        sm->CVDeleteFile("D:\\File20.txt");
        sm->CVDisplayStats();
        sm->CVDeleteFile("C:\\File1.txt");
        sm->CVDeleteFile("C:\\File4.txt");
        sm->CVDisplayStats();
        sm->CVDeleteFile("D:\\File7.txt");
        sm->CVDeleteFile("D:\\File70.txt");
        sm->CVDeleteFile("D:\\File30.txt");
        sm->CVDisplayStats();
    }
};