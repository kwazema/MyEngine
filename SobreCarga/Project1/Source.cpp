#include <iostream>
#include <vector>
struct Vector3
{
	Vector3() {
		std::cout << "Hello" << std::endl;
	};
	~Vector3()
	{
		std::cout << "Hey" << std::endl;
	}
	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		std::cout << "construct" << std::endl;

	}
	Vector3(const Vector3  & cpy) 
	{
		std::cout << "cpy" << std::endl;
	}
	float x, y, z;
};
int main()
{
	std::vector<Vector3> myVector;

	//Sobre carga de constructores
	myVector.push_back(Vector3(10,10,10));
	myVector.emplace_back(10,10,10); 


	std::cin.get();
	return 0;
}