#include "cgui.h"
#include "raylib.h"
#include <cstdio>

int main(void){
  InitWindow(500, 500, "button test");
  bool showMessage = false; 
  
  while (!WindowShouldClose()){ 
    BeginDrawing();
    ClearBackground(BLACK);
    if (DrawButton(250, 250, 50, 25, RED, WHITE,8.0f, "hello world")){
      printf("new print\n");
      showMessage = !showMessage;      
      // EnableEventWaiting() could be important maybe implement header
    }
    //DrawFPS(0, 0);
    if (showMessage){
      DrawText("hello world", 10, 10, 20, WHITE);
    } 
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
