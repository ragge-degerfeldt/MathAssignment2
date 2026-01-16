#pragma once
#include <cmath>
class vec4
{
public:
	float x;
	float y;
	float z;
	float w;

	vec4()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}

	vec4(float const x, float const y, float const z, float const w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	vec4(vec4 const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
	}

	vec4& operator=(vec4 const& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
		this->w = rhs.w;

		return *this;
	}

	vec4 operator-() const
	{
		return vec4(-this->x, -this->y, -this->z, -this->w);
	}

	vec4 operator+(vec4 const& rhs) const
	{
		return vec4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
	}

	vec4& operator+=(vec4 const& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;
		this->w += rhs.w;

		return *this;
	}

	vec4 operator-(vec4 const& rhs) const
	{
		return vec4(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
	}

	vec4& operator-=(vec4 const& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		this->w -= rhs.w;

		return *this;
	}

	vec4& operator*=(float const scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		this->w *= scalar;

		return *this;
	}

	vec4 operator*(float const scalar) const
	{
		return vec4(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
	}

	bool operator==(vec4 const& rhs) const
	{
		return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w);
	}

	bool operator!=(vec4 const& rhs) const
	{
		if (*this == rhs)
		{
			return false;
		}
		else return true;
	}

	float& operator[](unsigned int const i)
	{
		assert(0 <= i <= 3);

		switch (i)
		{
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		case 3:
			return this->w;
		}
	}

	float const& operator[](unsigned int const i) const
	{
		assert(0 <= i <= 3);

		switch (i)
		{
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		case 3:
			return this->w;
		}
	}
};

float dot(vec4 const& a, vec4 const& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

float length(vec4 const& v)
{
	return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

vec4 normalize(vec4 const& v)
{
	float l = length(v);

	return vec4(v.x / l, v.y / l, v.z / l, v.w / l);
}