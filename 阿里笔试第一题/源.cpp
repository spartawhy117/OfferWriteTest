#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
int GetMaxIncreaseInTerm(int currTerm,double& time , int n,const vector<vector<double>>& prices)
{
	int nextTerm = currTerm +1;
	double maxtimes = 0.0;
	int result=0;
	vector<double> nowPrices = prices[currTerm];
	vector<double> nextPrices = prices[nextTerm];
	for(int i=0;i<n;++i)
	{
		double currtime = nextPrices[i] / nowPrices[i];
		if(currtime>maxtimes)
		{
			maxtimes = currtime;
			result = i;
		}
	}
	time = maxtimes;
	return result;

}
double GetStockValue(int index,int term,double price, const vector<vector<double>>& prices)
{
	double stcokprice = prices[term][index];
	double buyStocks = price / stcokprice;
	double result = buyStocks*prices[term + 1][index];
	return result;
}
double GetMaintainValue(int index, int term, double price, const vector<vector<double>>& prices)
{
	double time = prices[term + 1][index] / prices[term][index];
	double result = price*time;
	return result;
}
double StockGod(int n, int m, double p, const vector<vector<double>>& prices)
{
	//第一次购买
	double currMoney = 1.0;
	double time = 0.0;
	int chooseIndex = GetMaxIncreaseInTerm(0,time,n, prices);
	
	double currStockValue = currMoney*time;
	double stockToCrash = currStockValue*(1.0 - p);
	double maintainValue = GetMaintainValue(chooseIndex, 1, currStockValue, prices);
	double changeStockValue;
	int lastIndex = chooseIndex;
	int term = 2;
	while (term<m)
	{
		chooseIndex = GetMaxIncreaseInTerm(term - 1, time, n, prices);
		if(chooseIndex!=lastIndex)
		{
			changeStockValue = GetStockValue(chooseIndex, term - 1, stockToCrash, prices);
			if (changeStockValue>maintainValue)
			{
				currStockValue = changeStockValue;
				stockToCrash = currStockValue*(1.0 - p);
				maintainValue = GetMaintainValue(chooseIndex, term, currStockValue, prices);
				lastIndex = chooseIndex;
			}
			else
			{
				currStockValue = maintainValue;
				stockToCrash = currStockValue*(1.0 - p);
				maintainValue = GetMaintainValue(chooseIndex, term, currStockValue, prices);
			}
		}
		else
		{
			currStockValue = maintainValue;
			stockToCrash = currStockValue*(1.0 - p);
			maintainValue = GetMaintainValue(chooseIndex, term, currStockValue, prices);
		}
			
		
		term ++;
	}

	return  stockToCrash;
}
/******************************结束写代码******************************/


int main()
{
	int n = 0;
	int m = 0;
	double p = 0;
	cin >> n >> m >> p;

	vector<vector<double>> prices;
	for (int i = 0; i < m; ++i) {
		prices.push_back(vector<double>());
		for (int j = 0; j < n; ++j) {
			double x = 0;
			cin >> x;
			prices.back().push_back(x);
		}
	}

	double final = StockGod(n, m, p, prices);
	printf("%.1f\n", final);


	system("pause");
	return 0;
}