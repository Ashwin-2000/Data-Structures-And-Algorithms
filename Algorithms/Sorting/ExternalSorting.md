# External Sorting
- It is a hybrid sorting
- It is used when the file size is too large that could not fit into memory
- Eg. - The size of file : 500GB
      The size of RAM  : 10GB
     
- We divide the file size into small chunks that fit into memory,and sort that part and write as temporary file in memory.
- The we merge the sub-sorted files into single one.

