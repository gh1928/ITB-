#include <SFML/Graphics.hpp>
#include "Framework/Framework.h"
#include "Framework/Utils.h"
#include "Framework/Const.h"


int main()
{
    FRAMEWORK->Init(WINDOW_WIDTH, WINDOW_HEIGHT);
    FRAMEWORK->Do();
    return 0;
}