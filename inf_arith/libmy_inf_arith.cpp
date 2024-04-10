#include <iostream>
#include <vector>
#include <cstring>
#include <list>
using namespace std;
namespace InfiniteArithmetic
{
    class Integer
    {
     private:
        char *number;
        int sign;
        int len_num;

        Integer add(const Integer& num)
        {
            int carry = 0;
            Integer temp;
            list<char> result;
            int i,j,sum;

            for(i = len_num-1,j = num.len_num-1;i>=0 && j>=0;i--,j--)
            {
                sum = (int)number[i]+(int)num.number[j]-(int)'0'-(int)'0'+carry;
                carry = sum/10;
                sum %= 10;
                result.push_front((char)(sum+'0'));
            }

            if(i>=0)
            {
                for(;i>=0;i--)
                {
                    sum = number[i]+carry-'0';
                    carry = sum/10;
                    sum = sum%10;
                    result.push_front((char)(sum+'0'));
                }
                if(carry>0)
                    result.push_front((char)(carry+'0'));
            }
            else if(j>=0)
            {
                for(;j>=0;j--)
                {
                    sum = num.number[j]+carry-'0';
                    carry = sum/10;
                    sum = sum%10;
                    result.push_front((char)(sum+'0'));
                }
                if(carry>0)
                    result.push_front((char)(carry+'0'));
            }
            temp.len_num = result.size();
            temp.sign = 0;
            temp.number = new char[temp.len_num];
            i=0;

            for(auto j = result.begin();i<temp.len_num;i++,j++)
                temp.number[i] = *j;

            return temp;
        }

        
     public:
        Integer()
        {
            len_num = 1;
            number = new char;
            sign = 1;
            string num = "0";
            copy(num.begin(),num.end(),number);
        }
        Integer(string num)
        {
            if(num[0]=='-')
            {
                sign = 0;
                len_num = num.length()-1;
                number = new char[len_num];
                copy(num.begin()+1,num.end(),number);
            }
            else if(num[0]=='+')
            {
                sign = 1;
                len_num = num.length()-1;
                number = new char[len_num];
                copy(num.begin()+1,num.end(),number);
            }
            else
            {
                sign = 1;
                len_num = num.length();
                number = new char[len_num];
                copy(num.begin(),num.end(),number);
            }
        }
        Integer(const Integer& num)
        {
            sign = num.sign;
            number = num.number;
            len_num = num.len_num;
        }
        void shownum()
        {
            cout<<number<<" "<<sign<<endl;
        }

        ~Integer()
        {
            delete number;
        }
    };
}
