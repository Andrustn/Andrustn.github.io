#ifndef SONG_H
#define SONG_H
#include<string>
#include<vector>
using namespace std;


class Song {

private:
	string songName;
	string songFirstLine;
	int timesPlayed;
public:
	Song();
	Song(string userSongName, string userSongFirstline);
	void SetSongName(string userSongName);
	void SetSongFirstLine(string userSongFirstLine);
	void SetTimesPlayed(int userTimesPlayed);
	string GetSongName();
	string GetSongFirstLine();
	int GetTimesPlayed();
	void IncrementTimesPlayed();
};

#endif