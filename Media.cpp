//
// Created by Christopher Vaughn on 10/24/25.
//

#include "Media.h"

// === 1. Base Media Type (for Polymorphism) ===


    // Common accessor
    std::string Media::getTitle() const { return title; }
    void Media::setTitle(const std::string& t) { title = t; }
    int Media::getDuration() const { return durationSeconds; }
    void Media::setDuration(int d) { durationSeconds = d; }