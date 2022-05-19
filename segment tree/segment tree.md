<h1> Segment tree </h1>  (unfinished)
<div> Data structure for range based query </div>


suppose there is an array with elements {1, 3, 2, -5, 6, 4}.
u need to find out the minimum element in the query range l to r.
<br><br>
where <br>
1 <= l <= arr.size() <br>
     1 <= r <= arr.size() <br>
       l < r
     <br><br> 
       
Brute force approach would be to iterate in the query range and 
update a ``min`` variable.<br> This will take ``O(N)`` time for each query.<br>
<br>Total time complexity : ```O(QN)``` where Q is the no. of query


<br> <br> <br>
Another approach <br>
