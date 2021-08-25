#ifndef RGUI_WIDGET_CHECKBOX
#define RGUI_WIDGET_CHECKBOX

#include <stdint.h>
#include "../deps/raylib-3.7.0/include/raylib.h"
#include "../rgui_data.c"
#include "../rgui.h"
#include "../utils/rgui_draw_rec_lines.h"

typedef struct
{
    Font*       font;
    Color       background_color;
    Color       background_color_overed;
    Color       font_color;
    Color       font_color_overed;
    float       line_thick;
    uint32_t    width;
    uint32_t    height;
    uint8_t     font_spacing;
    uint8_t     padding;
    _Bool       label_left;
} rgui_checkbox;

const rgui_checkbox checkbox_dark_label_left =
{
    .width                      = 20,
    .height                     = 20,
    .font                       = &rgui_global_font_main_18,
    .font_color                 = { .r = 0, .g = 0, .b = 0, .a = 255 },
    .font_color_overed          = { .r = 255, .g = 255, .b = 255, .a = 255 },
    .font_spacing               = 1.0f,
    .background_color           = { .r = 52, .g = 73, .b = 93, .a = 255 },
    .background_color_overed    = { .r = 52, .g = 73, .b = 93, .a = 175 },
    .label_left                 = true,
    .line_thick                 = 2.f,
    .padding                    = 10,
};

const rgui_checkbox checkbox_dark_label_right =
{
    .width                      = 20,
    .height                     = 20,
    .font                       = &rgui_global_font_main_18,
    .font_color                 = { .r = 0, .g = 0, .b = 0, .a = 255 },
    .font_color_overed          = { .r = 255, .g = 255, .b = 255, .a = 255 },
    .font_spacing               = 1.0f,
    .background_color           = { .r = 52, .g = 73, .b = 93, .a = 255 },
    .background_color_overed    = { .r = 52, .g = 73, .b = 93, .a = 175 },
    .label_left                 = false,
    .line_thick                 = 2.f,
    .padding                    = 10,
};


void rgui_widget_checkbox(const char* item, const char* label, const uint32_t x, const uint32_t y, rgui_checkbox* checkbox_style, const uint32_t mouse_x, const uint32_t mouse_y, _Bool* restrict enabled)
{
    const Font font = *checkbox_style->font;
    const Vector2 label_size = MeasureTextEx(font, label, font.baseSize, checkbox_style->font_spacing);
    uint32_t checkbox_x;
    uint32_t label_x;

    if (checkbox_style->label_left)
    {
        checkbox_x = x + label_size.x + checkbox_style->padding;
        label_x = x;
    }
    else
    {
        checkbox_x = x;
        label_x = checkbox_x + checkbox_style->width + checkbox_style->padding;
    }

    const uint32_t w            = checkbox_style->width;
    const uint32_t h            = checkbox_style->height;

    const _Bool overed          = mouse_x > checkbox_x && mouse_x < checkbox_x + w && mouse_y > y && mouse_y < y + h;
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


    const uint32_t margin_h = (h - label_size.y) / 2;

    DrawTextEx(font, label, (Vector2){label_x, y + margin_h}, font.baseSize, checkbox_style->font_spacing, checkbox_style->font_color);

    if (*enabled)
    {
        DrawRectangle(checkbox_x, y + margin_h, w, h, checkbox_style->background_color);
    }
    else
    {
        const Rectangle rec = {checkbox_x, y + margin_h, w, h};
        rgui_draw_rec_lines(rec, checkbox_style->line_thick, checkbox_style->background_color);
    }
}

#endif