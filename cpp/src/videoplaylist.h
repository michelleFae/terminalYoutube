#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "video.h"

/** A class used to represent a Playlist */

class VideoPlaylist {
  private:
  std::unordered_map<std::string, Video> mVideos;
  std::string playlistName;
  

 public:
  VideoPlaylist(const std::string& playlistName);
  std::vector<Video> getVideos() const;
  void addVideo(Video video);
  const std::string& removeVideo(const std::string& videoId);
  void removeAllVideos();
  void deletePlaylist();
  const Video *getVideo(const std::string& videoId) const;
  void setPlaylistName(const std::string& playlistName);
};
