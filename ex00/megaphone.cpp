
#include <iostream>
#include <cctype>


int main (int argc, char **argv)
{

    if(argc > 1)
    {
        for (int arg = 1; arg < argc; arg++)
        {
            int i = 0;
        
            while(argv[arg][i])
            {
                argv[arg][i] = std::toupper(argv[arg][i]);
                i++;
            }
            std::cout << argv[arg];
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
}
