#ifndef VECTOR_HPP
#define VECTOR_HPP

using namespace std;

struct Vector2i{
	int X;
	int Y;
	Vector2i():X(0),Y(0){};
	Vector2i(int v): X(v), Y(v){};
	Vector2i(int x, int y): X(x), Y(y){};
	Vector2i(const Vector2i& r): X(r.X), Y(r.Y){};
	Vector2i& operator=(const Vector2i& r){
		X = r.X;
		Y = r.Y;
		return *this;
	}
	Vector2i& operator+=(const Vector2i& r){
		X += r.X;
		Y += r.Y;
		return *this;
	}
	Vector2i& operator-=(const Vector2i& r){
		X -= r.X;
		Y -= r.Y;
		return *this;
	}
	bool operator==(const Vector2i& r){
		if(r.X != X) return false;
		else if(r.Y != Y) return false;
		return true;
	}
};

#endif
