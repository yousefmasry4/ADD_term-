#include <iostream> 
#include <list> 
#include <string.h>
#include <cstdlib>
using namespace std; 
struct primarytemp
{
  primarytemp() : process(), secondary() {}
  primarytemp(double process, double secondary) 
  : process(process), secondary(secondary) {}

  double process;
  double secondary; 
};
char fi(int x){
    if(x > 0)
        return '+';    
}
bool compare_nocase (primarytemp  first,primarytemp second)
{
  return ( first.secondary > second.secondary );
}
void getdata(int *a,int *b){
    char input[100];
    gets(input);
    for(int i=0;i<strlen(input);i++){
        int tt,v,zz;
    primarytemp p;
        string data="";
        int ff=0;
        if(input[i] !='x' ){
        for(v=i;v<strlen(input);v++){
            if(input[v] != 'x' ){
                data+=input[v];
            }else{
                break;
            }
                      //      cout<<tt;
        }
        tt=v;
        i=tt;

        *a=atoi(data.c_str());
    }else
    {
        *a=1;
    }
    
        if(input[i] == 'x'){
        //    puts("yes");
            string data2="";
            for(zz=i+1;zz<strlen(input);zz++){
         //       puts("dddddddddddddd");
                if(input[zz] != 'x' && input[zz] != '+' && input[zz] != '-'){
                    data2+=input[zz];
                    ff=1;
                }else{
                    break;
                }
                tt=zz;
            }
            i=tt;
            if(ff == 0){
                *b=1;
            }else
            *b=atoi(data2.c_str());
        }else{
            p.secondary=0;
        }
        i=tt;
    }
}
void addterm(char input[]){
        list<primarytemp> q;
    list <primarytemp> temp;
    list <primarytemp> temp2;
    list <primarytemp> temp3;
    primarytemp p;
    for(int i=0;i<strlen(input);i++){
        int tt,v,zz;
    primarytemp p;
        string data="";
        if(input[i] !='x' ){
        for(v=i;v<strlen(input);v++){
            if(input[v] != 'x' ){
                data+=input[v];
            }else{
                break;
            }
                      //      cout<<tt;
        }
        tt=v;
        i=tt;

        p.process=atoi(data.c_str());
    }else
    {
        p.process=1;
    }
    
        if(input[i] == 'x'){
            cout << "";
        //    puts("yes");
            string data2="";
            int ff=0;
            for(zz=i+1;zz<strlen(input);zz++){
         //       puts("dddddddddddddd");
                if(input[zz] != 'x' && input[zz] != '+' && input[zz] != '-'){
                    ff=1;
                    data2+=input[zz];
                }else{
                    break;
                }
                tt=zz;
            }
            i=tt;
            if(ff ==0){
                p.secondary=1;
            }else
            p.secondary=atoi(data2.c_str());
        }else{
            puts("");
            p.secondary=0;
        }
        i=tt;
        q.push_front(p);
    }
    int a=0,b=0;
    getdata(&a,&b);
    int flagz=0;
    q.sort(compare_nocase);
    while(!q.empty()){
        primarytemp x=q.front();
        primarytemp y;
        q.pop_front();
        if(flagz == 0 && b>x.secondary){
            y.process=a;
            y.secondary=b;
            temp.push_front(y);
            flagz=1;
        }
        if(b == x.secondary && flagz==0){
            flagz=1;
            x.process+=a;
        }
        temp.push_front(x);
       // break;
    }
    if(flagz == 0){
        primarytemp yr;
        yr.process=a;
        yr.secondary=b;
        temp.push_front(yr);
    }  
    temp.sort(compare_nocase);  
    while(!temp.empty()){
        primarytemp x=temp.front();
        temp.pop_front();
        if(!temp2.empty()){
            primarytemp y=temp2.front();
        //    cout<<"x"<<x.secondary<<"y"<<y.secondary<<endl;
      //      cout<<"x"<<x.process<<"y"<<y.process<<endl;
            double newx;
            if(y.secondary == x.secondary){
                newx=y.process+x.process;
                temp2.pop_front();
                primarytemp z;
                z.process=newx;
                double m=y.secondary;
                z.secondary=m;
                temp2.push_front(z);
  //              cout<<newx;
            }else{
                temp2.push_front(x);               
            }
        }else{
            temp2.push_front(x);
    //        puts("S");
        }
    }
    temp2.sort(compare_nocase);
    while(!temp2.empty()){
        primarytemp x=temp2.front();
        temp2.pop_front();
        temp3.push_front(x);
    }
    temp3.sort(compare_nocase);
    while(!temp3.empty()){
        primarytemp x=temp3.front();
        temp3.pop_front();
        cout<<fi(x.process)<<x.process<<"x^("<<x.secondary<<')';
       // break;
    }
}
int main(){
    char input[100];
    gets(input);
    addterm(input);
}
