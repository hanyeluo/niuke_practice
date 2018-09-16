#include <iostream>
#include <vector>
#include <string>

using namespace std;

//子数组最大和
int maxSumInSubArray(std::vector<int> & array , int len , int &begin , int &endd)
{
    int *c = new int[len];
    int max = -1000;
    int start = 0;
    int end = 0;
    int tmp = 0;

    c[0] = array[0];
    for(int i = 1;i < len;++i)
    {
        if(c[i-1] > 0)
        {
            c[i] = c[i-1] + array[i];
        }
        else
        {
            c[i] = array[i];
            tmp = i;
        }
        if(c[i] > max)
        {
            max = c[i];
            start = tmp;
            end = i;
        }
    }

    std::vector<int>::iterator begin_ = array.begin() + start;
    std::vector<int>::iterator end_ = array.begin() + end;
    array.erase(begin_,end_);
    begin = start;
    endd = end;
    //cout<<"子数组最大和的起始位置："<<start<<"~"<<end<<endl;
    return max;
}

//最长公共子序列
#define N 1000

int c[N][N];
int flag[N][N];

int getLCSlength(const std::string s1, const std::string s2)
{
	int i;
	int len1 = s1.size();;
	int len2 = s2.size();
	for(i=1;i<=len1;i++)
		c[i][0] = 0;
	for(i=0;i<=len2;i++)
		c[0][i] = 0;
	int j;
	for(i=1;i<=len1;i++)
		for(j=1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				c[i][j] = c[i-1][j-1] +1;
				flag[i][j] = 0;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j] = c[i-1][j];
				flag[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i][j-1];
				flag[i][j] = -1;
			}
		}
		return c[len1][len2];
}
string getLCS(const std::string s1, const std::string s2,int len, std::string &lcs)
{
	int i = s1.size();
	int j = s2.size();;
	while(i&&j)
	{
		if(flag[i][j]==0)
		{
			lcs = s1[i-1] + lcs;
			i--;
			j--;
		}
		else if(flag[i][j]==1)
			i--;
		else
			j--;
	}
	return lcs;
}

//最长公共字符串
int longest_common_substring(const string str1, const string str2 , string &lcs_r)
{
	int i,k,len1,len2,len,s1_start,s2_start,idx,curmax,max;
	len1 = str1.size();
	len2 = str2.size();
	len = len1 + len2;
	max = 0;
	for(i = 0 ; i < len ; i++)
	{
		s1_start = s2_start = 0;
		if(i < len1)
			s1_start = len1 - i;    //每次开始匹配的起始位置
		else
			s2_start = i - len1;
		curmax = 0;
		for(idx = 0 ; ( s1_start + idx < len1 ) && ( s2_start + idx < len2 ); idx++ )
		{
			if(str1[s1_start+idx]==str2[s2_start+idx])
				curmax++;
			else     //只要有一个不相等，就说明相等的公共字符断了，不连续了，要保存curmax与max中的最大值，并将curmax重置为0
			{
				//max = curmax > max ? curmax : max;
				if(curmax > max)
				{
					max = curmax;
					k = s1_start+idx-1;      //保存连续子串长度增加时连续子串最后一个字符在str1字符串中的下标位置，便于输出公共连续子串
				}
				curmax = 0;
			}
		}
		//max = curmax > max ? curmax : max;
		if(curmax > max)
		{
			max = curmax;
			k = s1_start+idx-1;
		}
	}
 
	//输出公共子串
	string s;
	s = str1.substr(k-max+1,max);
	lcs_r = s;
	//for(i=0;i<max;i++)
	//	s[i]=str1[k-max+1+i];     //公共字串在str1中的下标起始位置为k-max+1，结束位置为k
	//s[i]='\0';
	printf("最长公共子串为：");
	printf("%s",s.c_str());
	return max;
}
//大于1/2 1/3的数字是什么

int findhalf(vector<int> &a)
{
    int flag = 0;
    int i = 0;
    int k = 0;
    for (auto iter = a.begin(); iter != a.end(); ++iter) 
    {
        if(flag == 0)
        {
            k = *iter;
        }
        if( k == *iter)
            flag++;
        else
            flag--;
    }
    return k;
}
pair<int,int> findone_third(const vector<int> &nums)
{
    int m ,n;
    int cm , cn;
    for(auto num : nums)
    {
        if(cm == 0 || num == m)
        {
            m = num;
            ++cm;
        }
        else if(cn == 0 || num == n)
        {
            n = num;
            ++cn;
        }
        else
        {
            cn--;
            cm--;
        }
    }
    return make_pair(m,n);
}

int main(int argc, const char *argv[])
{
    string s1 ,s2;
    string lcs_r="";
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        scanf("%d",&x);
        a.push_back(x);
    }
    pair<int,int> result = findone_third(a);
    cout << result.first << ";" << result.second << endl;
    //cin >> s1;
    //cin >> s2;
    //int len = longest_common_substring(s1,s2,lcs_r);
    //int lcsLen = getLCSlength(s1,s2);
    //string lcs = getLCS(s1,s2,lcsLen,lcs_r);
    //cout << len << " : " << lcs_r;
    return 0;
}
