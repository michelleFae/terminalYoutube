#include "videoplaylist.h"

VideoPlaylist::VideoPlaylist(const std::string& playlistName) {
    this->playlistName = playlistName;
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

bool VideoPlaylist::containsVideo(const std::string& videoId) {
  if (this->mVideos.find(videoId) == this->mVideos.end()) {
        return false;
  }
  return true;
}

void VideoPlaylist::addVideo(const Video &video) {
  mVideos.emplace(video.getVideoId() , std::move(video));
  std::cout << containsVideo(video.getVideoId())<< std::endl;
  std::cout << "Added video to " << playlistName << ": " << video.getTitle() << std::endl;
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