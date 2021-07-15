#ifndef PLAYLIST_H
#define PLAYLIST_H
#include<string>
#include<vector>
#include "Song.h"
using namespace std;

class Playlist {
private:
	string playlistName;
	vector<Song*> songList;

public:
	Playlist();
	Playlist(string userPlaylistName);
	string GetPlaylistName();
	void AddSong(Song* userSong);
	void RemoveSong(int removeIndex);
	void PlaySongs();
	void PrintSongs();
	int GetPlaylistLength();
	void RemoveSongFromPlaylist(string songName);
};

#endif
