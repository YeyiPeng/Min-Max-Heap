# Min-Max-Heap
###### Final Project of EECS 495 Intensive Programming Design
#### Introduction
* A min-max heap is a complete binary tree and often represented in an array. 
* Invariants:
  1. containing alternating min and max levels
  2. the root is always at min level
  3. every node at min level is less than all of its descendants
  4. every node at max level is greater than all of its descendants
* Basic operations:
  * insert an element
  * find the least/greatest element
  * delete the least/greatest element
* Time complexity:
  * Insert & deletion: O(lg n)
  * getMin & getMax: O(1)
