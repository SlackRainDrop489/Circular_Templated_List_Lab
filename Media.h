//
// Created by Christopher Vaughn on 10/24/25.
//

#ifndef CIRCULARTEMPLATEDLIST_MEDIA_H
#define CIRCULARTEMPLATEDLIST_MEDIA_H
#include <string>

class Media {
protected:
    // Common state variables moved to the base class
    std::string title;
    int durationSeconds;

    // Protected constructor to initialize base members (called by derived classes)
    Media(const std::string& t, int d) : title(t), durationSeconds(d) {}

public:
    // Pure virtual methods define required behavior
    virtual std::string toString() const = 0;
    virtual void play() const = 0;

    // Required virtual destructor for safe cleanup
    virtual ~Media() = default;

    // Common accessor
    std::string getTitle() const;
    void setTitle(const std::string& t);
    int getDuration() const;
    void setDuration(int d);
};

#endif //CIRCULARTEMPLATEDLIST_MEDIA_H