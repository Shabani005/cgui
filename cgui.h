#include "raylib.h"
#include <cstdio>
#include <string>

bool DrawButton(int posX, int posY, int width, int height, Color color, Color TextColor,float fontSize, std::string text = ""){
  DrawRectangle(posX, posY, width, height, color);
  DrawText(text.c_str(), posX, posY+height/4, fontSize, TextColor);
 // idk if Draw Text posX is centered yet. But Height IS centered. 
  int mouseX = GetMouseX();
  int mouseY = GetMouseY();
  
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    if (mouseX >= posX && mouseX <= width+posX && mouseY >= posY && mouseY <= height+posY){
      return true;
    } // move mouseover check before button pressed to add cool effects like glow when over
  } // perhaps use Brighten 
  return false;
}

void DrawInputBox(){
  
}
