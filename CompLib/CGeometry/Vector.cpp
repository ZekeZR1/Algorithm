#define equals(a,b) (fabs((a) - (b)) < EPS)

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;
#define XYSORT

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
#ifdef XYSORT
		return x != p.x ? x < p.x : y < p.y;
#endif 
#ifdef YXSORT
		return y != p.y ? y < p.y : x < p.x;
#endif 
	}

	bool operator==(const Point & p) const {
		return fabs(x - p.x) < EPS and fabs(y - p.y) < EPS;
	}
};

typedef Point Vector;
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

typedef Segment Line;

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
	return abs(cross(l.p2 - l.p1, p - l.p1) / Vector(l.p2 - l.p1).abs());
}

//線分ｓと点ｐの距離
double getDistanceSP(Segment s, Point p) {
	if (dot(s.p2 - s.p1, p - s.p1) < 0.0) {
		Point r = p - s.p1;
		return r.abs();
	}
	if (dot(s.p1 - s.p2, p - s.p2) < 0.0) {
		Point r = p - s.p2;
		return r.abs();
	}
	return getDistanceLP(s, p);
}

//counter clock wise
int ccw(Point p0, Point p1, Point p2) {
	Vector a = p1 - p0;
	Vector b = p2 - p0;
	if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
	if (cross(a, b) < -EPS) return CLOCKWISE;
	if (dot(a, b) < -EPS) return ONLINE_BACK;
	if (a.norm() < b.norm()) return ONLINE_FRONT;
	return ON_SEGMENT;
}

//線分と線分の交差判定
bool intersect(Point p1, Point p2, Point p3, Point p4) {
	return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 and
		ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2) {
	return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

//線分と線分の距離
double getDistance(Segment s1, Segment s2) {
	if (intersect(s1, s2)) return 0.0;
	return min(
		min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
		min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2))
	);
}

//線分s1と線分s2の交点
Point getCrossPoint(Segment s1, Segment s2) {
	Vector base = s2.p2 - s2.p1;
	double d1 = abs(cross(base, s1.p1 - s2.p1));
	double d2 = abs(cross(base, s1.p2 - s2.p1));
	double t = d1 / (d1 + d2);
	return s1.p1 + (s1.p2 - s1.p1) * t;
}

//円ｃと線分ｌの交差判定
bool intersect(Circle c, Line l) {
	return getDistanceSP(l, c.c) <= c.r;
}

//円ｃと線分ｌの交点
pair<Point, Point> getCrossPoints(Circle c, Line l) {
	assert(intersect(c, l));
	Vector pr = project(l, c.c);
	Vector e = (l.p2 - l.p1) / Vector(l.p2 - l.p1).abs();
	double base = sqrt(c.r * c.r - Vector(pr - c.c).norm());
	return make_pair(pr + e * base, pr - e * base);
}

//円c1と円c2の交点
double arg(Vector p) { return atan2(p.y, p.x); }
Vector polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }

pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
	double d = Vector(c1.c - c2.c).abs();
	double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
	double t = arg(c2.c - c1.c);
	return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}

//点の内包判定
static const int IN = 2;
static const int ON = 1;
static const int OUT = 0;
int contains(Polygon g, Point p) {
	int n = g.size();
	bool x = false;
	rep(i, n) {
		Point a = g[i] - p, b = g[(i + 1) % n] - p;
		if (abs(cross(a, b)) < EPS and dot(a, b) < EPS) return ON;
		if (a.y > b.y)swap(a, b);
		if (a.y < EPS and EPS < b.y and cross(a, b) > EPS) x = !x;
	}
	return (x ? IN : OUT);
}

//凸包
Polygon andrewScan(Polygon s) {
	Polygon u, l;
	if (s.size() < 3) return s;
	sort(s.begin(), s.end());
	u.push_back(s[0]);
	u.push_back(s[1]);
	l.push_back(s[s.size() - 1]);
	l.push_back(s[s.size() - 2]);
	for (int i = 2; i < s.size(); i++) {
		for (int n = u.size(); n >= 2 && ccw(u[n - 2], u[n - 1], s[i]) == COUNTER_CLOCKWISE; n--) {
			u.pop_back();
		}
		u.push_back(s[i]);
	}
	for (int i = s.size() - 3; i >= 0; i--) {
		for (int n = l.size(); n >= 2 && ccw(l[n - 2], l[n - 1], s[i]) == COUNTER_CLOCKWISE; n--) {
			l.pop_back();
		}
		l.push_back(s[i]);
	}
	reverse(l.begin(), l.end());

	for (int i = u.size() - 2; i >= 1; i--) l.push_back(u[i]);
	return l;
}

//マンハッタン幾何 平面走査
static const int BOTTOM = 0;
static const int LEFT = 1;
static const int RIGHT = 2;
static const int TOP = 3;
//端点
class EndPoint {
public:
	Point p;
	int seg, st;
	EndPoint() {}
	EndPoint(Point p, int seg, int st) : p(p), seg(seg), st(st) {}
	bool operator<(const EndPoint& ep) const {
		if (p.y == ep.p.y) {
			return st < ep.st;
		}
		else return p.y < ep.p.y;
	}
};

EndPoint EP[2 * 100000];

//線分交差判定
int manhattanIntersection(vector<Segment> s) {
	int n = s.size();
	for (int i = 0, k = 0; i < n; i++) {
		if (s[i].p1.y == s[i].p2.y) {
			if (s[i].p1.x > s[i].p2.x) swap(s[i].p1, s[i].p2);
		}
		else if (s[i].p1.y > s[i].p2.y) swap(s[i].p1, s[i].p2);

		if (s[i].p1.y == s[i].p2.y) {
			EP[k++] = EndPoint(s[i].p1, i, LEFT);
			EP[k++] = EndPoint(s[i].p2, i, RIGHT);
		}
		else {
			EP[k++] = EndPoint(s[i].p1, i, BOTTOM);
			EP[k++] = EndPoint(s[i].p2, i, TOP);
		}
	}

	sort(EP, EP + (2 * n));

	set<int> BT;
	BT.insert(1000000001);
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (EP[i].st == TOP) {
			BT.erase(EP[i].p.x);
		}
		else if (EP[i].st == BOTTOM) {
			BT.insert(EP[i].p.x);
		}
		else if (EP[i].st == LEFT) {
			auto b = BT.lower_bound(s[EP[i].seg].p1.x);
			auto e = BT.upper_bound(s[EP[i].seg].p2.x);
			cnt += distance(b, e);
		}
	}
	return cnt;
}