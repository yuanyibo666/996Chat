#include"server.h"

int main()
{
    initServer();
    while(1)
    {
        acceptFunction();
    }
    
}