#include <stack>
#include <iostream>
#include <math.h>

using namespace std;

void towersGeneral(stack<int> &Cstack, int numDisks)
{

	stack<int> Astack;
	for (int i = numDisks; i > 0; i--)
	{
		Astack.push(i);
	}

	stack<int> Bstack;

	int step = pow(2, numDisks) - 1;

	int itr = 0;

	if (numDisks % 2 == 0)
	{
		/*

		while (itr<=step)
		{
				switch (itr%3)
			{
				case 0 :
					if(){

				}
					else if(){


				}
					else{
						if ()
						{

						}
						else{

						}

				}

				case 1 :
					if(){

					}
					else if(){

					}
					else{

					}


				case 2 :
					if(){

					}
					else if(){

					}
					else{

					}
			}
			itr++;

		}
		*/
	}
	else
	{

		while (itr < step)
		{
			switch (itr % 3)
			{
				/****CASE-0******/
			case 0:
				if (Cstack.empty() == true)
				{
					Cstack.push(Astack.top());
					Astack.pop();
				}
				else if (Astack.empty() == true)
				{
					Astack.push(Cstack.top());
					Cstack.pop();
				}
				else
				{
					if (Cstack.top() > Astack.top())
					{
						Cstack.push(Astack.top());
						Astack.pop();
					}
					else
					{
						Astack.push(Cstack.top());
						Cstack.pop();
					}
				}
				break;
			/****CASE-1******/
			case 1:
				if (Bstack.empty() == true)
				{
					Bstack.push(Astack.top());
					Astack.pop();
				}
				else if (Astack.empty() == true)
				{
					Astack.push(Bstack.top());
					Bstack.pop();
				}
				else
				{
					if (Bstack.top() > Astack.top())
					{
						Bstack.push(Astack.top());
						Astack.pop();
					}
					else
					{
						Astack.push(Bstack.top());
						Bstack.pop();
					}
				}
				break;
			/****CASE-2******/
			case 2:
				if (Cstack.empty() == true)
				{
					Cstack.push(Bstack.top());
					Bstack.pop();
				}
				else if (Bstack.empty() == true)
				{
					Bstack.push(Cstack.top());
					Cstack.pop();
				}
				else
				{
					if (Cstack.top() > Bstack.top())
					{
						Cstack.push(Bstack.top());
						Bstack.pop();
					}
					else
					{
						Bstack.push(Cstack.top());
						Cstack.pop();
					}
				}
				break;
			}
			
			itr++;
		}
	}
}

int main()
{
	stack<int> result; // The final peg
	// Challenge problem: write a general towersGeneral function
	// result = {};
	towersGeneral(result, 7);
	while (!result.empty())
	{
		cout << ' ' << result.top();
		result.pop();
	}
	cout << '\n';
	// Show the final peg
	return 0;
}
