#ifndef RGUI_DRAW_REC_LINES
#define RGUI_DRAW_REC_LINES

#include "../deps/raylib-3.7.0/include/raylib.h"

void rgui_draw_rec_lines(Rectangle rec, float lineThick, Color color)
{
    Rectangle top = { rec.x, rec.y, rec.width, lineThick };
    Rectangle bottom = { rec.x, rec.y - lineThick + rec.height, rec.width, lineThick };
    Rectangle left = { rec.x, rec.y + lineThick, lineThick, rec.height - lineThick*2.0f };
    Rectangle right = { rec.x - lineThick + rec.width, rec.y + lineThick, lineThick, rec.height - lineThick*2.0f };

    DrawRectangleRec(top, color);
    DrawRectangleRec(bottom, color);
    DrawRectangleRec(left, color);
    DrawRectangleRec(right, color);
}

#endif