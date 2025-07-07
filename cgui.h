#include "raylib.h"
#include <cstdio>
#include <string>

bool DrawButton(int posX, int posY, int width, int height, Color color, float fontSize, std::string text = ""){
  DrawRectangle(posX, posY, width, height, color);
  DrawText(text.c_str(), posX, posY, fontSize, color);
  
  int mouseX = GetMouseX();
  int mouseY = GetMouseY();
  
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    if (mouseX >= posX && mouseX <= width+posX && mouseY >= posY && mouseY <= height+posY){
      return true;
    } // move mouseover check before button pressed to add cool effects like glow when over
  }
  return false;
}

void DrawInputBox(){
  
}
