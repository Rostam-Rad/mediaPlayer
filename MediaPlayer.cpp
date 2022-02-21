/*****************************************
** File:    MediaPlayer.cpp
** Project: CMSC 202 project 5, Fall 2020
** Author:  Rostam Boroumand Rad
** Date:    12/7/20
** Section: 20/23
** E-mail:  r66@umbc.edu
** Description: This program holds the function defintions for MediaPlayer.h for project5
**
***********************************************/



#include "MediaPlayer.h"
#include "Tqueue.cpp"

//Name: MediaPlayer - Default Constructor
//Precondition: None
//Postcondition: Creates a new MediaPlayer
MediaPlayer::MediaPlayer(){
    LoadCatalog("proj5_media.txt");
}
//Name: MediaPlayer - Overloaded Constructor
//Precondition: None
//Postcondition: Creates a new MediaPlayer and passes the media filename
MediaPlayer::MediaPlayer(string filename){
    LoadCatalog(filename);
}
//Name: ~MediaPlayer - Destructor
//Precondition: None
//Postcondition: Creates a new MediaPlayer
MediaPlayer::~MediaPlayer(){
  for (Media *i : m_mediaCatalog){
    delete i;
  }
}
//Name: LoadCatalog(string filename)
//Precondition: Requires filename
//Postcondition: Loads the file into the m_mediaCatalog (as media)
void MediaPlayer::LoadCatalog(string filename){
    ifstream mediaFile;
    string title, artist, type, temp;
    int year = 0, rank = 0;
    mediaFile.open(filename);
    if (mediaFile.is_open()){
        while(getline(mediaFile, title, ';') && (title != "\n")){
            getline(mediaFile, artist, ';');
            getline(mediaFile, type, ';');
            getline(mediaFile, temp, ';');
            year = stoi(temp);
            getline(mediaFile, temp);
            rank = stoi(temp);
            m_mediaCatalog.push_back(new Media(title, artist, type, year, rank));
        }
    }else{
        cout << "Cannot open file." << endl;
    }


}
//Name: MainMenu
//Precondition: None
//Postcondition: Manages the application and the menu
void MediaPlayer::MainMenu() {
    int choice = 0;
    cout << "Welcome to UMBC Media Player" << endl;
    cout << m_mediaCatalog.size() << " media files loaded." << endl;
    while (choice != 5) {
        cout << "What would you like to do?" << endl;
        cout << "1. Display Media by Type and Year" << endl;
        cout << "2. Add Media to Playlist" << endl;
        cout << "3. Display Playlist" << endl;
        cout << "4. Sort Playlist by Year" << endl;
        cout << "5. Quit" << endl;
	cout << ">";
        cin >> choice;
	//menu
        switch (choice) {
            case 1:
                DisplayMedia();
                break;
            case 2:
                AddMedia();
                break;
            case 3:
                DisplayPlaylist();
                break;
            case 4:
                SortPlaylist();
                break;
            case 5:
                cout << "Thank you for using the UMBC Media Player" << endl;
                break;
        }
    }
}
//Name: DisplayMedia
//Precondition: User enters year (1958-2020)
//              (shows all years even if no media of that type exists for a particular year)
//Postcondition: Lists all media (numbered) for that year and returns int
//               of number found with that criteria

int MediaPlayer::DisplayMedia(){
    int year = 0;
    string type = "";
    cout << "Which media type do you want to display? " << endl;
    cout << "music" << endl;
    cout << "podcast" << endl;
    cout << ">";
    cin >> type;
    //input validation
    while (type != "podcast" &&  type != "music"){
        cout << "Please pick music or podcast" << endl;
	cout << "> ";
        cin >> type;
    }
    cout << "Which year would you like to display? (" << MIN_YEAR << "-" << MAX_YEAR << ")" << endl;
    cout << "> ";
    cin >> year;
    //makes sure correct year is entered
    while (year < MIN_YEAR || year > MAX_YEAR){
        cout << "Please enter a year in the correct range" << endl;
	cout << "> ";
        cin >> year;
    }
    int count = 0;
    cout << "******" << year << "*****" << endl;
    //loops through vecto to find users criteria
    for (unsigned int i = 0; i < m_mediaCatalog.size(); i++){
        Media med  = *m_mediaCatalog[i];
        if ((med.GetType() == type) && (med.GetYear() == year)){
            cout << i << ". " << med.GetTitle() << " by " << med.GetArtist() << endl;
            count ++;
        }
    }
    if (count == 0){
        cout << "No media found with your criteria" << endl;
    }else{
        cout << count << " media found." << endl;
    }
    return count;
}
//Name: AddMedia
//Precondition: m_mediaCatalog is populated
//Postcondition: Displays the current list and adds media
//               to the m_playList
void MediaPlayer::AddMedia() {
  cout << "Current Playlist: " << endl;
  DisplayPlaylist();
  cout << "Choose the media you would like to add to the playlist." << endl;
  //if at least 1  songs/podcasts are found
  if (DisplayMedia() != 0) {
    int choice = 0;
    cout << "Enter the number of the media you would like to add: " << endl;
    cout << "> ";
    cin >> choice;
    //adds to playlist
    m_playList.Enqueue(m_mediaCatalog[choice]);
  }
}
//Name: DisplayPlaylist
//Precondition: None (will indicate if list is empty)
//Postcondition: Displays the playlist
void MediaPlayer::DisplayPlaylist(){
    if (m_playList.Size() == 0) {
        cout << "The playlist is currently empty" << endl;
    }else{
        for (int i = 0; i < m_playList.Size() ; i++){
	  //displays list
            cout << i + 1 << ". " << m_playList.At(i)->GetTitle() << " by " << m_playList.At(i)->GetArtist() << " from " << m_playList.At(i)->GetYear() << endl;
        }
    }
}
//Name: SortPlaylist
//Precondition: None (will indicate if list is empty)
//Postcondition: Sorts the playlist by year
void MediaPlayer::SortPlaylist(){
    if (m_playList.Size() == 0) {
        cout << "Playlist is empty." << endl;
    }else{
        m_playList.Sort();
        cout << "Done sorting by year " << endl;
        cout << m_playList.Size() << " items sorted." << endl;
    }
}
