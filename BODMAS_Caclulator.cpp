#include<bits/stdc++.h>
using namespace std;
char *st;int top=-1,pftop=-1;
char *pf[30];
int *arr;
void initialise1()
{
	st=new char[30];
	top=-1;
	pftop=-1;
	for(int i=0;i<30;i++)
	{
		pf[i]=new char[15];
	}
}
void delete1()
{
	delete st;
}
void initialise2()
{
	top=-1;
	arr=new int[20];
}
char peektop()
{
	return st[top];
}
int type(char x)
{
	if(x>='0' && x<='9')
	{
		return 1;
	}
	else if(x=='(' || x==')')
	{
		return 2;
	}
	else 
	{
		return 4;
	}
}
int isprec(char x)
{
 char ch=x;
 switch(ch)
 {
	 case '+':case '-':return 2;
	 case '*':case '/':case '%':return 4;
	 case '^':return 5;
	 case '(':return 0;
 }
}
int osprec(char x)
{
 char ch=x;
 switch(ch)
 {
	 case '+':case '-':return 1;
	 case '*':case '/':case '%':return 3;
	 case '^':return 6;
	 case '(':return 10;
 }
}
int isoperator(char x)
{
	char ops[]={'+','-','*','/','%','^','('};
	for(int i=0;i<7;i++)
	{
		if(x==ops[i])
		{return i+1;}
	}
	return 0;
}
int isoperator2(char x)
{
	char ops[]={'+','-','*','/','%','^'};
	for(int i=0;i<6;i++)
	{
		if(x==ops[i])
		{return i+1;}
	}
	return 0;
}
int main()
{
	
	char temp[150];
	cout<<"Enter a numeric expression\n";
	cin.getline(temp,150,'\n');
	char exp[150];
	char cur[20];int k=0;
	int templen=strlen(temp);
	templen-=1;
	for(int i=0;i<templen;i++)
	{
		if(temp[i]==' ')
		{
			continue;
		}
      else if(isoperator2(temp[i]))
		{
			exp[k]=temp[i];k+=1;
			exp[k]=' ';k+=1;
		}
		else if(type(temp[i]) != type(temp[i+1]))
		{
			exp[k]=temp[i];
			k++;
			exp[k]=' ';k++;
		}
		else
		{
			exp[k]=temp[i];k++;
		}
	}
	exp[k]=' ';
	exp[++k]=')';
	exp[++k]='\0';
	stringstream s(exp);
	/*cout<<"This is parsed and filtered expression\n";
	for(int i=0;i<=k;i++)
	{
		cout<<exp[i];
	}*/
	initialise1();
	int x=0;
	while(s)
	{
		s.getline(cur,20,' ');
		if(strlen(cur) != 0)
		{
			if(cur[0]>='0' && cur[0]<='9')
			{
           pftop+=1;
			  strcpy(pf[pftop],cur);
			  continue;
			}
			else if(isoperator(cur[0]))
			{
				if(top<=-1)
				{
					top++;
					st[top]=cur[0];continue;
				}
            else if(osprec(cur[0]) > isprec(peektop()))
			   {
             top+=1;
				 st[top]=cur[0];
			   }
			  else if(osprec(cur[0]) < isprec(peektop()))
			   {
				  while(osprec(cur[0]) < isprec(peektop()))
				  {
					  char p2[2];
					  p2[0]=st[top];p2[1]='\0';
					  top--;
					  pftop+=1;
					  strcpy(pf[pftop],p2);
				  }
				  top+=1;
				  st[top]=cur[0];continue;
			   }
			}
			else if(cur[0] == ')')
			{
         while(peektop() != '(')
			{
				char p3[2];
				p3[0]=st[top];p3[1]='\0';
				top--;
				pftop+=1;
				strcpy(pf[pftop],p3);
			}
			top-=1;
			}

		}
	}
	initialise2();
	int res;
	/*for(int i=0;i<=pftop;i++)
	{
		cout<<pf[i];
	}*/
	for(int i=0;i<=pftop;i++)
	{
		if(pf[i][0]>='0' && pf[i][0]<='9')
		{
			top+=1;
			arr[top]=stoi(pf[i]);
		}
		else
		{
			int y=arr[top];top-=1;
			int x=arr[top];top-=1;
			switch(pf[i][0])
			{case '+':
			res=x+y;break;
			case '-':
			res=x-y;break;
			case '*':
			res=x*y;break;
			case '/':
			res=x/y;break;
			case '%':
			res=x%y;break;
			case '^':
			res=pow(x,y);break;
			}
			top+=1;
			arr[top]=res;
		}

	}
	cout<<endl;
	cout<<arr[0];
   return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	