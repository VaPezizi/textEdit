#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

#define HEIGHT 600
#define WIDTH 800
#define BUFFERSIZE 500

int main(){
	//Allocating memory for a Buffer of 500 characters
	char * BUFFER = (char*) malloc(sizeof(char) * (BUFFERSIZE + 1));
	BUFFER[BUFFERSIZE + 1] = '\0';

	InitWindow(WIDTH, HEIGHT, "Text Edit");
	SetTargetFPS(60);

	int letterCount = 0;

	while(!WindowShouldClose()){
		
		if(CheckCollisionPointRec(GetMousePosition(), (Rectangle) {0, 0, GetScreenWidth(), GetScreenHeight()})){
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
			
			int key = GetCharPressed();
	
			while(key > 0){
				if((key>= 32) && (key <= 255) && (letterCount < BUFFERSIZE)){
					
					BUFFER[letterCount] = (char)key;
					BUFFER[letterCount + 1] = '\0';
					letterCount++;
				}
				
				key = GetCharPressed();
			}
			if(IsKeyPressed(KEY_BACKSPACE)){
				letterCount--;
				if(letterCount < 0) letterCount = 0;
				BUFFER[letterCount] = '\0';
			}
		}
		
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	

		BeginDrawing();
		ClearBackground(WHITE);	
		
		DrawText(BUFFER, 10, 10, 40, MAROON);	
		
		EndDrawing();
		printf("Arvo :%c \n", BUFFER[letterCount - 1]);
	}	


	return 0;
}
