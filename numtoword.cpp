#define RANGE_MAX 18446744073709551615ULL
#define RANGE_MIN 1


#define P_OK 0
#define P_ERR_ARG -5
#define P_ERR_RANGE -10
#define P_ERR_TYPE -15

#include <iostream>
#include <cctype>
#include <climits>
#include <string>

using namespace std;


class numtoword
{
    public:

        string numword;
        unsigned long long int number;
        int init();

    private:
        unsigned long long int buff_number;

        void basic(unsigned long long int num);
        void basic_ones(unsigned long long int num);
        void basic_tens(unsigned long long int num);
        void basic_tens_bellow(unsigned long long int num);

        void thousands();
        void million();
        void billion();
        void trillion();
        void quadrillion();
        void quintillion();

};


int numtoword::init()
{
    int res;

    unsigned long long int test_num;

    if(this->number >= RANGE_MIN && this->number <= RANGE_MAX)
    {

        this->buff_number=this->number;


        this->numword = "";

        this->quintillion();

        this->quadrillion();

        this->trillion();

        this->billion();

        this->million();

        this->thousands();

        this->basic(this->buff_number);



        res = P_OK;
    }else
    {
        res=P_ERR_RANGE;
    };

    return res;
};

void numtoword::basic_ones(unsigned long long int num)
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


void numtoword::basic_tens(unsigned long long int num)
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

void numtoword::basic_tens_bellow(unsigned long long int num)
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


void numtoword::basic(unsigned long long int num)
{
    unsigned long long int buff_num;
    unsigned long long int test_num;

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


void numtoword::thousands()
{
    unsigned long long int buff_num;
    unsigned long long int test_num;

    test_num = this->buff_number;

    

    if(test_num >= 1000)
    {

        buff_num = test_num / 1000;


        this->basic(buff_num);
        this->numword += " Thousand";
        test_num = test_num - (buff_num * 1000);

        this->buff_number=test_num;

        if(test_num != 0)
        {
            this->numword += " ";
        };        

    };
};



void numtoword::million()
{
    unsigned long long int buff_num;
    unsigned long long int test_num;

    test_num = this->buff_number;

    

    if(test_num >= 1000000)
    {

        buff_num = test_num / 1000000;


        this->basic(buff_num);
        this->numword += " Million";
        test_num = test_num - (buff_num * 1000000);

        this->buff_number=test_num;

        if(test_num != 0)
        {
            this->numword += " ";
        };        

    };
};





void numtoword::billion()
{
    unsigned long long int buff_num;
    unsigned long long int test_num;

    test_num = this->buff_number;

    

    if(test_num >= 1000000000)
    {

        buff_num = test_num / 1000000000;


        this->basic(buff_num);
        this->numword += " Billion";
        test_num = test_num - (buff_num * 1000000000);

        this->buff_number=test_num;

        if(test_num != 0)
        {
            this->numword += " ";
        };        

    };

};



void numtoword::trillion()
{
    unsigned long long int buff_num;
    unsigned long long int test_num;

    test_num = this->buff_number;

    

    if(test_num >= 1000000000000)
    {

        buff_num = test_num / 1000000000000;


        this->basic(buff_num);
        this->numword += " Trillion";
        test_num = test_num - (buff_num * 1000000000000);

        this->buff_number=test_num;

        if(test_num != 0)
        {
            this->numword += " ";
        };        

    };

};



void numtoword::quadrillion()
{
    unsigned long long int buff_num;
    unsigned long long int test_num;

    test_num = this->buff_number;

    

    if(test_num >= 1000000000000000)
    {

        buff_num = test_num / 1000000000000000;


        this->basic(buff_num);
        this->numword += " Quadrillion";
        test_num = test_num - (buff_num * 1000000000000000);

        this->buff_number=test_num;

        if(test_num != 0)
        {
            this->numword += " ";
        };        

    };

};


void numtoword::quintillion()
{
    unsigned long long int buff_num;
    unsigned long long int test_num;

    test_num = this->buff_number;

    

    if(test_num >= 1000000000000000000)
    {

        buff_num = test_num / 1000000000000000000;


        this->basic(buff_num);
        this->numword += " Quintillion";
        test_num = test_num - (buff_num * 1000000000000000000);

        this->buff_number=test_num;

        if(test_num != 0)
        {
            this->numword += " ";
        };        

    };

};













int main (int argc, char* argv[])
{
    int res;

    unsigned long long int number;
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

            numtoword word_num;
            

            try
            {
                word_num.number = stoull(input);
                if( (res=word_num.init() ) == P_OK )
                {
                    cout << word_num.numword << endl;
                };

            }
            catch(const std::exception& e)
            {
                res=P_ERR_RANGE;
            };
            
            



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