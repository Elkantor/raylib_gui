#include <stdio.h>
#include "raylib_gui.h"
#include "widgets/button.h"

int main()
{
    SetTraceLogLevel(4);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(800, 600, "Test");

    raylib_gui_init();

    while(!WindowShouldClose())
    {
        const uint32_t width    = GetScreenWidth();
        const uint32_t height   = GetScreenHeight();
        const uint32_t mouse_x  = GetMouseX();
        const uint32_t mouse_y  = GetMouseY();

        BeginDrawing();
            ClearBackground(WHITE);
            
            const static char* button1 = "button1";
            raylib_gui_widget_button(button1, "test", 10, 10, 300, 100, BLUE, raylib_gui_global_font_main_32, mouse_x, mouse_y);
            if (button1 == raylib_gui_global_item_pressed)
            {
                printf("pressed\n");
                raylib_gui_global_item_pressed = NULL;
            }
            if (button1 == raylib_gui_global_item_overed)
            {
                printf("overed\n");
                raylib_gui_global_item_overed = NULL;
            }
            if (button1 == raylib_gui_global_item_down)
            {
                printf("mouse click down\n");
                raylib_gui_global_item_down = NULL;
            }

        EndDrawing();
    }

    raylib_gui_destroy();

    CloseWindow();
    return 0;
}