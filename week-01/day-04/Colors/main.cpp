#include <iostream>

int main() {

    // - Create a two dimensional array
    //   which can contain the different shades of specified colors
    // - In `colors[0]` store the shades of green:
    //   `"lime", "forest green", "olive", "pale green", "spring green"`
    // - In `colors[1]` store the shades of red:
    //   `"orange red", "red", "tomato"`
    // - In `colors[2]` store the shades of pink:
    //   `"orchid", "violet", "pink", "hot pink"`

    std::string colors[5][5] = {{"lime", "forest green", "olive", "pale green", "spring green"},
                                {"orange red", "red", "tomato", 0, 0},
                                {"orchid", "violet", "pink", "hot pink", 0}
    };

    return 0;
}