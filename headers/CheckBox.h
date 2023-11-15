//
// Created by lehen on 15/11/2023.
//

#ifndef INC_2CCPP_PROJECT_CHECKBOX_H
#define INC_2CCPP_PROJECT_CHECKBOX_H


#include "Vec2.h"
#include "raylib.h"

class CheckBox {
public:
    CheckBox(Vec2<int> position, Vec2<int> size, int padding, Color colorIn, Color colorEdge, bool defaultValue) :
    position(position),
    size(size),
    padding(padding),
    colorIn(colorIn),
    colorEdge(colorEdge),
    value(defaultValue)
    {};
    ~CheckBox() = default;

    bool GetValue() const{ return value;};
    void Draw();
    bool CanClick();
    void DetectClick();


private:
    Vec2<int> position;
    Vec2<int> size;
    int padding;
    Color colorIn;
    Color colorEdge;
    bool value;

};


#endif //INC_2CCPP_PROJECT_CHECKBOX_H
