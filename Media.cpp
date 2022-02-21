
/*****************************************
** File:    Media.cpp
** Author:  Rostam Boroumand Rad
** Date:    12/7/20
** E-mail:  r66@umbc.edu
** Description: This program holds the function definitions for Media.h
**
***********************************************/


#include "Media.h"

Media::Media() {
    m_year = 0;
    m_rank = 0;
    m_title = "";
    m_artist = "";
    m_type = "music";
}

Media::Media(string title, string artist, string type, int year, int rank) {
    m_title = title;
    m_artist = artist;
    m_type = type;
    m_year = year;
    m_rank = rank;
}

string Media::GetTitle()const{
    return m_title;
} // return title

string Media::GetArtist()const{
    return m_artist;
} // return artist

string Media::GetType()const{
    return m_type;
} //return type

int Media::GetYear()const{
    return m_year;
} // return year

int Media::GetRank()const{
    return m_rank;
} // return rank (1-100 from that year)

void Media::SetTitle(string title){
    m_title = title;
}

void Media::SetArtist(string artist){
    m_artist = artist;
}

void Media::SetType(string type){
    m_type = type;
}

void Media::SetYear(int year){
    m_year = year;
}

void Media::SetRank(int rank){
    m_rank = rank;
}

ostream& operator<<(ostream& out, Media& m) {
    out << m.m_title << " by " << m.m_artist << " from " << m.m_year;
    return out;
}

bool Media::operator<(const Media& m) {
    return m.m_year < m_year;
}
