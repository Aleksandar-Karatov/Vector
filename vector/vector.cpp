// 09_04_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template <typename T>
class myVector
{
public:
	myVector()
	{
		data = nullptr;
		size = 0;
		capacity = 0;
	}
	myVector(const myVector<T>& other);
	myVector(const T*);
	size_t getSize()const
	{
		return size;
	}
	size_t getCapacity()const
	{
		return capacity;
	}
	myVector<T>& operator= (const myVector<T>& other);
	T& operator[] (const size_t index)const;
	void pushBack(const T& toAdd);
	~myVector()
	{
		delete[] data;
	}

private:
	T* data;
	size_t size;
	size_t capacity;
	void copy(const myVector<T>& other)
	{
		if (this != &other)
		{
			size = other.size;
			capacity = other.capacity;
			data = new T[capacity];
			for (size_t i = 0; i < size; i++)
			{
				data[i] = other.data[i];
			}
		}
	}
	void resize()
	{
		capacity *= 2;
		T* buffer = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			buffer[i] = data[i];
		}
		delete[] data;
		data = new T[capacity];
		data = buffer;
	}
	void destroy()
	{
		delete[] data;
	}
};
template<typename T>
myVector<T>::myVector(const myVector<T>& other)
{
	copy(other);
}
template<typename T>
myVector<T>::myVector(const T* Data)
{
	size_t Size = 0;
	while (Data[Size] != NULL)
	{
		Size++;
	}
	size_t Capacity = 8;
	while (Capacity < Size)
	{
		Capacity *= 2;
	}
	size = Size;
	capacity = Capacity;
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = Data[i];
	}
}
template<typename T>
myVector<T>& myVector<T> :: operator= (const myVector<T>& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}
	return *this;
}
template <typename T>
T& myVector<T>:: operator[] (const size_t index)const
{
	if (index > size)
	{
		exit(1);
	}
	return data[index];
}
template<typename T>
void myVector<T>::pushBack(const T& toAdd)
{
	if (size + 1 >= capacity)
	{
		resize();
	}
	data[size] = toAdd;
	size++;
}
int main()
{
	std::cout << "Hello World!\n";
}

