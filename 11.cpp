#include <iostream>
#include <vector>

using namespace std;

class Product 
{
private:
	static double margin;

public:
	string name;
	string type;
	double purchacePrice;

	Product(string _name, string _type, double _purchacePrice)
	{
		name = _name;
		type = _type;
		purchacePrice = _purchacePrice;

	}	

	double getOptPrice()
	{
		return purchacePrice + purchacePrice * margin;
	}

	static void changeMargin(double newMargin)
	{
		margin = newMargin;
	}
};

double Product::margin = 0;

void outVector(vector<Product> vec)
{
	for (auto it : vec)
	{
		cout << it.getOptPrice() << endl;
	}
}

int main()
{
	Product::changeMargin(0.25);  // Установка наценки

	vector<Product> vec;
	vec.push_back(Product("cheese", "milk", 99.9));
	vec.push_back(Product("video card RTX 5090", "pc", 999.99));
	vec.push_back(Product("papich", "twitch", 9.99));

	outVector(vec);
}

