# Binary Search Tree Exercise

Here is an exercise that you can do if you want to implement a binary search tree.

There is a "skeleton" in place, in the form of empty functions that you can fill out. If you run the program, it will test these functions to see if they work. At first, these tests will all fail. But if you implement these functions correctly, the tests will pass.

After passing all of the functional tests, the program will run some performance tests and show you the results.

## Solutions

If you want to see a working implementation, check out the `implementation_complete` tag.

# Example Output

The following shows what the output looks like when your binary search tree implementation is correct and you run the program.

testAddNode PASSED
testFindNode PASSED
testGetNodeLevel PASSED
testRemoveLeaf PASSED
testRemoveNodeWithOneChild PASSED
testRemoveNodeWithTwoChildren PASSED
testRemoveRootNode PASSED

Linear search time for 100 elements: 14 microseconds
Binary search time for 100 elements: 11 microseconds
The linear search took 1.27273 times longer than the binary search

Linear search time for 1000 elements: 1072 microseconds
Binary search time for 1000 elements: 84 microseconds
The linear search took 12.7619 times longer than the binary search

Linear search time for 10000 elements: 110541 microseconds
Binary search time for 10000 elements: 1894 microseconds
The linear search took 58.3638 times longer than the binary search

Linear search time for 100000 elements: 10753216 microseconds
Binary search time for 100000 elements: 21353 microseconds
The linear search took 503.593 times longer than the binary search

Notice that the Linear and Binary search times are very similar when there are a small (100) number of items; but, when there are a lot of times (100,000) the binary search is over 500 times faster!


