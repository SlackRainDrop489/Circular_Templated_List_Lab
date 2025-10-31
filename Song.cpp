//
// Created by Christopher Vaughn on 10/24/25.
//
#include <sstream>
#include "Song.h"


// Public method to retrieve the title (useful for comparison, if needed)
std::string Song::getArtist() const { // This is to get the artist not the title
	return artist;
}

// Override toString() from the Media base class.
std::string Song::toString() const {
	std::stringstream ss;
	ss << "Song: " << title
			<< " | Artist: " << artist
			<< " | Duration: " << durationSeconds / 60 << "m " << durationSeconds % 60 << "s";
	return ss.str();
}

// Override play() to provide Song-specific behavior.
void Song::play() const {
	std::cout << "🎵 Now playing: " << title << " by " << artist << " 🎵" << std::endl;
}
