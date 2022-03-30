#include <stack>
#include <iostream>
#include <math.h>

using namespace std;

void towersGeneral(stack<int> &destination, int numDisks)
{

	stack<int> source;
	for (int i = numDisks; i > 0; i--)
	{
		source.push(i);
	}

	stack<int> auxiliary;

	int step = pow(2, numDisks) - 1;

	int itr = 0;

	if (numDisks % 2 == 0)
	{

		while (itr < step)
		{
			switch (itr % 3)
			{
				/****CASE-0******/
			case 0:
				if (auxiliary.empty() == true)
				{
					auxiliary.push(source.top());
					source.pop();
				}
				else if (source.empty() == true)
				{
					source.push(auxiliary.top());
					auxiliary.pop();
				}
				else
				{
					if (auxiliary.top() > source.top())
					{
						auxiliary.push(source.top());
						source.pop();
					}
					else
					{
						source.push(auxiliary.top());
						auxiliary.pop();
					}
				}
				break;
				/****CASE-1******/
			case 1:
				if (destination.empty() == true)
				{
					destination.push(source.top());
					source.pop();
				}
				else if (source.empty() == true)
				{
					source.push(destination.top());
					destination.pop();
				}
				else
				{
					if (destination.top() > source.top())
					{
						destination.push(source.top());
						source.pop();
					}
					else
					{
						source.push(destination.top());
						destination.pop();
					}
				}
				break;
				/****CASE-2******/
			case 2:
				if (destination.empty() == true)
				{
					destination.push(auxiliary.top());
					auxiliary.pop();
				}
				else if (auxiliary.empty() == true)
				{
					auxiliary.push(destination.top());
					destination.pop();
				}
				else
				{
					if (destination.top() > auxiliary.top())
					{
						destination.push(auxiliary.top());
						auxiliary.pop();
					}
					else
					{
						auxiliary.push(destination.top());
						destination.pop();
					}
				}
				break;
			}
			itr++;
		}
	}
	else
	{

		while (itr <step)
		{
			switch (itr % 3)
			{
				/****CASE-0******/
			case 0:
				if (destination.empty() == true)
				{
					destination.push(source.top());
					source.pop();
				}
				else if (source.empty() == true)
				{
					source.push(destination.top());
					destination.pop();
				}
				else
				{
					if (destination.top() > source.top())
					{
						destination.push(source.top());
						source.pop();
					}
					else
					{
						source.push(destination.top());
						destination.pop();
					}
				}
				break;
			/****CASE-1******/
			case 1:
				if (auxiliary.empty() == true)
				{
					auxiliary.push(source.top());
					source.pop();
				}
				else if (source.empty() == true)
				{
					source.push(auxiliary.top());
					auxiliary.pop();
				}
				else
				{
					if (auxiliary.top() > source.top())
					{
						auxiliary.push(source.top());
						source.pop();
					}
					else
					{
						source.push(auxiliary.top());
						auxiliary.pop();
					}
				}
				break;
			/****CASE-2******/
			case 2:
				if (destination.empty() == true)
				{
					destination.push(auxiliary.top());
					auxiliary.pop();
				}
				else if (auxiliary.empty() == true)
				{
					auxiliary.push(destination.top());
					destination.pop();
				}
				else
				{
					if (destination.top() > auxiliary.top())
					{
						destination.push(auxiliary.top());
						auxiliary.pop();
					}
					else
					{
						auxiliary.push(destination.top());
						destination.pop();
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
	
	int x;
	cout << " Please Enter A Disk Count"<< endl;
	cin >> x ;
	
	towersGeneral(result, x);
	while (!result.empty())
	{
		cout << ' ' << result.top();
		result.pop();
	}
	cout << '\n';
	
	return 0;
}
