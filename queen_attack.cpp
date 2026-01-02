#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>

//given some obstacles, how many places queen can attack

#define X 0
#define Y 1
#define D 2
int book[8][3]; //for 8 directions, keep max x, max y, distance from queen

//qx=qc, qy=qr
//px=pc, py=pr
//retun 0-7 or -1
int get_dir(int qx, int qy, int px, int py)
{
    if(py-qy==0 && px-qx>0) //+0
        return 0;
    else if(py-qy>0 && px-qx>0 && py-qy == px-qx) //+1
        return 1;
    else if(py-qy>0 && px-qx==0) //+inf
        return 2;
    else if(py-qy>0 && px-qx<0 && py-qy == -(px-qx)) //-1
        return 3;
    else if(py-qy==0 && px-qx<0) //-0
        return 4;
    else if(py-qy<0 && px-qx<0 && py-qy == px-qx) //1
        return 5;
    else if(py-qy<0 && px-qx==0) //-inf
        return 6;
    else if(py-qy<0 && px-qx>0 && -(py-qy) == px-qx) //-1
        return 7;
    else
        return -1;
}

//qx=qc, qy=qr
//px=pc, py=pr
int distance(int qx, int qy, int px, int py)
{
    int dx;
    int dy;
    int d;

    dx=abs(px-qx);
    dy=abs(py-qy);

    d=dx>dy?dx:dy;

    return d;
}

//qx=qc, qy=qr
void init_book(int qx, int qy, int n)
{
    int i;
    int px;
    int py;
    int d;
    int c;
    for(i=0; i<8; i++)
    {
        if(i==0)
        {
            //y=qy
            //intersecting with
            //x=n
            px=n;
            py=qy;
        }
        else if(i==1)
        {
            //y=mx+c
            //qy=1.qx+c
            //c=qy-qx
            c=qy-qx;
            //y=1.x+qy-qx
            //intersecting with
            //x=n
            if(c<=0) //q is below line of slope 1
            {
                px=n;
                py=n-qx+qy;
            }
            //y=n
            else //q is above line of slope 1
            {
                py=n;
                px=n+qx-qy;
            }
        }
        else if(i==2)
        {
            //x=qx
            //intersecting with
            //y=n
            px=qx;
            py=n;
        }
        else if(i==3)
        {
            //y=mx+c
            //qy=-1.qx+c
            //c=qy+qx
            c=qy+qx;
            //y=-1.x+qy+qx
            //intersecting with
            //x=1
            if(c<=n) //q is below line of slope -1
            {
                px=1;
                py=-1+qx+qy;
            }
            //y=n
            else //q is above line of slope -1
            {
                py=n;
                px=qx+qy-n;
            }
        }
        else if(i==4)
        {
            //y=qy
            //intersecting with
            //x=1
            px=1;
            py=qy;
        }
        else if(i==5)
        {
            //y=mx+c
            //qy=1.qx+c
            //c=qy-qx
            c=qy-qx;
            //y=1.x+qy-qx
            //intersecting with
            //y=1
            if(c<=0) //q is below line of slope 1
            {
                py=1;
                px=1+qx-qy;
            }
            //x=1
            else //q is above line of slope 1
            {
                px=1;
                py=1-qx+qy;
            }
        }
        else if(i==6)
        {
            //x=qx
            //intersecting with
            //y=1
            px=qx;
            py=1;
        }
        else if(i==7)
        {
            //y=mx+c
            //qy=-1.qx+c
            //c=qy+qx
            c=qy+qx;
            //y=-1.x+qy+qx
            //intersecting with
            //y=1
            if(c<=n) //q is below line of slope -1
            {
                py=1;
                px=qx+qy-1;
            }
            //x=n
            else //q is above line of slope -1
            {
                px=n;
                py=qx+qy-n;
            }
        }

        d=distance(qx, qy, px, py);

        book[i][X]=px;
        book[i][Y]=py;
        book[i][D]=d;
    }
}

void update_book(int dir, int d, int px, int py)
{
    d--; //left over freedom
    if(d < book[dir][D])
    {
        book[dir][X]=px;
        book[dir][Y]=py;
        book[dir][D]=d;
    }
}

//n=board size
//k=num of obstacles
//r_q=row of queen
//c_q=col of queen
//obstacles[k][2]: each element is an array of 2 integers, the row and column of an obstacle
//obstacles_rows=k
//obstacles_columns=2
int queensAttack(int n, int k, int r_q, int c_q, int obstacles_rows, int obstacles_columns, int** obstacles)
{
    int i;
    int qx=c_q;
    int qy=r_q;
    int dir;
    int d;
    int px;
    int py;

    init_book(qx, qy, n);

    for(i=0; i<obstacles_rows; i++)
    {
        px=obstacles[i][1];
        py=obstacles[i][0];
        dir=get_dir(qx, qy, px, py);
        if(dir==-1) continue;
        d=distance(qx, qy, px, py);

        update_book(dir, d, px, py);
    }

    int freedom=0;
    for(i=0; i<8; i++)
    {
        freedom += book[i][D];
    }

    return freedom;
}

int main()
{
    int n=5;
    int k=3;
    int r_q=4; //qy
    int c_q=3; //qx
    int obstacles_rows=3;
    int obstacles_columns=2;
    //int obstacles[3][2]={{5,5},{4,2},{2,3}};

            // y x
    int a[] = {5,5};
    int b[] = {4,2};
    int c[] = {2,3};
    int* obstacles[] = {a, b, c};

    int fdm = queensAttack(n, k, r_q, c_q, obstacles_rows, obstacles_columns, obstacles);

    printf("%d\n", fdm);
    return 0;
}

