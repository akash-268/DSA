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
        this->id = id;
        this->artist = artist;
        this->name = name;
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
    vector<unique_ptr<Music>> musics;

public:
    Playlist(int pid, string pname)
    {
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
    void addMusic(unique_ptr<Music> &music)
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
};
class User
{
    string username;
    vector<unique_ptr<Playlist>> playlists;
    int id;

public:
    User(int id, string name)
    {
        this->id = id;
        this->username = name;
    }
};
int main()
{
    unique_ptr<User> user1 = make_unique<User>(1, "Talha");
    unique_ptr<Playlist> playlist1 = make_unique<Playlist>(1, "Sad songs");
    unique_ptr<Music> music1 = make_unique<Music>(1, "Ek lamha", "Azan Sami");
    unique_ptr<Music> music2 = make_unique<Music>(2, "Humnava Mere", "Jubin");
    unique_ptr<Music> music3 = make_unique<Music>(3, "Your fault", "Excision");
    unique_ptr<Music> music4 = make_unique<Music>(4, "There for you", "Martin Garrix");
    unique_ptr<Music> music5 = make_unique<Music>(5, "Humnava Mere", "Jubin");
    playlist1->addMusic(music1);
    playlist1->addMusic(music2);
    unique_ptr<Playlist> playlist2 = make_unique<Playlist>(2, "Vibe songs");
    playlist2->addMusic(music3);
    playlist2->addMusic(music4);
    playlist2->addMusic(music5);
    playlist1->displayPlaylist();
    playlist2->displayPlaylist();
}