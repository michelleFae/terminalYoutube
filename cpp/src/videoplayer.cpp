#include "videoplayer.h"

#include <iostream>


void VideoPlayer::numberOfVideos() {
  std::cout << mVideoLibrary.getVideos().size() << " videos in the library"
            << std::endl;
}

void VideoPlayer::showAllVideos() {
    std::vector<Video> videoVector = mVideoLibrary.getVideos();
    std::sort(videoVector.begin(), videoVector.end());
    for (auto video : videoVector)
    {
        std::cout << video.getTitle() 
        << " (" << video.getVideoId() << ") [" ;

        int numTags = video.getTags().size();
        for (auto tag : video.getTags()) {
          std::cout << tag;
          if (numTags > 1) {
            std::cout << " ";
          }
          numTags--;
        }
        std::cout << "]" << std::endl;
    }
}

void VideoPlayer::playVideo(const std::string& videoId) {
  // check if video exists
  if (!mVideoLibrary.getVideo(videoId)) {
    std::cout << "Cannot play video: Video does not exist" << std::endl;
    return;
  }

  if (playingVideo) {
    // stop playing video
    stopVideo();
  }

  playingVideo = mVideoLibrary.getVideo(videoId);
  std::cout << "Playing video: " << playingVideo->getTitle() << std::endl;
}

void VideoPlayer::stopVideo() {
  // check if video is playing 
  if (playingVideo) {
    // stop playing video
    std::cout << "Stopping video: " << playingVideo->getTitle() << std::endl;
  } else {
    std::cout << "Cannot play video: Video does not exist" << std::endl;
  }
}

void VideoPlayer::playRandomVideo() {
  std::cout << "playRandomVideo needs implementation" << std::endl;
}

void VideoPlayer::pauseVideo() {
  std::cout << "pauseVideo needs implementation" << std::endl;
}

void VideoPlayer::continueVideo() {
  std::cout << "continueVideo needs implementation" << std::endl;
}

void VideoPlayer::showPlaying() {
  std::cout << "showPlaying needs implementation" << std::endl;
}

void VideoPlayer::createPlaylist(const std::string& playlistName) {
  std::cout << "createPlaylist needs implementation" << std::endl;
}

void VideoPlayer::addVideoToPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
  std::cout << "addVideoToPlaylist needs implementation" << std::endl;
}

void VideoPlayer::showAllPlaylists() {
  std::cout << "showAllPlaylists needs implementation" << std::endl;
}

void VideoPlayer::showPlaylist(const std::string& playlistName) {
  std::cout << "showPlaylist needs implementation" << std::endl;
}

void VideoPlayer::removeFromPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
  std::cout << "removeFromPlaylist needs implementation" << std::endl;
}

void VideoPlayer::clearPlaylist(const std::string& playlistName) {
  std::cout << "clearPlaylist needs implementation" << std::endl;
}

void VideoPlayer::deletePlaylist(const std::string& playlistName) {
  std::cout << "deletePlaylist needs implementation" << std::endl;
}

void VideoPlayer::searchVideos(const std::string& searchTerm) {
  std::cout << "searchVideos needs implementation" << std::endl;
}

void VideoPlayer::searchVideosWithTag(const std::string& videoTag) {
  std::cout << "searchVideosWithTag needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId, const std::string& reason) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::allowVideo(const std::string& videoId) {
  std::cout << "allowVideo needs implementation" << std::endl;
}
