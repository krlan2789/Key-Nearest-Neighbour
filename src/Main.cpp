#include <iostream>
#include "Sqrt.h"
#include "Data.h"
#include "CosineSimilarity.h"
#include "EuclideanDistance.h"
#include "KeyNearestNeighbour.h"

int main()
{
	int temp, angka, i = 0;
	std::cout << "Masukkan angka : ";
	std::cin >> angka;
	temp = angka;

	while (temp >= 2)
	{
		temp = temp / 2;
		i++;
	}
	while (i <= angka)
	{
		float data = Sqrt::subMethod(i);
		float data2 = Sqrt::meanMethod(i);
		std::cout << "Akar dari " << i << " dengan subMethod\t: " << data << " -> " << data*data << std::endl;
		std::cout << "Akar dari " << i << " dengan meanMethod\t: " << data2 << " -> " << data2*data2 << "\n\n";
		i++;
	}
	
	int paramLength = 2;
	float value[3][paramLength];

	Data* data = new Data(paramLength, "Merah");
	value[0][0] = 7.0f;
	value[0][1] = 5.0f;
	data->addData(value[0]);
	value[1][0] = 3.0f;
	value[1][1] = 4.0f;
	data->addData(value[1]);
	value[2][0] = 5.0f;
	value[2][1] = 7.0f;
	data->addData(value[2]);
	
	Data* data2 = new Data(paramLength, "Biru");
	value[0][0] = 10.0f;
	value[0][1] = 6.0f;
	data2->addData(value[0]);
	value[1][0] = 12.0f;
	value[1][1] = 9.0f;
	data2->addData(value[1]);
	value[2][0] = 11.0f;
	value[2][1] = 1.0f;
	data2->addData(value[2]);

	KeyNearestNeighbour knn = KeyNearestNeighbour();
	knn.addCategory(data);
	std::cout << "Setelah menambahkan kategori\n";
	knn.addCategory(data2);

	//  Euclidean Distance
	std::cout << "\nMenampilkan Data :\n";

	float** row = data->getPoints();
	float newData[2];
	newData[0] = 9.0f;
	newData[1] = 4.0f;

	for (int i = 0; i < data->getLength(); i++)
	{
		std::cout << "[" << i << "][" << data->getLength(true) << "] : ";
		for (int j = 0; j < data->getLength(true); j++)
		{
			std::cout << row[i][j] << ", ";
		}
		std::cout << "\n\t\tJarak dari [" << newData[0] << ", " << newData[1] <<"] : " << EuclideanDistance::getDiagonalDistance(newData, row[i]) << std::endl;
	}

	//  Cosine Similarity
	std::cout << "\nMenampilkan Data : " << "\n";

	float** row2 = data->getPoints();

	for (int i = 0; i < data->getLength(); i++)
	{
		std::cout << "[" << i << "][" << data->getLength(true) << "] : ";
		for (int j = 0; j < data->getLength(true); j++)
		{
			std::cout << row2[i][j] << ", ";
		}
		std::cout << "\n\t\tKemiripan dengan [" << newData[0] << ", " << newData[1] <<"] : " << CosineSimilarity::getDiffVector(newData, row2[i], 2) << "\n";
	}

	return 0;
}