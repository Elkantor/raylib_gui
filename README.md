# raylib_gui
Immediate mode gui on top of raylib

## How to build

- On windows (mingw)
```shell
cd proc/win
sh ./mingw.sh
```

## Widgets
- ### Buttons
```c
#include <stdio.h>
#include "rgui.h"
#include "widgets/button.h"
int main()
{
    SetTraceLogLevel(4);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(800, 600, "Test");
    rgui_init();

    while(!WindowShouldClose())
    {
        const uint32_t width    = GetScreenWidth();
        const uint32_t height   = GetScreenHeight();
        const uint32_t mouse_x  = GetMouseX();
        const uint32_t mouse_y  = GetMouseY();

        BeginDrawing();
            ClearBackground(WHITE);
            
            const static char* button1 = "button1";
            rgui_widget_button(button1, "test", 10, 10, &button_dark, mouse_x, mouse_y);
            if (button1 == rgui_global_item_pressed)
            {
                printf("pressed\n");
                rgui_global_item_pressed = NULL;
            }
            if (button1 == rgui_global_item_overed)
            {
                printf("overed\n");
                rgui_global_item_overed = NULL;
            }
            if (button1 == rgui_global_item_down)
            {
                printf("mouse click down\n");
                rgui_global_item_down = NULL;
            }
            
        EndDrawing();
    }

    rgui_destroy();
    CloseWindow();
    return 0;
}
