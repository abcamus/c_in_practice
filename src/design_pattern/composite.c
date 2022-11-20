/**
 * composite模式，将对象组合成树形结构以表示“部分-整体”的层次结构。使得用户对单个对象和组合
 * 对象的使用具有一致性
 * 
 */

typedef struct {
    void (*draw)(void *self);
} Graphic;

/* Picture是一系列图元的组合，Picture同时也是一个图元 */
typedef struct {
    void (*draw)(void *self);
    // add new g to list of graphics
    void (*add)(void *self, Graphic *g);
    #define MAX_GRAPH_NUM 16
    Graphic *graphics[MAX_GRAPH_NUM];
    unsigned graph_num;
} Picture;

static void draw_picture(Picture *pic)
{
    for (unsigned i = 0; i < pic->graph_num; i++) {
        Graphic *g = pic->graphics[i];
        g->draw(g);
    }
}