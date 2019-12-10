#pragma once

class TrainingSet
{
	public:
		static const int INPUT_COUNT = 2;
		double input[INPUT_COUNT];
		double output;
};

class Perceptron
{
public:
	TrainingSet *ts;
	int ts_count;
	double weights [TrainingSet::INPUT_COUNT] = { 0, 0 };
	int weights_count = 2;

	double bias = 0;
	double totalError = 0;
	double jehError = 0;

	Perceptron(TrainingSet *ts, int ts_count);
	~Perceptron();

	double DotProductBias(double v1[], double v2[]);

	double CalcOutput(int i);
	double CalcOutput(double i1, double i2);

	void InitialiseWeights();
	void UpdateWeights(int j);
	
	void Train(int epochs);

};

