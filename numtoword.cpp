#define P_OK 0
#define P_ERR_ARG -5
#define P_ERR_RANGE -10
#define P_ERR_TYPE -15

#include <iostream>
#include <cctype>

using namespace std;


class numtoword
{
    public:
        numtoword();
        ~numtoword();

        string numword;
        int number;
        int init();

        int basic();

    private:
        int buff_number;
};


int numtoword::init()
{
    int res;

    int test_num;

    



    return 0;
};


int numtoword::basic()
{
    return 0;

};






int main (int argc, char* argv[])
{
    int res;

    int number;
    int count;

    string input;



    if(argc == 2)
    {

        input = argv[1];

        count=0;

        for(char c : input)
        {
            if(isdigit(c))
            {
                            
            }else
            {
                count++;
            };
        };

        if(count == 0)
        {


            res=P_OK;

        }else
        {
            cout<<"ERR: Invalid ARG Input"<<endl;

            res = P_ERR_TYPE;
        };

        

    }else
    {
        cout<<"ERR: No ARG Input"<<endl;

        res = P_ERR_ARG;

    };


    return res;




};