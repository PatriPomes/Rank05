#pragma once

#include <iostream>

class vect2
{
	private:
		int x;
		int y;

	public:
		vect2();
		vect2(int x, int y);
		vect2(const vect2& other);
		vect2& operator=(const vect2& other);

		//insertion
		int operator[](int index) const;
		int& operator[](int index);

		//increment
		vect2& operator++();
		vect2 operator++(int);

		//decrement
		vect2& operator--();
		vect2 operator--(int);

		//addition
		vect2 operator+(const vect2& other) const;
		vect2& operator+=(const vect2& other);

		//substraction
		vect2 operator-(const vect2& other) const;
		vect2& operator-=(const vect2& other);

		//multiplication
		vect2 operator*(int num) const;
		vect2& operator*=(int num);

		//negative
		vect2 operator-() const;

		//equality
		bool operator==(const vect2& other) const;
		bool operator!=(const vect2& other) const;
};

vect2 operator*(int num, const vect2& obj);

std::ostream& operator<<(std::ostream& os,const vect2& obj);