typedef struct corner {
    int x1;
    int y1;
}corner, *pCorner;

struct rectangle {
    pCorner bottomleft;
    struct corner *bottomleft;
};