/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/

What if elements of nums2 are stored on disk, and the memory is
limited such that you cannot load all elements into the memory at
once?

If only nums2 cannot fit in memory, put all elements of nums1 into a HashMap, read chunks of array that fit into the memory, and record the intersections.

If both nums1 and nums2 are so huge that neither fit into the memory, sort them individually (external sort), then read 2 elements from each array at a time in memory, record intersections.

--

Thanks for the solution. I think the second part of the solution is impractical, if you read 2 elements at a time, this procedure will take forever. In principle, we want minimize the number of disk access during the run-time.

An improvement can be sort them using external sort, read (let's say) 2G of each into memory and then using the 2 pointer technique, then read 2G more from the array that has been exhausted. Repeat this until no more data to read from disk.

But I am not sure this solution is good enough for an interview setting. Maybe the interviewer is expecting some solution using Map-Reduce paradigm.

--

I think the goal of this question is to test whether the interview understands some of the data engineering techniques. From a data engineer's perspective, basically there are three ideas to solve the question:

Store the two strings in distributed system(whether self designed or not), then using MapReduce technique to solve the problem;

Processing the Strings by chunk, which fits the memory, then deal with each chunk of data at a time;

Processing the Strings by streaming, then check.
*/
