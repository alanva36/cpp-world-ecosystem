//
// Created by alanva on 4/22/26.
//

#ifndef PROJEKT_GAMESETTINGS_HPP
#define PROJEKT_GAMESETTINGS_HPP

class GameSettings {
private:
    int worldWidth;
    int worldHeight;

    const int MIN_SIZE = 20;
    const int MAX_SIZE = 300;

public:
    GameSettings();
    GameSettings(int width, int height, int organisms);

    int getWorldWidth() const { return worldWidth; }
    int getWorldHeight() const { return worldHeight; }

    void setWorldWidth(int width) { worldWidth = width; }
    void setWorldHeight(int height) { worldHeight = height; }

    void validateSettings();

};

#endif //PROJEKT_GAMESETTINGS_HPP