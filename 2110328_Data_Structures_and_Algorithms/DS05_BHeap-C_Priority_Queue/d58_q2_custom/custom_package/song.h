#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song
{
public:
  std::string artist, title;
  int count;

  Song() {}
  Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) {}
  Song(std::string artist, std::string title, int count) : artist(artist), title(title), count(count) {}

  friend std::ostream &operator<<(std::ostream &out, const Song &s)
  {
    return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
  }
};

//  you have to write something below this line
//  you *MIGHT* have to change the declaration of pq1 and pq2

struct SortByArtist
{
  bool operator()(const Song &A, const Song &B) const
  {
    return A.artist != B.artist ? A.artist > B.artist : (A.title != B.title ? A.title > B.title : A.count > B.count);
  };
};

struct SortBySales
{
  bool operator()(const Song &A, const Song &B) const
  {
    return A.count != B.count ? A.count < B.count : (A.artist != B.artist ? A.artist > B.artist : A.title > B.title);
  };
};

CP::priority_queue<Song, SortByArtist> pq1;
CP::priority_queue<Song, SortBySales> pq2;

#endif
