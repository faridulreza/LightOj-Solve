#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define _fl(x) //puts("FLAG " #x),ct endl;P
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
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int prec(string s)
{


    if(s == "^")return 3;
    if(s == "/" || s == "*")return 2;
    if(s == "+" || s == "-")return 1;
    return -1;
}

int isnum(string s )
{
    if(s.size() >= 2 && isdigit(s[1]) || isdigit(s[0]) || s[0] == 'x')return 1;
    return 0;
}

ll getn(string s)
{

    int i = 0, minus = 1;

    if(s[0] == '-')i++, minus = -1;
    if(s[0]== '+')i++;

    ll num = 0;
    for (; i < s.size(); ++i)
    {
        num *= 10;
        num += (s[i] - '0');
    }

    return num * minus;
}


void postfix(vector<string> &inp, vector<string> &out)
{


    stack<string> st;
    st.push("N");


    for(string word : inp)
    {

        if(isnum(word))out.pb (word);
        else if(word == "(")st.push(word);
        else if(word == ")")
        {

            while(st.top() != "N" && st.top() != "(" )
            {
                string c = st.top();
                out.pb (c);
                st.pop();
            }
            st.pop();
        }
        else
        {


            while(st.top() != "N" && st.top() != "(" && prec(st.top()) >= prec(word))
            {
                string c = st.top();

                out.pb(c);
                st.pop();
            }
            st.push(word);
        }
    }

    while(st.top() != "N" && st.top() != "(")
    {
        out.pb (st.top());
        st.pop();
    }

}

void tostring(string &inp, vector<string> &in)
{


    
    int l = inp.size();

    for (int i = 0; i < l; ++i)
    {
        
        if(isdigit(inp[i]))
        {
            string s;
            while(isdigit(inp[i]) && i<l)
            {

                s.pb(inp[i]);
                i++;
            }
            i--;
            in.pb(s);
        }
        else if(inp[i]=='x'){
          string s="x 1 + 0";
          in.pb(s);
        }
        else
        {
            string s(1, inp[i]);
            in.pb(s);
        }
    }

  

}


string itos(ll res){

    ll m = res;
   

    string s;
     if(res==0){
      s.assign(1,'0');
      return s;
     } 
    res=abs(res);

    while(res)
    {
        s.pb((res % 10 + '0'));
        res /= 10;
    }

    if(m < 0)s.pb('-');
    reverse(all(s));
    return s;


}

string operate(string a, string b, string c)
{

    string s;
    ll res;
    if(c == "+")res = getn(a) + getn(b);
    else if(c == "-")res = getn(a) - getn(b);
    else if(c == "*")res = getn(a) * getn(b);
    return itos(res);

}




string handlex(string aa, string bb,string op)
{


      // ct "got "<<aa;nl;
      // ct "got "<<bb;nl;

      stringstream a(aa),b(bb);
      string sa1,sop1,sc1,sa2,sop2,sc2;

      if(aa[0]=='x' && bb[0]=='x'){
         a>>sa1,b>>sa1;

         a>>sa1;
         a>>sop1;
         a>>sc1;

         b>>sa2;
         b>>sop2;
         b>>sc2;

         ll a2,c2,a1,c1;

         if(sa1.empty()|| sa1=="x")a1=1;
         else a1=getn(sa1);

         if(sa2.empty())a2=1;
         else a2=getn(sa2);

         if(sc1.empty())c1=0;
         else c1=getn(sc1);


         if(sc2.empty())c2=0;
         else c2=getn(sc2);
         

        ll rc,ra;

        if(op=="+")ra=a1+a2,rc=c1+c2;
        if(op=="-")ra=a1-a2,rc=c1-c2;
         

        string x("x "),jog(" + ");

        if(ra==0){
            return itos(rc); 
        }
        else if(rc==0)return x+ itos(ra)+jog+"0";
        else  return x+ itos(ra) + jog + itos(rc);
        

      }
      else if(aa[0]=='x'){
        
         a>>sa1;
         a>>sa1;
         a>>sop1;
         a>>sc1;

        

         ll a2,c2,a1,c1;
         
         if(sa1.empty() || sa1=="x")a1=1;
         else a1=getn(sa1);
         

         if(sc1.empty())c1=0;
         else c1=getn(sc1);
         
         a2=0;
         c2=getn(bb);
        

        ll rc,ra;

        if(op=="+")ra=a1+a2,rc=c1+c2;
        if(op=="-")ra=a1-a2,rc=c1-c2;
        if(op=="*")ra=a1*c2,rc=c1*c2;
         

        if(ra==0){
            return itos(rc); 
        }
        else if(rc==0)return "x "+ itos(ra)+" + "+"0";
        else  return "x "+ itos(ra)+" + "+ itos(rc);
        

       
      }
      else if(bb[0]=='x'){


         b>>sa2;

         
         b>>sa2;
         b>>sop2;
         b>>sc2;

         ll a2,c2,a1,c1;

         
         if(sa2.empty() || sa2=="x")a2=1;
         else a2=getn(sa2);
         

         if(sc2.empty())c2=0;
         else c2=getn(sc2);
        ll rc,ra;
        a1=0;
        c1=getn(aa);

        if(op=="+")ra=a1+a2,rc=c1+c2;
        if(op=="-")ra=a1-a2,rc=c1-c2;
        if(op=="*")rc=c1*c2,ra=c1*a2;
         

        if(ra==0){
            return itos(rc); 
        }
        else if(rc==0)return "x "+ itos(ra)+" + "+"0";
        else  return "x "+itos(ra)+" + "+ itos(rc);

      }

}


string eva(vector<string> &out){


    stack<string> st;


    for(string c : out)
    {

        if(isnum(c))st.push(c);
        else
        {

            string a, b;

            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            string s;
//             _(a);
//             _(b);
// //_fl(xxxxxxxx);
            if(a[0] == 'x' || b[0] == 'x')s = handlex(a, b, c);
            else s=operate(a,b,c);        

            //_(s);
            st.push(s);

        }

    }


return st.top();
}



int main()
{


     int T;
        cn T;
        getchar();
    for(int caseno=1; caseno<=T  ;caseno++){

    vector<string>in, out;
    string inp,s1,s2,res;
   
    getline(cin, inp,'=');
    tostring(inp, in);
    postfix(in, out);
    s1=eva(out);

    in.clear();  
    out.clear();
    getline(cin,inp,'\n');
    tostring(inp,in);
    postfix(in,out);

    s2=eva(out);

    if(s1[0]=='x' || s2[0]=='x')res=handlex(s1,s2,"-");
    else{
        if(s1==s2) printf("Case %d: infinitely many solutions\n",caseno);
        else printf("Case %d: no solution\n",caseno);
        continue;


    }

    if(res[0]!='x' && res[0]=='0'){
      printf("Case %d: infinitely many solutions\n",caseno);
    }
    else if(res[0]!='x' && res[0]!='0')printf("Case %d: no solution\n",caseno);
    
    else {

      stringstream ss(res);

      string a,c;

      ss>>a;
      ss>>a;
      ss>>c;
      ss>>c;

      ll aa,cc;

      aa=getn(a);
      cc=-getn(c);
      
      if(abs(cc)%abs(aa)==0){
          printf("Case %d: %lld\n",caseno,cc/aa);
      }
      else{

         ll g=gcd(abs(aa),abs(cc));

         aa/=g;
         cc/=g;
         if(cc*aa<0){
          aa=abs(aa);
          cc=-abs(cc);
         }
         else aa=abs(aa),cc=abs(cc);
         
         printf("Case %d: %lld/%lld\n",caseno,cc,aa);


      }



    }

    }


    return 0;
}










