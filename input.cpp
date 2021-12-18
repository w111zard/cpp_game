#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

#include "input.hpp"

struct termios oldt, newt;

void input_setup()
{
    fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );

}

void input_restore()
{
    fcntl(0, F_SETFL, fcntl(0, F_GETFL) & ~O_NONBLOCK);
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
}

int get_key()
{
    int key = getchar();

    if (key == 27)
    {
        key = getchar();
        if (key == 91)
        {
            key = getchar();
        }
    }

    // 0.5 sec
    usleep(100000);

    return key;
}

