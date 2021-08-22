#include <stdio.h>
#include "rgui.h"
#include "widgets/button.h"
#include "widgets/checkbox.h"
#include "widgets/slider.h"

int main()
{
    SetTraceLogLevel(4);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(800, 600, "Test");

    rgui_init();

    _Bool checkbox_enabled = false;
    _Bool checkbox_enabled2 = false;
    float slider1_percent = 0.12;

    while(!WindowShouldClose())
    {
        const uint32_t width    = GetScreenWidth();
        const uint32_t height   = GetScreenHeight();
        const uint32_t mouse_x  = GetMouseX();
        const uint32_t mouse_y  = GetMouseY();

        BeginDrawing();
            ClearBackground(WHITE);
            
            uint32_t pos_y = 0;
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
            pos_y += button_dark.height + 20;

            const static char* checkbox1 = "checkbox1";
            rgui_widget_checkbox(checkbox1, "checkbox label left", 10, pos_y, &checkbox_dark_label_left, mouse_x, mouse_y, &checkbox_enabled);
            if (checkbox1 == rgui_global_item_pressed)
            {
                checkbox_enabled = !checkbox_enabled;
                rgui_global_item_pressed = NULL;
            }
            pos_y += checkbox_dark_label_left.height + 20;

            const static char* checkbox2 = "checkbox2";
            rgui_widget_checkbox(checkbox2, "checkbox label right", 10, pos_y, &checkbox_dark_label_right, mouse_x, mouse_y, &checkbox_enabled2);
            if (checkbox2 == rgui_global_item_pressed)
            {
                checkbox_enabled2 = !checkbox_enabled2;
                rgui_global_item_pressed = NULL;
            }
            pos_y += checkbox_dark_label_right.height +20;

            const static char* slider1 = "slider1";
            slider1_percent = rgui_widget_slider(slider1, "slider label right", 10, pos_y, &slider_dark_label_right, mouse_x, mouse_y, slider1_percent, 0.001);
            printf("value: %f\n", slider1_percent);
        EndDrawing();
    }

    rgui_destroy();

    CloseWindow();
    return 0;
}