#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define _fl(x) //puts("FLAG " #x),fflush(stdout);
#define  _(x)  //cout<< #x <<" is "<< x <<endl;
#define fs first
#define sc second
#define pb push_back
#define all(v)  (v).begin(), (v).end()
#define _109 (1000000000)
#define _0(arr) memset(arr,0,sizeof ( arr ) )
#define _1(arr) memset(arr,-1,sizeof ( arr ) )
#define _ninp(n,arr) for(int i=0; i<n;i++)cin>>arr[i];
#define _nout(n,arr) for(int i=0; i<n;i++)cout<<arr[i]<<" \n"[i==n-1];
double _eps = 1e-6;



namespace Geometry
{

    // equation is in  ax+by+c=0 form




    int  g(double p, double q)
    {
        return ((p > q) || fabs(p - q) <= _eps);
    }

    int  l(double p, double q)
    {
        return ((p < q) || fabs(p - q) <= _eps);
    }

    struct pt
    {
        double x, y;
        void in()
        {
            cn x;
            cn y;
        }
        void assign( double _x, double _y)
        {
            x = _x;
            y = _y;
        }
        pt() {};
        pt(double _x, double _y)
        {
            x = _x;
            y = _y;
        }
        void out()
        {
            ct x spc y, nl;
        }
        bool operator ==(const pt &a)const
        {
            if(fabs(a.x - x) <= _eps && fabs(a.y - y) <= _eps)return true;
            return false;
        }

        double to(pt a)
        {
            return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
        }

        vector<double> eqn(pt p)
        {
            double a, b, c;
            a = (p.y - y);
            b = -(p.x - x);
            c = y * (p.x - x) - x * (p.y - y);
            vector<double> r;
            r.pb(a);
            r.pb(b);
            r.pb(c);
            return r;
        }
        vector<double> eqn_by_slope(double m)
        {
            double a, b, c;
            a = m;
            b = -1;
            c = y - m * x;
            vector<double> r;
            r.pb(a);
            r.pb(b);
            r.pb(c);
            return r;
        }

        int on_this_line(pt p1, pt p2)
        {
            vector<double> v = p1.eqn(p2);
            double r = v[0] * x + v[1] * y + v[2];
            if(fabs(r) <= _eps)
            {
                if(g(x, min(p1.x, p2.x)) && l(x, max(p1.x, p2.x)) && g(y, min(p1.y, p2.y)) && l(y, max(p1.y, p2.y)))
                    return 1;
            }
            return 0;
        }

        vector<double> eqn_orthogonal_to(pt p, pt q)
        {
            vector<double> v = p.eqn(q);
            double a = v[1];
            double b = -v[0];
            double c = -(a * x + b * y);
            vector <double> r;
            r.pb(a);
            r.pb(b);
            r.pb(c);
            return r;
        }

    };


    pt solve_eqn(vector<double> v, vector<double> v1, ll INF)
    {


        v[2] = -v[2];
        v1[2] = -v1[2];
        double ab = v[0] * v1[1] - (v1[0] * v[1]);

        if(fabs(ab) < _eps)
        {
            pt r(INF, INF);
            ct "IN/f";
            return r;
        }

        double x = (v[2] * v1[1] - (v1[2] * v[1])) / ab;
        double y = (v[0] * v1[2] - (v1[0] * v[2])) / ab;
        pt r(x, y);
        return r;
    }
    int orientation(pt a, pt b, pt c)
    {

        double r = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);

        if(fabs(r) <= _eps)return 0;
        else if(r < 0) return -1;
        return 1;

    }

    double evaluate_x(vector<double> &v, double x)
    {


        return ((-v[2] - x * v[0]) / v[1]);

    }
    double evaluate_y(vector<double> &v, double y)
    {

        return ((-v[2] - y * v[1]) / v[0]);

    }

    vector<pt> circle_line(double r, pt o, pt aa, pt bb)
    {
        aa.x -= o.x, bb.x -= o.x;
        aa.y -= o.y, bb.y -= o.y;

        vector<double> tm = aa.eqn(bb);
        vector<pt> rt;
        double a = tm[0], b = tm[1], c = tm[2]; // given as input

        double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
        if (c * c > r * r * (a * a + b * b) + _eps)
            return rt;
        else if (abs (c * c - r * r * (a * a + b * b)) < _eps)
        {

            pt aaa(x0, y0);
            if(aaa.on_this_line(aa, bb))rt.pb(aaa);
            return rt;
        }
        else
        {
            double d = r * r - c * c / (a * a + b * b);
            double mult = sqrt (d / (a * a + b * b));
            double ax, ay, bx, by;
            ax = x0 + b * mult;
            bx = x0 - b * mult;
            ay = y0 - a * mult;
            by = y0 + a * mult;
            pt aaa(ax, ay);
            pt bbb(bx, by);

            if(aaa.on_this_line(aa, bb))rt.pb(aaa);
            if(bbb.on_this_line(aa, bb))rt.pb(bbb);
            return rt;
        }
    }

    double angle(pt a, pt b, pt c)
    {

        double ab = a.to(b);
        double ac = a.to(c);

        b.x -= a.x, c.x -= a.x;
        b.y -= a.y, c.y -= a.y;

        double ang = (b.x * c.x + b.y * c.y) / (ab * ac);

        return acos(ang);

    }
}



ll r;

int inside(pair<ll, ll> a)
{

    if(a.fs * a.fs + a.sc * a.sc <= r * r)return 1;
    return 0;

}


double area(pair<double, double> a, pair<double, double> b)
{

    return .5 * (a.fs * b.sc - b.fs * a.sc);
}

double ans(pair<ll, ll> a, pair<ll, ll> b)
{

    if(inside(a) && inside(b))
    {

        return area(a, b);
    }
    else
    {
        using namespace Geometry;
        pt o(0, 0), aa(a.fs, a.sc), bb(b.fs, b.sc);

        vector<pt> v = circle_line(r, o, aa, bb);
        int sign = area(a, b) < 0 ? -1 : 1;

        _(area(a, b));

        if(inside(a))
        {

            if(v.size() == 1)
            {

                double rt = fabs(area(a, {v[0].x, v[0].y}));

                double ang = angle(o, bb, v[0]);

                rt += .5 * r * r * ang;
                return rt * sign;

            }
            else if(v.size() == 2)
            {
                pt oth;
                if(aa == v[0])oth = v[1];
                else oth = v[0];


                double rt = fabs(area(a, {oth.x, oth.y}));

                double ang = angle(o, bb, oth);

                rt += .5 * r * r * ang;

                return rt * sign;
            }
        }
        else if(inside(b))
        {

            if(v.size() == 1)
            {

                double rt = fabs(area(b, {v[0].x, v[0].y}));

                double ang = angle(o, aa, v[0]);
                rt += .5 * r * r * ang;

                return rt * sign;
            }
            else if(v.size() == 2)
            {
                pt oth;
                if(bb == v[0])oth = v[1];
                else oth = v[0];


                double rt = fabs(area(b, {oth.x, oth.y}));

                double ang = angle(o, aa, oth) ;

                rt += .5 * r * r * ang;

                return rt * sign;

            }


        }
        else
        {
            _fl(hr);

            if(v.size() == 0 || v.size() == 1)
            {
                double ang = angle(o, aa, bb);

                _(ang);

                double rt = .5 * ang * r * r * sign;
                _(rt);
                return rt;
            }
            else
            {


                double rt = fabs(area({v[0].x, v[0].y}, {v[1].x, v[1].y}));

                if(aa.to(v[0]) < aa.to(v[1]))
                {

                    double ang = angle(o, aa, v[0]);
                    rt += .5 * r * r * ang;
                    ang = angle(o, bb, v[1]);

                    rt += .5 * r * r * ang;
                    return rt * sign;

                }
                else
                {

                    double ang = angle(o, aa, v[1]);

                    rt += .5 * r * r * ang;
                    ang = angle(o, bb, v[0]);

                    rt += .5 * r * r * ang;
                    return rt * sign;


                }

            }

        }

    }


}

int main()
{

    /**
       
       How do we calculate area of a polygon?
       we devide the polygon into sevaral triangle and sum up the signed area of those triangle.

       we can choose an arbitary point as one vertex of all the triangle and other two vertex comes from
       the polygon's one side.

       typically this one vertex is (0,0);
       
       here we fix the circle centre as the fixed vertex ;

       now we calculate the signed common area of triangle and circle and sum them up;

       this method is can be used to get common area of circle and any polygon. 
       

    **/


    int T;
    cn T;
    for(int caseno = 1; caseno <= T  ; caseno++)
    {
        ll c1, c2;
        cn c1 >> c2 >> r;

        ll x1, x2, y1, y2;
        cn x1 >> y1 >> x2 >> y2;


        x1 -= c1;
        x2 -= c1;
        y1 -= c2;
        y2 -= c2;

        vector<pair<ll, ll>> v(4);

        v[0].fs = x1;
        v[0].sc = y1;

        v[1].fs = x2;
        v[1].sc = y1;

        v[2].fs = x2;
        v[2].sc = y2;

        v[3].fs = x1;
        v[3].sc = y2;

        double an = ans(v[3], v[0]) + ans(v[0], v[1]) + ans(v[1], v[2]) + ans(v[2], v[3]);



        printf("Case %d: %.10f\n", caseno, fabs(an));
    }







    return 0;
}
