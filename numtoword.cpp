/**
 * @file    numtoword.cpp
 * @brief   Numeric-to-Word Converter
 *
 * Converts unsigned integer values into their English word representation.
 * Supports the full range of unsigned 64-bit integers (1 to 18,446,744,073,709,551,615),
 * covering groups from ones up to quintillions.
 *
 * Usage:
 *   ./numtoword <number>
 *
 * Examples:
 *   ./numtoword 1000      -> "One Thousand"
 *   ./numtoword 1000000   -> "One Million"
 */

/** Supported input range boundaries (unsigned 64-bit limits). */
#define RANGE_MAX 18446744073709551615ULL
#define RANGE_MIN 1

/** Return codes for conversion and argument validation results. */
#define P_OK        0    ///< Conversion completed successfully.
#define P_ERR_ARG   -5   ///< Wrong number of command-line arguments.
#define P_ERR_RANGE -10  ///< Input value is outside the supported range.
#define P_ERR_TYPE  -15  ///< Input contains non-numeric characters.

#include <iostream>
#include <cctype>
#include <climits>
#include <string>

using namespace std;


/**
 * @class numtoword
 * @brief Encapsulates the number-to-English-word conversion logic.
 *
 * Set the `number` field, call `init()`, then read the result from `numword`.
 */
class numtoword
{
    public:
        string numword;                ///< Resulting English word string after conversion.
        unsigned long long int number; ///< Input number to be converted.
        int init();                    ///< Starts the conversion; returns a P_* status code.

    private:
        unsigned long long int buff_number; ///< Working copy of the input, consumed during conversion.

        void basic(unsigned long long int num);            ///< Converts 0-999 into words.
        void basic_ones(unsigned long long int num);       ///< Appends word for ones digit (1-9).
        void basic_tens(unsigned long long int num);       ///< Appends word for tens digit (1=Ten ... 9=Ninety).
        void basic_tens_bellow(unsigned long long int num);///< Appends word for teen values (10-19).

        void thousands();    ///< Handles the thousands group (1,000 - 999,999).
        void million();      ///< Handles the millions group.
        void billion();      ///< Handles the billions group.
        void trillion();     ///< Handles the trillions group.
        void quadrillion();  ///< Handles the quadrillions group.
        void quintillion();  ///< Handles the quintillions group (up to 18 quintillion).
};


/**
 * @brief  Validates the input and runs the full conversion pipeline.
 *
 * Processes the number from the largest group (quintillions) down to ones,
 * appending each group's English words to `numword` in order.
 *
 * @return P_OK on success, P_ERR_RANGE if the value is outside the supported range.
 */
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

/**
 * @brief  Appends the English word for a single digit (1-9) to `numword`.
 * @param  num  A digit value in the range 1-9.
 */
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


/**
 * @brief  Appends the English word for a tens-place value (1=Ten, 2=Twenty ... 9=Ninety).
 * @param  num  The tens digit (1-9), not the full two-digit value.
 */
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

/**
 * @brief  Appends the English word for teen values (10-19).
 * @param  num  A full integer value in the range 10-19.
 */
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


/**
 * @brief  Converts a value in the range 0-999 into its English word representation.
 *
 * Handles hundreds, tens, teens, and ones sequentially in a single pass,
 * appending each part to `numword` with appropriate spacing.
 *
 * @param  num  Value to convert, expected to be in the range 0-999.
 */
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


/**
 * @brief  Processes the thousands group from `buff_number`.
 *
 * Extracts the thousands portion, converts it to words, appends " Thousand",
 * then updates `buff_number` with the remainder.
 */
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



/**
 * @brief  Processes the millions group from `buff_number`.
 *
 * Extracts the millions portion, converts it to words, appends " Million",
 * then updates `buff_number` with the remainder.
 */
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





/**
 * @brief  Processes the billions group from `buff_number`.
 *
 * Extracts the billions portion, converts it to words, appends " Billion",
 * then updates `buff_number` with the remainder.
 */
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



/**
 * @brief  Processes the trillions group from `buff_number`.
 *
 * Extracts the trillions portion, converts it to words, appends " Trillion",
 * then updates `buff_number` with the remainder.
 */
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



/**
 * @brief  Processes the quadrillions group from `buff_number`.
 *
 * Extracts the quadrillions portion, converts it to words, appends " Quadrillion",
 * then updates `buff_number` with the remainder.
 */
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


/**
 * @brief  Processes the quintillions group from `buff_number`.
 *
 * Extracts the quintillions portion, converts it to words, appends " Quintillion",
 * then updates `buff_number` with the remainder.
 */
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





/**
 * @brief  Program entry point.
 *
 * Expects exactly one command-line argument containing a non-negative integer.
 * Validates that the argument consists entirely of digit characters, converts it
 * to an unsigned 64-bit integer, and prints the English word representation.
 * Prints a descriptive error message and returns a non-zero code on failure.
 *
 * @param  argc  Argument count; must be exactly 2 (program name + number).
 * @param  argv  Argument vector; argv[1] must be a numeric string.
 * @return P_OK on success, or a P_ERR_* code indicating the failure reason.
 */
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