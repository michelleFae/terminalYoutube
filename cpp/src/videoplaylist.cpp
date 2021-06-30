#include "videoplaylist.h"

VideoPlaylist::VideoPlaylist(std::string& playlistName):playlistName(std::move(playlistName)) {
}

std::vector<Video> VideoPlaylist::getVideos() const {
  std::vector<Video> result;
  for (const auto& video : mVideos) {
    result.emplace_back(video.second);
  }
  return result;
}

const Video* VideoPlaylist::getVideo(const std::string& videoId) const {
  const auto found = mVideos.find(videoId);
  if (found == mVideos.end()) {
    return nullptr;
  } else {
    return &(found->second);
  }
}


void VideoPlaylist::addVideo(Video video) {
  mVideos.emplace(video.getVideoId() , std::move(video));
}

const std::string& VideoPlaylist::removeVideo(const std::string& videoId) {
  for (const auto& video : mVideos) {
    if (video.second.getVideoId() == videoId) { 
        const std::string& title = video.second.getTitle();
        mVideos.erase(video.first); 
        return title; 
    }
  }
  return nullptr;
}

void VideoPlaylist::removeAllVideos() {
  for (const auto& video : mVideos) {
    mVideos.erase(video.first); 
  }
}

void VideoPlaylist::deletePlaylist() {

}