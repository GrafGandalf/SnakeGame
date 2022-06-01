#include <Menu.hpp>
#include <SFML/Graphics.hpp>



namespace Moving
{

    void KeyMove (float &x, float &y, float &frame)
    {
        float X=0, Y=0;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
        {
            X-=3; Y+=0;
            
            frame+=0.05;
            if (frame>6) frame=0;
            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            X+=3; Y+=0;
            
            frame+=0.05;
            if (frame>6) frame=0;
            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            X+=0; Y-=3;
            
            frame+=0.05;
            if (frame>6) frame=0;
            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            X+=0; Y+=3;
            
            frame+=0.05;
            if (frame>6) frame=0;
            
        }
        
        x=X; y=Y;
    };


    void Dash (float &x, float &y, bool &frame, float &timer)
    {
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (timer>=1200))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                x-=200;
                frame=true;
                timer=0;
            }
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                x+=200;
                frame=true;
                timer=0;
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                y-=200;
                frame=true;
                timer=0;
            }
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                y+=200;
                frame=true;
                timer=0;
            }
        }
    
    };

    void Stena (float &x, float &y, float X, float Y)
    {
        if (X+x>=2520-96+10) x=2519-X-96+10;
        if (X+x<=40) x=41-X;
        
        if (Y+y>=1400-71-40) y=1359-Y-71;
        if (Y+y<=340) y=341-Y;
        
    };


}


namespace Menu
{
    void DashMenu (float timer, int &PartTime)
    {
        if (timer<1200) PartTime=timer/100;
    };

    void BossAnimation (float &timer, float &NumofAn)
    {
        if (NumofAn==0) NumofAn = rand()%4+1;
        if (timer==0)
        {
            timer++; NumofAn = rand()%4+1;
        }
        timer++;
        if ((NumofAn==1)&&(timer>100))
        {
            timer=0;
        }
        if ((NumofAn==2)&&(timer>300))
        {
            timer=0;
        }
        if ((NumofAn==3)&&(timer>200))
        {
            timer=0;
        }
        if ((NumofAn==4)&&(timer>400))
        {
            timer=0;
        }
    };

}

namespace Hitboxy
{
    void RandApp (float &x, float &y, bool &OnFild)
    {
        OnFild=true;
        x=rand()%2400 + 100;
        y=rand()%800 + 340;
    };

    void RandExp (float &x, float &y, bool &OnFild)
    {
        OnFild=true;
        x=rand()%2300 + 200;
        y=rand()%750 + 380;
    };

    void AppiZmei(float AppX, float AppY, float ZmX, float ZmY, bool&OnFild)
    {
        bool os=false;
        for (int i=AppX; i<AppX+60; i++)
        {
            if ((i>=ZmX)&&(ZmX+80>=i)) os = true;
        }
        for (int i=AppY; i<AppY+60; i++)
        {
            if ((i>=ZmY)&&(ZmY+80>=i)&&(os==true)) OnFild=false;
        }
        
    };

    void ExpiZmei(float AppX, float AppY, float ZmX, float ZmY, bool&OnFild)
    {
        bool os=true;
        for (int i=AppX; i<AppX+100; i++)
        {
            if ((i>=ZmX)&&(ZmX+60>=i)) os = false;
        }
        for (int i=AppY; i<AppY+100; i++)
        {
            if ((i>=ZmY)&&(ZmY+80>=i)&&(os==false)) OnFild=true;
        }
        
    };

    void ExpAnim (float &timer, int &PartTime)
    {
        if ((timer!=432)&&(timer>324))
        {
            PartTime=timer/4;
            timer++;
        }
    };

}

