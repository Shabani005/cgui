#include "raylib.h"
#include <cstdio>

bool DrawButton(int posX, int posY, int width, int height, Color color){
  DrawRectangle(posX, posY, width, height, color);
  int mouseX = GetMouseX();
  int mouseY = GetMouseY();
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    if (mouseX >= posX && mouseX <= width+posX && mouseY >= posY && mouseY <= height+posY){
      return true;
    } // move mouseover check before button pressed to add cool effects like glow when over
  }
  return false;
}

void DrawTextBox(){
  
}
