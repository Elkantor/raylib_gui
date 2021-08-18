#ifndef RGUI
#define RGUI

#include <stdint.h>
#include "libs/raylib.h"
#include "rgui_data.c"

typedef enum
{
    RGUI_POSITION_TOP,
    RGUI_POSITION_BOTTOM,
    RGUI_POSITION_LEFT,
    RGUI_POSITION_RIGHT,
} rgui_position;

void rgui_init()
{
    rgui_global_font_main_14 = LoadFontEx("./fonts/Lato-Heavy.ttf", 14, NULL, 95);
    rgui_global_font_main_18 = LoadFontEx("./fonts/Lato-Heavy.ttf", 18, NULL, 95);
    rgui_global_font_main_20 = LoadFontEx("./fonts/Lato-Heavy.ttf", 20, NULL, 95);
    rgui_global_font_main_24 = LoadFontEx("./fonts/Lato-Heavy.ttf", 24, NULL, 95);
    rgui_global_font_main_32 = LoadFontEx("./fonts/Lato-Heavy.ttf", 32, NULL, 95);
}

void rgui_destroy()
{
    UnloadFont(rgui_global_font_main_14);
    UnloadFont(rgui_global_font_main_18);
    UnloadFont(rgui_global_font_main_20);
    UnloadFont(rgui_global_font_main_24);
    UnloadFont(rgui_global_font_main_32);
}

const uintptr_t rgui_item_update_event(const uintptr_t persistent_ptr, const uintptr_t item_ptr, const _Bool event)
{
    const uintptr_t current    = persistent_ptr - (persistent_ptr * (uint32_t)(event));
    const uintptr_t item       = item_ptr * (uint32_t)(event);
    const uintptr_t final      = current + item;
    return final;
}

#endif