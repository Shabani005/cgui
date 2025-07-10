#include "raylib.h"
#include <cmath>
#include <cstdio>
#include <string>
#include <list>


char* concatList(std::list<char> lst){
  size_t size = lst.size();
  char* cstr = new char[size+1];
  size_t index = 0;
  for (char ch : lst){
    cstr[index++] = ch;
  }
  cstr[size] = '\0';
  return cstr;
}


bool DrawButton(int posX, int posY, int width, int height, Color color, Color TextColor,float fontSize, std::string text = ""){
  DrawRectangle(posX, posY, width, height, color);
  DrawText(text.c_str(), posX, posY+height/4, fontSize, TextColor);
  // Add optional Borders in the Future (with custom width)
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


// may need it to be a char instead of bool but can change later
// Global or class member variable to persist text
std::string inputText = "";
bool inputBoxActive = false;

bool DrawInputBox(int posX, int posY, int width, int height, Color TextColor, float fontSize, Color color = WHITE) {
    DrawRectangle(posX, posY, width, height, color);
    
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (mouseX >= posX && mouseX <= width + posX && 
            mouseY >= posY && mouseY <= height + posY) {
            inputBoxActive = true;
        } else {
            inputBoxActive = false;
        }
    }
    
    if (inputBoxActive) {
        int key = GetCharPressed();
        while (key > 0) {
            if (key >= 32 && key <= 125) {  // Printable ASCII characters
                inputText += (char)key;
            }
            key = GetCharPressed();
        }
        
            if (IsKeyPressed(KEY_BACKSPACE) && !inputText.empty()) {
                inputText.pop_back();
        }
    }
    
    DrawText(inputText.c_str(), posX + 5, posY + height/4, fontSize, TextColor);
    
    return inputBoxActive;
}


// to make a toggle I will draw 2 rectangles (to manipulate colors easily)
// custom sizing with 50/50 defaults but not now
bool DrawToggle(int posX, int posY, int width, int height, Color offColor, Color onColor){
  
  static bool isClicked = false;

  DrawRectangle(posX, posY, width/2, height, offColor);
  DrawRectangle(posX+width/2, posY, width/2, height, offColor);
  DrawCircle(posX*1.05, posY*1.05, height/2, WHITE);
 

  int mouseX = GetMouseX();
  int mouseY = GetMouseY();
  
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
    if (mouseX >= posX && mouseX <= width+posX && mouseY >= posY && mouseY <= height+posY){
      isClicked = !isClicked;
    } // move mouseover check before button pressed to add cool effects like glow when over
  } // perhaps use Brighten 

  if (isClicked){
    offColor = GREEN; 
  }

  // DrawCircle(int centerX, int centerY, float radius, Color color)
  
  return true;
}

