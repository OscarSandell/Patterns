/*
 * fast < input.txt
 *
 * Compute and plot all line segments involving 4 points in input.txt
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include "point.h"
#include "window.h"
#include <unordered_map>
#include <limits>
using namespace std;

#define inf std::numeric_limits<double>::infinity()

template <>
struct std::hash<Point>
{
    size_t operator()(const Point &argv) const
    {
        std::string a = "(";
        a += to_string(argv.x);
        a += to_string(argv.y);
        a += ")";
        return std::hash<std::string>{}(a);
    }
};

int main(int argc, const char *argv[])
{
    WindowPtr window = create_window(argc, argv);

    // The array of points
    vector<Point> points;

    // Read points from cin
    int N{};
    cin >> N;

    for (int i{0}; i < N; ++i)
    {
        unsigned int x, y;
        cin >> x >> y;
        points.push_back(Point{x, y});
    }

    // draw points to screen all at once
    window->draw(points);

    // sort points by natural order
    // makes finding endpoints of line segments easy
    //sort(points.begin(), points.end());

    auto begin = chrono::high_resolution_clock::now();

    /////////////////////////////////////////////////////////////////////////////
    // Draw any lines that you find in 'points' using the function 'window->draw'.
    /////////////////////////////////////////////////////////////////////////////
    std::unordered_map<Point, std::unordered_map<double, std::vector<Point>>> drawmap{};

    for (auto &point : points)
    {
        for (auto &&i : points)
        {
            drawmap[point][point.slopeTo(i)].push_back(i);
        }
    }

    for (auto &&i : points)
    {
        for (auto &a : drawmap[i])
        {
            if (a.second.size() >= 3)
            {
                for (auto &&b : a.second)
                {
                    window->draw(i, b);
                }
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    cout << "Computing line segments took "
         << std::chrono::duration_cast<chrono::milliseconds>(end - begin).count()
         << " milliseconds." << endl;

    // wait for user to terminate program
    window->run();

    return 0;
}
