#include "Vector2D.h"

Vector2D::Vector2D()
{
	mx = 0.0f;
	my = 0.0f;
}

Vector2D::Vector2D(float x, float y)
{
	mx = x;
	my = y;
}

Vector2D& Vector2D::Add(const Vector2D& vec)
{
	mx += vec.mx;
	my += vec.my;
	return *this;
}

Vector2D& Vector2D::Subtract(const Vector2D& vec)
{
	mx -= vec.mx;
	my -= vec.my;
	return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& vec)
{
	mx *= vec.mx;
	my *= vec.my;
	return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& vec)
{
	mx /= vec.mx;
	my /= vec.my;
	return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& vec)
{
	return this->Add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec)
{
	return this->Subtract(vec);
}

Vector2D& Vector2D::operator*=(const Vector2D& vec)
{
	return this->Multiply(vec);
}

Vector2D& Vector2D::operator/=(const Vector2D& vec)
{
	return this->Divide(vec);
}

Vector2D& Vector2D::operator*(const int& i)
{
	this->mx *= i;
	this->my *= i;
	return *this;
}

Vector2D& Vector2D::zero()
{
	this->mx *= 0;
	this->my *= 0;
	return *this;
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
	return v1.Add(v2);
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
	return v1.Subtract(v2);
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
	return v1.Multiply(v2);
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
	return v1.Divide(v2);
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& vec)
{
	stream << "(" << vec.mx << ", " << vec.my << ")";
	return stream;
}
