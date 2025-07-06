#include "raylib.h"
#include <cstdio>

void DrawButton(int posX, int posY, int width, int height, Color color){
  DrawRectangle(posX, posY, width, height, color);
  int mouseX = GetMouseX();
  int mouseY = GetMouseY();
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    if (mouseX >= posX && mouseX <= width+posX && mouseY >= posY && mouseY <= height+posY){
      printf("hello world");
    }
  }
}
