#include "MyVector2.h"

float vectorLength(sf::Vector2f t_vector)		// get length of vector using sqrt of the sum of the squares
{
	float sumOfSquares = (t_vector.x * t_vector.x ) + (t_vector.y * t_vector.y);
	const float length = sqrt(sumOfSquares);
	return length;
}

float vectorLengthSquared(sf::Vector2f t_vector)		// get the length of the vector squared by using the sum of the squares
{
	const float lengthSquared = (t_vector.x * t_vector.x) + (t_vector.y * t_vector.y);
	return lengthSquared;
}

// get the cross product of the vectors by taking the product of the x and y of the two vectors
float vectorCorssProduct(sf::Vector2f t_vectorA, sf::Vector2f t_VectorB)		
{
	const float crossProduct = t_vectorA.x *t_VectorB.y - t_vectorA.y * t_VectorB.x;
	return crossProduct;
}

// get the dot product of the two vectors by taking the product of the two y's of the vectors from the product of the two x's of the vectors
float vectorDotProduct(sf::Vector2f t_vectorA, sf::Vector2f t_VectorB)
{
	const float dotProduct = (t_vectorA.x *t_VectorB.x) + (t_vectorA.y * t_VectorB.y);
	return dotProduct;
}

// get the angle between the vectors by dividing the dot product of the vectors by 
// the product of their magnitudes multiplied by 180 degrees divided by PI
float vectorAngleBetween(sf::Vector2f t_vectorA, sf::Vector2f t_VectorB)
{
	float cosine = vectorDotProduct(vectorUnitVector(t_vectorA), vectorUnitVector(t_VectorB));
	if (cosine > 1.0f)
	{
		cosine = 1.0f;
	}
	if (cosine < -1.0f)
	{
		cosine = -1.0f;
	}
	const float angleInRadians = std::acos(cosine);
	const float angleInDegrees = angleInRadians * 180.0f / PI;
	return angleInDegrees;
}

// get how much one of the vectors have to rotate to be in line with the other vector by using
// the cos and sin of the angle between them in radians and multiplying them by the components of the vector being moved
sf::Vector2f vectorRotateBy(sf::Vector2f t_vector, float t_angleRadians)
{
	const float cos = std::cos(t_angleRadians);		// calculate once use twice
	const float sin = std::sin(t_angleRadians);
	const float xComponent = (t_vector.x * cos) - (t_vector.y * sin);
	const float yComponent = (t_vector.x * sin) + (t_vector.y * cos);
	const sf::Vector2f result{ xComponent,yComponent };
	return sf::Vector2f(result);
}

// get the projection of the vectors by dividing the dot product from the two vectors,
// divided by the magnitude of the second vector, multiplied by the second vector divided by it's magnitude
sf::Vector2f vectorProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	const float dotProduct = vectorDotProduct(t_vector, t_onto);
	const float magnitude = vectorLength(t_onto);
	const float scale = (dotProduct / magnitude);
	const sf::Vector2f result = t_onto * scale;
	return sf::Vector2f(result);
}

// find the vector rejection by taking the projection from the vector
sf::Vector2f vectorRejection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	sf::Vector2f projection = vectorProjection(t_vector, t_onto);
	sf::Vector2f rejection = t_vector - projection;
	return sf::Vector2f(rejection);
}

// find the scalar prjection by getting the magnitude of the projection
float vectorScalarProjection(sf::Vector2f t_vector, sf::Vector2f t_onto)
{
	const float scalerProjection = vectorDotProduct(t_vector, t_onto) / vectorLength(t_onto);
	return scalerProjection;
}

// find the unit vector by multiplying each component of the vector by the magnitude
sf::Vector2f vectorUnitVector(sf::Vector2f t_vector)
{
	sf::Vector2f result{ 0.0f, 0.0f };
	const float length = vectorLength(t_vector);
	if (length != 0.0f)		// NEVER DIVIDE BY ZERO
	{
		result = sf::Vector2f{ t_vector.x / length, t_vector.y / length };
	}
	return result;
}
