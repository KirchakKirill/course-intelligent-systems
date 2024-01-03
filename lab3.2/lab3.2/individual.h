#pragma once
#include <iostream>
#include <vector>
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(-10.0, 10.0);
std::uniform_real_distribution<> dis_for_prob(0.0,1.0);
class individual
{
private:
	double x;
	double y;
	double probability_of_mutation;
	double func_value;
public:
	individual()
	{
		this->x = dis(gen);
		this->y = dis(gen);
		this->probability_of_mutation = dis_for_prob(gen);
		Function();
		 
	}

	individual(double x, double y)
	{
		this->x = x;
		this->y = y;
		this->probability_of_mutation = dis_for_prob(gen);
		Function();
	}
	double get_x() { return x; }
	double get_y() { return y; }
	void set_x(const double& newX) 
	{ 
		if (newX >= dis.a()&&newX<=dis.b())
		{
			this->x = newX;
		}
	}
	void set_y(const double& newY) 
	{
		if (newY >= dis.a() && newY <= dis.b())
		{
			this->y = newY;
		}
	}
	double get_probability_of_mutation() { return probability_of_mutation; }
	double get_func_value() { return func_value; }

	void Function() {
		this->func_value =  pow(x,2) + pow(y,2);
	}

};
