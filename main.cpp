#include <iostream>
#include <world.h>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
    assert(argc >= 2);

    srand(time(NULL));

    World &w = World::getInstance();
    w.build(argv[1]);

    if (argc >= 3)
    {
        w.renderSceneWithMpi(argc, argv, argv[2]);
    }
    else
    {
        w.renderSceneWithMpi(argc, argv, "output.bmp");
    }
    return 0;
}



