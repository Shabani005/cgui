#include "raylib.h"
#include "/home/shabani/projects/cgui/cgui.h"
#include <cstdio>

int main(void){
  InitWindow(500, 500, "button example");
  bool input1 = false;
  bool bt1 = false;
  bool working = false;
  
  while (!WindowShouldClose()) {


    BeginDrawing();
    
    if(DrawInputBox(250, 250, 200, 100, BLACK, 50.0f)){
      input1 = !input1;
    }
    
    if (input1){
     if (DrawButton(250, 380, 50, 25, RED, WHITE, 8.0f, "hello world")){
      bt1 = !bt1; 
     }
    }
    
    if (bt1){
      DrawButton(250, 120, 50, 25, RED, WHITE, 8.0f, "hello world");
    }
    
    if (DrawButton(150, 380, 50, 25, RED, WHITE, 8.0f, "working")){
      working = !working;
    }

    if (working){
      printf("working\n");
      working = !working;
    }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
