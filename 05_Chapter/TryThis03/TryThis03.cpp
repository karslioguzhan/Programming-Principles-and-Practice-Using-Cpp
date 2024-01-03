// TryThis03.cpp : Test this program with a variety of values. Print out the values of area1, area2, area3, and ratio. Insert more tests until all errors are caught. How do you know that you caught all errors? This is not a trick question; in this particular example you can give a valid argument for having caught all errors.

#include <iostream>

uint16_t area(uint16_t length, uint16_t width)
{
    if (length <= 0 || width <= 0)
    {
        std::cerr << "not all of the arguments are greater than 0\n";
        exit(-1);
    }
    return length * width;
}

uint16_t framed_area(uint16_t x, uint16_t y)
{
    constexpr int frame_width = 2;
    if (x - frame_width <= 0 || y - frame_width <= 0)
    {
        std::cerr << "non-positive area() argument called by framed_area()\n";
        exit(-1);
    }
    return area(x - frame_width, y - frame_width);
}

int f(int x, int y, int z)
{
    int area1 = area(x, y);
    std::cout << "area1: " << area1 << "\n";
    if (area1 <= 0)
    {
        std::cerr << "non-positive area\n";
        exit(-1);
    }
    //int area2 = framed_area(1, z); // Hardcoded 1 will always terminate session
    //std::cout << "area2: " << area2 << "\n";
    int area3 = framed_area(y, z);
    std::cout << "area3: " << area3 << "\n";
    double ratio = double(area1) / area3;
    std::cout << "ratio: " << ratio << "\n";
    return 0;
}

int main()
{
    f(3, 3, 3);
    f(1, 10, 10);
}