#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int> arr, vector<int> sum, int curr, int set, int last)
{
    if(set == 4 && last <= sum[curr])
        return 1;
    if(set >= 4)
        return 0;

    int total = 0;
    int out = 0;

    while(curr < arr.size() && total <= sum[curr])
    {
        total += arr[curr];
        curr++;
        out += helper(arr, sum, curr, set+1, total);
    }
    return out;
}

int count_subsegments(vector<int> arr, int count = 0)
{
    if(arr.size() < 3)
        return 0;
        
    vector<int> sum(arr.size());

    sum[(int)arr.size()-1] = arr[arr.size()-1];

    for(int i = arr.size()-2; i >= 0; i--)
    {
        sum[i] = arr[i] + sum[i+1];
    }

    for(int i : sum)
        cout << i << " ";
    cout << endl;

    return helper(arr, sum, 0, 1, 0);
}


/*
int count_subsegments(vector<int> arr, int curr=-1, int sum=0, int prev=0, int count=1)
{
    if(count == 3 && curr == arr.size() - 1 && sum >= prev)
        return 1;
    else if(count == 3)
    {
        for(int i = curr+1; i < arr.size(); i++)
        {
            sum += arr[i];
        }
        return sum >= prev;
    }

    int total = 0;
    cout << curr << " " << count << endl;
    for(int i = curr+1; i < arr.size(); i++)
    {
        sum += arr[i];
        if(sum >= prev)
            total += count_subsegments(arr, i, 0, sum, max(3, count+1));
    }

    if(count == 3 && sum >= prev)
        total++;
    
    return total;
}

int main()
{
    cout << count_subsegments({0,0,0}) << endl;
}

/*
void helper(vector<int> arr, int curr, int sum, int prev, int count, int& out)
{
    if(count == 3 && curr == arr.size() - 1 && sum >= prev)
        out++;

    for(int i = curr+1; i < arr.size(); i++)
    {
        sum += arr[i];
        if(sum >= prev)
            helper(arr, i, 0, sum, count+1, out);
    }

    if(count == 3 && sum >= prev)
        out++;
}

int count_subsegments(vector<int> arr)
{
    int answer = 0;
    helper(arr, -1, 0, 0, 1, answer);
    return answer;
}
*/