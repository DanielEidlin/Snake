//
// Created by Daniel Eidlin on 03/08/2020.
//

#include "SoundController.h"

SoundController::SoundController() {}

SoundController::SoundController(std::string soundPath) : soundPath(soundPath) {
    // Initialize audio subsystem
    SDL_Init(SDL_INIT_AUDIO);
    // load WAV file
    SDL_LoadWAV(soundPath.c_str(), &wavSpec, &wavBuffer, &wavLength);
    // open audio device
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
}

SoundController::~SoundController() {
    // clean up
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();
}

void SoundController::playSound() {
    // play audio
    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);

}
