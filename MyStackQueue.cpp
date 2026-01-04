#include "MyStackQueue.h"

int main()
{
	//MyQueue queue;
	MyStackQueue stack_queue;
	//queue.push(1);
	//queue.push(2);
	//queue.peek();  // ·µ»Ø 1
	//queue.pop();   // ·µ»Ø 1
	//queue.empty(); // ·µ»Ø false

	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> res = stack_queue.maxSlidingWindow(nums, 3);

}
