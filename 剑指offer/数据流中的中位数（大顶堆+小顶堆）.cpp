class Solution {
    /*
思路：
    1.维护一个大顶堆，一个小顶堆，且保证两点：
       1)小顶堆里的全大于大顶堆里的；
       2)个堆个数的差值小于等于1。
       
    2.当数目为偶数的时候，将这个值插入大顶堆中，再将大顶堆中的堆顶（即最大值）插入到小顶堆中；
      当数目为奇数的时候，将这个值插入小顶堆中，再讲小顶堆中的堆顶（即最小值）插入到大顶堆中。
  
    3.当总数字个数为奇数时，中位数就是小顶堆堆顶；
      当总数字个数为偶数时，中位数就是 2个堆堆顶的平均数。
    */
public:
    priority_queue<int,vector<int>,less<int> > big_heap; // 从大到小，大顶堆
    priority_queue<int,vector<int>,greater<int> > small_heap; // 从小到大，小顶堆
    // 让大顶堆所有元素均小于等于小顶堆的所有元素.
    int cnt = 0;
    void Insert(int num)
    {
        cnt += 1;
        if(cnt % 2 == 0) { // 元素个数是偶数时,将大顶堆堆顶放入小顶堆
            big_heap.push(num);
            small_heap.push(big_heap.top());
            big_heap.pop();
        }
        else {
            small_heap.push(num);
            big_heap.push(small_heap.top());
            small_heap.pop();
        }
    }

    double GetMedian()
    { 
        // 当总数字个数为奇数时，中位数就是大顶堆堆顶
        if(cnt % 2 == 1) {
            return big_heap.top();
        }
        // 当总数字个数为偶数时，中位数就是2个堆堆顶的平均数
        return double((big_heap.top() + small_heap.top()) / 2.0);
    }

};