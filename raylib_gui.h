#ifndef RAYLIB_GUI
#define RAYLIB_GUI

#include <stdint.h>
#include "libs/raylib.h"
#include "raylib_gui_data.c"

void raylib_gui_init()
{
    raylib_gui_global_font_main_14 = LoadFontEx("./fonts/Lato-Heavy.ttf", 14, NULL, 95);
    raylib_gui_global_font_main_18 = LoadFontEx("./fonts/Lato-Heavy.ttf", 18, NULL, 95);
    raylib_gui_global_font_main_20 = LoadFontEx("./fonts/Lato-Heavy.ttf", 20, NULL, 95);
    raylib_gui_global_font_main_24 = LoadFontEx("./fonts/Lato-Heavy.ttf", 24, NULL, 95);
    raylib_gui_global_font_main_32 = LoadFontEx("./fonts/Lato-Heavy.ttf", 32, NULL, 95);
}

void raylib_gui_destroy()
{
    UnloadFont(raylib_gui_global_font_main_14);
    UnloadFont(raylib_gui_global_font_main_18);
    UnloadFont(raylib_gui_global_font_main_20);
    UnloadFont(raylib_gui_global_font_main_24);
    UnloadFont(raylib_gui_global_font_main_32);
}

const uintptr_t raylib_gui_item_update_event(const uintptr_t persistent_ptr, const uintptr_t item_ptr, const _Bool event)
{
    const uintptr_t current    = persistent_ptr - (persistent_ptr * (uint32_t)(event));
    const uintptr_t item       = item_ptr * (uint32_t)(event);
    const uintptr_t final      = current + item;
    return final;
}

#endif