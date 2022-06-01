#pragma once
#include <SFML/Graphics.hpp>

namespace Moving
{
    
    void KeyMove(float &x, float &y, float &frame);

    void Dash (float &x, float &y, bool &frame, float &timer);

    void Stena (float &x, float &y, float X, float Y);

}

namespace Menu
{

    void DashMenu (float timer, int &PartTime);

    void BossAnimation (float &timer, float &NumofAn);

}

namespace Hitboxy
{
    void RandApp (float &x, float &y, bool &OnFild);

    void RandExp (float &x, float &y, bool &OnFild);

    void AppiZmei(float AppX, float AppY, float ZmX, float ZmY, bool&OnFild);

    void ExpiZmei(float AppX, float AppY, float ZmX, float ZmY, bool&OnFild);

    void ExpAnim (float &timer, int &PartTime);
}


