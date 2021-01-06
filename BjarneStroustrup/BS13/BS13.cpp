#include "Simple_window.h";
#include "Graph.h";
#include "Point.h";
#include "Window.h";
#include "GUI.h";

constexpr double PI = 3.14159;

inline double rad_to_deg(double rad)
{
	return (rad * 180 / PI);
}

inline double deg_to_rad(double rad)
{
	return (rad * PI / 180);
}

//Exercise 0 -----------------------------------------------------------------------------------------------------------------------------

//int main()
//{
//	Simple_window sw(Point{ 200, 200 }, 800, 1000, "Start");
//
//	Lines grid;
//	int x_size{ 800 }, y_size{ 800 }, step{ 100 };
//
//	for (int x = step; x <= x_size; x += step)
//		grid.add(Point{ x, 0 }, Point{ x, y_size });
//	for (int y = step; y <= y_size; y += step)
//		grid.add(Point{ 0, y }, Point{ x_size, y });
//	grid.set_color(Color::black);
//	sw.attach(grid);
//
//	Graph_lib::Vector_ref<Graph_lib::Rectangle> v_rect;
//	for (int x{}, y{}, i{}; x < x_size; x += step, y += step, i++)
//	{
//		v_rect.push_back(new Graph_lib::Rectangle{ Point{x, y}, Point{x + step, y + step} });
//		v_rect[i].set_fill_color(Color::red);
//		sw.attach(v_rect[i]);
//	}
//
//	Graph_lib::Vector_ref<Image> v_img;
//	for (int x{ 600 }, y{}, i{}; i < 3; y += 2*step, i++)
//	{
//		v_img.push_back(new Image(Point{ x, y }, "S:/perfect_circle/BjarneStroustrup/relef.jpg"));
//		v_img[i].set_mask(Point{ 1180, 620 }, 200, 200);
//		sw.attach(v_img[i]);
//	}
//	
//	for (int y{}; y < y_size; y+=step)
//		for (int x{}; x < x_size; x += step)
//		{
//			Image img(Point{ x, y }, "S:/perfect_circle/BjarneStroustrup/relef.jpg");
//			img.set_mask(Point{ x, y }, step, step);
//			sw.attach(img);
//			sw.wait_for_button();
//		}
//}

//Exercise 1 -----------------------------------------------------------------------------------------------------------------------------

class MyArc : public Shape
{
private:
	int r;
	int m_start;
	int m_end;
public:
	MyArc(Point p, int rr, int start = 0, int end = 360)
		: r{ rr }, m_start{ start }, m_end{ end }
	{
		if (start < 0 || end > 360 || start >= end)
			throw std::runtime_error("Arc: start >= end");
		add(Point{ p.x - r, p.y - r });
	}
	void draw_lines() const
	{
		if (color().visibility())
			fl_arc(point(0).x, point(0).y, r + r, r + r, m_start, m_end);
	}
	Point center() const
	{
		return { point(0).x + r, point(0).y + r };
	}
	int radius() const { return r; };
	void set_radius(int rr)
	{
		set_point(0, Point{ center().x - rr, center().y - rr });
		r = rr;
	}
};

//int main()
//{
//	Simple_window sw(Point{ 100, 100 }, 600, 400, "Arc");
//
//	MyArc arc(Point{ 300, 200 }, 100, 90, 300);
//	arc.set_color(Color::black);
//	sw.attach(arc);
//
//	sw.wait_for_button();
//}

//Exercise 2 -----------------------------------------------------------------------------------------------------------------------------

class MyBox : public Shape
{
private:
	Point c;
	int m_h;
	int m_w;
	int m_r;
public:
	MyBox(Point center, int height, int width, int radius)
		: m_h{ height / 2 }, m_w(width / 2), m_r{ radius }, c{ center }
	{
		if (((2 * radius) > width) || ((2 * radius) > height)
			|| radius <= 0)
			throw std::runtime_error("MyBox: bad radius");
	}
	void draw_lines() const
	{
		if (color().visibility())
		{
			fl_line(c.x + m_w, c.y + (m_h - m_r), c.x + m_w, c.y - (m_h - m_r));
			fl_line(c.x + (m_w - m_r), c.y - m_h, c.x - (m_w - m_r), c.y - m_h);
			fl_line(c.x - m_w, c.y - (m_h - m_r), c.x - m_w, c.y + (m_h - m_r));
			fl_line(c.x - (m_w - m_r), c.y + m_h, c.x + (m_w - m_r), c.y + m_h);
			fl_arc(c.x - m_r + (m_w - m_r), c.y - m_r - (m_h - m_r), m_r + m_r, m_r + m_r, 0, 90);
			fl_arc(c.x - m_r - (m_w - m_r), c.y - m_r - (m_h - m_r), m_r + m_r, m_r + m_r, 90, 180);
			fl_arc(c.x - m_r - (m_w - m_r), c.y - m_r + (m_h - m_r), m_r + m_r, m_r + m_r, 180, 270);
			fl_arc(c.x - m_r + (m_w - m_r), c.y - m_r + (m_h - m_r), m_r + m_r, m_r + m_r, 270, 360);
		}
	}
};

//int main()
//{
//	Simple_window sw(Point{ 100, 100 }, 600, 400, "Box");
//
//	MyBox box(Point{ 300, 200 }, 200, 50, 10);
//	box.set_color(Color::black);
//	sw.attach(box);
//	sw.wait_for_button();
//}

//Exercise 3 -----------------------------------------------------------------------------------------------------------------------------

enum class period
{
	first, second, third, fourth
};

period get_period(int angle)
{
	if (angle >= 0 && angle < 90)
		return period::first;
	else if (angle >= 90 && angle < 180)
		return period::second;
	else if (angle >= 180 && angle < 270)
		return period::third;
	else
		return period::fourth;
}

int get_angle(int x, int y, double hyp)
{
	int angle{};
	if (x < 0 && y < 0)
		angle += 90 + rad_to_deg(asin(abs(x) / hyp));
	else if (x <= 0 && y >= 0)
		angle += 180 + rad_to_deg(acos(abs(x) / hyp));
	else if (x > 0 && y > 0)
		angle += 270 + rad_to_deg(asin(abs(x) / hyp));
	else angle += rad_to_deg(acos(abs(x) / hyp));

	return angle;
}

int get_opposite_angle(int angle)
{
	angle += 180;
	return (angle >= 360) ? (angle - 360) : angle;
}

int trim_angle_to_first_period(int angle)
{
	if (angle < 0)
		angle += 360;
	while (get_period(angle) != period::first)
		angle -= 90;
	return angle;
}

void tune_xy(int& x, int& y, period per)
{
	switch (per)
	{
	case period::first:
		y = -y;
		break;
	case period::second:
		std::swap(x, y);
		x = -x;
		y = -y;
		break;
	case period::third:
		x = -x;
		break;
	case period::fourth:
		std::swap(x, y);
		break;
	}
}

Point get_xy(int radius, int ang)
{
	period per = get_period(ang);
	ang = trim_angle_to_first_period(ang);
	int x = radius * cos(deg_to_rad(ang));
	int y = radius * sin(deg_to_rad(ang));
	tune_xy(x, y, per);
	return Point(x, y);
	//return make_pair(x, y);
}

class Arrow : public Shape
{
private:
	int peak_len{ };
	int peak_angle{ };
public:
	Arrow(Point, Point, int, int);
	void draw_lines() const;
};

Arrow::Arrow(Point begin, Point end, int length = 15, int angle = 20)
	: peak_len{length}, peak_angle{angle}
{
	if (length < 0 || angle < 0)
		throw std::runtime_error("length or angle < 0");
	add(begin);
	add(end);
}

void Arrow::draw_lines() const
{
	int x_len = point(1).x - point(0).x;
	int y_len = point(1).y - point(0).y;

	double hyp = sqrt(pow(x_len, 2) + pow(y_len, 2));
	int angle_A = get_angle(x_len, y_len, hyp);

	int angle_opp = get_opposite_angle(angle_A);
	
	Point B = get_xy(peak_len, angle_opp - peak_angle);
	Point C = get_xy(peak_len, angle_opp + peak_angle);

	if (color().visibility())
	{
		fl_line(point(0).x, point(0).y, point(1).x, point(1).y);
		fl_line(point(1).x, point(1).y, point(1).x + B.x, point(1).y + B.y);
		fl_line(point(1).x, point(1).y, point(1).x + C.x, point(1).y + C.y);
	}
}

//int main()
//{
//	Simple_window sw(Point{ 100, 100 }, 800, 600, "Arrow");
//	Arrow ar(Point{ 400, 300 }, Point{400, 250 });
//	ar.set_color(Color::black);
//	sw.attach(ar);
//
//	Arrow ar1(Point{ 400, 300 }, Point{ 350, 270 });
//	ar1.set_color(Color::black);
//	sw.attach(ar1);
//
//	Arrow ar2(Point{ 400, 300 }, Point{ 330, 300 });
//	ar2.set_color(Color::black);
//	sw.attach(ar2);
//
//	Arrow ar3(Point{ 400, 300 }, Point{ 350, 330 });
//	ar3.set_color(Color::black);
//	sw.attach(ar3);
//
//	Arrow ar4(Point{ 400, 300 }, Point{ 400, 350 });
//	ar4.set_color(Color::black);
//	sw.attach(ar4);
//
//	Arrow ar5(Point{ 400, 300 }, Point{ 450, 330 });
//	ar5.set_color(Color::black);
//	sw.attach(ar5);
//
//	Arrow ar6(Point{ 400, 300 }, Point{ 470, 300 });
//	ar6.set_color(Color::black);
//	sw.attach(ar6);
//
//	Arrow ar7(Point{ 400, 300 }, Point{ 450, 270 });
//	ar7.set_color(Color::black);
//	sw.attach(ar7);
//
//	Arrow ar8(Point{ 400, 300 }, Point{ 550, 270 });
//	ar8.set_color(Color::black);
//	sw.attach(ar8);
//
//	Arrow ar9(Point{ 100, 300 }, Point{ 550, 380 });
//	ar9.set_color(Color::black);
//	sw.attach(ar9);
//
//	Arrow ar10(Point{ 700, 550 }, Point{ 680, 180 }, 150, 5);
//	ar10.set_color(Color::black);
//	sw.attach(ar10);
//
//	sw.wait_for_button();
//}

//Exercise 4 -----------------------------------------------------------------------------------------------------------------------------

Point n(const Graph_lib::Rectangle& rect)
{
	return Point(rect.point(0).x + rect.width() / 2, rect.point(0).y);
}

Point s(const Graph_lib::Rectangle& rect)
{
	return Point(rect.point(0).x + rect.width() / 2, rect.point(0).y + rect.height());
}

Point e(const Graph_lib::Rectangle& rect)
{
	return Point(rect.point(0).x, rect.point(0).y + rect.height() / 2);
}

Point w(const Graph_lib::Rectangle& rect)
{
	return Point(rect.point(0).x + rect.width(), rect.point(0).y + rect.height() / 2);
}

Point center(const Graph_lib::Rectangle& rect)
{
	return Point(rect.point(0).x + rect.width() / 2, rect.point(0).y + rect.height() / 2);
}

Point ne(const Graph_lib::Rectangle& rect)
{
	return Point(rect.point(0).x + rect.width(), rect.point(0).y);
}

Point se(const Graph_lib::Rectangle& rect)
{
	return Point(rect.point(0).x + rect.width(), rect.point(0).y + rect.height());
}

Point sw(const Graph_lib::Rectangle& rect)
{
	return Point(rect.point(0).x, rect.point(0).y + rect.height());
}

Point nw(const Graph_lib::Rectangle& rect)
{
	return Point(rect.point(0).x, rect.point(0).y);
}

//int main()
//{
//	try
//	{
//		Simple_window win(Point{ 100, 100 }, 800, 600, "Arrow");
//
//		Graph_lib::Rectangle rect(Point{ 50, 150 }, Point{ 100, 350 });
//		rect.set_color(Color::blue);
//		win.attach(rect);
//
//		Arrow ar(Point{ 400, 50 }, n(rect));
//		ar.set_color(Color::black);
//		win.attach(ar);
//
//		Arrow ar1(Point{ 400, 50 }, s(rect));
//		ar1.set_color(Color::black);
//		win.attach(ar1);
//
//		Arrow ar2(Point{ 400, 50 }, e(rect));
//		ar2.set_color(Color::black);
//		win.attach(ar2);
//
//		Arrow ar3(Point{ 400, 50 }, w(rect));
//		ar3.set_color(Color::black);
//		win.attach(ar3);
//
//		Arrow ar4(Point{ 400, 50 }, center(rect));
//		ar4.set_color(Color::black);
//		win.attach(ar4);
//
//		Arrow ar8(Point{ 400, 50 }, ne(rect));
//		ar8.set_color(Color::black);
//		win.attach(ar8);
//
//		Arrow ar6(Point{ 400, 50 }, se(rect));
//		ar6.set_color(Color::black);
//		win.attach(ar6);
//
//		Arrow ar5(Point{ 400, 50 }, sw(rect));
//		ar5.set_color(Color::black);
//		win.attach(ar5);
//
//		Arrow ar7(Point{ 400, 50 }, nw(rect));
//		ar7.set_color(Color::black);
//		win.attach(ar7);
//
//		win.wait_for_button();
//	}
//	catch (std::exception& e)
//	{
//		std::cout << "Exception! " << e.what();
//	}
//}

//Exercise 5 -----------------------------------------------------------------------------------------------------------------------------

Point n(const Graph_lib::Circle& c)
{
	return Point(c.point(0).x + c.radius(), c.point(0).y + c.radius());
}

Point s(const Graph_lib::Circle& c)
{
	return Point(c.point(0).x + c.radius(), c.point(0).y + c.radius() * 2);
}

Point e(const Graph_lib::Circle& c)
{
	return Point(c.point(0).x + c.radius() * 2, c.point(0).y + c.radius());
}

Point w(const Graph_lib::Circle& c)
{
	return Point(c.point(0).x, c.point(0).y + c.radius());
}

Point center(const Graph_lib::Circle& c)
{
	return Point(c.center());
}

Point ne(const Graph_lib::Circle& c)
{
	return Point(c.point(0).x + c.radius() * 2, c.point(0).y);
}

Point se(const Graph_lib::Circle& c)
{
	return Point(c.point(0).x + c.radius() * 2, c.point(0).y + c.radius() * 2);
}

Point sw(const Graph_lib::Circle& c)
{
	return Point(c.point(0).x, c.point(0).y + c.radius() * 2);
}

Point nw(const Graph_lib::Circle& c)
{
	return Point(c.point(0).x, c.point(0).y);
}

//int main()
//{
//	try
//	{
//		Simple_window win(Point{ 100, 100 }, 800, 600, "Arrow");
//
//		Graph_lib::Circle rect(Point{ 600, 350 }, 70);
//		rect.set_color(Color::blue);
//		win.attach(rect);
//
//		Arrow ar(Point{ 400, 50 }, n(rect));
//		ar.set_color(Color::black);
//		win.attach(ar);
//
//		Arrow ar1(Point{ 400, 50 }, s(rect));
//		ar1.set_color(Color::black);
//		win.attach(ar1);
//
//		Arrow ar2(Point{ 400, 50 }, e(rect));
//		ar2.set_color(Color::black);
//		win.attach(ar2);
//
//		Arrow ar3(Point{ 400, 50 }, w(rect));
//		ar3.set_color(Color::black);
//		win.attach(ar3);
//
//		Arrow ar4(Point{ 400, 50 }, center(rect));
//		ar4.set_color(Color::black);
//		win.attach(ar4);
//
//		Arrow ar8(Point{ 400, 50 }, ne(rect));
//		ar8.set_color(Color::black);
//		win.attach(ar8);
//
//		Arrow ar6(Point{ 400, 50 }, se(rect));
//		ar6.set_color(Color::black);
//		win.attach(ar6);
//
//		Arrow ar5(Point{ 400, 50 }, sw(rect));
//		ar5.set_color(Color::black);
//		win.attach(ar5);
//
//		Arrow ar7(Point{ 400, 50 }, nw(rect));
//		ar7.set_color(Color::black);
//		win.attach(ar7);
//
//		win.wait_for_button();
//	}
//	catch (std::exception& e)
//	{
//		std::cout << "Exception! " << e.what();
//	}
//}

//Exercise 8, 9 -----------------------------------------------------------------------------------------------------------------------------

class Regular_hexagon : public Closed_polyline
{
private:
	static const int angle_step{ 60 };
	int rad;
	Point c;
public:
	Regular_hexagon(Point, int);
	void draw_lines() const;
};

Regular_hexagon::Regular_hexagon(Point center, int radius) : rad{ radius }, c{center}
{
	if (radius < 0)
		throw std::runtime_error("Radius cannot be less than 0");
	for (int angle{ angle_step / 2 }; angle < 360; angle += angle_step)
	{
		auto p = get_xy(rad, angle);
		add(Point{c.x + p.x, c.y + p.y});
	}
}

void Regular_hexagon::draw_lines() const
{
	if (color().visibility())
		Closed_polyline::draw_lines();
}

//int main()
//{
//	try
//	{
//		int hex_radius{ 101 };
//		Point step = get_xy(hex_radius, 330);
//		Vector_ref<Regular_hexagon> v;
//
//		Simple_window win(Point{ 100, 100 }, 800, 600, "hexagon");
//
//		for (int y{ step.x }, j{ 0 }; y <= win.y_max(); y += 3 * step.y, y++)
//		{
//			int x{ 0 };
//			if (j % 2 != 0)
//				x += step.x;
//			for (; x <= win.x_max(); x += step.x * 2, j++)
//			{
//				v.push_back(new Regular_hexagon(Point{ x, y }, hex_radius));
//				v[j].set_color(Color::black);
//				win.attach(v[j]);
//			}
//		}
//		win.wait_for_button();
//	}
//	catch (std::exception& e)
//	{
//		std::cout << "Exception! " << e.what();
//	}
//}

//Exercise 10 -----------------------------------------------------------------------------------------------------------------------------

class Regular_polygon : public Closed_polyline
{
private:
	int step{};
	int rad{};
	int sides{};
	Point c;
public:
	Regular_polygon(Point, int, int);
	void draw_lines() const;
};
 
Regular_polygon::Regular_polygon(Point center, int radius, int num_sides)
	: rad{ radius }, c{ center }, sides{ num_sides }
{
	if (radius < 0)
		throw std::runtime_error("Radius cannot be less than 0");
	if (num_sides < 3)
		throw std::runtime_error("Number of sides have to be >= 3");
	step = 360 / sides;
	for (int angle{ step / 2 }; angle < 360; angle += step)
	{
		auto p = get_xy(rad, angle);
		add(Point{ c.x + p.x, c.y + p.y });
	}
}

void Regular_polygon::draw_lines() const
{
	if (color().visibility())
		Closed_polyline::draw_lines();
}

//int main()
//{
//	Simple_window win(Point{ 100, 100 }, 800, 600, "regular_polygon");
//
//	Regular_polygon rp(Point{ 400, 300 }, 70, 7);
//	rp.set_color(Color::black);
//	win.attach(rp);
//
//	win.wait_for_button();
//}

//Exercise 12 -----------------------------------------------------------------------------------------------------------------------------

int main()
{
	Simple_window win(Point{ 100, 100 }, 800, 600, "Marked circle");
	int radius{ 80 };

	Circle circ(Point{ 400, 300 }, radius);
	circ.set_color(Color::black);
	win.attach(circ);

	for (int angle{}; angle < 360; angle += 10)
	{
		auto p = get_xy(radius, angle);
		Mark mark(Point{ circ.center().x + p.x, circ.center().y + p.y }, 'X');
		mark.set_color(Color::red);
		win.attach(mark);
		win.wait_for_button();
	}

}
