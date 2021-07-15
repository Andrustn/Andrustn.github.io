#include<iostream>
#include<string>
#include "Playlist.h"

Playlist::Playlist() {
	playlistName = "No Name";
}
Playlist::Playlist(string userPlaylistName) {
	playlistName = userPlaylistName;
}
string Playlist::GetPlaylistName() {
	return playlistName;
}
void Playlist::AddSong(Song* userSong) {
	songList.push_back(userSong);
}
void Playlist::PlaySongs() {
	for (unsigned int i = 0; i < songList.size(); i++) {
		songList.at(i)->IncrementTimesPlayed();
		cout << songList.at(i)->GetSongFirstLine() << endl;
	}
}
void Playlist::RemoveSong(int removeIndex) {
	songList.erase(songList.begin() + removeIndex);
}
void Playlist::PrintSongs() {
	for (unsigned int i = 0; i < songList.size(); i++) {
		cout << i << ": " << songList.at(i)->GetSongName() << endl;
	}
}
int Playlist::GetPlaylistLength() {
	return songList.size();
}
void Playlist::RemoveSongFromPlaylist(string songName) {
	for (unsigned int i = 0; i < songList.size(); i++) {
		if (songList.at(i)->GetSongName() == songName) {
			songList.erase(songList.begin() + i);
		}
		else {
		}
	}
}