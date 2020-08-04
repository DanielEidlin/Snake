#include <iostream>
#include "Board.h"
#include "Snake.h"
#include <unistd.h>

int main() {
    std::cout << "Starting game!" << std::endl;
    Board board = Board(16, 35);
    Snake& snake = board.getSnake();
    while (true) {  // game loop
        board.getInput();
        if (snake.CanMove())
            snake.move();
        board.checkAppleEngage();   // check if the snake engaged the apple
        board.draw();   // draw the state of the game
        if (board.snakeCollided()) {
            usleep(300000); // delay for 300 ms to make snake collision detectable
            break;
        }
        usleep(110000); /* delay for 110 ms. if you wonder why 110 ms:
                        https://github.com/romanedgn/snake-game/blob/master/fSnakeGame.cpp */
    }
    // board.lose();

//    // Initialize audio subsystem
//    SDL_Init(SDL_INIT_AUDIO);
//    SDL_AudioSpec wavSpec;
//    Uint32 wavLength;
//    Uint8 *wavBuffer;
//    SDL_LoadWAV("../sound/apple.wav", &wavSpec, &wavBuffer, &wavLength);
//    // open audio device
//    SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
//
//    for (int i = 1; i < 51; i++) {
//        std::cout << i << std::endl;
//        // play audio
//        int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
//        SDL_PauseAudioDevice(deviceId, 0);
//        SDL_Delay(1000);
//    }

    return 0;
}
