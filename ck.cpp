#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include<bits/stdc++.h>

using namespace std;
SDL_Surface* surface;
struct point
{
    float x;
    float y;
};
int c5=0,l1=0,f1=0,c=100,r1=0,scar=0,scar1=0;
point a[5];
map<int,int>mbc,mec;
int bul_x[10],bul_y[10];
int l=0,s=0;
int col(int p_x,int p_y,int t){
    int l2;
    for(int i=0;i<5;i++){
        if(p_x>=a[i].x&&p_x<=a[i].x+50&&p_y<=a[i].y){
            bul_x[t]=1500;
            a[i].x=1500;
            scar=scar+1;
            mec[i]=0;
            return 0;

        }
    }
    return 1;
}
void bull(){
    int y=10,l1=l,m3;
    for(int i=0;i<10;i++){
        if(mbc[i]==1){
            bul_y[i]=bul_y[i]-10;

            if(bul_y[i]<-10){
                mbc[i]=0;

            }
            else{
                m3=col(bul_x[i],bul_y[i],i);
                mbc[i]=m3;
            }
        }
    }
}
void enemy(int s){
    a[s].x=c5%1150;
    a[s].y=0;
}
void emove(int i1){
    //a[i1].y=a[i1].y+2;
    if(mec[i1]==1){
        a[i1].y=a[i1].y+2;
    }
    //cout<<r1<<" ";
    if(a[i1].y>800){
        //f1=0;
        mec[i1]=0;
        //r1=r1-1;
    }
}
int bulcheck(){
    for(int i=0;i<10;i++){
        if(mbc[i]==0){
            return i;
        }
    }
    return -1;
}
//SDL_Surface* surface;
//int c=100;

int main(int agr, char* args[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win;
    //SDL_Init(SDL_INIT_EVERYTHING);
    win= SDL_CreateWindow("CASTELVANIA",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1200, 800, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_Rect m,l;
    //int x_pos,y_pos,c=0;
    m.h=100;
    m.w=100;
    m.x=600;
    m.y=400;
    surface = IMG_Load("midia/hero.jpg");
    SDL_Texture* tex= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect bac,alu1,alu2,alu3,bullet,e1;
    bac.h=800;
    bac.w=1200;
    bac.x=0;
    bac.y=0;
    surface=IMG_Load("midia/grass.png");
    SDL_Texture* back=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    alu1.h=128;
    alu1.w=128;
    alu1.x=600;
    alu1.y=800-128;
    surface=IMG_Load("midia/canon.png");
    if (!surface){
 		printf("replay Surface Error: %s\n",IMG_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}
    SDL_Texture* tex1=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    if(!tex1){
 		printf("replayTexture %s\n",SDL_GetError());
 		SDL_DestroyRenderer(rend);
 		SDL_DestroyWindow(win);
 		SDL_Quit();
		return 1;
 	}
    e1.h=50;
    e1.w=50;
    /*SDL_RenderClear(rend);
    SDL_RenderCopy(rend,tex1, NULL,&alu1);
    SDL_RenderPresent(rend);
    SDL_Delay(5000);*/
    int p=0;
    SDL_Event e;
    int q=0;
    int x_pos=600;
        int q4=0,s1=0,f=15;
        while(!q4){
            while(SDL_PollEvent(&e)!=0){
                switch(e.type){
                    case SDL_QUIT:
                        q4= 1;
                        break;
                    case SDL_KEYDOWN:
                        switch(e.key.keysym.sym ){
                            case SDLK_LEFT:
                                x_pos = max(0,x_pos-(300/60));
                                break;
                            case SDLK_RIGHT:
                                x_pos = min(1200-64,x_pos+(300/60));
                                    
                        }
                }
 		}
         if(q4==0){
                alu1.x=x_pos;
            }
            int mousex, mousey;
            int buttons = SDL_GetMouseState(&mousex, &mousey);
            if(buttons&SDL_BUTTON(SDL_BUTTON_LEFT) && f==15){
                //s1=s1%10;
                s1=bulcheck();
                mbc[s1]=1;
                bul_x[s1]=x_pos+54;
                bul_y[s1]=800-128;
                //s1=s1+1;
                f=0;
            }
           // cout<<c<<" ";
            bull();
            for(int i=0;i<5;i++){
                emove(i);
            }
            if(c==100){
                cout<<l1<<endl;
                if(mec[l1]==0){
                    enemy(l1);
                    cout<<"p"<<" "<<l1<<endl;
                    mec[l1]=1;
                    l1=l1+1;
                    l1=l1%5;
                    c=0;
                }
            }
            SDL_RenderClear(rend);
            SDL_RenderCopy(rend, back, NULL, &bac);
            for(int i=0;i<10;i++){
                bullet.h=20;
                bullet.w=20;
                bullet.x=bul_x[i];
                bullet.y=bul_y[i];
                //cout<<bul_y.size()<<" ";
                surface=IMG_Load("midia/1.jpg");
                SDL_Texture* redbul=SDL_CreateTextureFromSurface(rend,surface);
                SDL_FreeSurface(surface);
                SDL_RenderCopy(rend, redbul, NULL, &bullet);


            }
            for(int i=0;i<5;i++){
                e1.x=a[i].x;
                e1.y=a[i].y;
                //cout<<bul_y.size()<<" ";
                surface=IMG_Load("midia/y1.png");
                SDL_Texture* redbul=SDL_CreateTextureFromSurface(rend,surface);
                SDL_FreeSurface(surface);
                SDL_RenderCopy(rend, redbul, NULL, &e1);

            }
            SDL_RenderCopy(rend,tex1, NULL,&alu1);
            int l6,l5,l8=50,f10;
            l6=scar;
            scar1=scar;
            SDL_Rect fuck;
            //cout<<"q"<<" "<<scar<<" "<<scar1<<endl;
            f10=scar;
            for(int i=0;f10>0;i++){
                l5=l6%10;
                l6=l6/10;
                if(l5==1){
                    cout<<"q"<<endl;
                    fuck.h=50;
                    fuck.w=50;
                    fuck.x=1200-l8;
                    fuck.y=0;
                    l8=l8+50;
                    surface= IMG_Load("midia/1.jpg");
                    SDL_Texture* tex9;
                    tex9= SDL_CreateTextureFromSurface(rend,surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(rend,tex9,NULL,&fuck);

                }
                else if(l5==0){
                    fuck.h=50;
                    fuck.w=50;
                    fuck.x=1200-l8;
                    fuck.y=0;
                    l8=l8+50;
                    surface= IMG_Load("midia/0.jpg");
                    SDL_Texture* tex9;
                    tex9= SDL_CreateTextureFromSurface(rend,surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(rend,tex9,NULL,&fuck);

                }
                else if(l5==2){
                    fuck.h=50;
                    fuck.w=50;
                    fuck.x=1200-l8;
                    fuck.y=0;
                    l8=l8+50;
                    surface= IMG_Load("midia/2.jpg");
                    SDL_Texture* tex9;
                    tex9= SDL_CreateTextureFromSurface(rend,surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(rend,tex9,NULL,&fuck);

                }
                else if(l5==3){
                    fuck.h=50;
                    fuck.w=50;
                    fuck.x=1200-l8;
                    fuck.y=0;
                    l8=l8+50;
                    surface= IMG_Load("midia/3.jpg");
                    SDL_Texture* tex9;
                    tex9= SDL_CreateTextureFromSurface(rend,surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(rend,tex9,NULL,&fuck);

                }
                else if(l5==4){
                    fuck.h=50;
                    fuck.w=50;
                    fuck.x=1200-l8;
                    fuck.y=0;
                    l8=l8+50;
                    surface= IMG_Load("midia/4.jpg");
                    SDL_Texture* tex9;
                    tex9= SDL_CreateTextureFromSurface(rend,surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(rend,tex9,NULL,&fuck);

                }
                else if(l5==5){
                    fuck.h=50;
                    fuck.w=50;
                    fuck.x=1200-l8;
                    fuck.y=0;
                    l8=l8+50;
                    surface= IMG_Load("midia/5.jpg");
                    SDL_Texture* tex9;
                    tex9= SDL_CreateTextureFromSurface(rend,surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(rend,tex9,NULL,&fuck);

                }
                else if(l5==6){
                    fuck.h=50;
                    fuck.w=50;
                    fuck.x=1200-l8;
                    fuck.y=0;
                    l8=l8+50;
                    surface= IMG_Load("midia/6.jpg");
                    SDL_Texture* tex9;
                    tex9= SDL_CreateTextureFromSurface(rend,surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(rend,tex9,NULL,&fuck);

                }
                else if(l5==7){
                    fuck.h=50;
                    fuck.w=50;
                    fuck.x=1200-l8;
                    fuck.y=0;
                    l8=l8+50;
                    surface= IMG_Load("midia/7.jpg");
                    SDL_Texture* tex9;
                    tex9= SDL_CreateTextureFromSurface(rend,surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(rend,tex9,NULL,&fuck);

                }
                else if(l5==8){
                    fuck.h=50;
                    fuck.w=50;
                    fuck.x=1200-l8;
                    fuck.y=0;
                    l8=l8+50;
                    surface= IMG_Load("midia/8.jpg");
                    SDL_Texture* tex9;
                    tex9= SDL_CreateTextureFromSurface(rend,surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(rend,tex9,NULL,&fuck);

                }
                else if(l5==9){
                    fuck.h=50;
                    fuck.w=50;
                    fuck.x=1200-l8;
                    fuck.y=0;
                    l8=l8+50;
                    surface= IMG_Load("midia/9.jpg");
                    SDL_Texture* tex9;
                    tex9= SDL_CreateTextureFromSurface(rend,surface);
                    SDL_FreeSurface(surface);
                    SDL_RenderCopy(rend,tex9,NULL,&fuck);

                }
                f10=l6;
                
            }
            scar1=scar;
            //SDL_RenderCopy(rend, back, NULL, &bac);
            //SDL_RenderCopy(rend, back, NULL, &bac);
            SDL_RenderPresent(rend);
            SDL_Delay(1000/60);
            if(f<15){
                f=f+1;
            }

            if(c<100){
                c=c+1;
            }
        c5=c5+1511;
        c5=c5%1000000000;
        if(c<100){
            c=c+1;
        }

 	}
 	SDL_DestroyRenderer(rend);
 	SDL_DestroyWindow(win);

	SDL_Quit();

    return 0;
}

