#include <SFML/Graphics.hpp>
#include <Menu.hpp>
#include <locale>

int main()
{
    sf::RenderWindow window(sf::VideoMode(2560, 1400), "Snake Game v.1.0.1");
    setlocale(LC_ALL, "Russian");
    
    sf::Texture BossAnim;
    BossAnim.loadFromFile("/Users/enil/Desktop/Game/texture/Boss.jpg");
    sf::Texture PlayerModelTexture;
    PlayerModelTexture.loadFromFile("/Users/enil/Desktop/Game/texture/PlayerModelAnimationList.png");
    sf::Texture DashMetr;
    DashMetr.loadFromFile("/Users/enil/Desktop/Game/texture/DashMetr.png");
    sf::Texture Sand;
    Sand.loadFromFile("/Users/enil/Desktop/Game/texture/Sand.jpg");
    sf::Texture Heart;
    Heart.loadFromFile("/Users/enil/Desktop/Game/texture/Hearts.png");
    sf::Texture Aplle;
    Aplle.loadFromFile("/Users/enil/Desktop/Game/texture/Aplle.png");
    sf::Texture Round;
    Round.loadFromFile("/Users/enil/Desktop/Game/texture/KillRound.png");
    sf::Texture Explosion;
    Explosion.loadFromFile("/Users/enil/Desktop/Game/texture/Exp.png");
    
    sf::Font font;
    font.loadFromFile("/Users/enil/Desktop/Game/texture/Cirill.ttf");
    
    sf::Text BashRedy("", font, 44);
    BashRedy.setString("Dash NOT Ready");
    BashRedy.setColor(sf::Color(53, 53, 53));
    BashRedy.setStyle(sf::Text::Bold);
    BashRedy.setPosition(170, 90);
    
    sf::Text ScoreFont("", font, 44);
    ScoreFont.setString("You score:");
    ScoreFont.setColor(sf::Color(255, 161, 19));
    ScoreFont.setStyle(sf::Text::Bold);
    ScoreFont.setPosition(1850, 50);
    
    sf::Text Score("", font, 44);
    Score.setColor(sf::Color(255, 161, 19));
    Score.setStyle(sf::Text::Bold);
    Score.setPosition(2200, 150);
    
    sf::Text End("", font, 130);
    End.setString("YOU DEAD");
    End.setColor(sf::Color::Red);
    End.setStyle(sf::Text::Bold);
    End.setPosition(1000, 400);
    
    
    sf::Sprite Boss;
    Boss.setTexture(BossAnim);
    Boss.setTextureRect(sf::IntRect(279,121,460-279,335-121));
    Boss.setPosition(1200, 50);
    
    sf::Sprite Ex1;
    Ex1.setTexture(Round);
    Ex1.setTextureRect(sf::IntRect(0,0,100,100));
    Ex1.setPosition(-200, -200);
    sf::Sprite Ex2;
    Ex2.setTexture(Round);
    Ex2.setTextureRect(sf::IntRect(0,0,100,100));
    Ex2.setPosition(-200, -200);
    sf::Sprite Ex3;
    Ex3.setTexture(Round);
    Ex3.setTextureRect(sf::IntRect(0,0,100,100));
    Ex3.setPosition(-200, -200);
    sf::Sprite Ex4;
    Ex4.setTexture(Round);
    Ex4.setTextureRect(sf::IntRect(0,0,100,100));
    Ex4.setPosition(-200, -200);
    sf::Sprite Ex5;
    Ex5.setTexture(Round);
    Ex5.setTextureRect(sf::IntRect(0,0,100,100));
    Ex5.setPosition(-200, -200);
    sf::Sprite Ex6;
    Ex6.setTexture(Round);
    Ex6.setTextureRect(sf::IntRect(0,0,100,100));
    Ex6.setPosition(-200, -200);
    
    sf::Sprite PlayerModel;
    PlayerModel.setTexture(PlayerModelTexture);
    PlayerModel.setTextureRect(sf::IntRect(96,272,-96,71));
    PlayerModel.setPosition(50, 350);
    
    sf::Sprite DashM;
    DashM.setTexture(DashMetr);
    DashM.setTextureRect(sf::IntRect(71,81,99,99));
    DashM.setPosition(50, 50);
    
    sf::RectangleShape Ramka;
    Ramka.setSize(sf::Vector2f(2500, 1040));
    Ramka.setFillColor(sf::Color::White);
    Ramka.setPosition(30, 330);
    
    sf::Sprite Pole;
    Pole.setTexture(Sand);
    Pole.setTextureRect(sf::IntRect(0,0,2480,1020));
    Pole.setPosition(40, 340);
    
    sf::Sprite Apple;
    Apple.setTexture(Aplle);
    Apple.setTextureRect(sf::IntRect(0,0,60,60));
    Apple.setPosition(-100, -100);
    
    
    sf::Sprite Heart1;
    Heart1.setTexture(Heart);
    Heart1.setTextureRect(sf::IntRect(0,0,75,64));
    Heart1.setPosition(40, 180);
    sf::Sprite Heart2;
    Heart2.setTexture(Heart);
    Heart2.setTextureRect(sf::IntRect(0,0,75,64));
    Heart2.setPosition(140, 180);
    sf::Sprite Heart3;
    Heart3.setTexture(Heart);
    Heart3.setTextureRect(sf::IntRect(0,0,75,64));
    Heart3.setPosition(240, 180);
    
    //Моделька игрока и его Dash
    float PlayerModelFrame=0; float PlayerX=0, PlayerY=0;
    bool DashFrame=false; float timerOfDash=0; float DashFrameTime=0;
    int PlayerModelFrameCord[6] = {8, 105, 198, 286, 371, 460};
    //Меню ингейм
    int PartTime=0; bool Hearts[3]={true, true, true}; long PScore=0;
    float timerBossAnimation=0; float animationNum=0;
    float BossX=0; float BossY=0;
    //Яблоки
    bool AppOnField = false; float AppX=0, AppY=0;
    //Взрывы
    bool Ex1OnField = false; float Ex1X=100, Ex1Y=367; float Ex1Timer=432; int Ex1Part=0;bool Ex1Wz=false;
    bool Ex2OnField = false; float Ex2X=200, Ex2Y=835; float Ex2Timer=432; int Ex2Part=0;bool Ex2Wz=false;
    bool Ex3OnField = false; float Ex3X=534, Ex3Y=247; float Ex3Timer=432; int Ex3Part=0;bool Ex3Wz=false;
    bool Ex4OnField = false; float Ex4X=153, Ex4Y=666; float Ex4Timer=432; int Ex4Part=0;bool Ex4Wz=false;
    bool Ex5OnField = false; float Ex5X=833, Ex5Y=424; float Ex5Timer=432; int Ex5Part=0;bool Ex5Wz=false;
    bool Ex6OnField = false; float Ex6X=532, Ex6Y=245; float Ex6Timer=432; int Ex6Part=0;bool Ex6Wz=false;
    float ExpNoDMGTimer=0;

    while (window.isOpen())
    {
        
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        //############### Начало двигательного отрезка ###############
        
        timerOfDash+=1;
        Moving::KeyMove(PlayerX, PlayerY, PlayerModelFrame);
        Moving::Dash(PlayerX, PlayerY, DashFrame, timerOfDash);
        Moving::Stena(PlayerX, PlayerY, PlayerModel.getPosition().x, PlayerModel.getPosition().y);
        
        PlayerModel.move(PlayerX, PlayerY);
        
        
        
        if (DashFrame==true) //Работа с фреймами
        {
            if (DashFrameTime>=3)
            {
                DashFrame=false;
                DashFrameTime=0;
            }
            else DashFrameTime+=0.1;
            PlayerModel.setTextureRect(sf::IntRect(8,175,74,85));
            if (PlayerX<0)
            {
                PlayerModel.setTextureRect(sf::IntRect(8,175,74,85));
            }
            else if (PlayerX>0)
            {
                PlayerModel.setTextureRect(sf::IntRect(8+74,175,-74,85));
            }
        }
        else
        {
            if (PlayerX<0)
            {
                PlayerModel.setTextureRect(sf::IntRect(PlayerModelFrameCord[ int(PlayerModelFrame)],272,85,71));
            }
            else if (PlayerX>0)
            {
                PlayerModel.setTextureRect(sf::IntRect(PlayerModelFrameCord[ int(PlayerModelFrame)]+85,272,-85,71));
            }
            else
            {
                if (PlayerY<0)
                {
                    PlayerModel.setTextureRect(sf::IntRect(PlayerModelFrameCord[ int(PlayerModelFrame)],272,85,71));
                }
                if (PlayerY>0)
                {
                    PlayerModel.setTextureRect(sf::IntRect(PlayerModelFrameCord[ int(PlayerModelFrame)]+85,272,-85,71));
                }
            }
        }
        //############### Конец двигательного отрезка ###############
        
        //############### Начало отрезка меню  ###############
        
        if (DashFrame==true) // Инфа по Dash
        {
            DashM.setTextureRect(sf::IntRect(71,81,99,99));
            PartTime=0;
            
            BashRedy.setString("Dash NOT Ready");
            BashRedy.setColor(sf::Color(53, 53, 53));
        }
        else
        {
            Menu::DashMenu(timerOfDash, PartTime);
            
            DashM.setTextureRect(sf::IntRect(71+((PartTime%6)*152),81+((PartTime/6)*137),99,99));
            
            if (timerOfDash>=1200)
            {
                BashRedy.setString("Dash Ready");
                BashRedy.setColor(sf::Color(255, 161, 19));
            }
        }
        
        if (Hearts[0]==true) Heart1.setTextureRect(sf::IntRect(0,0,75,64));
        else Heart1.setTextureRect(sf::IntRect(80,0,75,64));
        if (Hearts[1]==true) Heart2.setTextureRect(sf::IntRect(0,0,75,64));
        else Heart2.setTextureRect(sf::IntRect(80,0,75,64));
        if (Hearts[2]==true) Heart3.setTextureRect(sf::IntRect(0,0,75,64));
        else Heart3.setTextureRect(sf::IntRect(80,0,75,64));
        
        Menu::BossAnimation(timerBossAnimation, animationNum);//Анимации думгая
        
        if (animationNum==1)
        {
            if ((timerBossAnimation>=0)&&(timerBossAnimation<25)) Boss.setTextureRect(sf::IntRect(92,121,181,214));
            if ((timerBossAnimation>=25)&&(timerBossAnimation<50)) Boss.setTextureRect(sf::IntRect(466,121,181,214));
            if ((timerBossAnimation>=50)&&(timerBossAnimation<75)) Boss.setTextureRect(sf::IntRect(92,121,181,214));
            if ((timerBossAnimation>=75)&&(timerBossAnimation<100)) Boss.setTextureRect(sf::IntRect(466,121,181,214));
        }
        
        if (animationNum==2)
        {
            if ((timerBossAnimation>=0)&&(timerBossAnimation<75)) Boss.setTextureRect(sf::IntRect(279,121,460-279,335-121));
            if ((timerBossAnimation>=75)&&(timerBossAnimation<150)) Boss.setTextureRect(sf::IntRect(466,343,181,214));
            if ((timerBossAnimation>=150)&&(timerBossAnimation<290)&&(int(timerBossAnimation)%40>20))
            {
                Boss.setTextureRect(sf::IntRect(279,568,181,214));
                if (int(timerBossAnimation)%40==1) Boss.move(-10, 0);
            }
            if ((timerBossAnimation>=150)&&(timerBossAnimation<290)&&(int(timerBossAnimation)%40<=20))
            {
                Boss.setTextureRect(sf::IntRect(279,568,181,214));
                if (int(timerBossAnimation)%40==21) Boss.move(10, 0);
            }
            if ((timerBossAnimation>=290)&&(timerBossAnimation<300)&&(int(timerBossAnimation)%40<=20))
            {
                Boss.setTextureRect(sf::IntRect(279,121,181,214));
                Boss.setPosition(1200, 50);
            }
        }
        
        if (animationNum==3)
        {
            if ((timerBossAnimation>=0)&&(timerBossAnimation<100)) Boss.setTextureRect(sf::IntRect(279,121,460-279,335-121));
            if ((timerBossAnimation>=100)&&(timerBossAnimation<200)) Boss.setTextureRect(sf::IntRect(279,343,181,214));
        }
        
        if (animationNum==4)
        {
            if ((timerBossAnimation>=0)&&(timerBossAnimation<400)) Boss.setTextureRect(sf::IntRect(279,121,460-279,335-121));
            
        }
        
        Score.setString(std::to_string(PScore)); // Отображение счета (1 строка)
        
        //############### Конец отрезка меню  ###############
        
        //############### Начало отрезка размещения яблок и взрывов и взаимодействия  ###############
        
        if (AppOnField==false) //Яблоки
        {
            Hitboxy::RandApp(AppX, AppY, AppOnField);
            Apple.setPosition(AppX, AppY);
        }
        else
        {
            Hitboxy::AppiZmei(Apple.getPosition().x, Apple.getPosition().y, PlayerModel.getPosition().x, PlayerModel.getPosition().y, AppOnField);
            if (AppOnField==false)
            {
                PScore++;
                Apple.setPosition(-100, -100);
            }
        }
        
        //Взрывы
        
        if (ExpNoDMGTimer!=0) ExpNoDMGTimer--;
        
        Ex1Timer++;
        if (Ex1OnField==false)
        {
            Hitboxy::RandExp(Ex1X, Ex1Y, Ex1OnField);
            Ex1.setPosition(Ex1X, Ex1Y);
            Ex1Timer=0;
        }
        else
        {
            if ((Ex1Timer!=432)&&(Ex1Timer>324))
            {
                Ex1.setTexture(Explosion);
                Hitboxy::ExpAnim(Ex1Timer, Ex1Part);
                Ex1.setTextureRect(sf::IntRect(0+(100*(Ex1Part%9)),0,100,100));
                
                Hitboxy::ExpiZmei(Ex1.getPosition().x, Ex1.getPosition().y, PlayerModel.getPosition().x, PlayerModel.getPosition().y, Ex1Wz);
                if (Ex1Wz==true)
                {
                    if ((Hearts[0]==true)&&(Hearts[1]==false)&&(ExpNoDMGTimer==0)) Hearts[0]=false;
                    if ((Hearts[1]==true)&&(Hearts[2]==false)&&(ExpNoDMGTimer==0)) Hearts[1]=false;
                    if ((Hearts[2]==true)&&(ExpNoDMGTimer==0)) Hearts[2]=false;
                    ExpNoDMGTimer=40; Ex1Wz=false;
                }
                
                if (Ex1Timer==432)
                {
                    Ex1.setTexture(Round);
                    Ex1.setTextureRect(sf::IntRect(0,0,100,100));
                    Ex1.setPosition(Ex1X, Ex1Y);
                    Ex1OnField=false;
                }
            }
            
        }
        
    
        
        
        Ex2Timer++;
        if (Ex2OnField==false)
        {
            Hitboxy::RandExp(Ex2X, Ex2Y, Ex2OnField);
            Ex2.setPosition(Ex2X, Ex2Y);
            Ex2Timer=0;
        }
        else
        {
            if ((Ex2Timer!=432)&&(Ex2Timer>324))
            {
                Ex2.setTexture(Explosion);
                Hitboxy::ExpAnim(Ex2Timer, Ex2Part);
                Ex2.setTextureRect(sf::IntRect(0+(100*(Ex2Part%9)),0,100,100));
                
                Hitboxy::ExpiZmei(Ex2.getPosition().x, Ex2.getPosition().y, PlayerModel.getPosition().x, PlayerModel.getPosition().y, Ex2Wz);
                if (Ex2Wz==true)
                {
                    if ((Hearts[0]==true)&&(Hearts[1]==false)&&(ExpNoDMGTimer==0)) Hearts[0]=false;
                    if ((Hearts[1]==true)&&(Hearts[2]==false)&&(ExpNoDMGTimer==0)) Hearts[1]=false;
                    if ((Hearts[2]==true)&&(ExpNoDMGTimer==0)) Hearts[2]=false;
                    ExpNoDMGTimer=40; Ex2Wz=false;
                }
                
                if (Ex2Timer==432)
                {
                    Ex2.setTexture(Round);
                    Ex2.setTextureRect(sf::IntRect(0,0,100,100));
                    Ex2.setPosition(Ex2X, Ex2Y);
                    Ex2OnField=false;
                }
            }
            
        }
        
        
        
        Ex3Timer++;
        if (Ex3OnField==false)
        {
            Hitboxy::RandExp(Ex3X, Ex3Y, Ex3OnField);
            Ex3.setPosition(Ex3X, Ex3Y);
            Ex3Timer=0;
        }
        else
        {
            if ((Ex3Timer!=432)&&(Ex3Timer>324))
            {
                Ex3.setTexture(Explosion);
                Hitboxy::ExpAnim(Ex3Timer, Ex3Part);
                Ex3.setTextureRect(sf::IntRect(0+(100*(Ex3Part%9)),0,100,100));
                
                Hitboxy::ExpiZmei(Ex3.getPosition().x, Ex3.getPosition().y, PlayerModel.getPosition().x, PlayerModel.getPosition().y, Ex3Wz);
                if (Ex3Wz==true)
                {
                    if ((Hearts[0]==true)&&(Hearts[1]==false)&&(ExpNoDMGTimer==0)) Hearts[0]=false;
                    if ((Hearts[1]==true)&&(Hearts[2]==false)&&(ExpNoDMGTimer==0)) Hearts[1]=false;
                    if ((Hearts[2]==true)&&(ExpNoDMGTimer==0)) Hearts[2]=false;
                    ExpNoDMGTimer=40; Ex3Wz=false;
                }
                
                if (Ex3Timer==432)
                {
                    Ex3.setTexture(Round);
                    Ex3.setTextureRect(sf::IntRect(0,0,100,100));
                    Ex3.setPosition(Ex3X, Ex3Y);
                    Ex3OnField=false;
                }
            }
            
        }
        
        Ex4Timer++;
        if (Ex4OnField==false)
        {
            Hitboxy::RandExp(Ex4X, Ex4Y, Ex4OnField);
            Ex4.setPosition(Ex4X, Ex4Y);
            Ex4Timer=0;
        }
        else
        {
            if ((Ex4Timer!=432)&&(Ex4Timer>324))
            {
                Ex4.setTexture(Explosion);
                Hitboxy::ExpAnim(Ex4Timer, Ex4Part);
                Ex4.setTextureRect(sf::IntRect(0+(100*(Ex4Part%9)),0,100,100));
                
                Hitboxy::ExpiZmei(Ex4.getPosition().x, Ex4.getPosition().y, PlayerModel.getPosition().x, PlayerModel.getPosition().y, Ex4Wz);
                if (Ex4Wz==true)
                {
                    if ((Hearts[0]==true)&&(Hearts[1]==false)&&(ExpNoDMGTimer==0)) Hearts[0]=false;
                    if ((Hearts[1]==true)&&(Hearts[2]==false)&&(ExpNoDMGTimer==0)) Hearts[1]=false;
                    if ((Hearts[2]==true)&&(ExpNoDMGTimer==0)) Hearts[2]=false;
                    ExpNoDMGTimer=40; Ex4Wz=false;
                }
                
                if (Ex4Timer==432)
                {
                    Ex4.setTexture(Round);
                    Ex4.setTextureRect(sf::IntRect(0,0,100,100));
                    Ex4.setPosition(Ex4X, Ex4Y);
                    Ex4OnField=false;
                }
            }
            
        }
        
        Ex5Timer++;
        if (Ex5OnField==false)
        {
            Hitboxy::RandExp(Ex5X, Ex5Y, Ex5OnField);
            Ex5.setPosition(Ex5X, Ex5Y);
            Ex5Timer=0;
        }
        else
        {
            if ((Ex5Timer!=432)&&(Ex5Timer>324))
            {
                Ex5.setTexture(Explosion);
                Hitboxy::ExpAnim(Ex5Timer, Ex5Part);
                Ex5.setTextureRect(sf::IntRect(0+(100*(Ex5Part%9)),0,100,100));
                
                Hitboxy::ExpiZmei(Ex5.getPosition().x, Ex5.getPosition().y, PlayerModel.getPosition().x, PlayerModel.getPosition().y, Ex5Wz);
                if (Ex5Wz==true)
                {
                    if ((Hearts[0]==true)&&(Hearts[1]==false)&&(ExpNoDMGTimer==0)) Hearts[0]=false;
                    if ((Hearts[1]==true)&&(Hearts[2]==false)&&(ExpNoDMGTimer==0)) Hearts[1]=false;
                    if ((Hearts[2]==true)&&(ExpNoDMGTimer==0)) Hearts[2]=false;
                    ExpNoDMGTimer=40; Ex5Wz=false;
                }
                
                if (Ex5Timer==432)
                {
                    Ex5.setTexture(Round);
                    Ex5.setTextureRect(sf::IntRect(0,0,100,100));
                    Ex5.setPosition(Ex5X, Ex5Y);
                    Ex5OnField=false;
                }
            }
            
        }
        
        Ex6Timer++;
        if (Ex6OnField==false)
        {
            Hitboxy::RandExp(Ex6X, Ex6Y, Ex6OnField);
            Ex6.setPosition(Ex6X, Ex6Y);
            Ex6Timer=0;
        }
        else
        {
            if ((Ex6Timer!=432)&&(Ex6Timer>324))
            {
                Ex6.setTexture(Explosion);
                Hitboxy::ExpAnim(Ex6Timer, Ex6Part);
                Ex6.setTextureRect(sf::IntRect(0+(100*(Ex6Part%9)),0,100,100));
                
                Hitboxy::ExpiZmei(Ex6.getPosition().x, Ex6.getPosition().y, PlayerModel.getPosition().x, PlayerModel.getPosition().y, Ex6Wz);
                if (Ex6Wz==true)
                {
                    if ((Hearts[0]==true)&&(Hearts[1]==false)&&(ExpNoDMGTimer==0)) Hearts[0]=false;
                    if ((Hearts[1]==true)&&(Hearts[2]==false)&&(ExpNoDMGTimer==0)) Hearts[1]=false;
                    if ((Hearts[2]==true)&&(ExpNoDMGTimer==0)) Hearts[2]=false;
                    ExpNoDMGTimer=40; Ex6Wz=false;
                }
                
                if (Ex6Timer==432)
                {
                    Ex6.setTexture(Round);
                    Ex6.setTextureRect(sf::IntRect(0,0,100,100));
                    Ex6.setPosition(Ex6X, Ex6Y);
                    Ex6OnField=false;
                }
            }
            
        }
        
        
        //############### Конец отрезка размещения яблок и взрывов и взаимодействия  ###############
        
        if ((Hearts[0]!=true)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)))
        {
            Hearts[0]=true;
            Hearts[1]=true;
            Hearts[2]=true;
        }
        
        if (Hearts[0]==true)
        {
            window.clear();
            window.draw(Ramka);
            window.draw(Pole);
            window.draw(DashM);
            window.draw(PlayerModel);
            window.draw(BashRedy); window.draw(ScoreFont); window.draw(Score);
            window.draw(Heart1); window.draw(Heart2); window.draw(Heart3);
            window.draw(Boss);
            window.draw(Ex1); window.draw(Ex2); window.draw(Ex3);
            window.draw(Ex4); window.draw(Ex5); window.draw(Ex6);
            window.draw(Apple);
        }
        else
        {
            window.clear();
            window.draw(End);
        }
        
        window.display();
    }

    return 0;
}
