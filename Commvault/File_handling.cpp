#include <fstream>
#include <iostream>
// #include <conio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
#include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
using namespace std;

int main()
{
    string data;
    // open a file in write mode.
    ofstream outfile;
    // int x = mkdir("D:/personal");
    outfile.open("D:/afile.txt");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    getline(cin, data);
    // write inputted data into the file.
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // again write inputted data into the file.
    outfile << data << endl;

    // close the opened file.
    outfile.close();

    // open a file in read mode.
    ifstream infile;
    ofstream cpyfile;
    infile.open("D:/afile.txt");
    cpyfile.open("D:/newwww/bfile.txt");
    cout << "Reading from the file" << endl;
    while (getline(infile, data))
    {
        cpyfile << data << "\n";
    }

    // write the data at the screen.
    // cout << data << endl;

    // again read the data from the file and display it.
    // infile >> data;
    // cout << data << endl;

    // close the opened file.
    infile.close();
    cpyfile.close();
    /*
        Creating Directories and moving files ->

        int check = mkdir("D:/newwww");
        rename("D:/afile.txt", "D:/newwww/bfile.txt");

        int check1 = mkdir("D:/newwww/temp");
        rename("D:/newwww/bfile.txt", "D:/newwww/temp/cfile.txt");
    */

    /*
    Deleting a File ->

    remove("D:/newwww/temp/cfile.txt");
    remove("D:/afile.txt");
    */

    return 0;
}