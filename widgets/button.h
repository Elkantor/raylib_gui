#ifndef RAYLIB_GUI_WIDGET_BUTTON
#define RAYLIB_GUI_WIDGET_BUTTON

#include <stdint.h>
#include "../libs/raylib.h"
#include "../raylib_gui_data.c"
#include "../raylib_gui.h"

void raylib_gui_widget_button(const char* item, const char* label, const uint32_t x, const uint32_t y, const uint32_t w, const uint32_t h, const Color color, const Font font, const uint32_t mouse_x, const uint32_t mouse_y)
{
    const char* item_label  = label;
    const _Bool overed      = mouse_x > x && mouse_x < x + w && mouse_y > y && mouse_y < y + h;
    const _Bool pressed     = (overed && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
    const _Bool forgotten   = raylib_gui_global_item_pressed == (char*)item && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    raylib_gui_global_item_overed   = (char*)raylib_gui_item_update_event((uintptr_t)raylib_gui_global_item_overed, (uintptr_t)item, overed);
    raylib_gui_global_item_pressed  = (char*)raylib_gui_item_update_event((uintptr_t)raylib_gui_global_item_pressed, (uintptr_t)item, pressed);

    if (forgotten)
    {
        raylib_gui_global_item_pressed = 0;
    }

    if (overed)
    {
        DrawRectangle(x, y, w, h, (Color){color.r, color.g, color.b, 155});
    }
    else
    {
        DrawRectangle(x, y, w, h, color);
    }

    const Vector2 label_size = MeasureTextEx(font, label, font.baseSize, 5.f);
    const uint32_t margin_w = (w - label_size.x) / 2;
    const uint32_t margin_h = (h - label_size.y) / 2;
    DrawTextEx(font, label, (Vector2){x + margin_w, y + margin_h}, font.baseSize, 5.f, WHITE);
    
}

#endif