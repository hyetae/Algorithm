#include <string>
#include <vector>
#include <bitset>

using namespace std;

int make_bit_return_number(int n)
{
    std::bitset<32> bits(n);
    auto str = bits.to_string();

    int number = 0;
    for(auto chr : str)
    {
        if(chr == '1')
            number++;
    }
    return number;
}
int solution(int n) {
    int answer = 0;

    int targetNumber = make_bit_return_number(n);

    while(1)
    {
        n=n+1;
        int num = make_bit_return_number(n);
        if(targetNumber == num)
        {
            break;
        }
    }
    answer = n;
    return answer;
}