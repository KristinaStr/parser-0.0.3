#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	string stroka;
	double a, m, s;
	char o1, o2;        

	getline(cin, stroka);                               
	istringstream stream(stroka);                        
	stream >> a; stream >> o1;                         
	while (stream >> m) 
	{                                
		if ((o1 == '*') || (o1 == '/')) 
		{              
			if (o1 == '*') 
			{
				a = a*m;
			}
			if (o1 == '/') 
			{         
 				if (m != 0) 
 				{                            
					a = a / m;
				}
				else {  
					cout << "error" << endl;              
					return -1;
				}
			}
			if (!(stream >> o1)) {                      
				break;                                    
			}
		}
		else if ((o1 == '+') || (o1 == '-')) 
		{          
			if (stream >> o2) {                          
				if ((o2 == '+') || (o2 == '-')) 
				{        
					if (o1 == '+') 
					{
						a +=m;
					}
					if (o1 == '-') 
					{
						a -=m;
					}
					o1 = o2; o2 = 0;
				}
				if ((o2 == '*') || (o2 == '/')) 
				{
					while ((o2 == '*') || (o2 == '/')) 
					{ 
					    stream>>s;
					   if (o2 == '*')
					   
					    {
					        m=m*s;
					    }
					    if (o2 == '/')
					    {
							if (s != 0) 
							{
								m = m / s;
							}
							else 
							{
								cout << "error" << endl;
								return -1;
							}
						}
						if (!(stream >> o2)) 
						{
							break;
						}
					}
					if (o1 == '+') 
					{
						a += m;
					}
					if (o1 == '-') 
					{
						a -= m;
					}
					o1 = o2; o2 = 0;
				}
			}
			else {
				if (o1 == '+') 
				{
					a += m;
				}
				if (o1 == '-') 
				{
					a -= m;
				}
			}
		}
	}
	cout << a << endl;
	return 0;
}
