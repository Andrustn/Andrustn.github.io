#include<iostream>
#include<string>
#include "Song.h"
#include "Playlist.h"
using namespace std;

void PrintOptions();

const string QUIT_STRING = "quit";
const string ADD_STRING = "add";
const string LIST_STRING = "list";
const string ADDP_STRING = "addp";
const string ADDSP_STRING = "addsp";
const string LISTP_STRING = "listp";
const string PLAY_STRING = "play";
const string REMP_STRING = "remp";
const string REMSP_STRING = "remsp";
const string REMSL_STRING = "remsl";
const string OPTIONS_STRING = "options";
const string STOP_STRING = "STOP";

int main() {

	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl;
	cout << "Enter your selection now: " << endl;
	string userOption;
	cin >> userOption;

	vector<Song*> songLibrary;
	vector<Playlist> listOfPlaylists;

	while (userOption != QUIT_STRING) {

		if (userOption == ADD_STRING) {
			string userSongName;
			string userSongFirstLine;
			string userInput;
			cout << "Read in Song names and first lines (type \"STOP\" when done): " << endl;
			cin.ignore();

			while (userInput != STOP_STRING) {
				
				cout << "Song Name: " << endl;
				getline(cin, userInput);
				if (userInput == STOP_STRING) {
					break;
				}
				userSongName = userInput;
				cout << "Song's first line: " << endl;
				getline(cin, userInput);
				if (userInput == STOP_STRING) {
					break;
				}
				userSongFirstLine = userInput;

				Song* newSongPtr = new Song;
				newSongPtr->SetSongName(userSongName);
				newSongPtr->SetSongFirstLine(userSongFirstLine);
				newSongPtr->SetTimesPlayed(0);

				songLibrary.push_back(newSongPtr);
			}
		}
		else if (userOption == LIST_STRING) {

			for (unsigned int i = 0; i < songLibrary.size(); i++) {
				cout << songLibrary.at(i)->GetSongName() << ": \"";
				cout << songLibrary.at(i)->GetSongFirstLine() << "\", ";
				cout << songLibrary.at(i)->GetTimesPlayed() << " play(s)." << endl;
			}
		}
		else if (userOption == ADDP_STRING) {
			string userPlaylistName;
			cout << "Playlist name: ";
			cin.ignore();
			getline(cin, userPlaylistName);
			Playlist newPlaylist(userPlaylistName);
			listOfPlaylists.push_back(newPlaylist);	
		}
		else if (userOption == ADDSP_STRING) {
			int userPlaylistChoice;
			int userSongChoice;
			
			for (unsigned int i = 0; i < listOfPlaylists.size(); i++) {
				cout << i <<": " << listOfPlaylists.at(i).GetPlaylistName() << endl;
			}
			cout << "Pick a playlist index number: " << endl;
			cin >> userPlaylistChoice;
			for (unsigned int i = 0; i < songLibrary.size(); i++) {
				cout << i << ": " << songLibrary.at(i)->GetSongName() << endl;
			}
			cout << "Pick a song index number : " << endl;
			cin >> userSongChoice;

			listOfPlaylists.at(userPlaylistChoice).AddSong(songLibrary.at(userSongChoice));

		}
		else if (userOption == LISTP_STRING) {
			for (unsigned int i = 0; i < listOfPlaylists.size(); i++) {
				cout << i << ": " << listOfPlaylists.at(i).GetPlaylistName() << endl;
			}
			
		}
		else if (userOption == PLAY_STRING) {
			int userPlaylistChoice;
			for (unsigned int i = 0; i < listOfPlaylists.size(); i++) {
				cout << i << ": " << listOfPlaylists.at(i).GetPlaylistName() << endl;
			}
			cout << "Pick a playlist index number: " << endl;
			cin >> userPlaylistChoice;

			cout << "Playing first lines of playlist : " << listOfPlaylists.at(userPlaylistChoice).GetPlaylistName() << endl;
			listOfPlaylists.at(userPlaylistChoice).PlaySongs();
		}
		else if (userOption == REMP_STRING) {
			int userPlaylistChoice;
			for (unsigned int i = 0; i < listOfPlaylists.size(); i++) {
				cout << i << ": " << listOfPlaylists.at(i).GetPlaylistName() << endl;
			}
			cout << "Pick a playlist index number to remove: " << endl;
			cin >> userPlaylistChoice;

			listOfPlaylists.erase(listOfPlaylists.begin() + userPlaylistChoice);
		}
		else if (userOption == REMSP_STRING) {
			int userPlaylistChoice;
			int userSongChoice;

			for (unsigned int i = 0; i < listOfPlaylists.size(); i++) {
				cout << i << ": " << listOfPlaylists.at(i).GetPlaylistName() << endl;
			}
			cout << "Pick a playlist index number: " << endl;
			cin >> userPlaylistChoice;
			listOfPlaylists.at(userPlaylistChoice).PrintSongs();
			cout << "Pick a song index number to remove : " << endl;
			cin >> userSongChoice;

			listOfPlaylists.at(userPlaylistChoice).RemoveSong(userSongChoice);
		}
		else if (userOption == REMSL_STRING) {
			int userSongChoice;
			for (unsigned int i = 0; i < songLibrary.size(); i++) {
				cout << i << ": " << songLibrary.at(i)->GetSongName() << endl;
			}
			cout << "Pick a song index number to remove : " << endl;
			cin >> userSongChoice;


			for (unsigned int i = 0; i < listOfPlaylists.size(); i++) {
				listOfPlaylists.at(i).RemoveSongFromPlaylist(songLibrary.at(userSongChoice)->GetSongName());	
			}
			delete songLibrary.at(userSongChoice); //freeing memory
			songLibrary.erase(songLibrary.begin() + userSongChoice);
		}
		else if (userOption == OPTIONS_STRING) {
			PrintOptions();
		}
		else {
			PrintOptions();
		}
		cout << endl;
		cout << "Enter your selection now :" << endl;
		cin >> userOption;
	}

	for (unsigned int i = 0; i < songLibrary.size(); i++) { // freeing memory
		delete songLibrary.at(i);
	}

	cout << "Goodbye!" << endl;
	//system("PAUSE");
	return 0;
}

void PrintOptions() {
	cout << "add      Adds a list of songs to the library" << endl;
	cout << "list     Lists all the songs in the library" << endl;
	cout << "addp     Adds a new playlist" << endl;
	cout << "addsp    Adds a song to a playlist" << endl;
	cout << "listp    Lists all the playlists" << endl;
	cout << "play     Plays a playlist" << endl;
	cout << "remp     Removes a playlist" << endl;
	cout << "remsp    Removes a song from a playlist" << endl;
	cout << "remsl    Removes a song from the library (and all playlists)" << endl;
	cout << "options  Prints this options menu" << endl;
	cout << "quit     Quits the program" << endl;
}