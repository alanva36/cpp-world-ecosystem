//
// Created by alanva on 4/22/26.
//

#include "GameSettings.hpp"

GameSettings::GameSettings()
    : worldWidth(80), worldHeight(20) {
}

GameSettings::GameSettings(int width, int height, int organisms)
    : worldWidth(width), worldHeight(height) {
    validateSettings();
}

void GameSettings::validateSettings() {
    if (worldWidth < MIN_SIZE) worldWidth = MIN_SIZE;
    if (worldWidth > MAX_SIZE) worldWidth = MAX_SIZE;
    if (worldHeight < MIN_SIZE) worldHeight = MIN_SIZE;
    if (worldHeight > MAX_SIZE) worldHeight = MAX_SIZE;
}