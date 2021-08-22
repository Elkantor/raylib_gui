#ifndef RGUI_WIDGET_SLIDER
#define RGUI_WIDGET_SLIDER

#include <stdint.h>
#include "../libs/raylib.h"
#include "../rgui_data.c"
#include "../rgui.h"

typedef struct
{
    Font*           font;
    Color           bar_color_fill;
    Color           bar_color_empty;
    Color           circle_color;
    Color           steps_color;
    uint32_t        width;
    uint32_t        height;
    float           circle_radius;
    float           steps_radius;
    rgui_position   label_position;
} rgui_slider;

rgui_slider slider_dark_label_right = 
{
    .width              = 200,
    .height             = 10,
    .font               = &rgui_global_font_main_18,
    .bar_color_fill     = (Color){ .r = 26, .g = 188, .b = 156, .a = 255 },
    .bar_color_empty    = (Color){ .r = 217, .g = 221, .b = 224, .a = 255 },
    .circle_color       = (Color){ .r = 22, .g = 160, .b = 134, .a = 255 },
    .steps_color        = (Color){ .r = 236, .g = 241, .b = 241, .a = 255 },
    .circle_radius      = 10.f,
    .steps_radius       = 2.f,
    .label_position     = RGUI_POSITION_RIGHT,
};

// Notes: 
// - value must be a value between value_min and value_max. 
// - value_max - value_min > 0 or the program can crash
float rgui_widget_slider(const char* item, const char* label, const uint32_t x, const uint32_t y, rgui_slider* slider_style, const uint32_t mouse_x, const uint32_t mouse_y, float percent, float step)
{
    const Font font     = *slider_style->font;
    const uint32_t w    = slider_style->width;
    const uint32_t h    = slider_style->height;

    // Draw the two parts of the bar (filled one from the left, and the empty one)
    {
        const uint32_t w_fill   = (w * percent);
        DrawRectangle(x, y, w_fill, h, slider_style->bar_color_fill);

        const uint32_t w_empty = w - w_fill;
        const uint32_t x_empty = x + w_fill;
        DrawRectangle(x_empty, y, w_empty, h, slider_style->bar_color_empty);
    }

    // Draw the circle
    const uint32_t circle_radius = 10;
    const float circle_pos_x = (x + w) * percent; 
    {
        DrawCircleSector((Vector2){ .x = circle_pos_x, .y = y + h/2 }, circle_radius, 0.f, 360.f, 21, slider_style->circle_color);
    }

    Rectangle circle_bbx = (Rectangle){ .x = circle_pos_x - circle_radius, .y = y-h/2, .width = circle_radius*2, .height = circle_radius*2 };
    DrawRectangleLinesEx(circle_bbx, 2.f, RED);
    
    const _Bool overed          = mouse_x > circle_bbx.x && mouse_x < circle_bbx.x + circle_bbx.width && mouse_y > circle_bbx.y && mouse_y < circle_bbx.y + circle_bbx.height;
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

    if (down && mouse_x != circle_pos_x)
    {
        if (mouse_x < circle_pos_x)
        {
            percent -= step;
        }
        if (mouse_x > circle_pos_x)
        {
            percent += step;
        }
    }
    if (percent < 0.f) 
    {
        percent = 0.f;
    }
    if (percent > 1.f)
    {
        percent = 1.f;
    } 

    return percent;
}

#endif