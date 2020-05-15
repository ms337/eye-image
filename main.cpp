#include "./engine/Engine.h"

int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        cerr << "Invalid no. of arguments given" << endl;
        exit(1);
    }
    Engine eng = Engine();
    eng.process(atoi(argv[1]));

    return 0;
}