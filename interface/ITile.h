//
// Created by kyomawolf on 10.02.24.
//

#ifndef ANOTHERTWO_TILE_H
#define ANOTHERTWO_TILE_H

#include <raylib-cpp.hpp>

namespace interface {

    class ITile {
    public:
        //ITile(int x = 0, int y = 0, int size = 16);
        virtual ~ITile() = 0;

        void render(const raylib::Vector2& position);
        void setTexture();

    private:
        int _x;
        int _y;

        int _offset_x = 0;
        int _offset_y = 0;

        int _size;
        raylib::Texture2D _tex;
    };

} // interface

#endif //ANOTHERTWO_TILE_H
