# raylib_gui
Immediate mode gui on top of raylib

## How to build

- On windows (mingw)
```shell
cd proc/win
sh ./mingw.sh
```

## Examples so far
![rgui](https://user-images.githubusercontent.com/20202017/129609874-1ea25f5c-1450-4f07-8bd6-bf4079c84adf.gif)


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
            // button_dark is a template for a dark theme rectangle button with text centered
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
```

- ### Checkbox
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
    
    _Bool checkbox1_enabled = false;
    _Bool checkbox2_enabled = false;

    while(!WindowShouldClose())
    {
        const uint32_t width    = GetScreenWidth();
        const uint32_t height   = GetScreenHeight();
        const uint32_t mouse_x  = GetMouseX();
        const uint32_t mouse_y  = GetMouseY();

        BeginDrawing();
            ClearBackground(WHITE);
            
            uint32_t pos_y = 0; // to draw the checkboxes on the same column
            const static char* checkbox1 = "checkbox1";
            // checkbox_dark_label_left is a template for a dark theme checkbox with a label on the left
            rgui_widget_checkbox(checkbox1, "checkbox label left", 10, pos_y, &checkbox_dark_label_left, mouse_x, mouse_y, &checkbox1_enabled);
            if (checkbox1 == rgui_global_item_pressed)
            {
                checkbox_enabled = !checkbox_enabled;
                rgui_global_item_pressed = NULL;
            }
            pos_y += checkbox_dark_label_left.height + 20;

            const static char* checkbox2 = "checkbox2";
            // checkbox_dark_label_left is a template for a dark theme checkbox with a label on the right
            rgui_widget_checkbox(checkbox2, "checkbox label right", 10, pos_y, &checkbox_dark_label_right, mouse_x, mouse_y, &checkbox2_enabled);
            if (checkbox2 == rgui_global_item_pressed)
            {
                checkbox_enabled2 = !checkbox_enabled2;
                rgui_global_item_pressed = NULL;
            }
            
        EndDrawing();
    }

    rgui_destroy();
    CloseWindow();
    return 0;
}
```
