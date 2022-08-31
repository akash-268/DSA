#include <bits/stdc++.h>
using namespace std;
// JAI SHREE RAM
// HAR HAR MAHADEV
class Song
{
private:
    int id;
    string name;
    string artist;

public:
    Song(int id, string n, string a)
    {
        this->id = id;
        name = n;
        artist = a;
    }
    int getSongId()
    {
        return id;
    }

    string getSongName()
    {
        return name;
    }
    string getSongArtist()
    {
        return artist;
    }
};
class Playlist
{
private:
    string name;
    vector<Song *> songs;

public:
    Playlist(string n)
    {
        name = n;
        songs.clear();
    }
    void addSong(Song *s)
    {
        songs.push_back(s);
        cout << endl
             << "SONG ADDED" << endl;
    }
    void deleteSong(Song *s)
    {
        vector<Song *>::iterator it = find(songs.begin(), songs.end(), s);
        if (it != songs.end())
            songs.erase(it);
    }
    Song *getSong(int x)
    {
        for (int i = 0; i < songs.size(); i++)
        {
            if (songs[i]->getSongId() == x)
            {
                return songs[i];
            }
        }
        return NULL;
    }
};

int main()
{
    cout << "\nENTER THE NUMBER OF SONGS YOU WANT:\n";
    int n;
    Playlist *pl = new Playlist("Fun Mood");
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "\nENTER DETAILS OF SONG " << i << endl;
        cout << "ENTER SONG NAME: ";
        string s, a;
        cin >> s;
        cout << "\nENTER ARTIST NAME: ";
        cin >> a;
        Song *obj = new Song(i, s, a);
        cout << endl
             << obj->getSongId() << ":"
             << obj->getSongName() << ":" << obj->getSongArtist() << endl;
        pl->addSong(obj);
    }
    // cout << pl->getSong(1)->getSongName() << endl;
    for (int i = 1; i <= n; i++)
    {
        Song *it = pl->getSong(i);
        if (it)
            cout << it->getSongName() << endl;
    }
    return 0;
}