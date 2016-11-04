#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;


int main()
{

	int pid=fork();//c1
	
	if(pid>0)
	{
		cout<<"Parent "<<getpid()<<endl;

		pid=fork();//c2

		if(pid==0)
		{
			cout<<"Child "<<getpid()<<endl;

			sleep(3);

			pid=fork();

			if(pid==0)
			{
				// 
				cout<<"Grandchild "<<getpid()<<endl;
			}

			else
			{
				pid = fork();

				if(pid==0)
				{
					cout<<"Grandchild "<<getpid()<<endl;
				}
			}

		}
	}

	else if(pid==0)
	{

		sleep(1);
		// child
		cout<<"Child "<<getpid()<<endl;

		pid = fork();

		if(pid==0)
		{
			// grandchild
			cout<<"Grandchild "<<getpid()<<endl;
		}

		else
		{
		
			// grandchild
			pid=fork();
			if(pid==0)
				cout<<"Grandchild "<<getpid()<<endl;
		}

	}



}