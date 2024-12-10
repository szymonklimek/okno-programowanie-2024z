
// Structure representing a point in 2D space
struct Point
{
    int x;
    int y;
};

// Structure representing a triangle in 2D space
struct Triangle
{
    struct Point cornerA;
    struct Point cornerB;
    struct Point cornerC;
};

struct Triangle createTriangle(struct Point cornerA, struct Point cornerB, struct Point cornerC);
