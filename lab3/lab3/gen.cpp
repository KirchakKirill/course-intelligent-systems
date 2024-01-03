#include <iostream>
#include <cmath>
#include <random>
/*����� � ������������ ��������� : ����� ���������� ������� ���� ����������.
�������� : �������� �������� ������*/

// ���������� �������, ��� ������� ����� ������ ���������
double function(double x, double y) {
    return pow(x, 2) + pow(y, 2);         //x+y
}
// ��������� �������� ��������� ������ ��� ������ �����������
double simulatedAnnealing(double lowerBound, double upperBound, double initialTemperature, double coolingRate,int numIterations) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(lowerBound, upperBound);

    double currentX = dist(rng);  // �������������� ������� �����
    double currentY = dist(rng);

    double temperature = initialTemperature;  // �������������� �����������

    for (int i = 0; i < numIterations; ++i) {
        double newX = dist(rng);  // ���������� ����� ��������� �����
        double newY = dist(rng);
        double currentValue = function(currentX, currentY);

        // ������� �������� �������� ����� � ������� �����
        double delta = function(newX, newY) - currentValue;

        // ���� ����� �������� ����� ��������, ��������� ����� �����
        if (delta < 0) {//***
            currentX = newX;
            currentY = newY;
        }
        // ���� ����� �������� ���� ��������, ��������� ����� ����� � ��������� ������������
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
    double lowerBound = -10.0;  // ������ ������� �������
    double upperBound = 10.0;   // ������� ������� �������
    double initialTemperature = 100.0;  // ��������� �����������
    double coolingRate = 0.99;  // ����������� ����������
    int numIterations = 100000;  // ���������� ��������

    double extremum = simulatedAnnealing(lowerBound, upperBound, initialTemperature, coolingRate, numIterations);
    std::cout << "�������� ������� : " << extremum << std::endl;

    return 0;
}