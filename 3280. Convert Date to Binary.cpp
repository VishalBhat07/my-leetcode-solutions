class Solution
{
public:
    string converter(string number)
    {
        int n = stoi(number);
        string temp = "";
        while (n != 0)
        {
            temp += n % 2 + '0';
            n = n / 2;
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    string convertDateToBinary(string date)
    {
        return converter(date.substr(0, 4)) + "-" +
               converter(date.substr(5, 2)) + "-" +
               converter(date.substr(8, 2));
    }
};