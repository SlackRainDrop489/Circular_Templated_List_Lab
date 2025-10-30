//
// Created by Christopher Vaughn on 10/24/25.
//

#ifndef CIRCULARTEMPLATEDLIST_SONG_H
#define CIRCULARTEMPLATEDLIST_SONG_H
#include <iostream>
#include "Media.h"


// === 2. Derived Media Type (Song) ===
// The Song class now derives from the Media base class.
class Song : public Media {
	private:
		std::string artist;

	public:
		// Constructor
		Song(const std::string &t, const std::string &a, int d)
			: Media(t, d) {
		}

		//get the artist
		std::string getArtist() const;

		// Override toString() from the Media base class.
		std::string toString() const override;

		// Override play() to provide Song-specific behavior.
		void play() const override;
};


#endif //CIRCULARTEMPLATEDLIST_SONG_H
