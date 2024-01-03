#pragma once
#include "individual.h"

class population
{
	
	std::vector<individual*> individuals;
	int number_individuals;
	double percent_mutant;
	int count_parents_for_reproduction;
	
public:
	population(int number,double percent,int count) 
	{
		this->number_individuals = number;
		this->individuals = generate_population(number_individuals);
		this->percent_mutant = percent;
		this->count_parents_for_reproduction = count;
	};

	void delete_old_population()
	{

		for (int i = 0; i < number_individuals; i++)
		{
			delete individuals[i];
		}


		individuals.erase(individuals.begin(),individuals.begin()+number_individuals);
		
	}

	std::vector<individual*> generate_population(int number)
	{
		std::vector<individual*> list;
		for (size_t i = 0; i < number; i++)
		{
			individual* indiv = new individual();
			list.push_back(indiv);
		}
		return list;
	}
	bool comp ( individual& first,  individual& second)
	{
		return first.get_func_value() < second.get_func_value();
	}
	
	std::vector<individual*>  selection()
	{
		
		std::sort(individuals.begin(), individuals.end(), []( individual* f,  individual* s)->bool {return f->get_func_value()<s->get_func_value();});
			return take();
	}
	std::vector<individual*> take()
	{
		std::vector<individual*> select_indviduals;
		for (int i = 0; i < number_individuals; i++)
		{
			if (i>=number_individuals-count_parents_for_reproduction)
			{
				select_indviduals.push_back(individuals[i]);
			}
		}
		return select_indviduals;

	}

	auto mutate()
	{
		double per = percent_mutant / 100;
		std::uniform_real_distribution<> m(1-per, 1+per);
		auto select_ind = selection();
		for(auto &ind :select_ind )
		{
			auto probably = dis_for_prob(gen);
			if (ind->get_probability_of_mutation() > probably)
			{
				ind->set_x(ind->get_x()*m(gen));
				ind->set_y(ind->get_y()*m(gen));
			}
		}
		
		return select_ind;
	}
	void crossover()
	{
		auto sample = mutate();
		fill_population(sample);
		delete_old_population();
	}

	void fill_population(const  std::vector<individual*>& sample)
	{
		auto SAMPLE_SIZE = sample.size();
		std::uniform_int_distribution<int> cross(0, SAMPLE_SIZE - 1);
		for (size_t i = 0; i < number_individuals; i++)
		{
			individuals.push_back(new individual(sample[cross(gen)]->get_x(), sample[cross(gen)]->get_y()));
		}
	}

	void print_population()
	{
		for (size_t i = 0; i < number_individuals; i++)
		{
			std::cout <<"x: "<<individuals[i]->get_x() << " " <<"y: "<<individuals[i]->get_y() << " " << "func: "<<individuals[i]->get_func_value() << std::endl;
		}
	}

	void gen_algorithm()
	{
		int i = 1;
		while (true)
		{
			std::cout << i << ":";
			print_population();
			crossover();
			++i;
		}
	}
};