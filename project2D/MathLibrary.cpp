#include <iostream>
#include "MathLibraryHeader.h"

//Name: Vec2
//Type: Vec2
//Description: 2D Vector
Vec2::Vec2(float a, float b) {
	x = a;
	y = b;
}
//Name: operator+
//Type: Vec2
//Description: overloads the + operator in order to add the axis one Vector to another 
Vec2 Vec2::operator + (Vec2 other)
{
	return Vec2(x + other.x, y + other.y);
}
//Name operator+=
//Tyoe Vec2
//description: overlads the += operator in order to add a float to the axis of a Vector
Vec2 Vec2::operator += (Vec2 other)
{
	return Vec2(x += other.x, y += other.y);
}
//Name: operator-
//Type: Vec2
//Description: overloads the - operator in order to subtract the axis of one Vector from another
Vec2 Vec2::operator - (Vec2 other)
{
	return Vec2(x - other.x, y - other.y);
}
//Name: operator*
//Type: Vec2
//Description: overloads the * operator to allow a 2D Vector to be multiplied by a scalar float
Vec2 Vec2::operator * (float scalar)
{
	return Vec2(x * scalar, y * scalar);
}
//Name: Magnitude
//Type: float
//Description: finds the square root of all axis on the Vector added together after squaring them
float Vec2::Magnitude()
{
	return sqrt((x*x) + (y*y));
}
//Name: Normalize
//Type: Vec2
//Description: Normalizes a 2d Vector by dividing all axis by the Vector's Magnitude
Vec2 Vec2::Normalize()
{
	return Vec2(x / Magnitude(), y / Magnitude());
}
//Name: DotProduct
//Type: float
//Description: adds the products of all the axis of two Vectors together
float Vec2::DotProduct(Vec2 other)
{
	return x*other.x + y*other.y;
}

//Name: Vec3
//Type: Vec3
//Description: 3D Vector
Vec3::Vec3(float a, float b, float c) {
	x = a;
	y = b;
	z = c;
}
//Name: operator+
//Type: Vec3
//Description: overloads the + operator in order to add the axis of one Vector to another
Vec3 Vec3::operator + (Vec3 other)
{
	return Vec3(x + other.x, y + other.y, z + other.z);
}
//Name: operator-
//Type: Vec3
//Description: overloads the - operator in order to subtract the axis of one Vector from another
Vec3 Vec3::operator - (Vec3 other)
{
	return Vec3(x - other.x, y - other.y, z - other.z);
}
//Name: operator*
//Type: Vec3
//Description:
Vec3 Vec3::operator *(float scalar)
{
	return Vec3(x * scalar, y* scalar, z * scalar);
}
//Name: Magnitude
//Type: float
//Description: finds the square root of all axis on the Vector added together after squaring them 
float Vec3::Magnitude()
{
	return sqrt((x*x) + (y*y) + (z*z));
}
//Name: Normalize
//Type: Vec3
//Description: 
Vec3 Vec3::Normalize()
{
	return Vec3(x / Magnitude(), y / Magnitude(), z / Magnitude());
}
//Name: DotProduct
//Type: float 
//Description: adds the products of all the axis of two 3D Vectors together
float Vec3::DotProduct(Vec3 other)
{
	return x*other.x + y*other.y + z*other.z;
}
//Name: CrossProduct
//Type: Vec3
//Description: finds the Crossproduct of 2 Vectors by multipling and subtracting their axis
Vec3 Vec3::CrossProduct(Vec3 other)
{
	float Crossx = y*other.z - z* other.y;
	float Crossy = x*other.z - z*other.x;
	float Crossz = x*other.y - y*other.x;
	return Vec3(Crossx, Crossy, Crossz);
}

//Name: Vec4
//Type: Vec4
//Description: 4D Vector
Vec4::Vec4(float a, float b, float c) {
	x = a;
	y = b;
	z = c;
}
//Name: operator+
//TYpe: Vec4
//Description: overloads the + operator in order to add the axis of one Vector to another 
Vec4 Vec4::operator + (Vec4 other)
{
	return Vec4(x + other.x, y + other.y, z + other.z);
}
//Name: operator -
//Type: Vec4
//Description: overloads the - operator in order to subtract the axis of one Vector to another  
Vec4 Vec4::operator - (Vec4 other)
{
	return Vec4(x - other.x, y - other.y, z - other.z);
}
//Name: operator*
//Type: Vec4
//Description: overloads the * operator in order to add the axis of one Vector to another
Vec4 Vec4::operator * (float scalar)
{
	return Vec4(x*scalar, y*scalar, z*scalar);
}
//Name: Magnitude
//Type: float
//Description: finds the square root of all axis on the Vector added together after squaring them
float Vec4::Magnitude()
{
	return sqrt((x*x) + (y*y) + (z*z));
}
//Name: Normalize
//Type: Vec4
//Description: Normalizes the Vector by dividing all axis by Magnitude
Vec4 Vec4::Normalize()
{
	return Vec4(x / Magnitude(), y / Magnitude(), z / Magnitude());
}
//Name: DotProduct
//Type: float
//Description: adds the products of all the axis of two 4D Vectors together
float Vec4::DotProduct(Vec4 other)
{
	return x*other.x + y*other.y + z*other.z;
}
//Name: CrossProduct
//Type: Vec4
//Description: finds the Crossproduct of 2 Vectors by multipling and subtracting their axis
Vec4 Vec4::CrossProduct(Vec4 other)
{
	float Crossx = y*other.z - z* other.y;
	float Crossy = x*other.z - z*other.x;
	float Crossz = x*other.y - y*other.x;
	return Vec4(Crossx, Crossy, Crossz);
}

//Name: Mat2
//Type: Mat2
//Description: 2D Matrix
Mat2::Mat2(float x1, float y1, float x2, float y2) {
	data[0] = x1;
	data[1] = y1;
	data[2] = x2;
	data[3] = y2;
}
//Mat2::Mat2(float Array[4]) {
//	for (int i = 0; i < 3; i++)
//	{
//		Array[i] = data[i];
//	}
//}
//Name: Multiplication
//Type: Mat2
//Description: finds the product of two Matrices
Mat2 Mat2::Multiplication(Mat2 other)
{
	return Mat2((data[0] * other.data[0]) - (data[1] * other.data[2]), (data[0] * other.data[1]) - (data[1] * other.data[3]),
		(data[2] * other.data[0]) - (data[3] * other.data[1]), (data[2] * other.data[2]) - (data[3] * data[3]));
}

//Name: Mat3
//Type: Mat3
//Description: 3D Matrix
Mat3::Mat3(float x1, float y1, float z1,
	float x2, float y2, float z2,
	float x3, float y3, float z3) {
	data[0] = x1;
	data[1] = y1;
	data[2] = z1;
	data[3] = x2;
	data[4] = y2;
	data[5] = z2;
	data[6] = x3;
	data[7] = y3;
	data[8] = z3;
}
//Name: Multiplication
//Type: Mat3
//Description: finds the product of two Matrices
Mat3 Mat3::Multiplication(Mat3 other)
{
	return Mat3(
		(data[0] * other.data[0]) - (data[1] * other.data[1]) - (data[2] * other.data[2]),
		(data[0] * other.data[3]) - (data[1] * other.data[4]) - (data[2] * other.data[5]),
		(data[0] * other.data[6]) - (data[1] * other.data[7]) - (data[2] * other.data[8]),
		(data[3] * other.data[0]) - (data[4] * other.data[1]) - (data[5] * other.data[2]),
		(data[3] * other.data[3]) - (data[4] * other.data[4]) - (data[5] * other.data[5]),
		(data[3] * other.data[6]) - (data[4] * other.data[7]) - (data[5] * other.data[8]),
		(data[6] * other.data[0]) - (data[7] * other.data[1]) - (data[8] * other.data[2]),
		(data[6] * other.data[3]) - (data[7] * other.data[4]) - (data[8] * other.data[5]),
		(data[6] * other.data[6]) - (data[7] * other.data[7]) - (data[8] * other.data[8]));
}
//Name: SetRotateX
//Type: Mat3
//Description: rotates a Matrix around it's X axis
//Mat3 Mat3::SetRotateX(float rotation)
//{
//	return Mat3((data[0] * rotation) , (data[1] * rotation) , (data[2] * rotation),
//		(data[3] * rotation) , (data[4] * 0) , (data[5] * 0),
//		(data[6] * rotation) , (data[7] * 0) , (data[8] * 0));
//}
////Name: SetRotateY
////Type: Mat3
////Description: rotates a Marix around it's Y axis
//Mat3 Mat3::SetRotateY(float rotation)
//{
//	return Mat3(
//		(data[0] * 0), (data[1] * 0), (data[2] * 0),
//		(data[3] * 0), (data[4] * rotation ), (data[5] * rotation), 
//		(data[6] * 0), (data[7] * rotation), (data[8] * 0))
//}
////Name: SetRotateZ
////Type: Mat3
////Description: rotates a Matrix around it's Z axis
//Mat3 Mat3::SetRotateZ(float rotation)
//{
//	return Mat3(
//		(data[0] * ), (data[1] * ), (data[2] * ), 
//		(data[3] * ), (data[4] * ), (data[5] * ),
//		(data[6] * ), (data[7] * ), (data[8] * ))
//}

//Name: Mat4
//Type: Mat4
//Description: finds the product of two Matrices
Mat4::Mat4(float x1, float y1, float z1, float t1,
	float x2, float y2, float z2, float t2,
	float x3, float y3, float z3, float t3,
	float b1, float b2, float b3, float b4) {
	data[0] = x1;
	data[1] = y1;
	data[2] = z1;
	data[3] = t1;
	data[4] = x2;
	data[5] = y2;
	data[6] = z2;
	data[7] = t2;
	data[8] = x3;
	data[9] = y3;
	data[10] = z3;
	data[11] = t3;
	data[12] = b1;
	data[13] = b2;
	data[14] = b3;
	data[15] = b4;
}
//Name: Multiplication
//Type: Mat4
//Description:
Mat4 Mat4::Multiplication(Mat4 other)
{
	return Mat4(
		(data[0] * other.data[0]) - (data[1] * other.data[1]) - (data[2] * other.data[2]) - (data[3] * other.data[3]),
		(data[0] * other.data[4]) - (data[1] * other.data[5]) - (data[2] * other.data[6]) - (data[3] * other.data[7]),
		(data[0] * other.data[8]) - (data[1] * other.data[9]) - (data[2] * other.data[10]) - (data[3] * other.data[11]),
		(data[0] * other.data[12]) - (data[1] * other.data[13]) - (data[2] * other.data[14]) - (data[3] * other.data[15]),
		(data[4] * other.data[0]) - (data[5] * other.data[1]) - (data[6] * other.data[2]) - (data[7] * other.data[3]),
		(data[4] * other.data[4]) - (data[5] * other.data[5]) - (data[6] * other.data[6]) - (data[7] * other.data[7]),
		(data[4] * other.data[8]) - (data[5] * other.data[9]) - (data[6] * other.data[10]) - (data[7] * other.data[11]),
		(data[4] * other.data[12]) - (data[5] * other.data[13]) - (data[6] * other.data[14]) - (data[7] * other.data[15]),
		(data[8] * other.data[0]) - (data[9] * other.data[1]) - (data[10] * other.data[2]) - (data[11] * other.data[3]),
		(data[8] * other.data[4]) - (data[9] * other.data[5]) - (data[10] * other.data[6]) - (data[11] * other.data[7]),
		(data[8] * other.data[8]) - (data[9] * other.data[9]) - (data[10] * other.data[10]) - (data[11] * other.data[11]),
		(data[8] * other.data[12]) - (data[9] * other.data[13]) - (data[10] * other.data[14]) - (data[11] * other.data[15]),
		(data[12] * other.data[0]) - (data[13] * other.data[1]) - (data[14] * other.data[2]) - (data[15] * other.data[3]),
		(data[12] * other.data[4]) - (data[13] * other.data[5]) - (data[14] * other.data[6]) - (data[15] * other.data[7]),
		(data[12] * other.data[8]) - (data[13] * other.data[9]) - (data[14] * other.data[10]) - (data[15] * other.data[11]),
		(data[12] * other.data[12]) - (data[13] * other.data[13]) - (data[14] * other.data[14]) - (data[15] * other.data[15])
	);
}
//Name: SetRotateX
//Type: Mat4
//Description: rotates a Matrix around it's X axis
//Mat4 Mat4::SetRotateX(float rotation)
//{
//	return Mat4((data[0] * rotation), (data[1] * rotation), (data[2] * rotation), (data[3] * rotation),
//		(data[4] * rotation), (data[5] * 0), (data[6] * 0), (data[7] * 0),
//		(data[8] * rotation), (data[9] * 0), (data[10] * 0), (data[11] * 0),
//		(data[12] * rotation), (data[13] * 0), (data[14] * 0), (data[15] * 0))
//}
////Name: SetRotateY
////Type: Mat4
////Description: rotates a Matrix around it's Y axis
//Mat4 Mat4::SetRotateY(float rotation)
//{
//	return Mat4(
//		(data[0] * 0), (data[1] * ), (data[2] * ), (data[3] * ),
//		(data[4] * ), (data[5] * ), (data[6] * ), (data[7] * ),
//		(data[8] * ), (data[9] * ), (data[10] * ), (data[11] * ),
//		(data[12] * ), (data[13] * ), (data[14] * ), (data[15] * ))
//}
////Name: SetRotateZ
////Type: Mat4
////Description: rotates a Matrix around it's Z axis
//Mat4 Mat4::SetRotateZ(float rotation)
//{
//	return Mat4(
//		(data[0] * ), (data[1] * ), (data[2] * ), (data[3] * ),
//		(data[4] * ), (data[5] * ), (data[6] * ), (data[7] * ),
//		(data[8] * ), (data[9] * ), (data[10] * ), (data[11] * ),
//		(data[12] * ), (data[13] * ), (data[14] * ), (data[15] * ))
//}
//Name: AddMat3
//Type: Mat4
//Description: adds a 3D Matrix to a 4D Matrix
//Mat4 Mat4::AddMat3(Mat3 other){
//	return Mat4 ()
//}