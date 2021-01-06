#include "Simple_window.h";
#include "Graph.h";
#include "Point.h";
#include "Window.h";
#include "GUI.h";
#include <cmath>;
#include <vector>;

//int main()
//{
//	using namespace Graph_lib;
//	Simple_window win(Point{ 500, 500 }, 800, 600, "My Window");
//
//	Axis xa(Axis::x, Point(20, 300), 280, 10, "x axis");
//	xa.set_color(Color::dark_red);
//	win.attach(xa);
//
//	Axis ya(Axis::y, Point(20, 300), 280, 10, "y axis");
//	ya.set_color(Color::dark_red);
//	win.attach(ya);
//
//	Function sin1(sin, 0, 100, Point(20, 150), 1000, 20, 35);
//	sin1.set_color(Color::blue);
//	win.attach(sin1);
//
//	Graph_lib::Polygon poly;
//	poly.add(Point{ 150, 150 });
//	poly.add(Point{ 250, 250 });
//	poly.add(Point{ 150, 250 });
//	poly.set_color(Color::cyan);
//	poly.set_fill_color(Color::black);
//	poly.set_style(Line_style::solid);
//	win.attach(poly);
//
//	Text t{ Point {250, 250}, "Hello!!!!!!!" };
//	t.set_color(Color::dark_magenta);
//	t.set_font(Font::helvetica);
//	win.attach(t);
//
//	Image i{ Point{300, 300}, "S:/perfect_circle/BjarneStroustrup/relef.jpg" };
//	i.set_mask(Point{ 300, 300 }, 300, 300);
//	win.attach(i);
//
//	Mark m{ Point{300, 100}, 'X' };
//	win.attach(m);
//
//	Graph_lib::Rectangle rect{ Point{120, 280}, 123, 27 };
//	rect.set_color(Color::dark_green);
//	win.attach(rect);
//
//	win.wait_for_button();
//}

//using namespace Graph_lib;

//Exercise 1 -------------------------------------------------------------------------------------------------------------

//int main()
//{
//	Simple_window sw{ Point(500, 500), 800, 600, "Ex1" };
//
//	Graph_lib::Rectangle rect{ Point{100, 100}, Point{200, 300 } };
//	rect.set_color(Color::blue);
//	sw.attach(rect);
//
//	Graph_lib::Polygon pl;
//	pl.add(Point{ 400, 100 });
//	pl.add(Point{ 500, 100 });
//	pl.add(Point{ 500, 300 });
//	pl.add(Point{ 400, 300 });
//	pl.set_color(Color::red);
//	sw.attach(pl);
//
//	sw.wait_for_button();
//}

//Exercise 2 -------------------------------------------------------------------------------------------------------------

//int main()
//{
//	Simple_window sw{ Point(500, 500), 800, 600, "Ex1" };
//
//	Graph_lib::Rectangle rect{ Point{100, 100}, Point{200, 130 } };
//	rect.set_color(Color::blue);
//	sw.attach(rect);
//
//	Text t{ Point{125, 120}, "Howdy!" };
//	t.set_color(Color::black);
//	sw.attach(t);
//
//	sw.wait_for_button();
//}

//Exercise 3 -------------------------------------------------------------------------------------------------------------

//int main()
//{
//	Simple_window sw{ Point(500, 500), 800, 600, "Ex1" };
//
//	Text t1{ Point{125, 120}, "R" };
//	t1.set_color(Color::black);
//	t1.set_font_size(150);
//	sw.attach(t1);
//
//	Text t2{ Point {250, 120 }, "R" };
//	t2.set_color(Color::blue);
//	t2.set_font_size(150);
//	sw.attach(t2);
//
//	Text t3{ Point {375, 120 }, "Y" };
//	t3.set_color(Color::green);
//	t3.set_font_size(150);
//	sw.attach(t3);
//
//	sw.wait_for_button();
//}

//Exercise 4 -------------------------------------------------------------------------------------------------------------
    //done, but deleted...
//
//Exercise 5 -------------------------------------------------------------------------------------------------------------

//int main()
//{
//	try
//	{
//		Simple_window sw{ Point(100, 100), 1600, 900, "Ex1" };
//
//		double x{ (2 * 1920) / 3.0 };
//		double y{ (3 * 1080) / 4.0 };
//
//		Graph_lib::Rectangle r{ Point{50, 50}, Point{int(50 + x), int(50 + y)} };
//		r.set_style(Line_style::solid);
//		sw.attach(r);
//
//		Graph_lib::Rectangle r1{ Point{50, 20}, Point{int(50 + x), 50} };
//		r1.set_fill_color(Color::red);
//		r1.set_color(Color::red);
//		sw.attach(r1);
//
//		Graph_lib::Rectangle r2{ Point{int(50 + x), 20}, Point{int(50 + x + 30), int(50 + y)} };
//		r2.set_fill_color(Color::red);
//		r2.set_color(Color::red);
//		sw.attach(r2);
//
//		Graph_lib::Rectangle r3{ Point{50, int(y + 20)}, Point{int(50 + x + 30), int(50 + y)} };
//		r3.set_fill_color(Color::red);
//		r3.set_color(Color::red);
//		sw.attach(r3);
//
//		Graph_lib::Rectangle r4{ Point{20, 20}, Point{50, int(50 + y)} };
//		r4.set_fill_color(Color::red);
//		r4.set_color(Color::red);
//		sw.attach(r4);
//
//		sw.wait_for_button();
//	}
//	catch (std::exception& e)
//	{
//		std::cout << "Exception! " << e.what();
//	}
//}

//Exercise 7 -------------------------------------------------------------------------------------------------------------

//int main()
//{
//    Simple_window sw{ Point {500, 500}, 1024, 720, "House" };
//
//    Graph_lib::Line l_ground(Point{ 0, 500 }, Point{1024, 500});
//    l_ground.set_color(Color::dark_green);
//    sw.attach(l_ground);
//
//    Graph_lib::Rectangle r_walls(Point{ 300, 200 }, Point{ 700, 500 });
//    r_walls.set_color(Color::black);
//    r_walls.set_fill_color(Color::cyan);
//    sw.attach(r_walls);
//
//    Graph_lib::Rectangle r_tube{ Point{320, 80}, Point{360, 190} };
//    r_tube.set_color(Color::black);
//    r_tube.set_fill_color(Color::yellow);
//    sw.attach(r_tube);
//
//    Graph_lib::Polygon p_roof;
//    p_roof.add(Point{ 270, 200 });
//    p_roof.add(Point{ 730, 200 });
//    p_roof.add(Point{ 500, 100 });
//    p_roof.set_fill_color(Color::dark_blue);
//    p_roof.set_style(Line_style::solid);
//    sw.attach(p_roof);
//
//    Graph_lib::Rectangle r_door(Point{ 460, 370 }, Point{ 540, 500 });
//    r_door.set_color(Color::black);
//    r_door.set_fill_color(Color::dark_cyan);
//    sw.attach(r_door);
//
//    Circle c_win_1(Point{ 380, 400 }, 40);
//    c_win_1.set_color(Color::black);
//    c_win_1.set_fill_color(Color::dark_magenta);
//    sw.attach(c_win_1);
//
//    Circle c_win_2(Point{ 620, 400 }, 40);
//    c_win_2.set_color(Color::black);
//    c_win_2.set_fill_color(Color::dark_magenta);
//    sw.attach(c_win_2);
//
//    sw.wait_for_button();
//}

//Exercise 8 -------------------------------------------------------------------------------------------------------------

//int main()
//{
//    Simple_window sw{ Point {500, 500}, 1024, 720, "House" };
//
//    Circle c1(Point{ 200, 250 }, 100);
//    c1.set_color(Color::blue);
//    sw.attach(c1);
//
//    Circle c2(Point{ 420, 250 }, 100);
//    c2.set_color(Color::black);
//    sw.attach(c2);
//
//    Circle c3(Point{ 640, 250 }, 100);
//    c3.set_color(Color::red);
//    sw.attach(c3);
//
//    Circle c4(Point{ 310, 380 }, 100);
//    c4.set_color(Color::yellow);
//    sw.attach(c4);
//
//    Circle c5(Point{ 530, 380 }, 100);
//    c5.set_color(Color::green);
//    sw.attach(c5);
//
//    sw.wait_for_button();
//}

//Exercise 9 -------------------------------------------------------------------------------------------------------------

constexpr int MAX = 20;
constexpr double PI = 3.14159;
constexpr double R = 0.9;

double get_x(int a, int b, int m, int n, double grade)
{
    double x{};
    //x = pow((1 - pow(abs(R * sin(grade) / b), n)), 1/double(m)) * a;
    return x;
}

double get_y(int a, int b, int m, int n, double grade)
{
    double y{};
    //y = pow((1 - pow(abs(R * cos(grade) / a), m)), 1/double(n)) * b;
    return y;
}

int main()
{
    try
    {
        std::cout << pow(-3, 1 / 4.0) << '\n';

        int x[MAX];
        int y[MAX];

        double dp = 2 * PI;
        double step = dp / MAX;
        double cur_step{};
        for (int i = 0; i < MAX; i++, cur_step += step)
        {
            x[i] = get_x(1, 1, 4, 2, cur_step);
            std::cout << x[i] << ' ';
            y[i] = get_y(1, 1, 4, 2, cur_step);
            std::cout << y[i] << '\n';

        }

        Simple_window sw{ Point {500, 500}, 1024, 720, "math" };
        int zoom{ 200 };
        
        Graph_lib::Polygon pol;
        for (int i = 0; i < MAX; i++)
        {
            Graph_lib::Circle* c = new Graph_lib::Circle(Point{ (zoom + int(x[i])), (zoom + int(y[i])) }, 10);
            c->set_color(Color::red);
            sw.attach(*c);
            //pol.add(Point{ (zoom + int(x[i])), (zoom + int(y[i])) });
        }
        sw.wait_for_button();
        //sw.attach(pol);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception! " << e.what();
    }
}
