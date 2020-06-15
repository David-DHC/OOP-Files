#pragma once
using namespace std;

class LoadStrategy
{

public:

    LoadStrategy() {};
    virtual float load() = 0;
    virtual ~LoadStrategy() {};

};

class NumberLoadStrategy : public LoadStrategy
{

public:

    float load()
    {
        float n;
        cin >> n;
        return n;
    }
};

class WordLoadStrategy : public LoadStrategy
{

public:

    float load()
    {
        string raw;
        getchar();

        getline(cin, raw, '#');

        string content[30];

        int number = 0;
        for (int i = 0; i < raw.length(); i++)
        {
            if (raw[i] == ' ')
                number++;
            else
                content[number] += raw[i];
        }

        string ten[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        string temp;
        for (int i = 0; i < number; i++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (content[i] == ten[k])
                    temp += (k + 48);
            }
        }

        int final = stoi(temp);
        return final;
    }
};
