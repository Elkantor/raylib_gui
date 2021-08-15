#ifndef RGUI_WIDGET_BUTTON
#define RGUI_WIDGET_BUTTON

#include <stdint.h>
#include "../libs/raylib.h"
#include "../rgui_data.c"
#include "../rgui.h"

void rgui_widget_button(const char* item, const char* label, const uint32_t x, const uint32_t y, const uint32_t w, const uint32_t h, const Color color, const Font font, const uint32_t mouse_x, const uint32_t mouse_y)
{
    const _Bool overed          = mouse_x > x && mouse_x < x + w && mouse_y > y && mouse_y < y + h;
    const _Bool pressed         = (overed && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
    const _Bool down            = (overed && IsMouseButtonDown(MOUSE_LEFT_BUTTON));
    const _Bool forgotten       = rgui_global_item_pressed == (char*)item && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    rgui_global_item_overed   = (char*)rgui_item_update_event((uintptr_t)rgui_global_item_overed, (uintptr_t)item, overed);
    rgui_global_item_pressed  = (char*)rgui_item_update_event((uintptr_t)rgui_global_item_pressed, (uintptr_t)item, pressed);
    rgui_global_item_down     = (char*)rgui_item_update_event((uintptr_t)rgui_global_item_pressed, (uintptr_t)item, down);

    if (forgotten)
    {
        rgui_global_item_pressed = 0;
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