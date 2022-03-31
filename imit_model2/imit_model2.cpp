#include <iostream>
#include <math.h>
#include <random>
#include <vector>
double DSV(const std::vector<double> &p)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> rg(0.000001, 1);//равномерное распределение[a,b) 
    int i = 0;
    double A = rg(gen);
    A = A - p[i];
    while (A > 0)
    {
        i++;
        A = A - p[i];
    }
    return i;
}
int main()
{
    //вектор, хранящий вероятности выпадения сумм очков двух игральных костей
    std::vector<double> p 
    {
        double(1)/double(36),  //2
        double(2)/ double(36), //3
        double(3) / double(36),//4
        double(4) / double(36),//5
        double(5) / double(36),//6
        double(6) / double(36),//7
        double(5) / double(36),//8
        double(4) / double(36),//9
        double(3) / double(36),//10
        double(2) / double(36),//11
        double(1) / double(36) //12
    };
    size_t N = 1000; //число  игр
    int score[N];//массив хранящий результаты игр для 1 игрока
    for (auto& it : score)
        it = 0;

    for (int i = 0; i < N; i++)
    {
        double firstPlayer = DSV(p);
        double secondPlayer = DSV(p);
        if (firstPlayer > secondPlayer)//если побеждает 1 игрок
        {
            score[i]++;
        }
        else if (firstPlayer < secondPlayer)//если побеждает 2 игрок
        {
            score[i]--;
        }
        else//ничья
            score[i] = 0;
    }
    int sum = 0;
    for (auto& it : score)
    {
        sum += it;
    }
    std::cout <<"First player score: " << sum;
    std::cout <<"\nAverage first player score:" << double(sum) / N;

}


