#include <Animations.hpp>
#include <SFML/Graphics.hpp>



namespace Moving1
{

    void RandomAnim(int &Num, int &timer)
    {
        if (timer==0)
        {
            Num=rand()%3 + 1;
            timer++;
        }
        else
        {
            timer++;
        }
    };

    void AnimOrr (int &X, int &Y)
    {
        
    };

}



