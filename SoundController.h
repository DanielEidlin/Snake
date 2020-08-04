//
// Created by Daniel Eidlin on 03/08/2020.
//

#ifndef SNAKE_SOUNDCONTROLLER_H
#define SNAKE_SOUNDCONTROLLER_H
#include <SDL.h>


#include <string>
#include "Sound.h"

class SoundController {
private:
    std::string soundPath;
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8* wavBuffer;
    SDL_AudioDeviceID deviceId;

public:
    SoundController();

    SoundController(std::string soundPath);

    ~SoundController();

    void playSound();

};


#endif //SNAKE_SOUNDCONTROLLER_H
