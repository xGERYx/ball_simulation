#include <iostream>

constexpr double gravity = 9.8;						// meter/second2

double inputHeightOfTower()
{
	double height = 0.0;
	std::cout << "Please enter the height of the tower(meters): ";
	std::cin >> height;

	return height;
}

double calcCurrentHeight(int time, double height)	// second, meter
{
	return (height - ((time * time) * gravity) / 2);
}

void printCurrentHeight(double height)	// meter
{
	int time = 0;
	
	if (calcCurrentHeight(time, height) > 0)
	{
		do
		{
			std::cout << "At " << time << " seconds, the ball is at height: " << calcCurrentHeight(time, height) << std::endl;
			time++;
		} 
		while (calcCurrentHeight(time, height) > 0);
	}

	std::cout << "At " << time << " seconds, the ball hit the ground!" << std::endl;
}

int main()
{
	double heightOfTower = inputHeightOfTower();	// meter
	
	printCurrentHeight(heightOfTower);

	std::cin.get();
	return 0;
}