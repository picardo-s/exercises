#include "Graph.h"
#include "GUI.h"
#include "Simple_window.h"
#include "std_lib_facilities.h"
#include "Window.h"
#include "Point.h"
#include "Graph_func.h"

//Exercise 0 -------------------------------------------------------------------------------------------------------------------------------------

class B1
{
public:
    virtual void vf() const
    {
        std::cout << "B1::vf()\n";
    }
    void f() const
    {
        std::cout << "B1::f()\n";
    }
    virtual void pvf() const = 0;
};

class D1 : public B1
{
public:
    void vf() const
    {
        std::cout << "D1::vf()\n";
    }
    void f() const
    {
        std::cout << "D1::f()\n";
    }
};

class D2 : public D1
{
public:
    void pvf() const
    {
        std::cout << "D2::pvf()\n";
    }
};

class B2
{
public:
    virtual void pvf() const = 0;
};

class D21 : public B2
{
private:
    string str{"asd"};
public:
    void pvf() const
    {
        std::cout << str << '\n';
    }
};

class D22 : public D21
{
private:
    int num{123};
public:
    void pvf() const
    {
        std::cout << num << '\n';
    }
};

void f(const B2& b)
{
    b.pvf();
}

//int main()
//{
//    B1 objB1;
//    objB1.vf();
//    objB1.f();
//
//    D1 objD1;
//    objD1.vf();
//    objD1.f();
//
//    B1& objB1_ref = objD1;
//    objB1_ref.vf();
//    objB1_ref.f();
//
//    D2 objD2;
//    objD2.pvf();
//    objD2.vf();
//    objD2.f();
//
//    D21 objD21;
//    D22 objD22;
//    f(objD21);
//    f(objD22);
//}

//Exercise 1 -------------------------------------------------------------------------------------------------------------------------------------

class Smiley : public Circle
{
public:
    using Circle::Circle;
    void draw_lines() const
    {
        Circle::draw_lines();
        if (color().visibility())
        {
            int eye_r{ radius() / 4 };
            Point eye1{ get_xy(radius() / 2, 45) };
            Point eye2{ get_xy(radius() / 2, 135) };
            fl_circle((center().x + eye1.x), (center().y + eye1.y), eye_r);
            fl_circle((center().x + eye2.x), (center().y + eye2.y), eye_r);
            fl_arc((center().x - eye_r), (center().y + eye_r), eye_r + eye_r, eye_r + eye_r, 180, 360);
        }
    }
};

class Frowny : public Circle
{
public:
    using Circle::Circle;
    void draw_lines() const
    {
        Circle::draw_lines();
        if (color().visibility())
        {
            int eye_r{ radius() / 4 };
            Point eye1{ get_xy(radius() / 2, 45) };
            Point eye2{ get_xy(radius() / 2, 135) };
            fl_circle((center().x + eye1.x), (center().y + eye1.y), eye_r);
            fl_circle((center().x + eye2.x), (center().y + eye2.y), eye_r);
            fl_arc((center().x - eye_r), (center().y + eye_r), eye_r + eye_r, eye_r + eye_r, 0, 180);
        }
    }
};

class SmileyHat : public Smiley
{
    using Smiley::Smiley;
    void draw_lines() const
    {
        Smiley::draw_lines();
        if (color().visibility())
        {
            fl_line(point(0).x, point(0).y, point(0).x + radius() * 2, point(0).y);
            fl_line(point(0).x + radius() / 2, point(0).y, point(0).x + radius() + radius() / 2, point(0).y);
            fl_line(point(0).x + radius() + radius() / 2, point(0).y, point(0).x + radius(), point(0).y - radius());
            fl_line(point(0).x + radius(), point(0).y - radius(), point(0).x + radius() / 2, point(0).y);
        }
    }
};

class FrownyHat : public Frowny
{
    using Frowny::Frowny;
    void draw_lines() const
    {
        Frowny::draw_lines();
        if (color().visibility())
        {
            fl_line(point(0).x, point(0).y, point(0).x + radius() * 2, point(0).y);
            fl_rect(point(0).x + radius() / 2, point(0).y - radius()/2, radius(), radius() / 2);
        }
        
    }
};

//int main()
//{
//    Simple_window win(Point{ 100, 100 }, 800, 600, "Faces");
//
//    Smiley smile(Point{ 100, 100 }, 50);
//    smile.set_color(Color::black);
//    win.attach(smile);
//
//    Frowny frown(Point{ 300, 100 }, 50);
//    frown.set_color(Color::black);
//    win.attach(frown);
//
//    SmileyHat sh(Point{ 100, 400 }, 50);
//    sh.set_color(Color::black);
//    win.attach(sh);
//
//    FrownyHat fh(Point{ 300, 400 }, 50);
//    fh.set_color(Color::black);
//    win.attach(fh);
//
//    win.wait_for_button();
//}

//Exercise 4 -------------------------------------------------------------------------------------------------------------------------------------

class Immobile_Circle : public Circle
{
public:
    using Circle::Circle;
private:
    void move(int dx, int dy)
    {
        Circle::move(dx, dy);
    }
};

//int main()
//{
//    Simple_window win(Point{ 100, 100 }, 800, 600, "Faces");
//
//    Immobile_Circle ic(Point{ 100, 100 }, 50);
//    ic.set_color(Color::black);
//    win.attach(ic);
//    //ic.move(30, 30);
//
//    Circle c(Point{ 100, 300 }, 50);
//    c.set_color(Color::black);
//    win.attach(c);
//    c.move(300, 30);
//
//    win.wait_for_button();
//}

//Exercise 5 -------------------------------------------------------------------------------------------------------------------------------------

class Striped_rectangle : public Rectangle
{
public:
    using Rectangle::Rectangle;
    void draw_lines() const
    {
        if (fill_color().visibility())
        {
            fl_color(fill_color().as_int());
            for (int dy{ point(0).y + 2 }; dy <(point(0).y + height()); dy += 2)
                fl_line(point(0).x + 1, dy, point(0).x + width() - 2, dy);
        }
        if (color().visibility())
        {
            fl_color(color().as_int());
            fl_rect(point(0).x, point(0).y, width(), height());
        }
    }
};

//int main()
//{
//    Simple_window win(Point{ 100, 100 }, 800, 600, "Striped_rect");
//
//    Striped_rectangle sr(Point{ 200, 100 }, 50, 450);
//    sr.set_fill_color(Color::red);
//    sr.set_color(Color::black);
//    win.attach(sr);
//
//    win.wait_for_button();
//}

//Exercise 6 -------------------------------------------------------------------------------------------------------------------------------------

class Striped_Circle : public Circle
{
    using Circle::Circle;
public:
    void draw_lines() const
    {
        if (fill_color().visibility())
        {
            fl_color(fill_color().as_int());
            for (int line{ 0 }, ang{0}, r(radius()); line <= (radius() * 2); line += 3)
            {
                ang = rad_to_deg(asin(static_cast<double>(r - line) / r));
                Point p{ get_xy(radius(), ang) };
                fl_line(center().x, point(0).y + line, center().x + p.x, point(0).y + line);
                fl_line(center().x, point(0).y + line, center().x - p.x, point(0).y + line);
            }
            //for (int ang1{ 95 }, ang2{ 85 }; ang1 <= 270; ang1 += 5, ang2 -= 5)            //maybe, but...
            //{
            //    if (ang2 == -5)
            //        ang2 = 355;
            //    Point p1{ get_xy(radius(), ang1) };
            //    Point p2{ get_xy(radius(), ang2) };
            //    fl_line(center().x + p1.x, center().y + p1.y, center().x + p2.x, center().y + p2.y);
            //}
            if (color().visibility())
            {
                fl_color(color().as_int());
                fl_circle(center().x, center().y, radius());
            }
        }
    }
};

//int main()
//{
//    Simple_window win(Point{ 100, 100 }, 800, 600, "Striped_circ");
//
//    Striped_Circle sc(Point{ 400, 300 }, 91);
//    sc.set_fill_color(Color::red);
//    sc.set_color(Color::black);
//    win.attach(sc);
//
//    win.wait_for_button();
//}

//Exercise 11-12 -------------------------------------------------------------------------------------------------------------------------------------

//class Binary_tree : public Shape
//{
//protected:
//    int levels{};
//    int d_x{};
//    int d_y{};
//    double sc{};
//    static const int r{5};
//    virtual void draw_points() const;
//public:
//    Binary_tree(Point, int, int, int, double);
//    void draw_lines() const;
//};
//
//Binary_tree::Binary_tree(Point position, int num_levels, int dx, int dy, double scale)
//    : levels{num_levels}, d_x{dx}, d_y{dy}, sc{scale}
//{
//    if (num_levels < 0)
//        throw std::runtime_error("Levels cannot be < 0");
//    for (int cur_lev{ 1 }, p{ 0 }, dx{ d_x }, dy{ d_y }; cur_lev <= levels; cur_lev++, dx *= sc)
//    {
//        if (cur_lev == 1)
//        {
//            add(position);
//            continue;
//        }
//        for (; p < (pow(2, cur_lev)/2 - 1); p++)
//        {
//            add(Point{ point(p).x - dx, point(p).y + dy });
//            add(Point{ point(p).x + dx, point(p).y + dy });
//        }
//
//    }
//}

//void Binary_tree::draw_points() const //draws the points as circles
//{
//    for (int i{ 0 }; i < number_of_points(); i++)
//        fl_circle(point(i).x, point(i).y, r);
//}
//
//void Binary_tree::draw_lines() const
//{
//    if (color().visibility())
//    {
//        draw_points();
//        for (int begin{ -1 }, end{ 1 }; end < number_of_points(); end++)
//        {
//            if (end % 2 != 0)
//                begin++;
//            fl_line(point(begin).x, point(begin).y, point(end).x, point(end).y);
//        }
//    }
//}
//
//class Binary_tree_rect : public Binary_tree
//{
//    Binary_tree::Binary_tree;
//protected:
//    void draw_points() const;
//};
//
//void Binary_tree_rect::draw_points() const
//{
//    for (int i{ 0 }; i < number_of_points(); i++)
//        fl_rect(point(i).x - r, point(i).y - r, r + r, r + r);
//}

//int main()
//{
//    Simple_window win(Point{ 100, 100 }, 1600, 600, "Tree");
//
//    Binary_tree bt(Point{800, 50 }, 3, 700, 75, 0.4);
//    bt.set_color(Color::black);
//    win.attach(bt);
//
//    Binary_tree_rect btr(Point{ 800, 300 }, 3, 750, 75, 0.25);
//    btr.set_color(Color::black);
//    win.attach(btr);
//
//    win.wait_for_button();
//}

//Exercise 13 -------------------------------------------------------------------------------------------------------------------------------------

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
    : peak_len{ length }, peak_angle{ angle }
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


class Binary_tree : public Shape
{
protected:
    int levels{};
    int d_x{};
    int d_y{};
    double sc{};
    Color line_color{ fl_color() };
    bool rev{};
    static const int r{5};
    virtual void draw_points() const;
public:
    Binary_tree(Point, int, int, int, double, Color, bool);
    void draw_lines() const;
};

Binary_tree::Binary_tree(Point position, int num_levels, int dx, int dy, double scale, Color line, bool reversed = false)
    : levels{ num_levels }, d_x{ dx }, d_y{ dy }, sc{ scale }, line_color{line}, rev{ reversed }
{
    if (num_levels < 0)
        throw std::runtime_error("Levels cannot be < 0");
    for (int cur_lev{ 1 }, p{ 0 }, dx{ d_x }, dy{ d_y }; cur_lev <= levels; cur_lev++, dx *= sc)
    {
        if (cur_lev == 1)
        {
            add(position);
            continue;
        }
        for (; p < (pow(2, cur_lev)/2 - 1); p++)
        {
            add(Point{ point(p).x - dx, point(p).y + dy });
            add(Point{ point(p).x + dx, point(p).y + dy });
        }

    }
}

void Binary_tree::draw_points() const //draws the points as circles
{
    for (int i{ 0 }; i < number_of_points(); i++)
        fl_circle(point(i).x, point(i).y, r);
}

void Binary_tree::draw_lines() const
{
    if (color().visibility())
    {
        draw_points();
        fl_color(line_color.as_int());
        bool flag{ true };
        for (int begin{ -1 }, end{ 1 }; end < number_of_points(); end++)
        {
            if (end % 2 != 0)
                begin++;
            /*if (rev && flag)
            {
                swap(begin, end);
                flag = false;
            }*/
            Arrow arr(point(begin), point(end));
            arr.draw_lines();
            //fl_line(point(begin).x, point(begin).y, point(end).x, point(end).y);
        }
    }
}

int main()
{
    Simple_window win(Point{ 100, 100 }, 1600, 600, "Tree");

    Binary_tree bt(Point{800, 50 }, 3, 700, 75, 0.25, Color::red, true);
    bt.set_color(Color::black);
    win.attach(bt);


    win.wait_for_button();
}

