#include "Simple_window.h"
#include "Graph.h"
#include "Point.h"
#include "Window.h"
#include "GUI.h"

enum class period
{
	first, second, third, fourth
};

inline double rad_to_deg(double rad);

inline double deg_to_rad(double rad);

period get_period(int angle);

int get_angle(int x, int y, double hyp);

int get_opposite_angle(int angle);

void tune_xy(int& x, int& y, period per);

Point get_xy(int radius, int ang);