#include <bits/stdc++.h>
using namespace std;
#include <memory>
class Music
{
    int id;
    string name, artist;

public:
    Music(int id, string name, string artist)
    {
        cout << "Created Music" << endl;
        this->id = id;
        this->artist = artist;
        this->name = name;
    }
    ~Music()
    {
        cout << "Deleted Music" << endl;
    }
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getArtist()
    {
        return artist;
    }
};
class Playlist
{
    int pid;
    string pname;
    vector<shared_ptr<Music>> musics;

public:
    Playlist(int pid, string pname)
    {
        cout << "Created Playlist" << endl;
        this->pid = pid;
        this->pname = pname;
    }
    void deleteMusic(int id)
    {
        int j = 0;
        for (auto &i : musics)
        {
            if (i->getId() == id)
                musics.erase(musics.begin() + j);
            j++;
        }
    }
    void displayPlaylist()
    {
        cout << getPlaylistName() << endl;
        cout << "---------------" << endl;
        for (auto &i : musics)
            cout
                << "ID: " << i->getId() << " Name: " << i->getName() << " Artist: " << i->getArtist() << endl;
        cout << "---------------";
    }
    void addMusic(shared_ptr<Music> &music)
    {
        musics.push_back(move(music));
    }
    void renamePlaylist(string name)
    {
        pname = name;
    }
    string getPlaylistName()
    {
        return pname;
    }
    ~Playlist()
    {
        cout << "DELETED Playlist" << endl;
    }
    void fun(User *obj)
    {
        cout << obj->getName() << endl;
    }
};
class User
{
    string username;
    vector<shared_ptr<Playlist>> playlists;
    int id;

public:
    User(int id, string name)
    {
        cout << "Created User" << endl;
        this->id = id;
        this->username = name;
    }
    string getName()
    {
        return username;
    }
    ~User()
    {
        cout << "Deleted User" << endl;
    }
};
int main()
{
    shared_ptr<User *> user2 = make_shared<User *>(1, "Akash");
    // {
    //     shared_ptr<User> user1 = make_shared<User>(1, "Akash");
    //     user2 = user1;
    // }
    // cout << user2->getName() << endl;

    shared_ptr<Playlist>
        playlist1 = make_shared<Playlist>(1, "Sad songs");
    playlist1->fun(*user2);
    // shared_ptr<Music> music1 = make_shared<Music>(1, "Ek lamha", "Azan Sami");
    // shared_ptr<Music> music2 = make_shared<Music>(2, "Humnava Mere", "Jubin");
    // shared_ptr<Music> music3 = make_shared<Music>(3, "Your fault", "Excision");
    // shared_ptr<Music> music4 = make_shared<Music>(4, "There for you", "Martin Garrix");
    // shared_ptr<Music> music5 = make_shared<Music>(5, "Humnava Mere", "Jubin");
    // playlist1->addMusic(music1);
    // playlist1->addMusic(music2);
    // shared_ptr<Playlist> playlist2 = make_shared<Playlist>(2, "Vibe songs");
    // playlist2->addMusic(music3);
    // playlist2->addMusic(music4);
    // playlist2->addMusic(music5);
    // playlist1->displayPlaylist();
    // playlist2->displayPlaylist();
}