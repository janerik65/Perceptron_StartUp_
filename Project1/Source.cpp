
#include "Perceptron.h"
#include <iostream>

void main()
{
	TrainingSet *ts = new TrainingSet[4];
	int ts_count = 4;
	for (int i = 0; i < ts_count; i++)
	{
		//jeh ts[i].input = new double[2];
		//jeh ts[i].input_count = 2;
		switch (i)
		{
		case 0:
			ts[i].input[0] = 0; ts[i].input[1] = 0;
			ts[i].output = 0;
			break;
		case 1:
			ts[i].input[0] = 1; ts[i].input[1] = 0;
			ts[i].output = 1;
			break;
		case 2:
			ts[i].input[0] = 0; ts[i].input[1] = 1;
			ts[i].output = 1;
			break;
		case 3:
			ts[i].input[0] = 1; ts[i].input[1] = 1;
			ts[i].output = 1;
			break;
		default:
			break;
		}
	}

	Perceptron p(ts, ts_count);
	p.Train(6);

	std::cout << "Press Enter to see calculate output..." << std::endl;
	getchar();

	std::cout << "Test 0 0: " << p.CalcOutput(0, 0) <<std::endl;
	std::cout << "Test 0 1: " << p.CalcOutput(0, 1) << std::endl;
	std::cout << "Test 1 0: " << p.CalcOutput(1, 0) << std::endl;
	std::cout << "Test 1 1: " << p.CalcOutput(1, 1) << std::endl;
	getchar();
}