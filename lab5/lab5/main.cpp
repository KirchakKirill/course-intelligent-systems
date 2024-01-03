#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;
struct Fact
{
public:
	string value;
	Fact(string value)
	{
		this->value = value;
	};
	Fact()
	{

	};
	string to_string()
	{
		return value;
	}
	bool operator < (const Fact& right) const 
	{
		return value < right.value;
	}
	bool operator == (const Fact& right) const
	{
		return value == right.value;
	}
};


struct Rule
{
public:
	vector<Fact> facts_in;
	Fact out_fact;
	Rule(Fact out_fact, vector<Fact> facts_in)
	{
		this->facts_in = facts_in;
		this->out_fact = out_fact;
	}
	string to_string_rule()
	{
		string res;
		for (Fact f : facts_in)
		{
			
			res += f.to_string() + "+";
		}
		res.replace(res.find_last_of("+"),1,"=");
		res += out_fact.to_string();
		return res;
	}

};

struct CurParentFact
{
public:
	Fact CurrentFact;
	Fact ParentFact;

	CurParentFact(Fact currentFact, Fact parentFact)
	{
		CurrentFact = currentFact;
		ParentFact = parentFact;
	}
	bool operator < (const CurParentFact& right) const
	{
		return this->CurrentFact < right.CurrentFact&& this->ParentFact < right.ParentFact;
	}
	bool operator == (const CurParentFact& right) const
	{
		return this->CurrentFact == right.CurrentFact&& this->ParentFact == right.ParentFact;
	}

};

class lab5
{
public:
	vector<Rule> read()
	{
		vector<Rule> rules;
		string s;
		ifstream fin("crafts.txt");
		if (!fin.is_open())
			cout << "Файл не может быть открыт!\n";
		else
		{
			while (getline(fin, s))
			{
				Rule rule = Parse(s);
				rules.push_back(rule);
			}
		}
		return rules;

	}
	Rule Parse(const string& s)
	{
		vector<Fact> facts;
		
		int  index_eq = s.find("=");
		Fact factOut{s.substr(0,index_eq)};
		int  start_index = index_eq + 1;
		int  end_index = s.length() - 1;
		while (true)
		{
			int  index_plus = s.find("+",start_index);
			if (index_plus==std::string::npos)
			{
				Fact factIn{ s.substr(start_index)};
				facts.push_back(factIn);
				break;
			}
			else
			{
				Fact factIn{ s.substr(start_index,index_plus-start_index) };
				facts.push_back(factIn);
				start_index = index_plus + 1;
			}
			
		}
		Rule rule{factOut,facts};
		
		return rule;
		
	}
	bool Accept(const Rule& rule, const vector<Fact>& facts)
	{
		for(const Fact& fact:rule.facts_in)
			if (find_if(facts.begin(), facts.end(), [fact](const Fact& f ) {return f.value==fact.value;})==facts.end())
				return false;
		return true;
	}

	bool forward(const Fact& goal,  const vector<Fact>& lfacts, const vector<Rule>& rules)
	{
		vector<Fact> facts{lfacts};
		bool isChanged = true;
		while (isChanged && find_if(facts.begin(), facts.end(), [goal](const Fact& fact) {return fact.value == goal.value;})==facts.end())
		{
			isChanged = false;
			for( Rule rule:rules)
			{
			bool contains_out = find_if(facts.begin(), facts.end(), [rule](const Fact& fact) {return fact.value == rule.out_fact.value;})!=facts.end();
			bool contains_goal = find_if(facts.begin(), facts.end(), [goal](const Fact& fact) {return fact.value == goal.value;})!=facts.end();
				if (!Accept(rule, facts) || contains_out || contains_goal)
					continue;

				facts.push_back(rule.out_fact);
				isChanged = true;
				
				cout  << rule.to_string_rule() << endl;
			}
		}
		cout<<endl;
		return true;
	}
	
	bool backward(Fact goal,  const vector<Fact>& lfacts, const vector<Rule>& rules)
	{
		vector<Fact> facts{ lfacts };
		map<Fact, vector<Rule>> factToRules;
		
		for(Rule rule:rules)
		{
			
			if (factToRules.find(rule.out_fact) != factToRules.end())
			{
				factToRules[rule.out_fact].push_back(rule);
				
			}
			else
			{
				factToRules[rule.out_fact] = vector<Rule>{rule};
			}

			for (Fact fact : rule.facts_in) {
				if (factToRules.find(fact) == factToRules.end())
				{
					factToRules[fact] = vector<Rule>{};
				}
			}
		}
		vector<CurParentFact> uncheckedFacts{ CurParentFact(goal,Fact{}) };
		while (true)
		{
			bool changed = false;
			bool breakFlag = false;
			vector<CurParentFact> t(uncheckedFacts);
			for(CurParentFact currentParentFact:t)
			{
				if (breakFlag)
					break;

				Fact currentFact = currentParentFact.CurrentFact;
				Fact ParentFact = currentParentFact.ParentFact;
				if (find(facts.begin(),facts.end(),currentFact) != facts.end() || find(facts.begin(), facts.end(), ParentFact) != facts.end())
					continue;

				for(Rule rule:factToRules[currentFact])
				{
					if (Accept(rule, facts))
					{
						cout<<"#" <<rule.to_string_rule()<<"-->" << currentParentFact.ParentFact.to_string()  << endl;
						if (currentFact.value==goal.value)
							return true;

						facts.push_back(currentFact);

						uncheckedFacts.erase(find(uncheckedFacts.begin(), uncheckedFacts.end(),currentParentFact));
						changed = true;
						breakFlag = true;
						break;
					}
					else
					{
						for(const Fact& fact:rule.facts_in)
						{
							if (find_if(facts.begin(), facts.end(), [fact](const Fact& f) {return f.value == fact.value; }) != facts.end() || find_if(uncheckedFacts.begin(), uncheckedFacts.end(), [fact,currentFact](const CurParentFact& cf) {return cf.CurrentFact.value==fact.value&&cf.ParentFact.value==currentFact.value;})!=uncheckedFacts.end())
								continue;

							uncheckedFacts.push_back(CurParentFact(fact, currentFact));
							changed = true;
						}
					}
				}
			}
			if (!changed)
				break;
		}

	}
};


vector<Fact> select(const vector<Rule>& rules)
{
	vector<Fact> facts1;
	for (const Rule& rule : rules)
	{
		facts1.push_back(rule.out_fact);
	}
	return facts1;
}
void Add(vector<Fact>& facts, const vector<Fact>& factsIn)
{
	for (auto f:factsIn)
	{
		facts.push_back(f);
	}
}
vector<Fact> select_many(const vector<Rule>& rules)
{
	vector<Fact> facts2;
	for (auto rule : rules)
	{
		Add(facts2,rule.facts_in);
	}
	return facts2;
}
vector<Fact> distinct(const vector<Fact>& f1)
{
	vector<string> s(f1.size());
	transform(f1.begin(), f1.end(), s.begin(), [](const Fact& fact) {return fact.value;});
	sort(begin(s), end(s));              
	auto it = std::unique(begin(s), end(s));
	s.erase(it, end(s));
	vector<Fact> res_facts(s.size());
	transform(s.begin(), s.end(), res_facts.begin(), [](const string& str) {return Fact(str); });
	return res_facts;
}
void remove_all(vector<Fact>& facts2, const vector<Fact>& facts1)
{
	for (const Fact& fact2:facts2)
	{
		for (const Fact& fact1:facts1)
		{
			if (fact2.value==fact1.value)
			{
				facts2.erase(find_if(facts2.begin(), facts2.end(), [fact1](const Fact& f) {return fact1.value==f.value;}));
			}
		}
	}
}


int main()
{
	setlocale(LC_ALL, "rus");
	lab5 val;
	vector<Rule> rules = val.read();
	//--------------------------------
	vector<Fact> facts1 = select(rules);
	distinct(facts1);

	vector<Fact> facts2 = select_many(rules);
	facts2 = distinct(facts2);
	
	remove_all(facts2,facts1);

	facts2.erase(find_if(facts2.begin(), facts2.end(), [](const Fact& fact) {return fact.value == "Skull Basher"; }));

	cout << "Правил: " << rules.size() << endl;
	cout << "Фактов: " << facts2.size() << endl;

	val.forward(Fact("Abyssal Blade"), facts2, rules);
	val.backward(Fact("Abyssal Blade"), facts2, rules);

	cout << "--------------------------------------------------" << endl;


	val.forward(Fact("Gleipnir"), facts2, rules);
	val.backward(Fact("Gleipnir"), facts2, rules);



	cout << "--------------------------------------------------" << endl;
	vector<Fact> facts3{Fact("Kaya Yasha Sange")};



	val.forward(Fact("Kaya Yasha Sange"), facts2, rules);
	val.backward(Fact("Kaya Yasha Sange"), facts2, rules);

	
	val.backward(Fact("A4"), facts3, rules);

	
}

