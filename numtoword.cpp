#define RANGE_MAX 1000000000
#define RANGE_MIN 1


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

        string numword;
        int number;
        int init();

    private:
        int buff_number;

        void basic(int num);
        void basic_ones(int num);
        void basic_tens(int num);
        void basic_tens_bellow(int num);

        void thousands(int num);
        void million(int num);

};


int numtoword::init()
{
    int res;

    int test_num;
    int buff_num;

    if(this->number >= RANGE_MIN && this->number < RANGE_MAX)
    {
        test_num = this->number;

        this->numword = "";

        if(test_num >= 1000000)
        {
            this->million(test_num);
            test_num = test_num - ( (test_num / 1000000) * 1000000);

            if(test_num != 0)
            {
                this->numword += " ";
            };

        };
        
        
        if(test_num >= 1000)
        {
            this->thousands(test_num);
            test_num = test_num - ( (test_num / 1000) * 1000);

            if(test_num != 0)
            {
                this->numword += " ";
            };

        };

        this->basic(test_num);



        res = P_OK;
    }else
    {
        res=P_ERR_RANGE;
    };

    return res;
};

void numtoword::basic_ones(int num)
{

    switch(num)
    {
        case 1:
            this->numword += "One";
            break;
        case 2:
            this->numword += "Two";
            break;
        case 3:
            this->numword += "Three";
            break;
        case 4:
            this->numword += "Four";
            break;
        case 5:
            this->numword += "Five";
            break;
        case 6:
            this->numword += "Six";
            break;
        case 7:
            this->numword += "Seven";
            break;
        case 8:
            this->numword += "Eight";
            break;
        case 9:
            this->numword += "Nine";
            break;
        default:
            break;

    };

};


void numtoword::basic_tens(int num)
{
    switch(num)
    {
        case 1:
            this->numword += "Ten";
            break;
        case 2:
            this->numword += "Twenty";
            break;
        case 3:
            this->numword += "Thirty";
            break;
        case 4:
            this->numword += "Fourty";
            break;
        case 5:
            this->numword += "Fifty";
            break;
        case 6:
            this->numword += "Sixty";
            break;
        case 7:
            this->numword += "Seventy";
            break;
        case 8:
            this->numword += "Eighty";
            break;
        case 9:
            this->numword += "Ninenty";
            break;
        default:
            break;
    };

};

void numtoword::basic_tens_bellow(int num)
{
    switch(num)
    {
        case 10:
            this->numword += "Ten";
            break;
        case 11:
            this->numword += "Eleven";
            break;
        case 12:
            this->numword += "Twelve";
            break;
        case 13:
            this->numword += "Thirteen";
            break;
        case 14:
            this->numword += "Fourteen";
            break;
        case 15:
            this->numword += "Fifteen";
            break;
        case 16:
            this->numword += "Sixteen";
            break;
        case 17:
            this->numword += "Seventeen";
            break;
        case 18:
            this->numword += "Eighteen";
            break;
        case 19:
            this->numword += "Nineteen";
            break;
        default:
            break;

    };

};


void numtoword::basic(int num)
{
    int buff_num;
    int test_num;

    test_num = num;

    if(test_num >= 100 && test_num < 1000)
    {
        buff_num = test_num / 100;
        this->basic_ones(buff_num);
        this->numword += " Hundred";
        test_num = test_num - (buff_num * 100);

        if(test_num != 0)
        {
            this->numword += " ";
        };

    };

    if (test_num >= 10 && test_num < 20)
    {
        buff_num = test_num;
        this->basic_tens_bellow(buff_num);
        test_num = test_num - buff_num;

        if (test_num != 0)
        {
            this->numword += " ";
        };
    };

    if (test_num >= 20 && test_num < 100)
    {
        buff_num = test_num / 10;
        this->basic_tens(buff_num);
        test_num = test_num - (buff_num * 10);

        if (test_num != 0)
        {
            this->numword += " ";
        };
    };

    if (test_num >= 1 && test_num < 10)
    {
        this->basic_ones(test_num);
    };
};


void numtoword::thousands(int num)
{
    int buff_num;
    int test_num;

    test_num = num;

    buff_num = test_num / 1000;

    if(buff_num != 0)
    {
        this->basic(buff_num);
        this->numword += " Thousand";
        test_num = test_num - (buff_num * 1000);

    };
};



void numtoword::million(int num)
{
    int buff_num;
    int test_num;

    test_num = num;

    buff_num = test_num / 1000000;

    if(buff_num != 0)
    {
        this->basic(buff_num);
        this->numword += " Million";
        test_num = test_num - (buff_num * 1000000);

    };
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

            if(input.length() < 10)
            {
                numtoword word_num;

                word_num.number = stoi(input);

                if ((res = word_num.init()) == P_OK)
                {
                    cout << word_num.numword << endl;
                };

            }else
            {
                res = P_ERR_RANGE;
            }

            numtoword word_num;

            word_num.number = stoi(input);

            



        }else
        {

            res = P_ERR_TYPE;
        };

        

    }else
    {

        res = P_ERR_ARG;

    };

    switch(res)
    {
        case P_OK:
            break;
        case P_ERR_ARG:
            cout<<"ERR: Invalid ARG Input"<<endl;
            break;
        case P_ERR_RANGE:
            cout<<"ERR: Number out of Range"<<endl;
            break;
        case P_ERR_TYPE:
            cout<<"ERR: Invalid ARG Input"<<endl;
            break;
        default:
            cout<<"ERR: Unknown Error"<<endl;
            break;

    };


    return res;




};