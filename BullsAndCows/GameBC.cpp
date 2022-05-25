// GameBC.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <Windows.h>

using namespace std;

void checkWord(string words)
{
    string input;
    bool b1, b2;
    bool flag = true;
    int bulls, cows, count = 0;

    do
    {
        cout << "Ваше слово: ";
        cin >> input;
        bulls = 0;
        cows = 0;

        transform(input.begin(), input.end(), input.begin(), tolower); //преобразование прописных букв в строчные

        if (input.size() == 4)
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = i + 1; j < 3; j++)
                {
                    if (input[i] == input[j])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        else
        {
            cout << "СЛОВО ДОЛЖНО СОСТОЯТЬ ИЗ 4-Х БУКВ!" << endl;
        }

        if (flag)
        {
            for (int i = 0; i < 4; i++)
            {
                if (words[i] == input[i]) bulls++;
            }

            for (int i = 0; i < 4; i++)
            {
                size_t pos = words.find_first_of(input[i]);
                b1 = pos != string::npos;
                b2 = words.find(input[i] != i);
                if (b1 && b2) cows++;
            }
        }

        count++;
        cout << "Быки: " << bulls << endl;
        cout << "Коровы: " << cows - bulls << endl;
        cout << endl;

    } while (bulls < 4);

    cout << "Вы выиграли!" << endl;
    cout << "Количество ходов: " << count << endl;
}

string randomWord()
{
    vector<string> words;
    ifstream file("D:\\Words.txt"); //считываем файл

    while (!file.eof()) //заполняем вектор
    {
        string word;
        file >> word;
        words.push_back(word);
    }

    default_random_engine gen{ random_device()() }; //генератор рандомных чисел
    uniform_int_distribution<> dist(0, words.size() - 1);

    file.close(); //закрываем файл

    return words[dist(gen)];
}

int main()
{
    setlocale(LC_CTYPE, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    checkWord(randomWord());

    return 0;
}
