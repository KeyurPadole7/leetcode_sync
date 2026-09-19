class Solution {
public:
    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
        int nrstx = max(x1, min(xc, x2));
        int nrsty = max(y1, min(yc, y2));

        int dx = nrstx - xc;
        int dy = nrsty - yc;

        return (dx*dx + dy*dy) <= radius*radius;
    }
};