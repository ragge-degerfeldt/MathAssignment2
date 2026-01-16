#pragma once
#include <cmath>
#include <cassert>

class vec2
{
public:
	float x;
	float y;

	vec2()
	{
		this->x = 0;
		this->y = 0;
	}

	vec2(float const x, float const y)
	{
		this->x = x;
		this->y = y;
	}

	vec2(vec2 const& v)
	{
		this->x = v.x;
		this->y = v.y;
	}

	vec2& operator=(vec2 const& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		this->x = rhs.x;
		this->y = rhs.y;

		return *this;
	}

	vec2 operator-() const
	{
		return vec2(-this->x, -this->y);
	}

	vec2 operator+(vec2 const& rhs) const
	{
		return vec2(this->x + rhs.x, this->y + rhs.y);
	}

	vec2& operator+=(vec2 const& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;

		return *this;
	}

	vec2 operator-(vec2 const& rhs) const
	{
		return vec2(this->x - rhs.x, this->y - rhs.y);
	}

	vec2& operator-=(vec2 const& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;

		return *this;
	}

	vec2& operator*=(float const scalar)
	{
		this->x *= scalar;
		this->y *= scalar;

		return *this;
	}

	vec2 operator*(float const scalar) const
	{
		return vec2(this->x * scalar, this->y * scalar);
	}

	bool operator==(vec2 const& rhs) const
	{
		return (this->x == rhs.x && this->y == rhs.y);
	}

	bool operator!=(vec2 const& rhs) const
	{
		if (*this == rhs)
		{
			return false;
		}
		else return true;
	}

	float& operator[](unsigned int const i)
	{
		assert(0 <= i <= 1);

		switch (i)
		{
		case 0:
			return this->x;
		case 1:
			return this->y;
		}
	}

	float const& operator[](unsigned int const i) const
	{
		assert(0 <= i <= 1);

		switch (i)
		{
		case 0:
			return this->x;
		case 1:
			return this->y;
		}
	}
};

class vec3
{
public:
	float x;
	float y;
	float z;

	vec3()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	vec3(float const x, float const y, float const z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	vec3(vec3 const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}

	vec3& operator=(vec3 const& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;

		return *this;
	}

	vec3 operator-() const
	{
		return vec3(-this->x, -this->y, -this->z);
	}

	vec3 operator+(vec3 const& rhs) const
	{
		return vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
	}

	vec3& operator+=(vec3 const& rhs)
	{
		this->x += rhs.x;
		this->y += rhs.y;
		this->z += rhs.z;

		return *this;
	}

	vec3 operator-(vec3 const& rhs) const
	{
		return vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
	}

	vec3& operator-=(vec3 const& rhs)
	{
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;

		return *this;
	}

	vec3& operator*=(float const scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;

		return *this;
	}

	vec3 operator*(float const scalar) const
	{
		return vec3(this->x * scalar, this->y * scalar, this->z * scalar);
	}

	bool operator==(vec3 const& rhs) const
	{
		return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
	}

	bool operator!=(vec3 const& rhs) const
	{
		if (*this == rhs)
		{
			return false;
		}
		else return true;
	}

	float& operator[](unsigned int const i)
	{
		assert(0 <= i <= 2);

		switch (i)
		{
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		}
	}

	float const& operator[](unsigned int const i) const
	{
		assert(0 <= i <= 2);

		switch (i)
		{
		case 0:
			return this->x;
		case 1:
			return this->y;
		case 2:
			return this->z;
		}
	}
};

float dot(vec3 const& a, vec3 const& b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

float length(vec3 const& v)
{
	return sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

vec3 cross(vec3 const& a, vec3 const& b)
{
	float x = (a.y * b.z) - (b.y * a.z);
	float y = (a.z * b.x) - (b.z * a.x);
	float z = (a.x * b.y) - (b.x * a.y);

	return vec3(x, y, z);
}

vec3 normalize(vec3 const& v)
{
	float l = length(v);
	
	return vec3(v.x / l, v.y / l, v.z / l);
}