#include "bMoney_H.h"
#include "Sterling_H.h"

int main()
{


    try
    {
        /*std::cout << "From Sterling to bMoney: \n";
        Sterling st;
        st.put_sterling();
        bMoney mon(st);
        std::cout << mon.get_money();*/

        std::cout << "\nFrom bMoney to Sterling: \n";
        bMoney mn;
        mn.put_money();
        Sterling ste(mn); //= mn;
        ste.display();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what();
    }
}
