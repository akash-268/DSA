#include <fstream>
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    // string data;
    // // open a file in write mode.
    // ofstream outfile;
    // // int x = mkdir("D:/personal");
    // outfile.open("afile.txt");

    // cout << "Writing to the file" << endl;
    // cout << "Enter your name: ";
    // getline(cin, data);
    // // write inputted data into the file.
    // outfile << data << endl;

    // cout << "Enter your age: ";
    // cin >> data;
    // cin.ignore();

    // // again write inputted data into the file.
    // outfile << data << endl;

    // // close the opened file.
    // outfile.close();

    // open a file in read mode.
    // write the data at the screen.
    ifstream infile;
    infile.open("abcdefgh.txt");
    int flag = 0;
    if (!infile)
    {
        flag = 1;   
        cout << "No such file found" << endl;
    }
    string line;
    while (infile && !flag)
    {
        getline(infile, line);
        cout << line;
    }
    infile.close();
    return 0;
}