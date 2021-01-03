/* https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3245/


Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]

 

Note:

    1 <= arr.length <= 10000
    0 <= arr[i] <= 9

*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int iIndex = 0;
        int iInitialSize = arr.size();
        for(auto iterator = begin(arr); iterator != end(arr); )
            {
                if(iInitialSize == iIndex)
                break;
                
                if(*iterator == 0)
                {
                    arr.insert(iterator, 0);
                    iIndex += 2;
                    iterator = begin(arr) + iIndex;
                    continue;
                }
                iIndex++;
                iterator++;

            }
            arr.resize(iInitialSize);
    }
};

int main()
{
    vector<int> arr {1,0,2,3,0,4,5,0};

    Solution sln;
    sln.duplicateZeros(arr);
    for(int x: arr)
    {
        cout << x << " ";
    }
}