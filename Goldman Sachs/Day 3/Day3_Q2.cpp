/*
**********FINDING CONSECUTIVE INTEGERS FROM A DATA STREAM**********
For a stream of integers, implement a data structure that checks if the last k integers parsed in the stream are equal to value.

Implement the DataStream class:

DataStream(int value, int k) Initializes the object with an empty integer stream and the two integers value and k.
boolean consec(int num) Adds num to the stream of integers. Returns true if the last k integers are equal to value, and false otherwise. If there are less than k integers, the condition does not hold true, so returns false.


Example 1:

Input
["DataStream", "consec", "consec", "consec", "consec"]
[[4, 3], [4], [4], [4], [3]]
Output
[null, false, false, true, false]

Explanation
DataStream dataStream = new DataStream(4, 3); //value = 4, k = 3
dataStream.consec(4); // Only 1 integer is parsed, so returns False.
dataStream.consec(4); // Only 2 integers are parsed.
                      // Since 2 is less than k, returns False.
dataStream.consec(4); // The 3 integers parsed are all equal to value, so returns True.
dataStream.consec(3); // The last k integers parsed in the stream are [4,4,3].
                      // Since 3 is not equal to value, it returns False.*/
#include <bits/stdc++.h>
using namespace std;
class DataStream
{
public:
    int value, k;
    vector<pair<int, int>> vec;
    DataStream(int value, int k)
    {
        this->value = value;
        this->k = k;
    }

    bool consec(int num)
    {
        int n = vec.size();
        if (n == 0 || vec[n - 1].first != num)
            vec.push_back({num, 1});
        else
        {
            int pre_cnt = vec[n - 1].second;
            vec.push_back({num, pre_cnt + 1});
        }

        if (num == value && vec[n].second >= k)
            return true;
        else
            return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
int main()
{

    return 0;
}