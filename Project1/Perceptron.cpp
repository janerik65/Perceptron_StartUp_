#include "Perceptron.h"
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>

#include <iostream>

Perceptron::Perceptron(TrainingSet *ts, int ts_count)
{
	this->ts = ts;
	this->ts_count = ts_count;
}

Perceptron::~Perceptron()
{
}

double Perceptron::DotProductBias(
						double v1[], 
						double v2[])
{
	if (v1 == NULL || v2 == NULL)
		return -1;

	double d = 0;
	for (int x = 0; x < TrainingSet::INPUT_COUNT; x++)
	{
		d += v1[x] * v2[x];
	}

	d += bias;

	return d;
	//return 0.0;
}

double Perceptron::CalcOutput(int i)
{
	double dp = DotProductBias(weights, ts[i].input);
	if (dp > 0) return(1);
	return (0);
	//return 0.0;
}

double Perceptron::CalcOutput(double i1, double i2)
{
	double inp[2];
	inp[0] = i1;
	inp[1] = i2;

	int inp_count = 2;
	double dp = DotProductBias(weights, inp);
	if (dp > 0) return(1);
	return (0);
	//return 0.0;
}

void Perceptron::InitialiseWeights()
{
	srand(time(NULL));

	for (int i = 0; i < weights_count; i++)
	{
		weights[i] = ((double(rand()) / double(RAND_MAX)) * (1.0 - (-1.0))) + (-1.0);
	}
	bias = ((double(rand()) / double(RAND_MAX)) * (1.0 - (-1.0))) + (-1.0);

	//jeh
	weights[0] = -0.5;
	weights[1] = -1.0;
	bias = -0.2;
}

void Perceptron::UpdateWeights(int j)
{
	double error = ts[j].output - CalcOutput(j);
	jehError = error;
	totalError += fabs((float)error);
	for (int i = 0; i < weights_count; i++)
	{
		weights[i] = weights[i] + error * ts[j].input[i];
	}
	bias += error;
}

void Perceptron::Train(int epochs)
{
	const int b = 6;
	const int p = 3;
	InitialiseWeights();

	for (int e = 0; e < epochs; e++)
	{
		totalError = 0;
		for (int t = 0; t < ts_count; t++)
		{
			UpdateWeights(t);
			std::cout << "W1:" << std::setw(b) << std::fixed << std::setprecision(p) << (weights[0]) << " W2: " << (weights[1]) << " B: " << bias << " E:" << jehError <<std::endl;
		}
		std::cout << "Epoch#: " << e << "...TOTAL ERROR: " << totalError << std::endl;
	}
	
}
