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

int c5=0,l1=0,f1=0,c=100,r1=0,scar=0,scar1=0,life=5,q4=2;
point a[5],ebul[10],ebul1[10];
map<int,int>mbc,mec,mebul,mebul1;
int bul_x[10],bul_y[10];
int l=0,s=0;

//int m3;
void bull(){
    for(int i=0;i<10;i++){
        if(mbc[i]==1){
            bul_y[i]=bul_y[i]-10;
            if(bul_y[i]<-10){
                mbc[i]=0;

            }
            else{
                for(int j=0;j<5;j++){
                    if(bul_x[i]>=a[j].x-10&&bul_x[i]<=a[j].x+50&&bul_y[i]<=a[j].y+40){
                        bul_x[i]=1500;
                        a[j].x=1500;
                        scar=scar+5;
                        mec[j]=0;
                        mbc[i]=0;
                    }
    }
            }
        }
    }
}
void enemy(int s){
    a[s].x=c5%1100+50;
    a[s].y=0;
}
int ce=0;
point dhal(int x3, int y3, int x1, int y1){
    point p;
    float q1,q7,x,y;
    x=x3;
    y=y3;
    if(x1!=x){
            q1=(y-y1)/(x-x1);
            q1=sqrt(1+pow(q1,2));
            q1=1/q1;
            //p.x=3*q1;
            q7=q1;
            q1=sqrt(1-pow(q1,2));
            //cout<<"q1"<<" "<<q1<<endl;
            p.y=3*q1;
            //cout<<p.y<<" "<<x<<" "<<y<<endl;
            p.x=3*q7;
            if(x<x1){
                p.x=p.x*-1;
            }
    }
    else{
        p.x=0;
        p.y=3;
    }
    return p;
}
void ebulcreate(int i1,int x,int y){
    for(int i=0;i<10;i++){
        if(mebul[i]==0){
            mebul[i]=1;
            ebul[i].x=a[i1].x;
            ebul[i].y=a[i1].y+50;
            //cout<<x<<" "<<y<<endl;
            ebul1[i]= dhal(x,y,ebul[i].x,ebul[i].y);
            //cout<<ebul[i].x<<endl;
            break;
        }
    }
}


void ebulmove(int x_pos){
    for(int i=0;i<10;i++){
        if(mebul[i]==1){
            ebul[i].x=ebul[i].x+ebul1[i].x;
            //cout<<"Y!"<<ebul1[i].y<<endl;
            float m70=ebul1[i].y;
            if(m70<0){
                m70=m70*-1;
            }
            //cout<<"M";
            //cout<<m70<<endl;
            ebul[i].y=ebul[i].y+m70;
            //cout<<"y2"<<ebul[i].y<<endl;
            for(int j=0;j<10;j++){
                    if(ebul[i].x>=x_pos-64&&ebul[i].x<=x_pos+128&&ebul[i].y>800-128-15){
                        ebul[i].x=1500;
                        //a[j].x=1500;
                        //scar=scar+7;
                        //mec[j]=0;
                        //mbc[i]=0;
                        mebul[i]=0;
                        mebul1[i]=0;
                        life=life-1;
                        if(life==0){
                            q4=3;
                        }
                    }
            }
            if(ebul[i].y>=800){
                mebul[i]=0;
            }
        }
    }
}
void emove(int i1,int x,int y){
    //a[i1].y=a[i1].y+2;
    if(mec[i1]==1){
        a[i1].y=a[i1].y+1;
        mebul1[i1]=mebul1[i1]+1;
        if(mebul1[i1]==180){
            ebulcreate(i1,x,y);
        }
        mebul1[i1]=mebul1[i1]%180;
        if(a[i1].y>800){
        //f1=0;
            mec[i1]=0;
            mebul1[i1]=0;
            //r1=r1-1;
            life=life-1;
            cout<<life<<endl;
            if(life==0){
                q4=3;
            }
        }
    }
    //cout<<r1<<" ";
    
}
int bulcheck(){
    for(int i=0;i<10;i++){
        if(mbc[i]==0){
            //cout<<i<<endl;
            return i;
        }
    }
    return -1;
}
void init34(){
    for(int i=0;i<10;i++){
        mbc[i]=0;
        mebul[i]=0;
        mebul1[i]=0;
        mec[i]=0;
    }
    
}
//SDL_Surface* surface;
//int c=100;

int main(int agr, char* args[]){
    SDL_Init(SDL_INIT_EVERYTHING);

	if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0){
		printf("video and timer: %s\n",SDL_GetError());
	}
	if (!(IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG)))
		printf("image: %s\n",SDL_GetError());

    SDL_Window* win;
    //SDL_Init(SDL_INIT_EVERYTHING);
    win= SDL_CreateWindow("CASTELVANIA",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 1200, 800, 0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_Rect m,l,nw,lf;
    //int x_pos,y_pos,c=0;
    m.h=100;
    m.w=100;
    m.x=600;
    m.y=400;
    surface = IMG_Load("midia/hero.jpg");
    SDL_Texture* tex= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    lf.h=30;
    lf.w=30;
    lf.y=0;
    surface=IMG_Load("midia/life.jpg");
    SDL_Texture* life23=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    SDL_Rect bac,alu1,alu2,alu3,bullet,e1,e2;
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
    SDL_Texture* tex100=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    if(!tex100){
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
    int s1=0,f=15;
    int l6,l5,l8=50,f10;
    SDL_Rect fuck,nw1,reply;
    
    surface=IMG_Load("midia/gola.png");
    if (!surface){
        printf("replay Surface Error: %s\n",IMG_GetError());
        SDL_DestroyRenderer(rend);
         SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
        }
    SDL_Texture* redbul=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface=IMG_Load("midia/y1.png");
    if (!surface){
        printf("replay Surface Error: %s\n",IMG_GetError());
        SDL_DestroyRenderer(rend);
         SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
        }
    SDL_Texture* redbul1=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface= IMG_Load("midia/1.jpg");
    SDL_Texture* tex1;
    tex1= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface= IMG_Load("midia/0.jpg");
    SDL_Texture* tex0;
    tex0= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface= IMG_Load("midia/2.jpg");
    SDL_Texture* tex2;
    tex2= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface= IMG_Load("midia/3.jpg");
    SDL_Texture* tex3;
    tex3= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface= IMG_Load("midia/4.jpg");
    SDL_Texture* tex4;
    tex4= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface= IMG_Load("midia/5.jpg");
    SDL_Texture* tex5;
    tex5= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface= IMG_Load("midia/6.jpg");
    SDL_Texture* tex6;
    tex6= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface= IMG_Load("midia/7.jpg");
    SDL_Texture* tex7;
    tex7= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface= IMG_Load("midia/8.jpg");
    SDL_Texture* tex8;
    tex8= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface= IMG_Load("midia/9.jpg");
    SDL_Texture* tex9;
    tex9= SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface=IMG_Load("midia/nw.jpeg");
    SDL_Texture* newgame=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface=IMG_Load("midia/gameover.jpg");
    SDL_Texture* newgame1=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    surface=IMG_Load("midia/conti.jpg");
    SDL_Texture* reply10=SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);
    int mousex, mousey,lfe=0;
        while(q4!=1){
            /*while(SDL_PollEvent(&e)!=0){
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
                                break;
                            case SDLK_SPACE:
                                s1=bulcheck();
                                mbc[s1]=1;
                                bul_x[s1]=x_pos+54;
                                bul_y[s1]=800-128;
                                //s1=s1+1;
                                f=0;
                                break;
                                    
                        }
                }
 		}*/
         if(q4==0){
                while(SDL_PollEvent(&e)!=0){
                    switch(e.type){
                        case SDL_QUIT:
                            q4= 1;
                            break;
                        case SDL_KEYDOWN:
                            switch(e.key.keysym.sym ){
                                case SDLK_LEFT:
                                    x_pos = max(0,x_pos-(500/60));
                                    break;
                                case SDLK_RIGHT:
                                    x_pos = min(1200-64,x_pos+(500/60));
                                        
                            }
                    }
 		}
                alu1.x=x_pos;
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
                    ebulmove(x_pos);
                    for(int i=0;i<5;i++){
                        emove(i,alu1.x+64,800-128);
                    }
                    if(c==100){
                        //cout<<l1<<endl;
                        if(mec[l1]==0){
                            enemy(l1);
                            //cout<<l1<<endl;
                            //cout<<"p"<<" "<<l1<<endl;
                            mec[l1]=1;
                            l1=l1+1;
                            l1=l1%5;
                            c=0;
                        }
                    }
                    SDL_RenderClear(rend);
                    SDL_RenderCopy(rend, back, NULL, &bac);
                    for(int i=0;i<10;i++){
                        if(mbc[i]==1){
                            bullet.h=20;
                            bullet.w=20;
                            bullet.x=bul_x[i];
                            bullet.y=bul_y[i];
                            //cout<<bul_y.size()<<" ";
                            SDL_RenderCopy(rend, redbul, NULL, &bullet);
                            }
                    }
                    for(int i=0;i<5;i++){
                        if(mec[i]==1){
                            e1.x=a[i].x;
                            e1.y=a[i].y;
                            //cout<<"p"<<" ";
                            SDL_RenderCopy(rend, redbul1, NULL, &e1);

                            }
                    }
                    for(int i=0;i<10;i++){
                        if(mebul[i]==1){
                            e2.w=20;
                            e2.h=20;
                            e2.x=ebul[i].x;
                            e2.y=ebul[i].y;
                            SDL_RenderCopy(rend,redbul1,NULL,&e2);
                        }
                    }
                    //lf.x=0;
                    for(int i=0;i<life;i++){
                        lf.x=lfe;
                        lfe=lfe+30;
                        SDL_RenderCopy(rend,life23,NULL,&lf);
                    }
                    lfe=0;
                    SDL_RenderCopy(rend,tex100, NULL,&alu1);
                    l8=50;
                    l6=scar;
                    scar1=scar;
                    //SDL_Rect fuck;
                    //cout<<"q"<<" "<<scar<<" "<<scar1<<endl;
                    f10=scar;
                    for(int i=0;f10>0;i++){
                        l5=l6%10;
                        l6=l6/10;
                        if(l5==1){
                            //cout<<"q"<<endl;
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=1200-l8;
                            fuck.y=0;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex1,NULL,&fuck);

                        }
                        else if(l5==0){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=1200-l8;
                            fuck.y=0;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex0,NULL,&fuck);

                        }
                        else if(l5==2){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=1200-l8;
                            fuck.y=0;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex2,NULL,&fuck);

                        }
                        else if(l5==3){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=1200-l8;
                            fuck.y=0;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex3,NULL,&fuck);

                        }
                        else if(l5==4){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=1200-l8;
                            fuck.y=0;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex4,NULL,&fuck);

                        }
                        else if(l5==5){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=1200-l8;
                            fuck.y=0;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex5,NULL,&fuck);

                        }
                        else if(l5==6){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=1200-l8;
                            fuck.y=0;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex6,NULL,&fuck);

                        }
                        else if(l5==7){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=1200-l8;
                            fuck.y=0;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex7,NULL,&fuck);

                        }
                        else if(l5==8){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=1200-l8;
                            fuck.y=0;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex8,NULL,&fuck);

                        }
                        else if(l5==9){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=1200-l8;
                            fuck.y=0;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex9,NULL,&fuck);

                        }
                        f10=l6;
                        
                    }
                    scar1=scar;
                    //SDL_RenderCopy(rend, back, NULL, &bac);
                    //SDL_RenderCopy(rend, back, NULL, &bac);
                    SDL_RenderPresent(rend);
                    //SDL_RenderClear(rend);
                    SDL_Delay(1000/60);
                    if(f<15){
                        f=f+1;
                    }

                    if(c<100){
                        c=c+1;
                    }
                c5=c5+1511;
                c5=c5%1000000000;
            }
            else if(q4==2){
                SDL_RenderClear(rend);
                SDL_RenderCopy(rend, back, NULL, &bac);
                //SDL_Rect nw;
                nw.h=100;
                nw.w=300;
                nw.x=100;
                nw.y=100;
                
                SDL_RenderCopy(rend,newgame,NULL,&nw);
                /*nw.y=100+64+30;
                surface=IMG_Load("midia/2.jpg");
                SDL_Texture* */
                SDL_RenderPresent(rend);
                SDL_Delay(100/60);
                //int mousex, mousey;
                int buttons = SDL_GetMouseState(&mousex, &mousey);
                //printf("%d %d\n",mousex,mousey);

                if(buttons & SDL_BUTTON(SDL_BUTTON_LEFT)){
                    //printf("%d %d\n",mousex,mousey);
                    if(mousex>=nw.x && mousex<=(nw.x+nw.w) && mousey>=nw.y && mousey<=(nw.y+nw.h)){
                        q4=0;
                    }
                }
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT){
                        q4=1;
                    }
                }
            }
            else if(q4==3){
                SDL_RenderClear(rend);
                SDL_RenderCopy(rend, back, NULL, &bac);
                //SDL_Rect nw,reply;
                nw1.h=100;
                nw1.w=400;
                nw1.x=400;
                nw1.y=300;
                SDL_RenderCopy(rend,newgame1,NULL,&nw1);
                reply.h=64;
                reply.w=300;
                reply.x=450;
                reply.y=300+100+50;
                SDL_RenderCopy(rend,reply10,NULL,&reply);
                   int l6,l5,l8=50,f10;
                    l6=scar;
                    scar1=scar;
                    //SDL_Rect fuck;
                    //cout<<"q"<<" "<<scar<<" "<<scar1<<endl;
                    f10=scar;
                    for(int i=0;f10>0;i++){
                        l5=l6%10;
                        l6=l6/10;
                        if(l5==1){
                            cout<<"q"<<endl;
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=800-l8;
                            fuck.y=300-60;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex1,NULL,&fuck);

                        }
                        else if(l5==0){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=800-l8;
                            fuck.y=300-60;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex0,NULL,&fuck);

                        }
                        else if(l5==2){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=800-l8;
                            fuck.y=300-60;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex2,NULL,&fuck);

                        }
                        else if(l5==3){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=800-l8;
                            fuck.y=300-60;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex3,NULL,&fuck);

                        }
                        else if(l5==4){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=800-l8;
                            fuck.y=300-60;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex4,NULL,&fuck);

                        }
                        else if(l5==5){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=800-l8;
                            fuck.y=300-60;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex5,NULL,&fuck);

                        }
                        else if(l5==6){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=800-l8;
                            fuck.y=300-60;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex6,NULL,&fuck);

                        }
                        else if(l5==7){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=800-l8;
                            fuck.y=300-60;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex7,NULL,&fuck);

                        }
                        else if(l5==8){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=800-l8;
                            fuck.y=300-60;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex8,NULL,&fuck);

                        }
                        else if(l5==9){
                            fuck.h=50;
                            fuck.w=50;
                            fuck.x=800-l8;
                            fuck.y=300-60;
                            l8=l8+50;
                            SDL_RenderCopy(rend,tex9,NULL,&fuck);

                        }
                        f10=l6;
                        
                    }
                    //scar=0;
                SDL_RenderPresent(rend);
                SDL_Delay(100/60);
                int mousex, mousey;
                int buttons = SDL_GetMouseState(&mousex, &mousey);
                //printf("%d %d\n",mousex,mousey);

                if(buttons & SDL_BUTTON(SDL_BUTTON_LEFT)){
                    //printf("%d %d\n",mousex,mousey);
                    if(mousex>=reply.x && mousex<=(reply.x+reply.w) && mousey>=reply.y && mousey<=(reply.y+reply.h)){
                        q4=0;
                        life=5;
                        scar=0;
                        init34();
                        x_pos=600;
                        for(int i=0;i<10;i++){
                            mbc[i]=0;
                        }
                        for(int i=0;i<5;i++){
                            mec[i]=0;
                        }
                    }
                }
                while(SDL_PollEvent(&e)!=0){
                    if(e.type==SDL_QUIT){
                        q4=1;
                    }
                }

            }
 	}
 	SDL_DestroyRenderer(rend);
 	SDL_DestroyWindow(win);

	SDL_Quit();

    return 0;
}