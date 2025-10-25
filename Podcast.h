//
// Created by Christopher Vaughn on 10/24/25.
//

#ifndef CIRCULARTEMPLATEDLIST_PODCAST_H
#define CIRCULARTEMPLATEDLIST_PODCAST_H

#include <iostream>
#include "Media.h"

// Represents a podcast episode, showing how multiple types can share the list.
class Podcast : public Media {
private:
    std::string episodeTitle;
    std::string host;
    int episodeNumber;
public:
    // Constructor
    Podcast(const std::string& t, const std::string& h, const int d)
    : Media(t, d) {}

    // Override toString() from the Media base class.
    std::string toString() const override;

    // Override play() to provide Podcast-specific behavior.
    void play() const override;
};

#endif //CIRCULARTEMPLATEDLIST_PODCAST_H