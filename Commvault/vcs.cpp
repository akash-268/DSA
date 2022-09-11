#include<bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>
#include <unistd.h>
#include <filesystem>
#include <cstdio>

namespace fs = std::filesystem;

#define VERSION_FILE "version_no.txt"
#define INDEX_FILE "index.txt"
#define BUFF_SIZE 256
using namespace std;


class VCS {
private:
    map<string, string> filemap;
    vector<string> filelist;
    vector<string> untracked;
    vector<string> modified;
    vector<string> deleted;

    string get_sha(string& filename) {
        string f1 = "sha1sum " + filename + " > temp.txt";
        system(f1.c_str());
        ifstream sha_file("temp.txt", ios::in);
        string result_sha;
        getline(sha_file, result_sha);
        fclose();
        if (remove("temp.txt")) {
            cout << "Error deleting temp file!!\n";
        }
        stringstream ss;
        ss << result_sha;
        ss >> result_sha;
        return result_sha;
    }

    vector<string> get_files_from(string& path) {
        vector<string> file_vector;
        fs::path p(path);
        for (auto const& dir_entry: fs::directory_iterator){path} {
            string s = dir_entry.string();
            if (s == "." or s == ".." or s == ".vcs" or 
                s == "a.out" or s == ".vscode") continue;

            if (dir_entry.is_regular_file()) {
                file_vector.push_back(dir_entry.filename().string());
            }
        }
        return file_vector;
    }


    map<string, string> get_map_from(string path) {
        map<string, string> result_mp;
        fstream f(path, std::ios_base::in);
        if (f.is_open())
        {
            string line;
            while (getline(f, line)) //reading line by line of file
            {
                stringstream ss(line); //tokenising using space filename sha
                string filename = "";
                string sha = "";
                ss >> filename;
                ss >> sha;
                result_mp[filename] = sha;
            }
        }
        else {
            perror("unable to open file inf get_map_from function");
            exit(1);
        }
        return result_mp;
    }

public:
    // initialize the directory for VCS functionalities
    VCS() {
        char buffer[BUFF_SIZE];
        getcwd(buffer, sizeof(buffer));
        string curr_path(buffer);

        if (mkdir(".vcs") == -1) {
            cerr << "Error making vcs directory\n";
            exit(EXIT_FAILURE);
        }
        else {
            cout << "Initialized empty VCS repository in " << curr_path << "/.vcs\n";
        }

        if (chdir(".vcs") == -1) {
            cout << "Error changing directory to .vcs\n";
            exit(EXIT_FAILURE);
        }

        if (mkdir("global") == -1) {
            cout << "Error making directory ./global\n";
            exit(EXIT_FAILURE);
        }

        if (chdir("global") == -1) {
            cout << "error changing directory to global\n";
            exit(EXIT_FAILURE);
        }
    }



    void init() {
        char buffer[BUFF_SIZE];
        getcwd(buffer, sizeof(buffer));
        string curr_path(buffer);

        if (chdir(".vcs/global") == -1) {
            cerr << "Error changing directory.\nCheck if you are in vcs' initialized directory\n";
        }
        getcwd(buffer, sizeof(buffer));
        string global_path(buffer);

        vector<string> files = get_files_from(curr_path);

        for (int i = 0; i < files.size(); i++) {
            string filename = files[i];
            
            string input_path = curr_path + "/" + filename;

            string outpath = global_path + "/" + filename;

            ifstream fin; ofstream fout;

            fin.open(input_path, ios::in);
            fout.open(outpath, ios::out);
            string line;

            while ( getline(fin, line) ) {
                fout << line << endl;
            }
            fin.close();
            fout.close();
        }
        string path = curr_path + "/.vcs";
        if ( chdir(path.c_str()) == -1 ) {
            cerr << "Error in changing directory to .vcs\n Maybe it got deleted!!!\n";
            exit(EXIT_FAILURE);
        }

        // changing the version number in curr_directory
        ofstream fout;
        fout.open("version_no.txt", ios::out);
        if (fout) {
            string num = "0";
            fout << num << endl;
        }
        fout.close();

        ofstream flog;
        flog.open("vcs_log.txt", ios::out);
        flog.close();

        if ( mkdir("0") == -1 )  {
            cerr << "Error in making the 0th version\n";
            exit(EXIT_FAILURE);
        }

        if ( chdir("0") == -1 ) {
            cerr << "Error in making the directory for current version\n";
            exit(EXIT_FAILURE);
        }

        ofstream fout2;
        fout.open("index.txt");
        fout.close();
    }



    void status() {
        char cwd[256];
        string path = "";
        if ( getcwd(cwd, sizeof(cwd)) != nullptr) {
            path = cwd;
            path += "/.vcs";
        } else {
            perror("Unable to get current Working directory\n");
            exit(EXIT_FAILURE);
        }

        string vc_path = path + VERSION_FILE;
        fstream vcfile(vc_path, std::ios_base::in);
        string vc;
        vcfile >> vc;

        vcfile.close();

        string indexpath = path + vc + "/" + INDEX_FILE;
        filelist = get_files_from(cwd);
        int num_of_files = filelist.size();

        filemap = get_map_from(indexpath);

        for (int i = 0; i < num_of_files; i++) {
            string shaf = get_sha(filelist[i]);
            if (filemap.find(filelist[i]) == filemap.end()) {
                untracked.push_back(filelist[i]);
            } else {
                if (filemap[filelist[i]] != shaf) {
                    modified.push_back(filelist[i]);
                }
            }
        }
        sort (filelist.begin(), filelist.end());
        for (auto f : filemap) {
            if (find(filelist.begin(), filelist.end(), f.first) == filelist.end()) {
                deleted.push_back(f.first);
            }
        }
        cout << "Modified files " << modified.size() << endl;
        cout << "Untracked files " << untracked.size() << endl;
        cout << "Deleted files " << deleted.size() << endl;

    }

    void add() {

    }

    void log() {

    }

    void commit() {

    }

    void retrieve() {

    }

    void rollback() {

    }

    void diff() {

    }

    void push() {

    }

    void pull() {

    }

    void merge() {

    }
};

int main() {
    VCS* myvcs = new VCS();

    return 0;
}
