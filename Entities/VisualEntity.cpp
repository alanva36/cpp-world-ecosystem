//
// Created by alanva on 3/31/26.
//

#include "VisualEntity.hpp"

VisualEntity::VisualEntity(char model, int color_pair)
    : model(model), color_pair(color_pair)
{
}

char VisualEntity::getModel() const {
    return model;
}

int VisualEntity::getColor() const {
    return color_pair;
}

void VisualEntity::setModel(char new_model) {
    model = new_model;
}

void VisualEntity::setColor(int new_color) {
    color_pair = new_color;
}