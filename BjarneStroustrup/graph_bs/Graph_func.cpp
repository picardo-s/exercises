#include "Graph_func.h"

constexpr double PI = 3.14159;

inline double rad_to_deg(double rad)
{
	return (rad * 180 / PI);
}

inline double deg_to_rad(double rad)
{
	return (rad * PI / 180);
}

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
}