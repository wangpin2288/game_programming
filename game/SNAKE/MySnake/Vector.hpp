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

struct Vector2f{
	float X;
	float Y;
	Vector2f():X(0),Y(0){};
	Vector2f(float v): X(v), Y(v){};
	Vector2f(float x, float y): X(x), Y(y){};
	Vector2f(const Vector2f& r): X(r.X), Y(r.Y){};
	Vector2f& operator=(const Vector2f& r){
		X = r.X;
		Y = r.Y;
		return *this;
	}
	Vector2f& operator+=(const Vector2f& r){
		X += r.X;
		Y += r.Y;
		return *this;
	}
	Vector2f& operator-=(const Vector2f& r){
		X -= r.X;
		Y -= r.Y;
		return *this;
	}
	bool operator==(const Vector2f& r){
		if(r.X != X) return false;
		else if(r.Y != Y) return false;
		return true;
	}
};

struct Vector3i{
	int X;
	int Y;
	int Z;
	Vector3i():X(0),Y(0),Z(0){}
	Vector3i(int v): X(v), Y(v),Z(v){}
	Vector3i(int x, int y, int z): X(x), Y(y),Z(z){}
	Vector3i(const Vector3i& r): X(r.X), Y(r.Y),Z(r.Z){}
	Vector3i& operator=(const Vector3i& r){
		X = r.X;
		Y = r.Y;
		Z = r.Z;
		return *this;
	}
	Vector3i& operator+=(const Vector3i& r){
		X += r.X;
		Y += r.Y;
		Z += r.Z;
		return *this;
	}
	Vector3i& operator-=(const Vector3i& r){
		X -= r.X;
		Y -= r.Y;
		Z -= r.Z;
		return *this;
	}
	bool operator==(const Vector3i& r){
		if(r.X != X) return false;
		else if(r.Y != Y) return false;
		else if(r.Z != Z) return false;
		return true;
	}
};

struct Vector3f{
	float X;
	float Y;
	float Z;
	Vector3f():X(0),Y(0),Z(0){}
	Vector3f(float v): X(v), Y(v),Z(v){}
	Vector3f(float x, float y, float z): X(x), Y(y),Z(z){}
	Vector3f(const Vector3f& r): X(r.X), Y(r.Y),Z(r.Z){}
	Vector3f& operator=(const Vector3f& r){
		X = r.X;
		Y = r.Y;
		Z = r.Z;
		return *this;
	}
	Vector3f& operator+=(const Vector3f& r){
		X += r.X;
		Y += r.Y;
		Z += r.Z;
		return *this;
	}
	Vector3f& operator-=(const Vector3f& r){
		X -= r.X;
		Y -= r.Y;
		Z -= r.Z;
		return *this;
	}
	bool operator==(const Vector3f& r){
		if(r.X != X) return false;
		else if(r.Y != Y) return false;
		else if(r.Z != Z) return false;
		return true;
	}
};

struct Vector4i{
	int X;
	int Y;
	int Z;
	int W;
	Vector4i():X(0),Y(0),Z(0),W(0){}
	Vector4i(int v): X(v), Y(v),Z(v),W(v){}
	Vector4i(int x, int y, int z,int w): X(x), Y(y),Z(z),W(w){}
	Vector4i(const Vector4i& r): X(r.X), Y(r.Y),Z(r.Z),W(r.W){}
	Vector4i& operator=(const Vector4i& r){
		X = r.X;
		Y = r.Y;
		Z = r.Z;
		W = r.W;
		return *this;
	}
	Vector4i& operator+=(const Vector4i& r){
		X += r.X;
		Y += r.Y;
		Z += r.Z;
		W += r.W;
		return *this;
	}
	Vector4i& operator-=(const Vector4i& r){
		X -= r.X;
		Y -= r.Y;
		Z -= r.Z;
		W -= r.W;
		return *this;
	}
	bool operator==(const Vector4i& r){
		if(r.X != X) return false;
		else if(r.Y != Y) return false;
		else if(r.Z != Z) return false;
		else if(r.W != W) return false;
		return true;
	}
};

struct Vector4f{
	float X;
	float Y;
	float Z;
	float W;
	Vector4f():X(0),Y(0),Z(0),W(0){}
	Vector4f(float v): X(v), Y(v),Z(v),W(v){}
	Vector4f(float x, float y, float z,float w): X(x), Y(y),Z(z),W(w){}
	Vector4f(const Vector4f& r): X(r.X), Y(r.Y),Z(r.Z),W(r.W){}
	Vector4f& operator=(const Vector4f& r){
		X = r.X;
		Y = r.Y;
		Z = r.Z;
		W = r.W;
		return *this;
	}
	Vector4f& operator+=(const Vector4f& r){
		X += r.X;
		Y += r.Y;
		Z += r.Z;
		W += r.W;
		return *this;
	}
	Vector4f& operator-=(const Vector4f& r){
		X -= r.X;
		Y -= r.Y;
		Z -= r.Z;
		W -= r.W;
		return *this;
	}
	bool operator==(const Vector4f& r){
		if(r.X != X) return false;
		else if(r.Y != Y) return false;
		else if(r.Z != Z) return false;
		else if(r.W != W) return false;
		return true;
	}
};
#endif
