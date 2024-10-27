# Corner Grocer purchase frequency app
## Portfolio project by Kai Grignon for course CS 210 at Southern New Hampshire University
- The requirement for this project was to create a text-based application in C++ that counted the frequencies of words in a text file, output this data into another file, and finally made the data available to the user in three forms:
  1. Chart
  2. Histogram
  3. Specific search
- To store the data, I implemented a linked list. I implemented destructors in both the list class and the node class to ensure that when the list was deleted, all of the nodes were completely erased, preventing memory leakage.
- While the linked list served the purpose of storing the data, it was not the most efficient. To fix this, I would implement an unordered map instead.
- I found writing the addNode method for the linked list to be quite difficult, since I was dealing with a number of possible scenarios where the head and/or tail of the list could be null. I found it helpful to sketch the procedure on paper so I could visualize it more clearly. I intend to use this technique in similar situations in the future.
- I wrote documentation for each method and function in the program, as well as extensive in-line comments. This documentation helped me to keep the code organized and see the big picture. This would also be useful in the future if I or someone else were to refactor or adapt the code. Documenting my code is a skill that I think will be very helpful in future programming courses.
