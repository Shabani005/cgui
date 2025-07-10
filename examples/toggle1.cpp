#include "/home/shabani/projects/cgui/cgui.h"
#include <raylib.h>

int main(void){
  InitWindow(500, 500, "test");

  while (!WindowShouldClose()) {
    BeginDrawing();
    DrawToggle(250, 250, 50, 25, RED, GREEN);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
