#pragma once
#include <cmath>
#include <cassert>

class mat3
{
public:
	vec3 m[3];
	mat3()
	{
		float o = 0.0f;
		float l = 1.0f;
		m[0] = vec3(l, o, o);
		m[1] = vec3(o, l, o);
		m[2] = vec3(o, o, l);
	}

	mat3(vec3 const& r0, vec3 const& r1, vec3 const& r2, vec3 const& r3)
	{
		m[0] = r0;
		m[1] = r1;
		m[2] = r2;
	}

	mat3(mat3 const& m)
	{
		this->m[0] = m[0];
		this->m[1] = m[1];
		this->m[2] = m[2];
	}

	mat3& operator=(mat3 const& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		this->m[0] = rhs[0];
		this->m[1] = rhs[1];
		this->m[2] = rhs[2];

		return *this;
	}

	mat3 operator*(mat3 const& rhs) const
	{
		mat3 product = mat3();
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				product.m[i][j] =
					(this->m[i][0] * rhs[0][j]) +
					(this->m[i][1] * rhs[1][j]) +
					(this->m[i][2] * rhs[2][j]);
			}
		}
		return product;
	}


	vec3 operator*(vec3 const& rhs) const
	{
		vec3 product = vec3();
		for (int i = 0; i <= 2; i++)
		{
			product[i] =
				(this->m[i][0] * rhs[0]) +
				(this->m[i][1] * rhs[1]) +
				(this->m[i][2] * rhs[2]);
		}
		return product;
	}

	bool operator==(mat3 const& rhs) const
	{
		return (this->m[0] == rhs[0] && this->m[1] == rhs[1] && this->m[2] == rhs[2]);
	}

	bool operator!=(mat3 const& rhs) const
	{
		if (*this == rhs)
		{
			return false;
		}
		else return true;
	}

	vec3& operator[](unsigned int const i)
	{
		assert(0 <= i <= 3);
		return this->m[i];
	}


	vec3 const& operator[](unsigned int const i) const
	{
		assert(0 <= i <= 3);
		return this->m[i];
	}
};

class mat2
{
public:
	vec2 m[2];
	mat2()
	{
		float o = 0.0f;
		float l = 1.0f;
		m[0] = vec2(l, o);
		m[1] = vec2(o, l);
	}

	mat2(vec2 const& r0, vec2 const& r1)
	{
		m[0] = r0;
		m[1] = r1;
	}

	mat2(mat2 const& m)
	{
		this->m[0] = m[0];
		this->m[1] = m[1];
	}

	mat2& operator=(mat2 const& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		this->m[0] = rhs[0];
		this->m[1] = rhs[1];

		return *this;
	}

	mat2 operator*(mat2 const& rhs) const
	{
		mat2 product = mat2();
		for (int i = 0; i <= 1; i++)
		{
			for (int j = 0; j <= 1; j++)
			{
				product.m[i][j] =
					(this->m[i][0] * rhs[0][j]) +
					(this->m[i][1] * rhs[1][j]);
			}
		}
		return product;
	}


	vec2 operator*(vec2 const& rhs) const
	{
		vec2 product = vec2();
		for (int i = 0; i <= 1; i++)
		{
			product[i] =
				(this->m[i][0] * rhs[0]) +
				(this->m[i][1] * rhs[1]);
		}
		return product;
	}

	bool operator==(mat2 const& rhs) const
	{
		return (this->m[0] == rhs[0] && this->m[1] == rhs[1]);
	}

	bool operator!=(mat2 const& rhs) const
	{
		if (*this == rhs)
		{
			return false;
		}
		else return true;
	}

	vec2& operator[](unsigned int const i)
	{
		assert(0 <= i <= 1);
		return this->m[i];
	}


	vec2 const& operator[](unsigned int const i) const
	{
		assert(0 <= i <= 1);
		return this->m[i];
	}
};

class mat4
{
public:
	vec4 m[4];

	mat4()
	{
		float o = 0.0f;
		float l = 1.0f;
		m[0] = vec4(l, o, o, o);
		m[1] = vec4(o, l, o, o);
		m[2] = vec4(o, o, l, o);
		m[3] = vec4(o, o, o, l);
	}

	mat4(vec4 const& r0, vec4 const& r1, vec4 const& r2, vec4 const& r3)
	{
		m[0] = r0;
		m[1] = r1;
		m[2] = r2;
		m[3] = r3;
	}

	mat4(mat4 const& m)
	{
		this->m[0] = m[0];
		this->m[1] = m[1];
		this->m[2] = m[2];
		this->m[3] = m[3];
	}

	mat4& operator=(mat4 const& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		this->m[0] = rhs[0];
		this->m[1] = rhs[1];
		this->m[2] = rhs[2];
		this->m[3] = rhs[3];

		return *this;
	}

	mat4 operator*(mat4 const& rhs) const
	{
		mat4 product = mat4();
		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 3; j++)
			{
				product.m[i][j] =
					(this->m[i][0] * rhs[0][j]) +
					(this->m[i][1] * rhs[1][j]) +
					(this->m[i][2] * rhs[2][j]) +
					(this->m[i][3] * rhs[3][j]);
			}
		}
		return product;
	}


	vec4 operator*(vec4 const& rhs) const
	{
		vec4 product = vec4();
		for (int i = 0; i <= 3; i++)
		{
			product[i] =
				(this->m[i][0] * rhs[0]) +
				(this->m[i][1] * rhs[1]) +
				(this->m[i][2] * rhs[2]) +
				(this->m[i][3] * rhs[3]);
		}
		return product;
	}

	bool operator==(mat4 const& rhs) const
	{
		return (this->m[0] == rhs[0] && this->m[1] == rhs[1] && this->m[2] == rhs[2] && this->m[3] == rhs[3]);
	}

	bool operator!=(mat4 const& rhs) const
	{
		if (*this == rhs)
		{
			return false;
		}
		else return true;
	}

	vec4& operator[](unsigned int const i)
	{
		assert(0 <= i <= 3);
		return this->m[i];
	}


	vec4 const& operator[](unsigned int const i) const
	{
		assert(0 <= i <= 3);
		return this->m[i];
	}
};


float determinant(mat2 const& m)
{
	return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
}

float determinant(mat3 const& m)
{
	int res = 0;
	for (int col = 0; col < 3; ++col)
	{

		mat2 sub = mat2();
		for (int i = 1; i < 3; ++i)
		{
			int subcol = 0;
			for (int j = 0; j < 3; ++j)
			{

				if (j == col) continue;

				sub[i - 1][subcol++] = m[i][j];
			}
		}

		int sign = (col % 2 == 0) ? 1 : -1;
		res += sign * m[0][col] * determinant(sub);
	}

	return res;
}

mat3 minor(mat4 const& m, int row, int col)
{
	mat3 sub = mat3();
	int subrow = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (i == row) { continue; }
		int subcol = 0;
		for (int j = 0; j < 4; ++j)
		{
			if (j == col) { continue; }
			sub[subrow][subcol] = m[i][j];
			subcol++;
		}
		subrow++;
	}

	return sub;
}

float cofactor(mat4 const& m, int row, int col)
{
	mat3 sub = minor(m, row, col);


	int sign = ((row + col) % 2 == 0) ? 1 : -1;
	return sign * determinant(sub);
}

float determinant(mat4 const& m)
{
	int res = 0;
	for (int col = 0; col < 4; ++col)
	{
		float co = cofactor(m, 0, col);
		res += m[0][col] * co;
	}

	return res;
}

mat4 transpose(mat4 const& m)
{
	mat4 result = mat4();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result[i][j] = m[j][i];
		}
	}

	return result;
}

mat4 inverse(mat4 const& m)
{
	if (determinant(m) == 0.0f) { return mat4(); }

	mat4 stage1 = mat4();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			stage1[i][j] = cofactor(m, i, j);
		}
	}
	mat4 stage2 = transpose(stage1);
	float divdet = 1.0f / determinant(m);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			stage2[i][j] *= divdet;
		}
	}
	return stage2;
}



mat4 rotationx(float const rad)
{
	vec4 r0 = vec4(1.0f, 0.0f, 0.0f, 0.0f);
	vec4 r1 = vec4(0.0f, cosf(rad), sinf(rad), 0.0f);
	vec4 r2 = vec4(0.0f, -sinf(rad), cosf(rad), 0.0f);
	vec4 r3 = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	return mat4(r0,r1,r2,r3);

}

mat4 rotationy(float const rad)
{
	vec4 r0 = vec4(cosf(rad), 0.0f, -sinf(rad), 0.0f);
	vec4 r1 = vec4(0.0f, 1.0f, 0.0f, 0.0f);
	vec4 r2 = vec4(sinf(rad), 0.0f, cosf(rad), 0.0f);
	vec4 r3 = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	return mat4(r0, r1, r2, r3);
}

mat4 rotationz(float const rad)
{
	vec4 r0 = vec4(cosf(rad), -sinf(rad), 0.0f, 0.0f);
	vec4 r1 = vec4(sinf(rad), cosf(rad), 0.0f, 0.0f);
	vec4 r2 = vec4(0.0f, 0.0f, 1.0f, 0.0f);
	vec4 r3 = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	return mat4(r0, r1, r2, r3);
}

mat4 rotationaxis(vec3 const& v, float const rad)
{
	return mat4();

}

