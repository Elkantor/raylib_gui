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
    .width              = 100,
    .height             = 10,
    .font               = &rgui_global_font_main_18,
    .bar_color_fill     = (Color){ .r = 26, .g = 188, .b = 156, .a = 255 },
    .bar_color_empty    = (Color){ .r = 217, .g = 221, .b = 224, .a = 255 },
    .circle_color   = (Color){ .r = 22, .g = 160, .b = 134, .a = 255 },
    .steps_color    = (Color){ .r = 236, .g = 241, .b = 241, .a = 255 },
    .circle_radius  = 10.f,
    .steps_radius   = 2.f,
    .label_position = RGUI_POSITION_RIGHT,
};

void rgui_widget_slider(const char* item, const char* label, const uint32_t x, const uint32_t y, rgui_slider* slider_style, const uint32_t mouse_x, const uint32_t mouse_y, float* restrict value, const float value_min, const float value_max, float steps)
{
    const Font font     = *slider_style->font;
    const uint32_t w    = slider_style->width;
    const uint32_t h    = slider_style->height; 

    const float value_fill  = *value;
    const float value_empty = value_max - value_fill;
    const float number_values = value_max - value_min;

    const uint32_t w_fill   = (w / value_fill);
    DrawRectangle(x, y, w_fill, h, slider_style->bar_color_fill);

    const uint32_t w_empty = w - value_fill;
    const uint32_t x_empty = x + w_fill;
    DrawRectangle(x_empty, y, w_empty, h, slider_style->bar_color_empty);

    //DrawCircle(x + 20, y + h/2, slider_style->circle_radius, slider_style->circle_color);
    DrawCircleSector((Vector2){ .x = x + 20, .y = y + h/2 }, 10.f, 0.f, 360.f, 21, slider_style->circle_color);

}

#endif