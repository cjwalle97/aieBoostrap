#pragma once
#pragma once

class Vec2
{
private:
	float x;
	float y;
public:
	Vec2() {};
	Vec2(float a, float b);
	Vec2 operator + (Vec2 other);
	Vec2 operator += (Vec2 other);
	Vec2 operator - (Vec2 other);
	Vec2 operator * (float scalar);
	float Magnitude();
	Vec2 Normalize();
	float DotProduct(Vec2 other);
};

class Vec3
{
private:
	float x;
	float y;
	float z;
public:
	Vec3() {};
	Vec3(float a, float b, float c);
	Vec3 operator + (Vec3 other);
	Vec3 operator - (Vec3 other);
	Vec3 operator *(float scalar);
	float Magnitude();
	Vec3 Normalize();
	float DotProduct(Vec3 other);
	Vec3 CrossProduct(Vec3 other);
};

class Vec4
{
private:
	float x;
	float y;
	float z;
public:
	Vec4() {};
	Vec4(float a, float b, float c);
	Vec4 operator + (Vec4 other);

	Vec4 operator - (Vec4 other);
	Vec4 operator * (float scalar);
	float Magnitude();
	Vec4 Normalize();
	float DotProduct(Vec4 other);
	Vec4 CrossProduct(Vec4 other);
};

class Mat2
{
private:
	float data[4];
public:
	Mat2() {};
	Mat2(float x1, float y1, float x2, float y2);
	//Mat2 (float Array [4] );
	Mat2 Multiplication(Mat2 other);
};

class Mat3
{
private:
	float data[9];
public:
	Mat3() {};
	Mat3(float x1, float y1, float z1,
		float x2, float y2, float z2,
		float x3, float y3, float z3);
	Mat3 Multiplication(Mat3 other);
	//Mat3 SetRotateX(float rotation);
	//Mat3 SetRotateY(float rotation);
	//Mat3 SetRotateZ(float rotation);
};

class Mat4
{
private:
float data[16];
public:
	Mat4() {};
	Mat4(float x1, float y1, float z1, float t1,
		float x2, float y2, float z2, float t2,
		float x3, float y3, float z3, float t3, 
		float b1, float b2, float b3, float b4);
	Mat4 Multiplication(Mat4 other);
	//Mat4 SetRotateX(float rotation);
	//Mat4 SetRotateY(float rotation);
	//Mat4 SetRotateZ(float rotation);
	//Mat4 AddMat3(Mat3 other);
};