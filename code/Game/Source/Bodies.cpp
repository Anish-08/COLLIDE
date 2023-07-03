#include"Bodies.h"
#include"defs.h"

Bodies::Bodies(double u, double v, double w, double h,int type,SDL_Renderer* renderer ): x(u),y(v),wid(w),hei(h), type(type) {
    r = 0;
    g = 0;
    b = 0;
    o = 255;
    vel_x=0;
    vel_y = 0;
    
    if(type){
        image = SDL_LoadBMP("images/ghost.bmp"); 	
        texture = SDL_CreateTextureFromSurface(renderer, image);
    }
    else{
        image = SDL_LoadBMP("images/pacman.bmp"); 	
        texture = SDL_CreateTextureFromSurface(renderer, image);
    }
    
}

Bodies::~Bodies(){
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
}

void Bodies::SetColour(int ri, int gi, int bi){
    r = ri;
    g = gi;
    b = bi;
}

void Bodies::SetVel(int ux, int uy){
    vel_x = ux;
    vel_y = uy;
}


bool Bodies::check_col(Bodies* B){
    if(((x>=B->x && x<=(B->x+B->wid)) 
        || (B->x>=x && B->x<=(x+wid))
    )&&((y>=B->y && y<=(B->y+B->hei)) 
        || (B->y>=y && B->y<=(y+hei)))
    ) return true;
    return false;  
}

void Bodies::display(SDL_Renderer* renderer){
    SDL_Rect fillRect = {x ,y ,wid,hei};
    SDL_RenderCopy(renderer,texture,NULL,&fillRect); 
}

void Bodies::move(){
    if(!(x+vel_x<0 || x+vel_x+wid>WIDTH)) x+=vel_x;
    if(!(y+vel_y<0 || y+vel_y+hei>HEIGHT)) y+=vel_y;
}
