#define equals(a,b) (fabs((a) - (b)) < EPS)

class Point {
public:
	double x, y;

	Point(double x = 0, double y = 0) : x(x), y(y) {}

	Point operator+(Point p) { return Point(x + p.x, y + p.y); }
	Point operator-(Point p) { return Point(x - p.x, y - p.y); }
	Point operator*(double a) { return Point(a * x, a * y); }
	Point operator / (double a) { return Point(x / a, y / a); }

	double norm() { return x * x + y * y; }
	double abs() { return sqrt(norm()); }

	bool operator<(const Point & p) const {
		return x != p.x ? x < p.x : y < p.y;
	}

	bool operator==(const Point & p) const {
		return fabs(x - p.x) < EPS and fabs(y - p.y) < EPS;
	}
};

typedef Point Vector;
typedef Segment Line;
typedef vector<Point> Polygon;

double dot(Vector a, Vector b) {
	return a.x* b.x + a.y * b.y;
}

double cross(Vector a, Vector b) {
	return a.x* b.y - a.y * b.x;
}

class Segment {
public:
	Point p1, p2;
	Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};

class Circle {
public:
	Point c;
	double r;
	Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

//直交判定
bool isOrthogonal(Vector a, Vector b) {
	return equals(dot(a, b), 0.0);
}

bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
	return isOrthogonal(a1 - a2, b1 - b2);
}

bool isOrthogonal(Segment s1, Segment s2) {
	return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

//平行判定
bool isParallel(Vector a, Vector b) {
	return equals(cross(a, b), 0.0);
}

bool isParallel(Point a1, Point a2, Point b1, Point b2) {
	return isParallel(a1 - a2, b1 - b2);
}

bool isParallel(Segment s1, Segment s2) {
	return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

//線分sに対する点pの射影
Point project(Segment s, Point p) {
	Vector base = s.p2 - s.p1;
	double r = dot(p - s.p1, base) / base.norm();
	return s.p1 + base * r;
}

//線分ｓに対する点ｐの反射
Point refrect(Segment s, Point p) {
	return p + (project(s, p) - p) * 2.0;
}

//2点間の距離
double getDistance(Point a, Point b) {
	Point res = a - b;
	return res.abs();
}
//点と直線の距離
double getDistanceLP(Line l, Point p) {
	return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}

//線分ｓと点ｐの距離
double getDistanceSP(Segment s, Point p) {
	if (dot(s.p2 - s.p1, p - s.p1) < 0.0) {
		Point r = p - s.p1;
		return r.abs();
	}
}

//線分と線分の交差判定
bool intersect(Segment s1, Segment s2) {
	//return ( ccw())
}

//線分と線分の距離
double getDistance(Segment s1, Segment s2) {
	if (intersect(s1, s2)) return 0.0;
	return min(
		min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
		min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2))
	);
}