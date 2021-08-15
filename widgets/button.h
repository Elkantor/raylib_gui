#ifndef RGUI_WIDGET_BUTTON
#define RGUI_WIDGET_BUTTON

#include <stdint.h>
#include "../libs/raylib.h"
#include "../rgui_data.c"
#include "../rgui.h"


typedef struct 
{
    Font*       font;
    Color       background_color;
    Color       background_color_overed;
    Color       font_color;
    Color       font_color_overed;
    uint32_t    width;
    uint32_t    height;
    uint8_t     font_spacing;
    uint8_t     label_margin_left;
    _Bool       text_centered;
} rgui_button;

rgui_button button_dark =
{
    .width                      = 100,
    .height                     = 30,
    .font                       = &rgui_global_font_main_18,
    .font_color                 = { .r = 255, .g = 255, .b = 255, .a = 255 },
    .font_color_overed          = { .r = 255, .g = 255, .b = 255, .a = 255 },
    .font_spacing               = 1.0f,
    .text_centered              = true,
    .background_color           = { .r = 52, .g = 73, .b = 93, .a = 255 },
    .background_color_overed    = { .r = 52, .g = 73, .b = 93, .a = 175 },
};


void rgui_widget_button(const char* item, const char* label, const uint32_t x, const uint32_t y, rgui_button* restrict button_style, const uint32_t mouse_x, const uint32_t mouse_y)
{
    const uint32_t w            = button_style->width;
    const uint32_t h            = button_style->height;

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
        DrawRectangle(x, y, w, h, button_style->background_color_overed);
    }
    else
    {
        DrawRectangle(x, y, w, h, button_style->background_color);
    }

    const Font font = *button_style->font;
    const Vector2 label_size = MeasureTextEx(font, label, font.baseSize, button_style->font_spacing);

    const uint32_t margin_h = (h - label_size.y) / 2;
    if (button_style->text_centered)
    {
        const uint32_t margin_w = (w - label_size.x) / 2;
        DrawTextEx(font, label, (Vector2){x + margin_w, y + margin_h}, font.baseSize, button_style->font_spacing, button_style->font_color);
    }
    else
    {
        DrawTextEx(font, label, (Vector2){ x + button_style->label_margin_left, y + margin_h}, font.baseSize, button_style->font_spacing, button_style->font_color); 
    }
    
}

#endif