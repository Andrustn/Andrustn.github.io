#include<iostream>
#include<string>
#include "Song.h"

void Song::SetSongName(string userSongName) {
	songName = userSongName;
}
void Song::SetSongFirstLine(string userSongFirstLine) {
	songFirstLine = userSongFirstLine;
}
void Song::SetTimesPlayed(int userTimesPlayed) {
	timesPlayed = userTimesPlayed;
}
Song::Song() {
	songName = "No Name";
	songFirstLine = "No first line";
	timesPlayed = 0;
}
Song::Song(string userSongName, string userSongFirstLine) {
	songName = userSongName;
	songFirstLine = userSongFirstLine;
}
string Song::GetSongName() {
	return songName;
}
string Song::GetSongFirstLine() {
	return songFirstLine;
}
int Song::GetTimesPlayed() {
	return timesPlayed;
}
void Song::IncrementTimesPlayed() {
	timesPlayed = timesPlayed + 1;
}
