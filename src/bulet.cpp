
#include<bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
using namespace std;
void bulli(SDL_Renderer &rend){
        for(int i=0;i<s;i++){
            bullet[i].h=10;
            bullet[i].w=5;
            bullet[i].x=bul_x;
            bullet[i].y=bul_y;
            surface=IMG_Load("midia/ALU3.png");
            SDL_Texture* redbul=SDL_CreateTextureFromSurface(rend,surface);
            fre
        }
}