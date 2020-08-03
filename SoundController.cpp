//
// Created by Daniel Eidlin on 03/08/2020.
//

#include "SoundController.h"

SoundController::SoundController() {
    // Initialize audio subsystem
    SDL_Init(SDL_INIT_AUDIO);
}

SoundController::~SoundController() {
    // clean up
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();
}

void SoundController::playSound(Sound sound) {
    // load WAV file
    switch (sound) {
        case Sound::Apple:
            SDL_LoadWAV(appleSoundPath.c_str(), &wavSpec, &wavBuffer, &wavLength);
            break;

        default:
            return;
    }

    // open audio device
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);

    // play audio
    int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);

}
