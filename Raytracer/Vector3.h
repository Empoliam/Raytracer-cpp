#pragma once

template <typename T>
class Vector3
{
public:

	Vector3() {

		v[0] = 0;
		v[1] = 0;
		v[2] = 0;

	}


	Vector3(T x, T y, T z)
	{

		v[0] = x;
		v[1] = y;
		v[2] = z;

	}

	Vector3 operator+(const Vector3<T>& U) const
	{

		float x = U[0] + v[0];
		float y = U[1] + v[1];
		float z = U[2] + v[2];

		return Vector3(x, y, z);

	}

	Vector3 operator+(const T& a) const
	{
		T x = v[0] + a;
		T y = v[1] + a;
		T z = v[2] + a;

		return Vector3(x, y, z);
	}

	Vector3& operator+=(const T& a)
	{

		v[0] += a;
		v[1] += a;
		v[2] += a;

		return *this;

	}

	Vector3 operator-(const T& a) const
	{
		T x = v[0] - a;
		T y = v[1] - a;
		T z = v[2] - a;

		return Vector3(x, y, z);
	}

	Vector3 operator-(const Vector3& U) const
	{
		T x = U[0] - v[0];
		T y = U[1] - v[1];
		T z = U[2] - v[2];

		return Vector3(x, y, z);
	}

	Vector3 operator-() const
	{
		T x = -v[0];
		T y = -v[1];
		T z = -v[2];

		return Vector3(x, y, z);
	}

	T operator[](int i) const
	{
		return v[i];
	}

	T& operator[](int i)
	{
		return v[i];
	}

	Vector3 operator*(const T& a) const
	{
		T x = v[0] * a;
		T y = v[1] * a;
		T z = v[2] * a;

		return Vector3(x, y, z);
		
	}

	inline T dot(const Vector3& U)
	{
		return (v[0] * U[0]) + (v[1] * U[1]) + (v[2] * U[2]);
	}

	inline T norm()
	{
		return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
	}

	inline T length()
	{
		return sqrt(norm());
	}


private:
	T v[3];
};

typedef Vector3<float> Vector3f;

template <typename T>
class Ray3
{

public:
	Vector3<T> origin;
	Vector3<T> direction;


	Vector3<T> raycast(const T& t)
	{
		return origin + t * direction;
	}

};