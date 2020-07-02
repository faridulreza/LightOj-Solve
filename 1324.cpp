#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PI (acos(-1))
#define ct cout<<
#define cn cin>>
#define spc <<" "<<
#define nl puts("")
#define _fl(x) puts("FLAG " #x);
#define  _(x)  cout<< #x <<" is "<< x <<endl;
#define fs first
#define sc second
#define pb push_back
#define all(v)  (v).begin(), (v).end()
#define _109 (1000000000)
#define _0(arr) memset(arr,0,sizeof ( arr ) )
#define _1(arr) memset(arr,-1,sizeof ( arr ) )
#define _ninp(n,arr) for(int i=0; i<n;i++)cin>>arr[i];
#define _nout(n,arr) for(int i=0; i<n;i++)cout<<arr[i]<<" \n"[i==n-1];
double _eps=1e-6;
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


bool isvar(char s){

    
    	if(s>='a' && s<='j')return true;
        return false;
}
int prec(char s){

   if(s=='!')return 3;
   if(s=='&')return 2;
   if(s=='|')return 1;
   else return 0;
}


void postfix(string &varlist,string &inp, string &out)
{


    stack<char> st;
    st.push('N');


    for(char word : inp)
    {

        if(isvar(word))out.pb(word),varlist.pb(word);
        else if(word == '(')st.push(word);
        else if(word == ')')
        {

            while(st.top() != 'N' && st.top() != '(' )
            {
                char c = st.top();
                out.pb (c);
                st.pop();
            }
            st.pop();

        }


        else
        {


            while(st.top() != 'N' && st.top() != '(' && prec(st.top()) >=prec(word) && ((st.top()=='!')?word!='!':1) )
            {
                char c = st.top();
                out.pb(c);
                st.pop();
            }
            st.push(word);
        }
    }

    while(st.top() != 'N' && st.top() != '(')
    {
        out.pb (st.top());
        st.pop();
    }

}

int evaluate(map<char,bool> &var,string &out){


    stack<bool>st;
    for(auto c:out){

         if(isvar(c)){    
            if(var.count(c))st.push(var[c]);
            else st.push(0); 
          }
          else{
               
              if(c=='!'){
              	bool a=st.top();
              	st.pop();
              
              	st.push(!a);
              }
              else if(c=='&'){

              	bool b=st.top();st.pop();
              	bool a=st.top();st.pop();

              	st.push(a&b);

              }
              else {

                 
              	bool b=st.top();st.pop();
              	bool a=st.top();st.pop();
              	st.push(a|b);
              }
          }
    }
return st.top();
}




int main() {


   int T;
   cn T;
   getchar();
   string inp;
   string out,out2;
   string varlist;

   for(int caseno=1; caseno<=T  ;caseno++){
   int f,s;

   getline(cin,inp);
   postfix(varlist,inp,out);
   varlist.clear();

   
   getline(cin,inp);
   postfix(varlist,inp,out2);
   
   set<char>st(all(varlist));

   varlist.clear();

   for(int x:st)varlist.pb(x);



   
   
   int l=1<<((int)varlist.size());
   map<char,bool>var;
   
   int br=0;
   for (int i = 0; i <l; ++i)
   {
   	int bin=i;
   	for (int j = 0; j <varlist.size(); ++j)
   	{
   		var[varlist[j]]=bin&1;
   		bin/=2;
   	}
   	f=evaluate(var,out);
   		s=evaluate(var,out2);
   	    if(f!=s){br=1;break;}
   	

   }
   
   var.clear();
   inp.clear();
   out.clear();
   out2.clear();
   if(!br)printf("Case %d: Equivalent\n",caseno);
   else printf("Case %d: Not Equivalent\n",caseno);

   }
  return 0;
}
