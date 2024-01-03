#include <iostream>
#include <cmath>
#include <random>
/*Поиск в пространстве состояний : поиск экстремума функции двух аргументов.
Алгоритм : алгоритм эмуляции отжига*/

// Определяем функцию, для которой будем искать экстремум
double function(double x, double y) {
    return pow(x, 2) + pow(y, 2);         //x+y
}
// Реализуем алгоритм симуляции отжига для поиска экстремумов
double simulatedAnnealing(double lowerBound, double upperBound, double initialTemperature, double coolingRate,int numIterations) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(lowerBound, upperBound);

    double currentX = dist(rng);  // инициализируем текущую точку
    double currentY = dist(rng);

    double temperature = initialTemperature;  // инициализируем температуру

    for (int i = 0; i < numIterations; ++i) {
        double newX = dist(rng);  // генерируем новую случайную точку
        double newY = dist(rng);
        double currentValue = function(currentX, currentY);

        // Считаем разность значений новой и текущей точек
        double delta = function(newX, newY) - currentValue;

        // Если новое значение лучше текущего, принимаем новую точку
        if (delta < 0) {//***
            currentX = newX;
            currentY = newY;
        }
        // Если новое значение хуже текущего, принимаем новую точку с некоторой вероятностью
        else {
            double acceptanceProb = exp(-delta / temperature);// ***
            std::uniform_real_distribution<double> acceptanceDist(0.0, 1.0);
            double acceptanceRand = acceptanceDist(rng);

            if (acceptanceRand < acceptanceProb) {
                currentX = newX;
                currentY = newY;
            }
        }
        temperature *= coolingRate;
    }

    return function(currentX, currentY);
}

int main() {
    setlocale(LC_ALL,"ru");
    double lowerBound = -10.0;  // нижняя граница функции
    double upperBound = 10.0;   // верхняя граница функции
    double initialTemperature = 100.0;  // начальная температура
    double coolingRate = 0.99;  // коэффициент охлаждения
    int numIterations = 100000;  // количество итераций

    double extremum = simulatedAnnealing(lowerBound, upperBound, initialTemperature, coolingRate, numIterations);
    std::cout << "Значение функции : " << extremum << std::endl;

    return 0;
}